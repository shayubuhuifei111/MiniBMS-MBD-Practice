/*
 * BATTERY_MANAGEMENT_SYSTEM.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "BATTERY_MANAGEMENT_SYSTEM".
 *
 * Model version              : 1.125
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Wed Jul 30 17:59:57 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BATTERY_MANAGEMENT_SYSTEM_h_
#define BATTERY_MANAGEMENT_SYSTEM_h_
#ifndef BATTERY_MANAGEMENT_SYSTEM_COMMON_INCLUDES_
#define BATTERY_MANAGEMENT_SYSTEM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                          /* BATTERY_MANAGEMENT_SYSTEM_COMMON_INCLUDES_ */

#include "BATTERY_MANAGEMENT_SYSTEM_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T BM_CtctrFlt;               /* '<S3>/BMS OPERATION MODE' */
} B_BATTERY_MANAGEMENT_SYSTEM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S4>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S4>/Discrete-Time Integrator' */
  real_T BPC_BattAmpHr;                /* '<S4>/Data Store Memory1' */
  real_T BPC_BattWHr;                  /* '<S4>/Data Store Memory2' */
  uint32_T temporalCounter_i1;         /* '<S3>/BMS OPERATION MODE' */
  int16_T UnitDelay_DSTATE;            /* '<S13>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S16>/Unit Delay' */
  int16_T UnitDelay_DSTATE_kw;         /* '<S19>/Unit Delay' */
  int16_T UnitDelay_DSTATE_e;          /* '<S25>/Unit Delay' */
  int16_T UnitDelay_DSTATE_b;          /* '<S28>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S31>/Unit Delay' */
  int16_T UnitDelay_DSTATE_or;         /* '<S51>/Unit Delay' */
  int16_T UnitDelay_DSTATE_e0;         /* '<S54>/Unit Delay' */
  int16_T UnitDelay_DSTATE_p;          /* '<S57>/Unit Delay' */
  int16_T UnitDelay_DSTATE_on;         /* '<S39>/Unit Delay' */
  int16_T UnitDelay_DSTATE_c;          /* '<S42>/Unit Delay' */
  int16_T UnitDelay_DSTATE_os;         /* '<S45>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_d;          /* '<S1>/Unit Delay' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S4>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S4>/Discrete-Time Integrator' */
  uint8_T is_active_c3_BATTERY_MANAGEMENT;/* '<S3>/BMS OPERATION MODE' */
  uint8_T is_c3_BATTERY_MANAGEMENT_SYSTEM;/* '<S3>/BMS OPERATION MODE' */
  uint8_T is_CONTACTOR_CONNECT_SEQUENCE;/* '<S3>/BMS OPERATION MODE' */
  boolean_T Memory_PreviousInput;      /* '<S14>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S17>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S20>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S26>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S29>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S32>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S52>/Memory' */
  boolean_T Memory_PreviousInput_hv;   /* '<S55>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S58>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S40>/Memory' */
  boolean_T Memory_PreviousInput_hg;   /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_fv;   /* '<S46>/Memory' */
} DW_BATTERY_MANAGEMENT_SYSTEM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Obsr_VCell[3];              /* '<Root>/Obsr_VCell' */
  real32_T Obsr_VBatPack;              /* '<Root>/Obsr_VBatPack' */
  real32_T Obsr_VBus;                  /* '<Root>/Obsr_VBus' */
  real_T Obsr_TMdul[3];                /* '<Root>/Obsr_TMdul' */
  real_T Obsr_IBatPack;                /* '<Root>/Obsr_IBatPack' */
  boolean_T Obsr_StsIgnOn;             /* '<Root>/Obsr_StsIgnOn' */
  boolean_T Obsr_StsChPlg;             /* '<Root>/Obsr_StsChPlg' */
} ExtU_BATTERY_MANAGEMENT_SYSTE_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T BM_OperMode;                 /* '<Root>/BM_OperMode' */
  boolean_T BM_CtctrCnctCmd;           /* '<Root>/BM_CtctrCnctCmd' */
  real32_T BPC_BattSoc;                /* '<Root>/BPC_BattSoc' */
  real_T BPC_BattWh;                   /* '<Root>/BPC_BattWh' */
  real_T BPC_BattAmpHr;                /* '<Root>/BPC_BattAmpHr' */
  real_T MTM_TBat;                     /* '<Root>/MTM_TBat' */
  uint8_T BFH_StsBattFlt;              /* '<Root>/BFH_StsBattFlt' */
  boolean_T BM_StsCtctrCnct;           /* '<Root>/BM_StsCtctrCnct' */
  real32_T Outport1;                   /* '<Root>/Outport1' */
  boolean_T Outport2;                  /* '<Root>/Outport2' */
} ExtY_BATTERY_MANAGEMENT_SYSTE_T;

