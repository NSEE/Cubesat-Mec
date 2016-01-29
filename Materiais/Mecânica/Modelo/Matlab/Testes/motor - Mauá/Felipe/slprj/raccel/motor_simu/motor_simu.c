#include <math.h>
#include "motor_simu.h"
#include "motor_simu_private.h"
#include "motor_simu_dt.h"

const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;

#ifdef RSIM_WITH_SOLVER_MULTITASKING

const boolean_T gbl_raccel_isMultitasking = 1;

#else

const boolean_T gbl_raccel_isMultitasking = 0;

#endif

const boolean_T gbl_raccel_tid01eq = 0;
const int_T gbl_raccel_NumST = 2;
const char_T *gbl_raccel_Version = "8.0 (R2011a) 09-Mar-2011";
void raccel_setup_MMIStateLog(SimStruct* S)
{

#ifdef UseMMIDataLogging

  rt_FillStateSigInfoFromMMI(ssGetRTWLogInfo(S),&ssGetErrorStatus(S));

#endif

}

const char *gblSlvrJacPatternFileName =
  "slprj\\raccel\\motor_simu\\motor_simu_Jpattern.mat";
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"

BlockIO rtB;
ContinuousStates rtX;
D_Work rtDWork;
static SimStruct model_S;
SimStruct *const rtS = &model_S;
void MdlInitialize(void)
{
  rtX.Integrator_CSTATE = rtP.Integrator_IC;
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;
  rtX.Integrator_CSTATE_b = rtP.Integrator_IC_i;
  rtX.Integrator1_CSTATE_k = rtP.Integrator1_IC_p;
  rtX.Integrator_CSTATE_o = rtP.Integrator_IC_o;
  rtX.Filter_CSTATE = rtP.Filter_IC;
  rtX.Integrator_CSTATE_p = rtP.Integrator_IC_h;
  rtX.Filter_CSTATE_l = rtP.Filter_IC_i;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlOutputs(int_T tid)
{
  real_T rtb_Filter;
  real_T rtb_Sum_g;
  real_T rtb_Integrator;
  real_T rtb_Sum_a;
  real_T rtb_Kt;
  real_T rtb_DerivativeGain;
  rtB.Integrator = rtX.Integrator_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    if (ssIsMajorTimeStep(rtS)) {
      rtDWork.D_MODE = ((ssGetTaskTime(rtS,0) >= rtP.D_Time));
    }

    if (rtDWork.D_MODE == 1) {
      rtB.D = rtP.D_YFinal;
    } else {
      rtB.D = rtP.D_Y0;
    }
  }

  rtb_Sum_g = rtX.Integrator1_CSTATE;
  rtB.Sum1 = rtB.D + rtb_Sum_g;
  if (ssIsSampleHit(rtS, 1, 0)) {
    if (ssIsMajorTimeStep(rtS)) {
      rtDWork.theta_e_MODE = ((ssGetTaskTime(rtS,0) >= rtP.theta_e_Time));
    }

    if (rtDWork.theta_e_MODE == 1) {
      rtB.theta_e = rtP.theta_e_YFinal;
    } else {
      rtB.theta_e = rtP.theta_e_Y0;
    }
  }

  rtB.i = rtX.Integrator_CSTATE_b;
  rtb_Kt = rtP.Kt_Gain * rtB.i;
  rtB.dthetadt = rtX.Integrator1_CSTATE_k;
  rtB.d2thetadt2 = (rtb_Kt - rtP.Damping_Gain * rtB.dthetadt) * rtP.Inertia_Gain;
  rtB.u = rtP.I_Gain * rtB.d2thetadt2 * rtP.u_Gain;
  rtb_Sum_g = rtB.theta_e - rtB.Sum1;
  rtb_Kt = rtP.ProportionalGain_Gain * rtb_Sum_g;
  rtb_Integrator = rtX.Integrator_CSTATE_o;
  rtb_DerivativeGain = rtP.DerivativeGain_Gain * rtb_Sum_g;
  rtb_Sum_a = rtX.Filter_CSTATE;
  rtB.FilterCoefficient = (rtb_DerivativeGain - rtb_Sum_a) *
    rtP.FilterCoefficient_Gain;
  rtB.Sum = (rtb_Kt + rtb_Integrator) + rtB.FilterCoefficient;
  rtb_Sum_a = rtB.Sum - rtB.dthetadt;
  rtb_Kt = rtP.ProportionalGain_Gain_j * rtb_Sum_a;
  rtb_Integrator = rtX.Integrator_CSTATE_p;
  rtb_DerivativeGain = rtP.DerivativeGain_Gain_l * rtb_Sum_a;
  rtb_Filter = rtX.Filter_CSTATE_l;
  rtB.FilterCoefficient_g = (rtb_DerivativeGain - rtb_Filter) *
    rtP.FilterCoefficient_Gain_p;
  rtB.Sum_h = (rtb_Kt + rtb_Integrator) + rtB.FilterCoefficient_g;
  if (ssIsMajorTimeStep(rtS)) {
    rtDWork.Saturation_MODE = rtB.Sum_h >= rtP.Saturation_UpperSat ? 1 :
      rtB.Sum_h > rtP.Saturation_LowerSat ? 0 : -1;
  }

  rtB.Saturation = rtDWork.Saturation_MODE == 1 ? rtP.Saturation_UpperSat :
    rtDWork.Saturation_MODE == -1 ? rtP.Saturation_LowerSat : rtB.Sum_h;
  rtB.didt = ((rtB.Saturation - rtP.Resistance_Gain * rtB.i) - rtP.Ke_Gain *
              rtB.dthetadt) * rtP.Inductance_Gain;
  rtB.IntegralGain = rtP.IntegralGain_Gain * rtb_Sum_a;
  rtB.IntegralGain_n = rtP.IntegralGain_Gain_o * rtb_Sum_g;
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  UNUSED_PARAMETER(tid);
}

