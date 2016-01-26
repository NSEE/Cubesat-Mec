#include "__cf_simu.h"
#ifndef RTW_HEADER_simu_h_
#define RTW_HEADER_simu_h_
#ifndef simu_COMMON_INCLUDES_
#define simu_COMMON_INCLUDES_
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
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "simu_types.h"
#define MODEL_NAME simu
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (2)   
#elif NCSTATES != 2
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { real_T oovwbqjh43 ; real_T e3tkznhazr ; real_T bkfo2fpbcc ;
real_T id3ixiwic0 ; } BlockIO ; typedef struct { struct { void * LoggedData ;
} mzr4adu30a ; struct { void * LoggedData ; } p35mfe5krn ; struct { void *
LoggedData ; } d4jp05lalp ; int_T edwmkoqjaw ; } D_Work ; typedef struct {
real_T namf2lydjp ; real_T kohwojvt5z ; } ContinuousStates ; typedef struct {
real_T namf2lydjp ; real_T kohwojvt5z ; } StateDerivatives ; typedef struct {
boolean_T namf2lydjp ; boolean_T kohwojvt5z ; } StateDisabled ; typedef
struct { real_T namf2lydjp ; real_T kohwojvt5z ; } CStateAbsTol ; typedef
struct { real_T jvmfk2vttc ; } ZCSignalValues ; typedef struct { ZCSigState
h3bbe0mwyd ; } PrevZCSigStates ; struct Parameters_ { real_T Integrator1_IC ;
real_T Integrator_IC ; real_T Ir_Time ; real_T Ir_Y0 ; real_T Ir_YFinal ;
real_T Gain_Gain ; real_T Gain1_Gain ; real_T Gain3_Gain ; real_T Gain2_Gain
; } ; extern Parameters rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR
; extern BlockIO rtB ; extern ContinuousStates rtX ; extern D_Work rtDWork ;
extern PrevZCSigStates rtPrevZCSigState ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
#endif