/* Parameters (default storage) */
struct P_BATTERY_MANAGEMENT_SYSTEM_T_ {
  real32_T BM_TiCtctrCnct_P;           /* Variable: BM_TiCtctrCnct_P
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T BM_TiCtctrDCnct_P;          /* Variable: BM_TiCtctrDCnct_P
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real32_T BPC_BattTotalCharge_P;      /* Variable: BPC_BattTotalCharge_P
                                        * Referenced by:
                                        *   '<S4>/BMS_TiProc_C2'
                                        *   '<S4>/Discrete-Time Integrator'
                                        */
  real32_T BPC_BattTotalEnergy_P;      /* Variable: BPC_BattTotalEnergy_P
                                        * Referenced by: '<S4>/Discrete-Time Integrator1'
                                        */
  real32_T CVM_VCellMaxCutoffTh_P;     /* Variable: CVM_VCellMaxCutoffTh_P
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T CVM_VCellMaxDrtdTh_P;       /* Variable: CVM_VCellMaxDrtdTh_P
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real32_T CVM_VCellMaxWarnTh_P;       /* Variable: CVM_VCellMaxWarnTh_P
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real32_T CVM_VCellMinCutoffTh_P;     /* Variable: CVM_VCellMinCutoffTh_P
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T CVM_VCellMinDrtdTh_P;       /* Variable: CVM_VCellMinDrtdTh_P
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real32_T CVM_VCellMinWarnTh_P;       /* Variable: CVM_VCellMinWarnTh_P
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real32_T MTM_TMdulMaxCutoffTh_P;     /* Variable: MTM_TMdulMaxCutoffTh_P
                                        * Referenced by: '<S34>/Constant'
                                        */
  real32_T MTM_TMdulMaxDrtdTh_P;       /* Variable: MTM_TMdulMaxDrtdTh_P
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real32_T MTM_TMdulMaxWarnTh_P;       /* Variable: MTM_TMdulMaxWarnTh_P
                                        * Referenced by: '<S34>/Constant2'
                                        */
  real32_T MTM_TMdulMinCutoffTh_P;     /* Variable: MTM_TMdulMinCutoffTh_P
                                        * Referenced by: '<S35>/Constant'
                                        */
  real32_T MTM_TMdulMinDrtdTh_P;       /* Variable: MTM_TMdulMinDrtdTh_P
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real32_T MTM_TMdulMinWarnTh_P;       /* Variable: MTM_TMdulMinWarnTh_P
                                        * Referenced by: '<S35>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMaxCutoff_P;    /* Variable: CVM_DMaxVCellMaxCutoff_P
                                        * Referenced by: '<S10>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMaxDrtd_P;      /* Variable: CVM_DMaxVCellMaxDrtd_P
                                        * Referenced by: '<S11>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMaxWarn_P;      /* Variable: CVM_DMaxVCellMaxWarn_P
                                        * Referenced by: '<S12>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMinCutoff_P;    /* Variable: CVM_DMaxVCellMinCutoff_P
                                        * Referenced by: '<S22>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMinDrtd_P;      /* Variable: CVM_DMaxVCellMinDrtd_P
                                        * Referenced by: '<S23>/Constant2'
                                        */
  int16_T CVM_DMaxVCellMinWarn_P;      /* Variable: CVM_DMaxVCellMinWarn_P
                                        * Referenced by: '<S24>/Constant2'
                                        */
  int16_T CVM_DMinVCellMaxCutoff_P;    /* Variable: CVM_DMinVCellMaxCutoff_P
                                        * Referenced by: '<S10>/Constant3'
                                        */
  int16_T CVM_DMinVCellMaxDrtd_P;      /* Variable: CVM_DMinVCellMaxDrtd_P
                                        * Referenced by: '<S11>/Constant3'
                                        */
  int16_T CVM_DMinVCellMaxWarn_P;      /* Variable: CVM_DMinVCellMaxWarn_P
                                        * Referenced by: '<S12>/Constant3'
                                        */
  int16_T CVM_DMinVCellMinCutoff_P;    /* Variable: CVM_DMinVCellMinCutoff_P
                                        * Referenced by: '<S22>/Constant3'
                                        */
  int16_T CVM_DMinVCellMinDrtd_P;      /* Variable: CVM_DMinVCellMinDrtd_P
                                        * Referenced by: '<S23>/Constant3'
                                        */
  int16_T CVM_DMinVCellMinWarn_P;      /* Variable: CVM_DMinVCellMinWarn_P
                                        * Referenced by: '<S24>/Constant3'
                                        */
  int16_T MTM_DMaxTMdulMaxCutoff_P;    /* Variable: MTM_DMaxTMdulMaxCutoff_P
                                        * Referenced by: '<S36>/Constant2'
                                        */
  int16_T MTM_DMaxTMdulMaxDrtd_P;      /* Variable: MTM_DMaxTMdulMaxDrtd_P
                                        * Referenced by: '<S37>/Constant2'
                                        */
  int16_T MTM_DMaxTMdulMaxWarn_P;      /* Variable: MTM_DMaxTMdulMaxWarn_P
                                        * Referenced by: '<S38>/Constant2'
                                        */
  int16_T MTM_DMaxTMdulMinCutoff_P;    /* Variable: MTM_DMaxTMdulMinCutoff_P
                                        * Referenced by: '<S48>/Constant2'
                                        */
  int16_T MTM_DMaxTMdulMinDrtd_P;      /* Variable: MTM_DMaxTMdulMinDrtd_P
                                        * Referenced by: '<S49>/Constant2'
                                        */
  int16_T MTM_DMaxTMdulMinWarn_P;      /* Variable: MTM_DMaxTMdulMinWarn_P
                                        * Referenced by: '<S50>/Constant2'
                                        */
  int16_T MTM_DMinTMdulMaxCutoff_P;    /* Variable: MTM_DMinTMdulMaxCutoff_P
                                        * Referenced by: '<S36>/Constant3'
                                        */
  int16_T MTM_DMinTMdulMaxDrtd_P;      /* Variable: MTM_DMinTMdulMaxDrtd_P
                                        * Referenced by: '<S37>/Constant3'
                                        */
  int16_T MTM_DMinTMdulMaxWarn_P;      /* Variable: MTM_DMinTMdulMaxWarn_P
                                        * Referenced by: '<S38>/Constant3'
                                        */
  int16_T MTM_DMinTMdulMinCutoff_P;    /* Variable: MTM_DMinTMdulMinCutoff_P
                                        * Referenced by: '<S48>/Constant3'
                                        */
  int16_T MTM_DMinTMdulMinDrtd_P;      /* Variable: MTM_DMinTMdulMinDrtd_P
                                        * Referenced by: '<S49>/Constant3'
                                        */
  int16_T MTM_DMinTMdulMinWarn_P;      /* Variable: MTM_DMinTMdulMinWarn_P
                                        * Referenced by: '<S50>/Constant3'
                                        */
  uint8_T BMS_EnaFltSts[13];           /* Variable: BMS_EnaFltSts
                                        * Referenced by: '<S1>/BMS_FltEnaFlag'
                                        */
  uint8_T BMS_ModeEnaFltChk[13];       /* Variable: BMS_ModeEnaFltChk
                                        * Referenced by: '<S1>/BMS_FltEnaFlag'
                                        */
  uint8_T NrCutoff_C;                  /* Variable: NrCutoff_C
                                        * Referenced by:
                                        *   '<S1>/Constant3'
                                        *   '<S8>/Constant3'
                                        *   '<S9>/Constant3'
                                        *   '<S34>/Constant3'
                                        *   '<S35>/Constant3'
                                        */
  uint8_T NrDrtd_C;                    /* Variable: NrDrtd_C
                                        * Referenced by:
                                        *   '<S8>/Constant4'
                                        *   '<S9>/Constant4'
                                        *   '<S34>/Constant4'
                                        *   '<S35>/Constant4'
                                        */
  uint8_T NrNoFlt_C;                   /* Variable: NrNoFlt_C
                                        * Referenced by:
                                        *   '<S8>/Constant6'
                                        *   '<S9>/Constant6'
                                        *   '<S34>/Constant6'
                                        *   '<S35>/Constant6'
                                        */
  uint8_T NrTMdulSnsr_C;               /* Variable: NrTMdulSnsr_C
                                        * Referenced by: '<S6>/Constant'
                                        */
  uint8_T NrWarn_C;                    /* Variable: NrWarn_C
                                        * Referenced by:
                                        *   '<S8>/Constant5'
                                        *   '<S9>/Constant5'
                                        *   '<S34>/Constant5'
                                        *   '<S35>/Constant5'
                                        */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S14>/Memory'
                                  */
  boolean_T SRFlipFlop_initial_condition_l;
                               /* Mask Parameter: SRFlipFlop_initial_condition_l
                                * Referenced by: '<S17>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_c;
                               /* Mask Parameter: SRFlipFlop_initial_condition_c
                                * Referenced by: '<S20>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_ln;
                              /* Mask Parameter: SRFlipFlop_initial_condition_ln
                               * Referenced by: '<S26>/Memory'
                               */
  boolean_T SRFlipFlop_initial_condition_e;
                               /* Mask Parameter: SRFlipFlop_initial_condition_e
                                * Referenced by: '<S29>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_i;
                               /* Mask Parameter: SRFlipFlop_initial_condition_i
                                * Referenced by: '<S32>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_n;
                               /* Mask Parameter: SRFlipFlop_initial_condition_n
                                * Referenced by: '<S52>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_j;
                               /* Mask Parameter: SRFlipFlop_initial_condition_j
                                * Referenced by: '<S55>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_ig;
                              /* Mask Parameter: SRFlipFlop_initial_condition_ig
                               * Referenced by: '<S58>/Memory'
                               */
  boolean_T SRFlipFlop_initial_condition_cb;
                              /* Mask Parameter: SRFlipFlop_initial_condition_cb
                               * Referenced by: '<S40>/Memory'
                               */
  boolean_T SRFlipFlop_initial_condition_p;
                               /* Mask Parameter: SRFlipFlop_initial_condition_p
                                * Referenced by: '<S43>/Memory'
                                */
  boolean_T SRFlipFlop_initial_condition_d;
                               /* Mask Parameter: SRFlipFlop_initial_condition_d
                                * Referenced by: '<S46>/Memory'
                                */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Constant1_Value_ex;           /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Constant1_Value_ot;           /* Expression: 0
                                        * Referenced by: '<S51>/Constant1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S4>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_LowerSa;/* Expression: 0
                                          * Referenced by: '<S4>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S4>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S4>/Discrete-Time Integrator'
                                          */
  real_T Gain_Gain;                    /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 48*0.985
                                        * Referenced by: '<S4>/Data Store Memory1'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 48*3*4.22*0.985
                                        * Referenced by: '<S4>/Data Store Memory2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant1_Value_nt;           /* Expression: 0
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value_pz;           /* Expression: 0
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant1_Value_na;           /* Expression: 0
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Constant_Value_iq;            /* Expression: 1
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Constant1_Value_ke;           /* Expression: 0
                                        * Referenced by: '<S49>/Constant1'
                                        */
  real_T Constant_Value_is;            /* Expression: 1
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant1_Value_bn;           /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant1_Value_kp;           /* Expression: 0
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T Constant_Value_g2;            /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant1_Value_lu;           /* Expression: 0
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S4>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S4>/Saturation'
                                       */
  int16_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S13>/Unit Delay'
                                */
  int16_T UnitDelay_InitialCondition_f;
                             /* Computed Parameter: UnitDelay_InitialCondition_f
                              * Referenced by: '<S16>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S19>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_p;
                             /* Computed Parameter: UnitDelay_InitialCondition_p
                              * Referenced by: '<S25>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_a;
                             /* Computed Parameter: UnitDelay_InitialCondition_a
                              * Referenced by: '<S28>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S31>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_m;
                             /* Computed Parameter: UnitDelay_InitialCondition_m
                              * Referenced by: '<S51>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_n;
                             /* Computed Parameter: UnitDelay_InitialCondition_n
                              * Referenced by: '<S54>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_ms;
                            /* Computed Parameter: UnitDelay_InitialCondition_ms
                             * Referenced by: '<S57>/Unit Delay'
                             */
  int16_T UnitDelay_InitialCondition_k;
                             /* Computed Parameter: UnitDelay_InitialCondition_k
                              * Referenced by: '<S39>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S42>/Unit Delay'
                              */
  int16_T UnitDelay_InitialCondition_d;
                             /* Computed Parameter: UnitDelay_InitialCondition_d
                              * Referenced by: '<S45>/Unit Delay'
                              */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S14>/Logic'
                                        */
  boolean_T Logic_table_g[16];         /* Computed Parameter: Logic_table_g
                                        * Referenced by: '<S17>/Logic'
                                        */
  boolean_T Logic_table_n[16];         /* Computed Parameter: Logic_table_n
                                        * Referenced by: '<S20>/Logic'
                                        */
  boolean_T Logic_table_m[16];         /* Computed Parameter: Logic_table_m
                                        * Referenced by: '<S26>/Logic'
                                        */
  boolean_T Logic_table_f[16];         /* Computed Parameter: Logic_table_f
                                        * Referenced by: '<S29>/Logic'
                                        */
  boolean_T Logic_table_a[16];         /* Computed Parameter: Logic_table_a
                                        * Referenced by: '<S32>/Logic'
                                        */
  boolean_T Logic_table_p[16];         /* Computed Parameter: Logic_table_p
                                        * Referenced by: '<S52>/Logic'
                                        */
  boolean_T Logic_table_h[16];         /* Computed Parameter: Logic_table_h
                                        * Referenced by: '<S55>/Logic'
                                        */
  boolean_T Logic_table_fz[16];        /* Computed Parameter: Logic_table_fz
                                        * Referenced by: '<S58>/Logic'
                                        */
  boolean_T Logic_table_b[16];         /* Computed Parameter: Logic_table_b
                                        * Referenced by: '<S40>/Logic'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S43>/Logic'
                                        */
  boolean_T Logic_table_px[16];        /* Computed Parameter: Logic_table_px
                                        * Referenced by: '<S46>/Logic'
                                        */
  uint8_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S1>/Unit Delay'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_BATTERY_MANAGEMENT_SY_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_P;

/* Block signals (default storage) */
extern B_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_B;

/* Block states (default storage) */
extern DW_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_BATTERY_MANAGEMENT_SYSTE_T BATTERY_MANAGEMENT_SYSTEM_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BATTERY_MANAGEMENT_SYSTE_T BATTERY_MANAGEMENT_SYSTEM_Y;

/* Model entry point functions */
extern void BATTERY_MANAGEMENT_SYSTEM_initialize(void);
extern void BATTERY_MANAGEMENT_SYSTEM_step(void);
extern void BATTERY_MANAGEMENT_SYSTEM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BATTERY_MANAGEMENT_S_T *const BATTERY_MANAGEMENT_SYSTEM_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS')    - opens subsystem MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS
 * hilite_system('MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MiniBMS'
 * '<S1>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS'
 * '<S2>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/BATTERY_FAULT_HANDLING - BFH'
 * '<S3>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/BATTERY_OPERATION_MODE - BM'
 * '<S4>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/BATTERY_PARAMETER_CALCULATION - BPC'
 * '<S5>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM'
 * '<S6>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM'
 * '<S7>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/BATTERY_OPERATION_MODE - BM/BMS OPERATION MODE'
 * '<S8>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State'
 * '<S9>'   : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State'
 * '<S10>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem'
 * '<S11>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem1'
 * '<S12>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem2'
 * '<S13>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem/Subsystem'
 * '<S14>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem/Subsystem/S-R Flip-Flop'
 * '<S15>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem/Subsystem/Saturation Dynamic'
 * '<S16>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem1/Subsystem'
 * '<S17>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem1/Subsystem/S-R Flip-Flop'
 * '<S18>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem1/Subsystem/Saturation Dynamic'
 * '<S19>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem2/Subsystem'
 * '<S20>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem2/Subsystem/S-R Flip-Flop'
 * '<S21>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Max_Cell_Voltage_Fault_State/Subsystem2/Subsystem/Saturation Dynamic'
 * '<S22>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem'
 * '<S23>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem1'
 * '<S24>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem2'
 * '<S25>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem/Subsystem'
 * '<S26>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem/Subsystem/S-R Flip-Flop'
 * '<S27>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem/Subsystem/Saturation Dynamic'
 * '<S28>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem1/Subsystem'
 * '<S29>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem1/Subsystem/S-R Flip-Flop'
 * '<S30>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem1/Subsystem/Saturation Dynamic'
 * '<S31>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem2/Subsystem'
 * '<S32>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem2/Subsystem/S-R Flip-Flop'
 * '<S33>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/CELL_VOLTAGE_MONITORING - CVM/Min_Cell_Voltage_Fault_State/Subsystem2/Subsystem/Saturation Dynamic'
 * '<S34>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State'
 * '<S35>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State'
 * '<S36>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem'
 * '<S37>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem1'
 * '<S38>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem2'
 * '<S39>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem/Subsystem'
 * '<S40>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem/Subsystem/S-R Flip-Flop'
 * '<S41>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem/Subsystem/Saturation Dynamic'
 * '<S42>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem1/Subsystem'
 * '<S43>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem1/Subsystem/S-R Flip-Flop'
 * '<S44>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem1/Subsystem/Saturation Dynamic'
 * '<S45>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem2/Subsystem'
 * '<S46>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem2/Subsystem/S-R Flip-Flop'
 * '<S47>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Max_Module_Temperature_Fault_State/Subsystem2/Subsystem/Saturation Dynamic'
 * '<S48>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem'
 * '<S49>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem1'
 * '<S50>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem2'
 * '<S51>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem/Subsystem'
 * '<S52>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem/Subsystem/S-R Flip-Flop'
 * '<S53>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem/Subsystem/Saturation Dynamic'
 * '<S54>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem1/Subsystem'
 * '<S55>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem1/Subsystem/S-R Flip-Flop'
 * '<S56>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem1/Subsystem/Saturation Dynamic'
 * '<S57>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem2/Subsystem'
 * '<S58>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem2/Subsystem/S-R Flip-Flop'
 * '<S59>'  : 'MiniBMS/BATTERY_MANAGEMENT_SYSTEM - BMS/MODULE_TEMPERATURE_MONITORING - MTM/Min_Module_Temperature_Fault_State/Subsystem2/Subsystem/Saturation Dynamic'
 */
#endif                                 /* BATTERY_MANAGEMENT_SYSTEM_h_ */