void MdlDerivatives(void)
{
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE = rtB.u;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE = rtB.Integrator;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_b = rtB.didt;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE_k = rtB.d2thetadt2;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_o =
      rtB.IntegralGain_n;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Filter_CSTATE = rtB.FilterCoefficient;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_p = rtB.IntegralGain;
  }

  {
    ((StateDerivatives *) ssGetdX(rtS))->Filter_CSTATE_l =
      rtB.FilterCoefficient_g;
  }
}

void MdlProjection(void)
{
}

void MdlInitSystemMatrices(void)
{
}

void MdlZeroCrossings(void)
{
  ((ZCSignalValues *) ssGetSolverZcSignalVector(rtS))->D_StepTime_ZC = ssGetT
    (rtS) - rtP.D_Time;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(rtS))->theta_e_StepTime_ZC =
    ssGetT(rtS) - rtP.theta_e_Time;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(rtS))->Saturation_UprLim_ZC =
    rtB.Sum_h - rtP.Saturation_UpperSat;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(rtS))->Saturation_LwrLim_ZC =
    rtB.Sum_h - rtP.Saturation_LowerSat;
}

void MdlTerminate(void)
{
}

void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 8);
  ssSetNumY(rtS, 0);
  ssSetNumU(rtS, 0);
  ssSetDirectFeedThrough(rtS, 0);
  ssSetNumSampleTimes(rtS, 2);
  ssSetNumBlocks(rtS, 42);
  ssSetNumBlockIO(rtS, 16);
  ssSetNumBlockParams(rtS, 32);
}

void MdlInitializeSampleTimes(void)
{
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
}

void raccel_set_checksum(SimStruct *rtS)
{
  ssSetChecksumVal(rtS, 0, 1679774229U);
  ssSetChecksumVal(rtS, 1, 1100778443U);
  ssSetChecksumVal(rtS, 2, 218967375U);
  ssSetChecksumVal(rtS, 3, 3509204635U);
}

