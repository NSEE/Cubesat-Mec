/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * untitled_acc.c
 *
 * Code generation for model "untitled_acc.mdl".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Mon Aug 25 16:47:53 2014
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "untitled_acc.h"
#include "untitled_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T B_0_4_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_0_2_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE;
  if (ssGetTaskTime(S,0) < ((Parameters *) ssGetDefaultParam(S))->P_4) {
    B_0_4_0 = ((Parameters *) ssGetDefaultParam(S))->P_5;
  } else {
    B_0_4_0 = ((Parameters *) ssGetDefaultParam(S))->P_6;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_6_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_0_8_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_10 * ((BlockIO *) _ssGetBlockIO(S))->B_0_2_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_0_9_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_11 * ((BlockIO *) _ssGetBlockIO(S))->B_0_8_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 = (((((Parameters *)
    ssGetDefaultParam(S))->P_1 * ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0 +
    ((Parameters *) ssGetDefaultParam(S))->P_3 * ((BlockIO *) _ssGetBlockIO(S)
    )->B_0_2_0) + ((Parameters *) ssGetDefaultParam(S))->P_7 * B_0_4_0) +
    ((Parameters *) ssGetDefaultParam(S))->P_9 * ((BlockIO *) _ssGetBlockIO(S)
    )->B_0_6_0) + ((BlockIO *) _ssGetBlockIO(S))->B_0_9_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<Root>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 11, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 12, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 13, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 14, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 15, SS_CALL_MDL_OUTPUTS);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_0_2_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_0_10_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_0_8_0;
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 78692557U);
  ssSetChecksumVal(S, 1, 2009548506U);
  ssSetChecksumVal(S, 2, 1310892213U);
  ssSetChecksumVal(S, 3, 3380910309U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
