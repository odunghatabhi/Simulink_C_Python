/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bounce.h
 *
 * Code generated for Simulink model 'bounce'.
 *
 * Model version                  : 10.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar 13 13:57:40 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bounce_h_
#define RTW_HEADER_bounce_h_
#ifndef bounce_COMMON_INCLUDES_
#define bounce_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bounce_COMMON_INCLUDES_ */

#include "bounce_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T dxdt_DSTATE;                  /* '<S1>/dxdt' */
  real_T StateNameX;                   /* '<S1>/x' */
  int8_T dxdt_PrevResetState;          /* '<S1>/dxdt' */
  int8_T x_PrevResetState;             /* '<S1>/x' */
  uint8_T dxdt_IC_LOADING;             /* '<S1>/dxdt' */
  uint8_T x_IC_LOADING;                /* '<S1>/x' */
  boolean_T InitialVelocity_FirstOutputTime;/* '<Root>/Initial Velocity ' */
} DW_bounce_T;

/* Real-time Model Data Structure */
struct tag_RTM_bounce_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block states (default storage) */
extern DW_bounce_T bounce_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Velocity;                /* '<S1>/dxdt' */
extern real_T Position;                /* '<S1>/x' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T coefficient_of_restitution;/* Variable: coefficient_of_restitution
                                          * Referenced by: '<Root>/Coefficient of  Restitution'
                                          */
extern real_T gravitational_constant;  /* Variable: gravitational_constant
                                        * Referenced by: '<Root>/Gravitational acceleration'
                                        */

/* Model entry point functions */
extern void bounce_initialize(void);
extern void bounce_step(void);
extern void bounce_terminate(void);

/* Real-time Model object */
extern RT_MODEL_bounce_T *const bounce_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S3>/ICDXDT_Consistent' : Unused code path elimination
 * Block '<S3>/ReinitializationFlag' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bounce'
 * '<S1>'   : 'bounce/Second-Order  Integrator'
 * '<S2>'   : 'bounce/Second-Order  Integrator/Integration Logic'
 * '<S3>'   : 'bounce/Second-Order  Integrator/InternalICDXDT'
 * '<S4>'   : 'bounce/Second-Order  Integrator/InternalICX'
 * '<S5>'   : 'bounce/Second-Order  Integrator/StateValueAtInitialization'
 * '<S6>'   : 'bounce/Second-Order  Integrator/Integration Logic/Compare To Zero'
 * '<S7>'   : 'bounce/Second-Order  Integrator/Integration Logic/Compare To Zero1'
 * '<S8>'   : 'bounce/Second-Order  Integrator/Integration Logic/Compare To Zero2'
 * '<S9>'   : 'bounce/Second-Order  Integrator/Integration Logic/Compare To Zero3'
 * '<S10>'  : 'bounce/Second-Order  Integrator/Integration Logic/x greater than xU'
 * '<S11>'  : 'bounce/Second-Order  Integrator/Integration Logic/x less than xL'
 * '<S12>'  : 'bounce/Second-Order  Integrator/InternalICDXDT/Compare To Zero'
 * '<S13>'  : 'bounce/Second-Order  Integrator/InternalICDXDT/Compare To Zero2'
 */
#endif                                 /* RTW_HEADER_bounce_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