SimStruct * raccel_register_model(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(BlockIO));
  }

  ssSetDefaultParam(rtS, (real_T *) &rtP);

  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(ContinuousStates));
  }

  {
    void *dwork = (void *) &rtDWork;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(D_Work));
  }

  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
    dtInfo.B = &rtBTransTable;
    dtInfo.P = &rtPTransTable;
  }

  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "motor_simu");
  ssSetPath(rtS, "motor_simu");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 300.0);

  {
    static RTWLogInfo rt_DataLoggingInfo;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  {
    {
      static int_T rt_LoggedStateWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "motor_simu/Integrator",
        "motor_simu/Integrator1",
        "motor_simu/Motor + Controlador/DC Motor/Integrator",
        "motor_simu/Motor + Controlador/DC Motor/Integrator1",
        "motor_simu/PID theta_c/Integrator",
        "motor_simu/PID theta_c/Filter",
        "motor_simu/Motor + Controlador/PID speed_c/Integrator",
        "motor_simu/Motor + Controlador/PID speed_c/Filter"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        8,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[8];
      rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)&rtX.Integrator_CSTATE;
      rt_LoggedStateSignalPtrs[1] = (void*)&rtX.Integrator1_CSTATE;
      rt_LoggedStateSignalPtrs[2] = (void*)&rtX.Integrator_CSTATE_b;
      rt_LoggedStateSignalPtrs[3] = (void*)&rtX.Integrator1_CSTATE_k;
      rt_LoggedStateSignalPtrs[4] = (void*)&rtX.Integrator_CSTATE_o;
      rt_LoggedStateSignalPtrs[5] = (void*)&rtX.Filter_CSTATE;
      rt_LoggedStateSignalPtrs[6] = (void*)&rtX.Integrator_CSTATE_p;
      rt_LoggedStateSignalPtrs[7] = (void*)&rtX.Filter_CSTATE_l;
    }

    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "tmp_raccel_xout");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "xFinal");
    rtliSetSigLog(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "none");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 1000);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[8];
    static real_T absTol[8] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6,
      1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[8] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U };

    static uint8_T zcAttributes[4] = { (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP),
      (ZC_EVENT_ALL), (ZC_EVENT_ALL) };

    static ssNonContDerivSigInfo nonContDerivSigInfo[2] = {
      { 1*sizeof(real_T), (char*)(&rtB.theta_e), (NULL) }
      , { 1*sizeof(real_T), (char*)(&rtB.D), (NULL) }
    };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.0001);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 1);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 2);
    ssSetNonContDerivSigInfos(rtS, nonContDerivSigInfo);
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "ode45");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverZcSignalAttrib(rtS, zcAttributes);
    ssSetSolverNumZcSignals(rtS, 4);
    ssSetModelZeroCrossings(rtS, MdlZeroCrossings);
    ssSetSolverConsecutiveZCsStepRelTol(rtS, 2.8421709430404007E-13);
    ssSetSolverMaxConsecutiveZCs(rtS, 1000);
    ssSetSolverConsecutiveZCsError(rtS, 2);
    ssSetSolverMaskedZcDiagnostic(rtS, 1);
    ssSetSolverIgnoredZcDiagnostic(rtS, 1);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 4);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 1679774229U);
  ssSetChecksumVal(rtS, 1, 1100778443U);
  ssSetChecksumVal(rtS, 2, 218967375U);
  ssSetChecksumVal(rtS, 3, 3509204635U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ssSetRTWExtModeInfo(rtS, &rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ssGetRTWExtModeInfo(rtS), &ssGetModelMappingInfo
      (rtS));
    rteiSetChecksumsPtr(ssGetRTWExtModeInfo(rtS), ssGetChecksums(rtS));
    rteiSetTPtr(ssGetRTWExtModeInfo(rtS), ssGetTPtr(rtS));
  }

  return rtS;
}
