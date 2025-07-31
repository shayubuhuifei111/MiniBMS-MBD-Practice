/*
 * BATTERY_MANAGEMENT_SYSTEM_data.c
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

#include "BATTERY_MANAGEMENT_SYSTEM.h"

/* Block parameters (default storage) */
P_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_P = {
  /* Variable: BM_TiCtctrCnct_P
   * Referenced by: '<S3>/Constant'
   */
  10.0F,

  /* Variable: BM_TiCtctrDCnct_P
   * Referenced by: '<S3>/Constant1'
   */
  10.0F,

  /* Variable: BPC_BattTotalCharge_P
   * Referenced by:
   *   '<S4>/BMS_TiProc_C2'
   *   '<S4>/Discrete-Time Integrator'
   */
  48.0F,

  /* Variable: BPC_BattTotalEnergy_P
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  607.68F,

  /* Variable: CVM_VCellMaxCutoffTh_P
   * Referenced by: '<S8>/Constant'
   */
  4.22F,

  /* Variable: CVM_VCellMaxDrtdTh_P
   * Referenced by: '<S8>/Constant1'
   */
  4.15F,

  /* Variable: CVM_VCellMaxWarnTh_P
   * Referenced by: '<S8>/Constant2'
   */
  4.1F,

  /* Variable: CVM_VCellMinCutoffTh_P
   * Referenced by: '<S9>/Constant'
   */
  3.26F,

  /* Variable: CVM_VCellMinDrtdTh_P
   * Referenced by: '<S9>/Constant1'
   */
  3.0F,

  /* Variable: CVM_VCellMinWarnTh_P
   * Referenced by: '<S9>/Constant2'
   */
  2.8F,

  /* Variable: MTM_TMdulMaxCutoffTh_P
   * Referenced by: '<S34>/Constant'
   */
  55.0F,

  /* Variable: MTM_TMdulMaxDrtdTh_P
   * Referenced by: '<S34>/Constant1'
   */
  52.5F,

  /* Variable: MTM_TMdulMaxWarnTh_P
   * Referenced by: '<S34>/Constant2'
   */
  50.0F,

  /* Variable: MTM_TMdulMinCutoffTh_P
   * Referenced by: '<S35>/Constant'
   */
  -20.0F,

  /* Variable: MTM_TMdulMinDrtdTh_P
   * Referenced by: '<S35>/Constant1'
   */
  0.0F,

  /* Variable: MTM_TMdulMinWarnTh_P
   * Referenced by: '<S35>/Constant2'
   */
  5.0F,

  /* Variable: CVM_DMaxVCellMaxCutoff_P
   * Referenced by: '<S10>/Constant2'
   */
  5,

  /* Variable: CVM_DMaxVCellMaxDrtd_P
   * Referenced by: '<S11>/Constant2'
   */
  5,

  /* Variable: CVM_DMaxVCellMaxWarn_P
   * Referenced by: '<S12>/Constant2'
   */
  5,

  /* Variable: CVM_DMaxVCellMinCutoff_P
   * Referenced by: '<S22>/Constant2'
   */
  5,

  /* Variable: CVM_DMaxVCellMinDrtd_P
   * Referenced by: '<S23>/Constant2'
   */
  5,

  /* Variable: CVM_DMaxVCellMinWarn_P
   * Referenced by: '<S24>/Constant2'
   */
  5,

  /* Variable: CVM_DMinVCellMaxCutoff_P
   * Referenced by: '<S10>/Constant3'
   */
  -5,

  /* Variable: CVM_DMinVCellMaxDrtd_P
   * Referenced by: '<S11>/Constant3'
   */
  -5,

  /* Variable: CVM_DMinVCellMaxWarn_P
   * Referenced by: '<S12>/Constant3'
   */
  -5,

  /* Variable: CVM_DMinVCellMinCutoff_P
   * Referenced by: '<S22>/Constant3'
   */
  -5,

  /* Variable: CVM_DMinVCellMinDrtd_P
   * Referenced by: '<S23>/Constant3'
   */
  -5,

  /* Variable: CVM_DMinVCellMinWarn_P
   * Referenced by: '<S24>/Constant3'
   */
  -5,

  /* Variable: MTM_DMaxTMdulMaxCutoff_P
   * Referenced by: '<S36>/Constant2'
   */
  5,

  /* Variable: MTM_DMaxTMdulMaxDrtd_P
   * Referenced by: '<S37>/Constant2'
   */
  5,

  /* Variable: MTM_DMaxTMdulMaxWarn_P
   * Referenced by: '<S38>/Constant2'
   */
  5,

  /* Variable: MTM_DMaxTMdulMinCutoff_P
   * Referenced by: '<S48>/Constant2'
   */
  5,

  /* Variable: MTM_DMaxTMdulMinDrtd_P
   * Referenced by: '<S49>/Constant2'
   */
  5,

  /* Variable: MTM_DMaxTMdulMinWarn_P
   * Referenced by: '<S50>/Constant2'
   */
  5,

  /* Variable: MTM_DMinTMdulMaxCutoff_P
   * Referenced by: '<S36>/Constant3'
   */
  -5,

  /* Variable: MTM_DMinTMdulMaxDrtd_P
   * Referenced by: '<S37>/Constant3'
   */
  -5,

  /* Variable: MTM_DMinTMdulMaxWarn_P
   * Referenced by: '<S38>/Constant3'
   */
  -5,

  /* Variable: MTM_DMinTMdulMinCutoff_P
   * Referenced by: '<S48>/Constant3'
   */
  -5,

  /* Variable: MTM_DMinTMdulMinDrtd_P
   * Referenced by: '<S49>/Constant3'
   */
  -5,

  /* Variable: MTM_DMinTMdulMinWarn_P
   * Referenced by: '<S50>/Constant3'
   */
  -5,

  /* Variable: BMS_EnaFltSts
   * Referenced by: '<S1>/BMS_FltEnaFlag'
   */
  { 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U },

  /* Variable: BMS_ModeEnaFltChk
   * Referenced by: '<S1>/BMS_FltEnaFlag'
   */
  { 0U, 100U, 110U, 111U, 115U, 120U, 130U, 140U, 200U, 211U, 220U, 230U, 255U },

  /* Variable: NrCutoff_C
   * Referenced by:
   *   '<S1>/Constant3'
   *   '<S8>/Constant3'
   *   '<S9>/Constant3'
   *   '<S34>/Constant3'
   *   '<S35>/Constant3'
   */
  3U,

  /* Variable: NrDrtd_C
   * Referenced by:
   *   '<S8>/Constant4'
   *   '<S9>/Constant4'
   *   '<S34>/Constant4'
   *   '<S35>/Constant4'
   */
  2U,

  /* Variable: NrNoFlt_C
   * Referenced by:
   *   '<S8>/Constant6'
   *   '<S9>/Constant6'
   *   '<S34>/Constant6'
   *   '<S35>/Constant6'
   */
  0U,

  /* Variable: NrTMdulSnsr_C
   * Referenced by: '<S6>/Constant'
   */
  3U,

  /* Variable: NrWarn_C
   * Referenced by:
   *   '<S8>/Constant5'
   *   '<S9>/Constant5'
   *   '<S34>/Constant5'
   *   '<S35>/Constant5'
   */
  1U,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S14>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_l
   * Referenced by: '<S17>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_c
   * Referenced by: '<S20>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_ln
   * Referenced by: '<S26>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_e
   * Referenced by: '<S29>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_i
   * Referenced by: '<S32>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_n
   * Referenced by: '<S52>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_j
   * Referenced by: '<S55>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_ig
   * Referenced by: '<S58>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_cb
   * Referenced by: '<S40>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_p
   * Referenced by: '<S43>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition_d
   * Referenced by: '<S46>/Memory'
   */
  false,

  /* Expression: 0
   * Referenced by: '<S13>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S28>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S51>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S54>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S57>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  -2.7777778086601757E-5,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S4>/Gain1'
   */
  -2.7777778086601757E-5,

  /* Expression: 48*0.985
   * Referenced by: '<S4>/Data Store Memory1'
   */
  47.28,

  /* Expression: 48*3*4.22*0.985
   * Referenced by: '<S4>/Data Store Memory2'
   */
  598.5648,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S22>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S25>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S24>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S51>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S49>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S54>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S50>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S57>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S39>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S37>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S38>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S45>/Constant'
   */
  1.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S4>/Gain2'
   */
  100.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S4>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S4>/Saturation'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S13>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_f
   * Referenced by: '<S16>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_b
   * Referenced by: '<S19>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_p
   * Referenced by: '<S25>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_a
   * Referenced by: '<S28>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_e
   * Referenced by: '<S31>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_m
   * Referenced by: '<S51>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_n
   * Referenced by: '<S54>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_ms
   * Referenced by: '<S57>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_k
   * Referenced by: '<S39>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S42>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay_InitialCondition_d
   * Referenced by: '<S45>/Unit Delay'
   */
  0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S14>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_g
   * Referenced by: '<S17>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_n
   * Referenced by: '<S20>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_m
   * Referenced by: '<S26>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_f
   * Referenced by: '<S29>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_a
   * Referenced by: '<S32>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_p
   * Referenced by: '<S52>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_h
   * Referenced by: '<S55>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_fz
   * Referenced by: '<S58>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_b
   * Referenced by: '<S40>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d
   * Referenced by: '<S43>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_px
   * Referenced by: '<S46>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: UnitDelay_InitialCondition_j
   * Referenced by: '<S1>/Unit Delay'
   */
  0U
};
