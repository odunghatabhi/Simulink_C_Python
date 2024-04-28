/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flow.c
 *
 * Code generated for Simulink model 'flow'.
 *
 * Model version                  : 3.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Mar 26 17:31:45 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "flow.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include <math.h>

/* Exported block signals */
real_T sensormeasure;                  /* '<S8>/OUTPUT_1_0' */

/* Exported block parameters */
real_T valve = 1.0;                    /* Variable: valve
                                        * Referenced by: '<Root>/Innput Signal'
                                        */

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void flow_step(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  char *msg;
  char *msg_0;
  char *msg_1;
  real_T tmp_3[27];
  real_T tmp_0[8];
  real_T tmp_5[8];
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_3;
  real_T time_tmp;
  real_T time_tmp_0;
  int32_T isHit;
  int32_T isHit_0;
  int32_T tmp_2;
  int_T tmp_4[4];
  int_T tmp_1[3];
  int_T tmp_6[3];
  boolean_T tmp;

  /* SimscapeInputBlock: '<S8>/INPUT_2_1_1' incorporates:
   *  RandomNumber: '<Root>/Random Signal'
   */
  rtDW.INPUT_2_1_1[0] = rtDW.NextOutput;
  rtDW.INPUT_2_1_1[1] = 0.0;
  rtDW.INPUT_2_1_1[2] = 0.0;
  rtDW.INPUT_2_1_1_Discrete[0] = !(rtDW.INPUT_2_1_1[0] ==
    rtDW.INPUT_2_1_1_Discrete[1]);
  rtDW.INPUT_2_1_1_Discrete[1] = rtDW.INPUT_2_1_1[0];
  rtDW.INPUT_2_1_1[0] = rtDW.INPUT_2_1_1_Discrete[1];
  rtDW.INPUT_2_1_1[3] = rtDW.INPUT_2_1_1_Discrete[0];

  /* SimscapeInputBlock: '<S8>/INPUT_1_1_1' incorporates:
   *  Constant: '<Root>/Innput Signal'
   */
  rtDW.INPUT_1_1_1[0] = valve;
  rtDW.INPUT_1_1_1[1] = 0.0;
  rtDW.INPUT_1_1_1[2] = 0.0;
  rtDW.INPUT_1_1_1_Discrete[0] = !(rtDW.INPUT_1_1_1[0] ==
    rtDW.INPUT_1_1_1_Discrete[1]);
  rtDW.INPUT_1_1_1_Discrete[1] = rtDW.INPUT_1_1_1[0];
  rtDW.INPUT_1_1_1[0] = rtDW.INPUT_1_1_1_Discrete[1];
  rtDW.INPUT_1_1_1[3] = rtDW.INPUT_1_1_1_Discrete[0];

  /* SimscapeExecutionBlock: '<S8>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S8>/OUTPUT_1_0'
   */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = ((rtM->Timing.clockTick0) * 1.0);
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 11;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 8;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_2_1_1[0];
  tmp_0[1] = rtDW.INPUT_2_1_1[1];
  tmp_0[2] = rtDW.INPUT_2_1_1[2];
  tmp_0[3] = rtDW.INPUT_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = rtDW.INPUT_1_1_1[0];
  tmp_0[5] = rtDW.INPUT_1_1_1[1];
  tmp_0[6] = rtDW.INPUT_1_1_1[2];
  tmp_0[7] = rtDW.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mOutputs.mN = 19;
  simulationData->mData->mOutputs.mX = &rtDW.STATE_1[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_tmp_0 = ((rtM->Timing.clockTick0) * 1.0);
  time_0 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S8>/STATE_1' */

  /* SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_4[0] = 0;
  tmp_3[0] = rtDW.INPUT_2_1_1[0];
  tmp_3[1] = rtDW.INPUT_2_1_1[1];
  tmp_3[2] = rtDW.INPUT_2_1_1[2];
  tmp_3[3] = rtDW.INPUT_2_1_1[3];
  tmp_4[1] = 4;
  tmp_3[4] = rtDW.INPUT_1_1_1[0];
  tmp_3[5] = rtDW.INPUT_1_1_1[1];
  tmp_3[6] = rtDW.INPUT_1_1_1[2];
  tmp_3[7] = rtDW.INPUT_1_1_1[3];
  tmp_4[2] = 8;
  memcpy(&tmp_3[8], &rtDW.STATE_1[0], 19U * sizeof(real_T));
  tmp_4[3] = 27;
  simulationData->mData->mInputValues.mN = 27;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mOutputs.mN = 1;

  /* SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */
  simulationData->mData->mOutputs.mX = &sensormeasure;

  /* SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_2 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_2;
  isHit_0 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_0;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(rtM, msg_0);
    }
  }

  /* Update for RandomNumber: '<Root>/Random Signal' */
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 500.0 +
    200000.0;

  /* Update for SimscapeExecutionBlock: '<S8>/STATE_1' */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_3 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_3;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 11;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 8;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_6[0] = 0;
  tmp_5[0] = rtDW.INPUT_2_1_1[0];
  tmp_5[1] = rtDW.INPUT_2_1_1[1];
  tmp_5[2] = rtDW.INPUT_2_1_1[2];
  tmp_5[3] = rtDW.INPUT_2_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = rtDW.INPUT_1_1_1[0];
  tmp_5[5] = rtDW.INPUT_1_1_1[1];
  tmp_5[6] = rtDW.INPUT_1_1_1[2];
  tmp_5[7] = rtDW.INPUT_1_1_1[3];
  tmp_6[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(rtM, msg_1);
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void flow_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for SimscapeExecutionBlock: '<S8>/STATE_1' */
    tmp = nesl_lease_simulator("flow/Solver Configuration2_1", 0, 0);
    rtDW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp_0) {
      flow_d8e93a5c_1_gateway();
      tmp = nesl_lease_simulator("flow/Solver Configuration2_1", 0, 0);
      rtDW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ON;
    modelParameters.mRTWModifiedTimeStamp = 6.33371299E+8;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 1.0;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S8>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("flow/Solver Configuration2_1", 1, 0);
    rtDW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(rtDW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      flow_d8e93a5c_1_gateway();
      tmp = nesl_lease_simulator("flow/Solver Configuration2_1", 1, 0);
      rtDW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_0.mRTWModifiedTimeStamp = 6.33371299E+8;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 1.0;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(rtM, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */

    /* InitializeConditions for RandomNumber: '<Root>/Random Signal' */
    rtDW.RandSeed = 1144108930U;
    rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 500.0 +
      200000.0;
  }
}

/* Model terminate function */
void flow_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S8>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)rtDW.STATE_1_SimData);
  nesl_erase_simulator("flow/Solver Configuration2_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S8>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)rtDW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("flow/Solver Configuration2_1");
  nesl_destroy_registry();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
