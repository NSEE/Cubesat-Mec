#ifndef RTW_HEADER_motor_simu_h_
#define RTW_HEADER_motor_simu_h_
#ifndef motor_simu_COMMON_INCLUDES_
# define motor_simu_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#endif

#include "motor_simu_types.h"
#define MODEL_NAME                     motor_simu
#define NSAMPLE_TIMES                  (2)
#define NINPUTS                        (0)
#define NOUTPUTS                       (0)
#define NBLOCKIO                       (16)
#define NUM_ZC_EVENTS                  (0)
#ifndef NCSTATES
# define NCSTATES                      (8)
#elif NCSTATES != 8
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

typedef struct {
  real_T Integrator;
  real_T D;
  real_T Sum1;
  real_T theta_e;
  real_T i;
  real_T dthetadt;
  real_T d2thetadt2;
  real_T u;
  real_T FilterCoefficient;
  real_T Sum;
  real_T FilterCoefficient_g;
  real_T Sum_h;
  real_T Saturation;
  real_T didt;
  real_T IntegralGain;
  real_T IntegralGain_n;
} BlockIO;

typedef struct {
  struct {
    void *LoggedData;
  } speed1_PWORK;

  struct {
    void *LoggedData;
  } theta_PWORK;

  struct {
    void *LoggedData;
  } acel_m1_PWORK;

  struct {
    void *LoggedData;
  } speed_m_PWORK;

  struct {
    void *LoggedData;
  } voltage_saturation_PWORK;

  struct {
    void *LoggedData;
  } Scope_PWORK;

  int_T D_MODE;
  int_T theta_e_MODE;
  int_T Saturation_MODE;
} D_Work;

typedef struct {
  real_T Integrator_CSTATE;
  real_T Integrator1_CSTATE;
  real_T Integrator_CSTATE_b;
  real_T Integrator1_CSTATE_k;
  real_T Integrator_CSTATE_o;
  real_T Filter_CSTATE;
  real_T Integrator_CSTATE_p;
  real_T Filter_CSTATE_l;
} ContinuousStates;

typedef struct {
  real_T Integrator_CSTATE;
  real_T Integrator1_CSTATE;
  real_T Integrator_CSTATE_b;
  real_T Integrator1_CSTATE_k;
  real_T Integrator_CSTATE_o;
  real_T Filter_CSTATE;
  real_T Integrator_CSTATE_p;
  real_T Filter_CSTATE_l;
} StateDerivatives;

typedef struct {
  boolean_T Integrator_CSTATE;
  boolean_T Integrator1_CSTATE;
  boolean_T Integrator_CSTATE_b;
  boolean_T Integrator1_CSTATE_k;
  boolean_T Integrator_CSTATE_o;
  boolean_T Filter_CSTATE;
  boolean_T Integrator_CSTATE_p;
  boolean_T Filter_CSTATE_l;
} StateDisabled;

typedef struct {
  real_T D_StepTime_ZC;
  real_T theta_e_StepTime_ZC;
  real_T Saturation_UprLim_ZC;
  real_T Saturation_LwrLim_ZC;
} ZCSignalValues;

typedef struct {
  ZCSigState D_StepTime_ZCE;
  ZCSigState theta_e_StepTime_ZCE;
  ZCSigState Saturation_UprLim_ZCE;
  ZCSigState Saturation_LwrLim_ZCE;
} PrevZCSigStates;

struct Parameters_ {
  real_T Integrator_IC;
  real_T D_Time;
  real_T D_Y0;
  real_T D_YFinal;
  real_T Integrator1_IC;
  real_T theta_e_Time;
  real_T theta_e_Y0;
  real_T theta_e_YFinal;
  real_T Integrator_IC_i;
  real_T Kt_Gain;
  real_T Integrator1_IC_p;
  real_T Damping_Gain;
  real_T Inertia_Gain;
  real_T I_Gain;
  real_T u_Gain;
  real_T ProportionalGain_Gain;
  real_T Integrator_IC_o;
  real_T DerivativeGain_Gain;
  real_T Filter_IC;
  real_T FilterCoefficient_Gain;
  real_T ProportionalGain_Gain_j;
  real_T Integrator_IC_h;
  real_T DerivativeGain_Gain_l;
  real_T Filter_IC_i;
  real_T FilterCoefficient_Gain_p;
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Resistance_Gain;
  real_T Ke_Gain;
  real_T Inductance_Gain;
  real_T IntegralGain_Gain;
  real_T IntegralGain_Gain_o;
};

extern Parameters rtP;
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern BlockIO rtB;
extern ContinuousStates rtX;
extern D_Work rtDWork;
extern PrevZCSigStates rtPrevZCSigState;
extern SimStruct *const rtS;
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif
