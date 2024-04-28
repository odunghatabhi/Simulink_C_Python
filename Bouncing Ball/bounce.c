/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bounce.c
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

#include "bounce.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Exported block signals */
real_T Velocity;                       /* '<S1>/dxdt' */
real_T Position;                       /* '<S1>/x' */

/* Exported block parameters */
real_T coefficient_of_restitution = -0.8;/* Variable: coefficient_of_restitution
                                          * Referenced by: '<Root>/Coefficient of  Restitution'
                                          */
real_T gravitational_constant = -10.0; /* Variable: gravitational_constant
                                        * Referenced by: '<Root>/Gravitational acceleration'
                                        */

/* Block states (default storage) */
DW_bounce_T bounce_DW;

/* Real-time model */
static RT_MODEL_bounce_T bounce_M_;
RT_MODEL_bounce_T *const bounce_M = &bounce_M_;

/* Model step function */
void bounce_step(void)
{
  real_T rtb_InitialVelocity;
  real_T rtb_Switch_n_idx_0;
  real_T rtb_Switch_n_idx_1;
  real_T rtb_Time;
  boolean_T rtb_Compare_ha;
  boolean_T rtb_Compare_l;
  boolean_T rtb_LogicalOperator6;

  /* InitialCondition: '<Root>/Initial Velocity ' incorporates:
   *  Gain: '<Root>/Coefficient of  Restitution'
   *  Memory: '<Root>/Memory'
   */
  if (bounce_DW.InitialVelocity_FirstOutputTime) {
    bounce_DW.InitialVelocity_FirstOutputTime = false;
    rtb_InitialVelocity = 0.0;
  } else {
    rtb_InitialVelocity = coefficient_of_restitution * Velocity;
  }

  /* End of InitialCondition: '<Root>/Initial Velocity ' */

  /* DigitalClock: '<S1>/Time' */
  rtb_Time = ((bounce_M->Timing.clockTick0) * 1.0);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S1>/x0'
   */
  if (rtb_Time != 0.0) {
    rtb_Switch_n_idx_0 = bounce_DW.StateNameX;
    rtb_Switch_n_idx_1 = bounce_DW.dxdt_DSTATE;
  } else {
    rtb_Switch_n_idx_0 = 25.0;
    rtb_Switch_n_idx_1 = rtb_InitialVelocity;
  }

  /* End of Switch: '<S5>/Switch' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare_l = (rtb_Switch_n_idx_0 <= 0.0);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_ha = (rtb_Switch_n_idx_0 >= (rtInf));

  /* Logic: '<S2>/Logical Operator6' */
  rtb_LogicalOperator6 = (rtb_Compare_l || rtb_Compare_ha);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Logic: '<S3>/LowerSat And  dx Pos.'
   *  RelationalOperator: '<S12>/Compare'
   */
  if ((!(rtb_InitialVelocity > 0.0)) || (!rtb_Compare_l)) {
    /* Switch: '<S3>/Switch2' incorporates:
     *  Constant: '<S13>/Constant'
     *  Logic: '<S3>/Upper Sat  and dx Neg'
     *  RelationalOperator: '<S13>/Compare'
     */
    if ((!(rtb_InitialVelocity < 0.0)) || (!rtb_Compare_ha)) {
      /* Switch: '<S3>/Switch5' incorporates:
       *  Constant: '<S3>/Zero'
       *  Logic: '<S3>/Not Upper Sat  and Not Lower Sat'
       */
      if (rtb_Compare_l || rtb_Compare_ha) {
        rtb_InitialVelocity = 0.0;
      }

      /* End of Switch: '<S3>/Switch5' */
    }

    /* End of Switch: '<S3>/Switch2' */
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S1>/x0'
   *  Switch: '<S4>/Switch'
   */
  if (rtb_Time != 0.0) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/LowerLimitX'
     *  Switch: '<S4>/Switch1'
     */
    if (rtb_Compare_l) {
      rtb_Time = 0.0;
    } else if (rtb_Compare_ha) {
      /* Switch: '<S4>/Switch1' incorporates:
       *  Constant: '<S4>/UpperLimitX'
       */
      rtb_Time = (rtInf);
    } else {
      rtb_Time = bounce_DW.StateNameX;
    }
  } else {
    rtb_Time = 25.0;
  }

  /* End of Switch: '<S4>/Switch3' */

  /* DiscreteIntegrator: '<S1>/dxdt' incorporates:
   *  Switch: '<S3>/Switch3'
   *  Switch: '<S3>/Switch4'
   */
  if (bounce_DW.dxdt_IC_LOADING != 0) {
    bounce_DW.dxdt_DSTATE = rtb_InitialVelocity;
  }

  if (rtb_LogicalOperator6 && (bounce_DW.dxdt_PrevResetState <= 0)) {
    bounce_DW.dxdt_DSTATE = rtb_InitialVelocity;
  }

  /* DiscreteIntegrator: '<S1>/dxdt' */
  Velocity = bounce_DW.dxdt_DSTATE;

  /* DiscreteIntegrator: '<S1>/x' */
  if (bounce_DW.x_IC_LOADING != 0) {
    bounce_DW.StateNameX = rtb_Time;
    if (bounce_DW.StateNameX < 0.0) {
      bounce_DW.StateNameX = 0.0;
    }
  }

  if (rtb_LogicalOperator6 && (bounce_DW.x_PrevResetState <= 0)) {
    bounce_DW.StateNameX = rtb_Time;
    if (bounce_DW.StateNameX < 0.0) {
      bounce_DW.StateNameX = 0.0;
    }
  }

  /* DiscreteIntegrator: '<S1>/x' */
  Position = bounce_DW.StateNameX;

  /* Update for DiscreteIntegrator: '<S1>/dxdt' */
  bounce_DW.dxdt_IC_LOADING = 0U;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<Root>/Gravitational acceleration'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S2>/Logical Operator1'
   *  Logic: '<S2>/Logical Operator3'
   *  Logic: '<S2>/Logical Operator4'
   *  Logic: '<S2>/Low Sat  And u positive'
   *  Logic: '<S2>/Lower Sat  And v positive'
   *  Logic: '<S2>/Upper Sat  And u negative'
   *  Logic: '<S2>/Upper Sat  And v negative'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (((gravitational_constant > 0.0) && rtb_Compare_l) || (rtb_Compare_ha &&
       (gravitational_constant < 0.0)) || ((!rtb_Compare_l) && (!rtb_Compare_ha))
      || (rtb_Compare_ha && (rtb_Switch_n_idx_1 < 0.0)) || (rtb_Compare_l &&
       (rtb_Switch_n_idx_1 > 0.0))) {
    rtb_Switch_n_idx_1 = gravitational_constant;
  } else {
    rtb_Switch_n_idx_1 = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S1>/dxdt' incorporates:
   *  Switch: '<S2>/Switch'
   */
  bounce_DW.dxdt_DSTATE += rtb_Switch_n_idx_1;
  bounce_DW.dxdt_PrevResetState = (int8_T)rtb_LogicalOperator6;

  /* Update for DiscreteIntegrator: '<S1>/x' incorporates:
   *  DiscreteIntegrator: '<S1>/dxdt'
   */
  bounce_DW.x_IC_LOADING = 0U;
  bounce_DW.StateNameX += Velocity;
  if (bounce_DW.StateNameX < 0.0) {
    bounce_DW.StateNameX = 0.0;
  }

  bounce_DW.x_PrevResetState = (int8_T)rtb_LogicalOperator6;

  /* End of Update for DiscreteIntegrator: '<S1>/x' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  bounce_M->Timing.clockTick0++;
}

/* Model initialize function */
void bounce_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for InitialCondition: '<Root>/Initial Velocity ' */
  bounce_DW.InitialVelocity_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/dxdt' */
  bounce_DW.dxdt_PrevResetState = 2;
  bounce_DW.dxdt_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/x' */
  bounce_DW.x_PrevResetState = 2;
  bounce_DW.x_IC_LOADING = 1U;
}

/* Model terminate function */
void bounce_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
