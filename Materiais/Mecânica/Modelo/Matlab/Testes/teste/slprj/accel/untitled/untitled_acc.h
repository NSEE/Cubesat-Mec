  /*
  * untitled_acc.h
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
  #ifndef RTW_HEADER_untitled_acc_h_
  #define RTW_HEADER_untitled_acc_h_
  

    #ifndef untitled_acc_COMMON_INCLUDES_
  # define untitled_acc_COMMON_INCLUDES_
    #include <stdlib.h>
    #include <stddef.h>
        #define S_FUNCTION_NAME simulink_only_sfcn 
  #define S_FUNCTION_LEVEL 2
  #define RTW_GENERATED_S_FUNCTION

    #include "rtwtypes.h"
    #include "simstruc.h"
    #include "fixedpoint.h"
    
  #endif /* untitled_acc_COMMON_INCLUDES_ */
  

    #include "untitled_acc_types.h"    

            /* Block signals (auto storage) */
                
          typedef struct  {
                    
                          real_T B_0_0_0; /* '<S1>/Integrator1' */

        

          
          
                          real_T B_0_2_0; /* '<S1>/Integrator' */

        

          
          
                          real_T B_0_6_0; /* '<S1>/Integrator2' */

        

          
          
                          real_T B_0_8_0; /* '<S1>/Gain3' */

        

          
          
                          real_T B_0_9_0; /* '<S1>/Gain4' */

        

          
          
                          real_T B_0_10_0; /* '<S1>/Sum' */

        

          

          } BlockIO;
        
            
          /* Block states (auto storage) for system '<Root>' */
            
      typedef struct  {
                  
                                struct {
        void *LoggedData;
    } Scope_PWORK; /* '<Root>/Scope' */

        

          
          
                                struct {
        void *LoggedData;
    } Scope1_PWORK; /* '<Root>/Scope1' */

        

          
          
                                struct {
        void *LoggedData;
    } Scope2_PWORK; /* '<Root>/Scope2' */

        

          
          
                                struct {
        void *LoggedData;
    } Scope3_PWORK; /* '<Root>/Scope3' */

        

          
          
                                struct {
        void *LoggedData;
    } Scope4_PWORK; /* '<Root>/Scope4' */

        char pad_Scope4_PWORK[4];

          

      } D_Work;
      
              
        /* Continuous states (auto storage) */
        typedef struct {
      	    real_T Integrator1_CSTATE; /* '<S1>/Integrator1' */
	    real_T Integrator_CSTATE; /* '<S1>/Integrator' */
	    real_T Integrator2_CSTATE; /* '<S1>/Integrator2' */
  
    } ContinuousStates;
    
        
        /* State derivatives (auto storage) */
        typedef struct {
      	    real_T Integrator1_CSTATE; /* '<S1>/Integrator1' */
	    real_T Integrator_CSTATE; /* '<S1>/Integrator' */
	    real_T Integrator2_CSTATE; /* '<S1>/Integrator2' */
  
    } StateDerivatives;
        
        
        /* State disabled  */
        typedef struct {
      	    boolean_T Integrator1_CSTATE; /* '<S1>/Integrator1' */
	    boolean_T Integrator_CSTATE; /* '<S1>/Integrator' */
	    boolean_T Integrator2_CSTATE; /* '<S1>/Integrator2' */
  
    } StateDisabled;
    
      
            /* Parameters (auto storage) */
      
        struct Parameters_ {
                      
             real_T P_0; /* Expression: 0
    * Referenced by: '<S1>/Integrator1'
   */
            
             real_T P_1; /* Expression: k2
    * Referenced by: '<S1>/Gain1'
   */
            
             real_T P_2; /* Expression: 0
    * Referenced by: '<S1>/Integrator'
   */
            
             real_T P_3; /* Expression: k1
    * Referenced by: '<S1>/Gain'
   */
            
             real_T P_4; /* Expression: 8
    * Referenced by: '<Root>/Step'
   */
            
             real_T P_5; /* Expression: 0
    * Referenced by: '<Root>/Step'
   */
            
             real_T P_6; /* Expression: 6
    * Referenced by: '<Root>/Step'
   */
            
             real_T P_7; /* Expression: k3
    * Referenced by: '<S1>/Gain2'
   */
            
             real_T P_8; /* Expression: 0
    * Referenced by: '<S1>/Integrator2'
   */
            
             real_T P_9; /* Expression: k5
    * Referenced by: '<S1>/Gain5'
   */
            
             real_T P_10; /* Expression: J
    * Referenced by: '<S1>/Gain3'
   */
            
             real_T P_11; /* Expression: k4
    * Referenced by: '<S1>/Gain4'
   */
  

        };
      
      

                        extern Parameters rtDefaultParameters; /* parameters */



      
    #endif /* RTW_HEADER_untitled_acc_h_ */
