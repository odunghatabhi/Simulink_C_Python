/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flow.h
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

#ifndef RTW_HEADER_flow_h_
#define RTW_HEADER_flow_h_
#ifndef flow_COMMON_INCLUDES_
#define flow_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "flow_d8e93a5c_1_gateway.h"
#endif                                 /* flow_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_2_1_1[4];               /* '<S8>/INPUT_2_1_1' */
  real_T INPUT_1_1_1[4];               /* '<S8>/INPUT_1_1_1' */
  real_T STATE_1[19];                  /* '<S8>/STATE_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S8>/INPUT_2_1_1' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S8>/INPUT_1_1_1' */
  real_T STATE_1_Discrete[11];         /* '<S8>/STATE_1' */
  real_T NextOutput;                   /* '<Root>/Random Signal' */
  real_T OUTPUT_1_0_Discrete;          /* '<S8>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S8>/STATE_1' */
  void* STATE_1_SimData;               /* '<S8>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S8>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S8>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S8>/STATE_1' */
  void* SINK_1_RtwLogger;              /* '<S8>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S8>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S8>/SINK_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S8>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S8>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S8>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S8>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S8>/OUTPUT_1_0' */
  int_T STATE_1_Modes[8];              /* '<S8>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S8>/OUTPUT_1_0' */
  uint32_T RandSeed;                   /* '<Root>/Random Signal' */
  boolean_T STATE_1_FirstOutput;       /* '<S8>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S8>/OUTPUT_1_0' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
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

/* Block signals and states (default storage) */
extern DW rtDW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T sensormeasure;           /* '<S8>/OUTPUT_1_0' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T valve;                   /* Variable: valve
                                        * Referenced by: '<Root>/Innput Signal'
                                        */

/* Model entry point functions */
extern void flow_initialize(void);
extern void flow_step(void);
extern void flow_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'flow'
 * '<S1>'   : 'flow/PS-Simulink Converter'
 * '<S2>'   : 'flow/Simulink-PS Converter'
 * '<S3>'   : 'flow/Simulink-PS Converter1'
 * '<S4>'   : 'flow/Solver Configuration2'
 * '<S5>'   : 'flow/PS-Simulink Converter/EVAL_KEY'
 * '<S6>'   : 'flow/Simulink-PS Converter/EVAL_KEY'
 * '<S7>'   : 'flow/Simulink-PS Converter1/EVAL_KEY'
 * '<S8>'   : 'flow/Solver Configuration2/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_flow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
