/*
 * BATTERY_MANAGEMENT_SYSTEM.c
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
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "BATTERY_MANAGEMENT_SYSTEM_private.h"

/* Named constants for Chart: '<S3>/BMS OPERATION MODE' */
#define BATTERY_MANAGEMENT_SYST_IN_IDLE ((uint8_T)10U)
#define BATTERY_MANAGEMENT_SYS_IN_FAULT ((uint8_T)9U)
#define BATTERY_MANAGEMENT__IN_CHARGING ((uint8_T)1U)
#define BATTERY_MANAGEME_IN_DISCHARGING ((uint8_T)3U)
#define BATTERY_MANA_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define BATTE_IN_CONTACTOR_CONNECT_FAIL ((uint8_T)3U)
#define BATT_IN_CONTACTOR_CONNECT_CHECK ((uint8_T)1U)
#define BA_IN_CONTACTOR_CONNECT_COMMAND ((uint8_T)2U)
#define BA_IN_CONTACTOR_CONNECT_SUCCESS ((uint8_T)2U)
#define BA_IN_CONTACTOR_DISCONNECT_FAIL ((uint8_T)7U)
#define B_IN_CONTACTOR_CONNECT_SEQUENCE ((uint8_T)4U)
#define B_IN_CONTACTOR_DICCONNECT_CHECK ((uint8_T)5U)
#define IN_CONTACTOR_DISCONNECT_COMMAND ((uint8_T)6U)
#define IN_CONTACTOR_DISCONNECT_SUCCESS ((uint8_T)8U)

/* Block signals (default storage) */
B_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_B;

/* Block states (default storage) */
DW_BATTERY_MANAGEMENT_SYSTEM_T BATTERY_MANAGEMENT_SYSTEM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_BATTERY_MANAGEMENT_SYSTE_T BATTERY_MANAGEMENT_SYSTEM_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BATTERY_MANAGEMENT_SYSTE_T BATTERY_MANAGEMENT_SYSTEM_Y;

/* Real-time model */
static RT_MODEL_BATTERY_MANAGEMENT_S_T BATTERY_MANAGEMENT_SYSTEM_M_;
RT_MODEL_BATTERY_MANAGEMENT_S_T *const BATTERY_MANAGEMENT_SYSTEM_M =
  &BATTERY_MANAGEMENT_SYSTEM_M_;
uint32_T plook_u32u8_binckan(uint8_T u, const uint8_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32u8(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && ((uint8_T)((uint32_T)bp[bpIndex + 1U] - u) <=
         (uint8_T)((uint32_T)u - bp[bpIndex]))) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32u8(uint8_T u, const uint8_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/* Model step function */
void BATTERY_MANAGEMENT_SYSTEM_step(void)
{
  real_T rtb_Switch1_e;
  real_T tmp;
  real32_T maxV;
  real32_T rtb_Saturation;
  int16_T rtb_Switch2;
  int16_T rtb_Switch2_c;
  int16_T rtb_Switch2_e;
  int16_T rtb_Switch2_h;
  int16_T rtb_Switch2_iz;
  int16_T rtb_Switch2_k1;
  int16_T rtb_Switch2_kz;
  int16_T rtb_Switch2_l;
  int16_T rtb_Switch2_lg;
  int16_T rtb_Switch2_mf;
  int16_T rtb_Switch2_mw;
  int16_T rtb_Switch2_p;
  uint8_T rtb_BMS_FltEnaFlag;
  uint8_T rtb_Max;
  uint8_T rtb_MultiportSwitch;
  uint8_T rtb_MultiportSwitch_g;
  boolean_T rtb_Logic_a_idx_0;
  boolean_T rtb_Logic_b_idx_0;
  boolean_T rtb_Logic_f_idx_0;
  boolean_T rtb_Logic_g4_idx_0;
  boolean_T rtb_Logic_g_idx_0;
  boolean_T rtb_Logic_h_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_j_idx_0;
  boolean_T rtb_Logic_jp_idx_0;
  boolean_T rtb_Logic_k_idx_0;
  boolean_T rtb_Logic_o_idx_0;
  boolean_T rtb_Logic_ox_idx_0;
  boolean_T rtb_OR;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
   *  DataStoreRead: '<S4>/Data Store Read1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattWHr;
    if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE >
        BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalEnergy_P) {
      BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE =
        BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalEnergy_P;
    } else if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE <
               BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator1_LowerSa) {
      BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE =
        BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   */
  BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattWHr =
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  DataStoreRead: '<S4>/Data Store Read2'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattAmpHr;
    if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE >
        BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalCharge_P) {
      BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE =
        BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalCharge_P;
    } else if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE <
               BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator_LowerSat) {
      BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE =
        BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* DataStoreWrite: '<S4>/Data Store Write2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattAmpHr =
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<S4>/Gain2' incorporates:
   *  Constant: '<S4>/BMS_TiProc_C2'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Product: '<S4>/Divide'
   */
  rtb_Saturation = (real32_T)
    (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE /
     BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalCharge_P) *
    BATTERY_MANAGEMENT_SYSTEM_P.Gain2_Gain;

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Saturation > BATTERY_MANAGEMENT_SYSTEM_P.Saturation_UpperSat) {
    rtb_Saturation = BATTERY_MANAGEMENT_SYSTEM_P.Saturation_UpperSat;
  } else if (rtb_Saturation < BATTERY_MANAGEMENT_SYSTEM_P.Saturation_LowerSat) {
    rtb_Saturation = BATTERY_MANAGEMENT_SYSTEM_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* MinMax: '<S5>/Min1' incorporates:
   *  Inport: '<Root>/Obsr_VCell'
   */
  maxV = fmaxf(fmaxf(BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[0],
                     BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[1]),
               BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[2]);

  /* Lookup_n-D: '<S1>/BMS_FltEnaFlag' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_BMS_FltEnaFlag =
    BATTERY_MANAGEMENT_SYSTEM_P.BMS_EnaFltSts[plook_u32u8_binckan
    (BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_d,
     BATTERY_MANAGEMENT_SYSTEM_P.BMS_ModeEnaFltChk, 12U)];

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S13>/Constant1'
   *  Switch: '<S13>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant'
       *  Constant: '<S8>/Constant'
       *  MinMax: '<S5>/Min1'
       *  RelationalOperator: '<S8>/Relational Operator'
       *  Sum: '<S13>/Sum'
       *  Sum: '<S13>/Sum1'
       *  Switch: '<S13>/Switch1'
       *  UnitDelay: '<S13>/Unit Delay'
       */
      if (maxV > BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMaxCutoffTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_i;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_i;
      }

      /* End of Switch: '<S13>/Switch' */
    } else {
      /* Switch: '<S13>/Switch1' incorporates:
       *  UnitDelay: '<S13>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  RelationalOperator: '<S15>/LowerRelop1'
   *  RelationalOperator: '<S15>/UpperRelop'
   *  Switch: '<S15>/Switch'
   */
  if (rtb_Switch2 > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxCutoff_P) {
    rtb_Switch2 = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxCutoff_P;
  } else if (rtb_Switch2 < BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxCutoff_P)
  {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    rtb_Switch2 = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxCutoff_P;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* CombinatorialLogic: '<S14>/Logic' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Logic: '<S13>/OR'
   *  Memory: '<S14>/Memory'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   */
  rtb_Logic_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxCutoff_P <= rtb_Switch2) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value != 0.0) ||
                 (rtb_Switch2 <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxCutoff_P))) << 1)
    + BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput];

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S16>/Constant1'
   *  Switch: '<S16>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_p != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_e);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_mw = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S8>/Constant1'
       *  MinMax: '<S5>/Min1'
       *  RelationalOperator: '<S8>/Relational Operator1'
       *  Sum: '<S16>/Sum'
       *  Sum: '<S16>/Sum1'
       *  Switch: '<S16>/Switch1'
       *  UnitDelay: '<S16>/Unit Delay'
       */
      if (maxV > BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMaxDrtdTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_k +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_k;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_k -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_k;
      }

      /* End of Switch: '<S16>/Switch' */
    } else {
      /* Switch: '<S16>/Switch1' incorporates:
       *  UnitDelay: '<S16>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_k;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_mw = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (rtb_Switch2_mw > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxDrtd_P) {
    rtb_Switch2_mw = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxDrtd_P;
  } else if (rtb_Switch2_mw < BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxDrtd_P)
  {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S11>/Constant3'
     */
    rtb_Switch2_mw = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxDrtd_P;
  }

  /* End of Switch: '<S18>/Switch2' */

  /* CombinatorialLogic: '<S17>/Logic' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Logic: '<S16>/OR'
   *  Memory: '<S17>/Memory'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  rtb_Logic_k_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_g[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxDrtd_P <= rtb_Switch2_mw) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_p != 0.0) ||
                 (rtb_Switch2_mw <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxDrtd_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_m];

  /* Switch: '<S19>/Switch2' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S19>/Constant1'
   *  Switch: '<S19>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_nt != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_h = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S19>/Constant'
       *  Constant: '<S8>/Constant2'
       *  MinMax: '<S5>/Min1'
       *  RelationalOperator: '<S8>/Relational Operator2'
       *  Sum: '<S19>/Sum'
       *  Sum: '<S19>/Sum1'
       *  Switch: '<S19>/Switch1'
       *  UnitDelay: '<S19>/Unit Delay'
       */
      if (maxV > BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMaxWarnTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_kw +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_a;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_kw -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_a;
      }

      /* End of Switch: '<S19>/Switch' */
    } else {
      /* Switch: '<S19>/Switch1' incorporates:
       *  UnitDelay: '<S19>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_kw;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_h = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S19>/Switch2' */

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S12>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtb_Switch2_h > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxWarn_P) {
    rtb_Switch2_h = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxWarn_P;
  } else if (rtb_Switch2_h < BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxWarn_P)
  {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S12>/Constant3'
     */
    rtb_Switch2_h = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxWarn_P;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* CombinatorialLogic: '<S20>/Logic' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S12>/Constant3'
   *  Logic: '<S19>/OR'
   *  Memory: '<S20>/Memory'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  RelationalOperator: '<S19>/Relational Operator1'
   */
  rtb_Logic_b_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_n[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMaxWarn_P <= rtb_Switch2_h) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_nt != 0.0) ||
                 (rtb_Switch2_h <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMaxWarn_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_h];

  /* MinMax: '<S5>/Min' incorporates:
   *  Inport: '<Root>/Obsr_VCell'
   */
  maxV = fminf(fminf(BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[0],
                     BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[1]),
               BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VCell[2]);

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S25>/Constant1'
   *  Switch: '<S25>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_pz != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_f);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_e = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S25>/Switch' incorporates:
       *  Constant: '<S25>/Constant'
       *  Constant: '<S9>/Constant'
       *  MinMax: '<S5>/Min'
       *  RelationalOperator: '<S9>/Relational Operator'
       *  Sum: '<S25>/Sum'
       *  Sum: '<S25>/Sum1'
       *  Switch: '<S25>/Switch1'
       *  UnitDelay: '<S25>/Unit Delay'
       */
      if (maxV < BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMinCutoffTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_j;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_j;
      }

      /* End of Switch: '<S25>/Switch' */
    } else {
      /* Switch: '<S25>/Switch1' incorporates:
       *  UnitDelay: '<S25>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_e = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   *  RelationalOperator: '<S27>/LowerRelop1'
   *  RelationalOperator: '<S27>/UpperRelop'
   *  Switch: '<S27>/Switch'
   */
  if (rtb_Switch2_e > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinCutoff_P) {
    rtb_Switch2_e = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinCutoff_P;
  } else if (rtb_Switch2_e <
             BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinCutoff_P) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S22>/Constant3'
     */
    rtb_Switch2_e = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinCutoff_P;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* CombinatorialLogic: '<S26>/Logic' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   *  Logic: '<S25>/OR'
   *  Memory: '<S26>/Memory'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  RelationalOperator: '<S25>/Relational Operator1'
   */
  rtb_Logic_o_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_m[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinCutoff_P <= rtb_Switch2_e) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_pz != 0.0) ||
                 (rtb_Switch2_e <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinCutoff_P))) << 1)
    + BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_a];

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S28>/Constant1'
   *  Switch: '<S28>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_k != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_g);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_l = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S28>/Switch' incorporates:
       *  Constant: '<S28>/Constant'
       *  Constant: '<S9>/Constant1'
       *  MinMax: '<S5>/Min'
       *  RelationalOperator: '<S9>/Relational Operator1'
       *  Sum: '<S28>/Sum'
       *  Sum: '<S28>/Sum1'
       *  Switch: '<S28>/Switch1'
       *  UnitDelay: '<S28>/Unit Delay'
       */
      if (maxV < BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMinDrtdTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_b +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_g;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_b -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_g;
      }

      /* End of Switch: '<S28>/Switch' */
    } else {
      /* Switch: '<S28>/Switch1' incorporates:
       *  UnitDelay: '<S28>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_b;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_l = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  RelationalOperator: '<S30>/LowerRelop1'
   *  RelationalOperator: '<S30>/UpperRelop'
   *  Switch: '<S30>/Switch'
   */
  if (rtb_Switch2_l > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinDrtd_P) {
    rtb_Switch2_l = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinDrtd_P;
  } else if (rtb_Switch2_l < BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinDrtd_P)
  {
    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     */
    rtb_Switch2_l = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinDrtd_P;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* CombinatorialLogic: '<S29>/Logic' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Logic: '<S28>/OR'
   *  Memory: '<S29>/Memory'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   */
  rtb_Logic_g_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_f[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinDrtd_P <= rtb_Switch2_l) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_k != 0.0) ||
                 (rtb_Switch2_l <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinDrtd_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_l];

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S31>/Constant1'
   *  Switch: '<S31>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_na != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_o);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_iz = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S31>/Constant'
       *  Constant: '<S9>/Constant2'
       *  MinMax: '<S5>/Min'
       *  RelationalOperator: '<S9>/Relational Operator2'
       *  Sum: '<S31>/Sum'
       *  Sum: '<S31>/Sum1'
       *  Switch: '<S31>/Switch1'
       *  UnitDelay: '<S31>/Unit Delay'
       */
      if (maxV < BATTERY_MANAGEMENT_SYSTEM_P.CVM_VCellMinWarnTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_o +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_o;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_o -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_o;
      }

      /* End of Switch: '<S31>/Switch' */
    } else {
      /* Switch: '<S31>/Switch1' incorporates:
       *  UnitDelay: '<S31>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_o;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_iz = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Constant: '<S24>/Constant3'
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  RelationalOperator: '<S33>/UpperRelop'
   *  Switch: '<S33>/Switch'
   */
  if (rtb_Switch2_iz > BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinWarn_P) {
    rtb_Switch2_iz = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinWarn_P;
  } else if (rtb_Switch2_iz < BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinWarn_P)
  {
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S24>/Constant3'
     */
    rtb_Switch2_iz = BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinWarn_P;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* CombinatorialLogic: '<S32>/Logic' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/Constant2'
   *  Constant: '<S24>/Constant3'
   *  Logic: '<S31>/OR'
   *  Memory: '<S32>/Memory'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S31>/Relational Operator1'
   */
  rtb_Logic_g4_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_a[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMaxVCellMinWarn_P <= rtb_Switch2_iz) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_na != 0.0) ||
                 (rtb_Switch2_iz <=
                  BATTERY_MANAGEMENT_SYSTEM_P.CVM_DMinVCellMinWarn_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_c];

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  if (!rtb_Logic_o_idx_0) {
    /* MultiPortSwitch: '<S9>/Multiport Switch1' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    if (!rtb_Logic_g_idx_0) {
      /* MultiPortSwitch: '<S9>/Multiport Switch2' incorporates:
       *  Constant: '<S9>/Constant5'
       *  Constant: '<S9>/Constant6'
       */
      if (!rtb_Logic_g4_idx_0) {
        rtb_MultiportSwitch = BATTERY_MANAGEMENT_SYSTEM_P.NrNoFlt_C;
      } else {
        rtb_MultiportSwitch = BATTERY_MANAGEMENT_SYSTEM_P.NrWarn_C;
      }

      /* End of MultiPortSwitch: '<S9>/Multiport Switch2' */
    } else {
      rtb_MultiportSwitch = BATTERY_MANAGEMENT_SYSTEM_P.NrDrtd_C;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch1' */
  } else {
    rtb_MultiportSwitch = BATTERY_MANAGEMENT_SYSTEM_P.NrCutoff_C;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* MinMax: '<S6>/Min' incorporates:
   *  Inport: '<Root>/Obsr_TMdul'
   */
  rtb_Switch1_e = fmin(fmin(BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[0],
    BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[1]),
                       BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[2]);

  /* Switch: '<S51>/Switch2' incorporates:
   *  Constant: '<S48>/Constant1'
   *  Constant: '<S51>/Constant1'
   *  Switch: '<S51>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_d != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_ot);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_p = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S51>/Switch' incorporates:
       *  Constant: '<S35>/Constant'
       *  Constant: '<S51>/Constant'
       *  MinMax: '<S6>/Min'
       *  RelationalOperator: '<S35>/Relational Operator'
       *  Sum: '<S51>/Sum'
       *  Sum: '<S51>/Sum1'
       *  Switch: '<S51>/Switch1'
       *  UnitDelay: '<S51>/Unit Delay'
       */
      if (rtb_Switch1_e < BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMinCutoffTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_or +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_iq;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_or -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_iq;
      }

      /* End of Switch: '<S51>/Switch' */
    } else {
      /* Switch: '<S51>/Switch1' incorporates:
       *  UnitDelay: '<S51>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_or;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_p = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  Constant: '<S48>/Constant2'
   *  Constant: '<S48>/Constant3'
   *  RelationalOperator: '<S53>/LowerRelop1'
   *  RelationalOperator: '<S53>/UpperRelop'
   *  Switch: '<S53>/Switch'
   */
  if (rtb_Switch2_p > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinCutoff_P) {
    rtb_Switch2_p = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinCutoff_P;
  } else if (rtb_Switch2_p <
             BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinCutoff_P) {
    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S48>/Constant3'
     */
    rtb_Switch2_p = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinCutoff_P;
  }

  /* End of Switch: '<S53>/Switch2' */

  /* CombinatorialLogic: '<S52>/Logic' incorporates:
   *  Constant: '<S48>/Constant1'
   *  Constant: '<S48>/Constant2'
   *  Constant: '<S48>/Constant3'
   *  Logic: '<S51>/OR'
   *  Memory: '<S52>/Memory'
   *  RelationalOperator: '<S51>/Relational Operator'
   *  RelationalOperator: '<S51>/Relational Operator1'
   */
  rtb_Logic_ox_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_p[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinCutoff_P <= rtb_Switch2_p) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_d != 0.0) ||
                 (rtb_Switch2_p <=
                  BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinCutoff_P))) << 1)
    + BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_j];

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S49>/Constant1'
   *  Constant: '<S54>/Constant1'
   *  Switch: '<S54>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_ke != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_j);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_mf = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S54>/Switch' incorporates:
       *  Constant: '<S35>/Constant1'
       *  Constant: '<S54>/Constant'
       *  MinMax: '<S6>/Min'
       *  RelationalOperator: '<S35>/Relational Operator1'
       *  Sum: '<S54>/Sum'
       *  Sum: '<S54>/Sum1'
       *  Switch: '<S54>/Switch1'
       *  UnitDelay: '<S54>/Unit Delay'
       */
      if (rtb_Switch1_e < BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMinDrtdTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e0 +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_is;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e0 -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_is;
      }

      /* End of Switch: '<S54>/Switch' */
    } else {
      /* Switch: '<S54>/Switch1' incorporates:
       *  UnitDelay: '<S54>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e0;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_mf = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Switch: '<S56>/Switch2' incorporates:
   *  Constant: '<S49>/Constant2'
   *  Constant: '<S49>/Constant3'
   *  RelationalOperator: '<S56>/LowerRelop1'
   *  RelationalOperator: '<S56>/UpperRelop'
   *  Switch: '<S56>/Switch'
   */
  if (rtb_Switch2_mf > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinDrtd_P) {
    rtb_Switch2_mf = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinDrtd_P;
  } else if (rtb_Switch2_mf < BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinDrtd_P)
  {
    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S49>/Constant3'
     */
    rtb_Switch2_mf = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinDrtd_P;
  }

  /* End of Switch: '<S56>/Switch2' */

  /* CombinatorialLogic: '<S55>/Logic' incorporates:
   *  Constant: '<S49>/Constant1'
   *  Constant: '<S49>/Constant2'
   *  Constant: '<S49>/Constant3'
   *  Logic: '<S54>/OR'
   *  Memory: '<S55>/Memory'
   *  RelationalOperator: '<S54>/Relational Operator'
   *  RelationalOperator: '<S54>/Relational Operator1'
   */
  rtb_Logic_j_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_h[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinDrtd_P <= rtb_Switch2_mf) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_ke != 0.0) ||
                 (rtb_Switch2_mf <=
                  BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinDrtd_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hv];

  /* Switch: '<S57>/Switch2' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S57>/Constant1'
   *  Switch: '<S57>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_h != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_n);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_lg = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S35>/Constant2'
       *  Constant: '<S57>/Constant'
       *  MinMax: '<S6>/Min'
       *  RelationalOperator: '<S35>/Relational Operator2'
       *  Sum: '<S57>/Sum'
       *  Sum: '<S57>/Sum1'
       *  Switch: '<S57>/Switch1'
       *  UnitDelay: '<S57>/Unit Delay'
       */
      if (rtb_Switch1_e < BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMinWarnTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_p +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_l;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_p -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_l;
      }

      /* End of Switch: '<S57>/Switch' */
    } else {
      /* Switch: '<S57>/Switch1' incorporates:
       *  UnitDelay: '<S57>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_p;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_lg = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S57>/Switch2' */

  /* Switch: '<S59>/Switch2' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Constant: '<S50>/Constant3'
   *  RelationalOperator: '<S59>/LowerRelop1'
   *  RelationalOperator: '<S59>/UpperRelop'
   *  Switch: '<S59>/Switch'
   */
  if (rtb_Switch2_lg > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinWarn_P) {
    rtb_Switch2_lg = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinWarn_P;
  } else if (rtb_Switch2_lg < BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinWarn_P)
  {
    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S50>/Constant3'
     */
    rtb_Switch2_lg = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinWarn_P;
  }

  /* End of Switch: '<S59>/Switch2' */

  /* CombinatorialLogic: '<S58>/Logic' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S50>/Constant2'
   *  Constant: '<S50>/Constant3'
   *  Logic: '<S57>/OR'
   *  Memory: '<S58>/Memory'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  RelationalOperator: '<S57>/Relational Operator1'
   */
  rtb_Logic_h_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_fz[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMinWarn_P <= rtb_Switch2_lg) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_h != 0.0) ||
                 (rtb_Switch2_lg <=
                  BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMinWarn_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_f];

  /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
   *  Constant: '<S35>/Constant3'
   */
  if (!rtb_Logic_ox_idx_0) {
    /* MultiPortSwitch: '<S35>/Multiport Switch1' incorporates:
     *  Constant: '<S35>/Constant4'
     */
    if (!rtb_Logic_j_idx_0) {
      /* MultiPortSwitch: '<S35>/Multiport Switch2' incorporates:
       *  Constant: '<S35>/Constant5'
       *  Constant: '<S35>/Constant6'
       */
      if (!rtb_Logic_h_idx_0) {
        rtb_MultiportSwitch_g = BATTERY_MANAGEMENT_SYSTEM_P.NrNoFlt_C;
      } else {
        rtb_MultiportSwitch_g = BATTERY_MANAGEMENT_SYSTEM_P.NrWarn_C;
      }

      /* End of MultiPortSwitch: '<S35>/Multiport Switch2' */
    } else {
      rtb_MultiportSwitch_g = BATTERY_MANAGEMENT_SYSTEM_P.NrDrtd_C;
    }

    /* End of MultiPortSwitch: '<S35>/Multiport Switch1' */
  } else {
    rtb_MultiportSwitch_g = BATTERY_MANAGEMENT_SYSTEM_P.NrCutoff_C;
  }

  /* End of MultiPortSwitch: '<S35>/Multiport Switch' */

  /* MinMax: '<S6>/Min1' incorporates:
   *  Inport: '<Root>/Obsr_TMdul'
   */
  rtb_Switch1_e = fmax(fmax(BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[0],
    BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[1]),
                       BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[2]);

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S39>/Constant1'
   *  Switch: '<S39>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_bn != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_m);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_kz = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S39>/Switch' incorporates:
       *  Constant: '<S34>/Constant'
       *  Constant: '<S39>/Constant'
       *  MinMax: '<S6>/Min1'
       *  RelationalOperator: '<S34>/Relational Operator'
       *  Sum: '<S39>/Sum'
       *  Sum: '<S39>/Sum1'
       *  Switch: '<S39>/Switch1'
       *  UnitDelay: '<S39>/Unit Delay'
       */
      if (rtb_Switch1_e > BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMaxCutoffTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_on +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_c;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_on -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_c;
      }

      /* End of Switch: '<S39>/Switch' */
    } else {
      /* Switch: '<S39>/Switch1' incorporates:
       *  UnitDelay: '<S39>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_on;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_kz = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant3'
   *  RelationalOperator: '<S41>/LowerRelop1'
   *  RelationalOperator: '<S41>/UpperRelop'
   *  Switch: '<S41>/Switch'
   */
  if (rtb_Switch2_kz > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxCutoff_P) {
    rtb_Switch2_kz = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxCutoff_P;
  } else if (rtb_Switch2_kz <
             BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxCutoff_P) {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S36>/Constant3'
     */
    rtb_Switch2_kz = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxCutoff_P;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* CombinatorialLogic: '<S40>/Logic' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant3'
   *  Logic: '<S39>/OR'
   *  Memory: '<S40>/Memory'
   *  RelationalOperator: '<S39>/Relational Operator'
   *  RelationalOperator: '<S39>/Relational Operator1'
   */
  rtb_Logic_f_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_b[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxCutoff_P <= rtb_Switch2_kz) <<
    1) + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_bn != 0.0) ||
                    (rtb_Switch2_kz <=
                     BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxCutoff_P))) <<
    1) + BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_p];

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S42>/Constant1'
   *  Switch: '<S42>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_kp != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_b);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_k1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S42>/Switch' incorporates:
       *  Constant: '<S34>/Constant1'
       *  Constant: '<S42>/Constant'
       *  MinMax: '<S6>/Min1'
       *  RelationalOperator: '<S34>/Relational Operator1'
       *  Sum: '<S42>/Sum'
       *  Sum: '<S42>/Sum1'
       *  Switch: '<S42>/Switch1'
       *  UnitDelay: '<S42>/Unit Delay'
       */
      if (rtb_Switch1_e > BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMaxDrtdTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_c +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_g2;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_c -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_g2;
      }

      /* End of Switch: '<S42>/Switch' */
    } else {
      /* Switch: '<S42>/Switch1' incorporates:
       *  UnitDelay: '<S42>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_c;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_k1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Switch: '<S44>/Switch2' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Constant: '<S37>/Constant3'
   *  RelationalOperator: '<S44>/LowerRelop1'
   *  RelationalOperator: '<S44>/UpperRelop'
   *  Switch: '<S44>/Switch'
   */
  if (rtb_Switch2_k1 > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxDrtd_P) {
    rtb_Switch2_k1 = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxDrtd_P;
  } else if (rtb_Switch2_k1 < BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxDrtd_P)
  {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S37>/Constant3'
     */
    rtb_Switch2_k1 = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxDrtd_P;
  }

  /* End of Switch: '<S44>/Switch2' */

  /* CombinatorialLogic: '<S43>/Logic' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S37>/Constant2'
   *  Constant: '<S37>/Constant3'
   *  Logic: '<S42>/OR'
   *  Memory: '<S43>/Memory'
   *  RelationalOperator: '<S42>/Relational Operator'
   *  RelationalOperator: '<S42>/Relational Operator1'
   */
  rtb_Logic_a_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_d[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxDrtd_P <= rtb_Switch2_k1) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_kp != 0.0) ||
                 (rtb_Switch2_k1 <=
                  BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxDrtd_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hg];

  /* Switch: '<S45>/Switch2' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S45>/Constant1'
   *  Switch: '<S45>/Switch1'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_lu != 0.0) {
    tmp = floor(BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_ex);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_c = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    if (rtb_BMS_FltEnaFlag != 0) {
      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S34>/Constant2'
       *  Constant: '<S45>/Constant'
       *  MinMax: '<S6>/Min1'
       *  RelationalOperator: '<S34>/Relational Operator2'
       *  Sum: '<S45>/Sum'
       *  Sum: '<S45>/Sum1'
       *  Switch: '<S45>/Switch1'
       *  UnitDelay: '<S45>/Unit Delay'
       */
      if (rtb_Switch1_e > BATTERY_MANAGEMENT_SYSTEM_P.MTM_TMdulMaxWarnTh_P) {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_os +
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_n;
      } else {
        tmp = (real_T)BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_os -
          BATTERY_MANAGEMENT_SYSTEM_P.Constant_Value_n;
      }

      /* End of Switch: '<S45>/Switch' */
    } else {
      /* Switch: '<S45>/Switch1' incorporates:
       *  UnitDelay: '<S45>/Unit Delay'
       */
      tmp = BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_os;
    }

    tmp = floor(tmp);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_Switch2_c = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
      -tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S45>/Switch2' */

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  RelationalOperator: '<S47>/LowerRelop1'
   *  RelationalOperator: '<S47>/UpperRelop'
   *  Switch: '<S47>/Switch'
   */
  if (rtb_Switch2_c > BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxWarn_P) {
    rtb_Switch2_c = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxWarn_P;
  } else if (rtb_Switch2_c < BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxWarn_P)
  {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S38>/Constant3'
     */
    rtb_Switch2_c = BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxWarn_P;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* CombinatorialLogic: '<S46>/Logic' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  Logic: '<S45>/OR'
   *  Memory: '<S46>/Memory'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   */
  rtb_Logic_jp_idx_0 = BATTERY_MANAGEMENT_SYSTEM_P.Logic_table_px[((((uint32_T)
    (BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMaxTMdulMaxWarn_P <= rtb_Switch2_c) << 1)
    + (uint32_T)((BATTERY_MANAGEMENT_SYSTEM_P.Constant1_Value_lu != 0.0) ||
                 (rtb_Switch2_c <=
                  BATTERY_MANAGEMENT_SYSTEM_P.MTM_DMinTMdulMaxWarn_P))) << 1) +
    BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_fv];

  /* MultiPortSwitch: '<S34>/Multiport Switch' incorporates:
   *  Constant: '<S34>/Constant3'
   */
  if (!rtb_Logic_f_idx_0) {
    /* MultiPortSwitch: '<S34>/Multiport Switch1' incorporates:
     *  Constant: '<S34>/Constant4'
     */
    if (!rtb_Logic_a_idx_0) {
      /* MultiPortSwitch: '<S34>/Multiport Switch2' incorporates:
       *  Constant: '<S34>/Constant5'
       *  Constant: '<S34>/Constant6'
       */
      if (!rtb_Logic_jp_idx_0) {
        rtb_BMS_FltEnaFlag = BATTERY_MANAGEMENT_SYSTEM_P.NrNoFlt_C;
      } else {
        rtb_BMS_FltEnaFlag = BATTERY_MANAGEMENT_SYSTEM_P.NrWarn_C;
      }

      /* End of MultiPortSwitch: '<S34>/Multiport Switch2' */
    } else {
      rtb_BMS_FltEnaFlag = BATTERY_MANAGEMENT_SYSTEM_P.NrDrtd_C;
    }

    /* End of MultiPortSwitch: '<S34>/Multiport Switch1' */
  } else {
    rtb_BMS_FltEnaFlag = BATTERY_MANAGEMENT_SYSTEM_P.NrCutoff_C;
  }

  /* End of MultiPortSwitch: '<S34>/Multiport Switch' */

  /* MultiPortSwitch: '<S8>/Multiport Switch' */
  if (!rtb_Logic_idx_0) {
    /* MultiPortSwitch: '<S8>/Multiport Switch1' */
    if (!rtb_Logic_k_idx_0) {
      /* MultiPortSwitch: '<S8>/Multiport Switch2' */
      if (!rtb_Logic_b_idx_0) {
        /* MinMax: '<S2>/Max' incorporates:
         *  Constant: '<S8>/Constant6'
         */
        rtb_Max = BATTERY_MANAGEMENT_SYSTEM_P.NrNoFlt_C;
      } else {
        /* MinMax: '<S2>/Max' incorporates:
         *  Constant: '<S8>/Constant5'
         */
        rtb_Max = BATTERY_MANAGEMENT_SYSTEM_P.NrWarn_C;
      }

      /* End of MultiPortSwitch: '<S8>/Multiport Switch2' */
    } else {
      /* MinMax: '<S2>/Max' incorporates:
       *  Constant: '<S8>/Constant4'
       */
      rtb_Max = BATTERY_MANAGEMENT_SYSTEM_P.NrDrtd_C;
    }

    /* End of MultiPortSwitch: '<S8>/Multiport Switch1' */
  } else {
    /* MinMax: '<S2>/Max' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    rtb_Max = BATTERY_MANAGEMENT_SYSTEM_P.NrCutoff_C;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* MinMax: '<S2>/Max' incorporates:
   *  DataTypeConversion: '<S2>/Cast'
   *  Delay: '<S2>/Delay'
   */
  if (rtb_Max < rtb_MultiportSwitch) {
    rtb_Max = rtb_MultiportSwitch;
  }

  if (rtb_Max < rtb_MultiportSwitch_g) {
    rtb_Max = rtb_MultiportSwitch_g;
  }

  if (rtb_Max < rtb_BMS_FltEnaFlag) {
    rtb_Max = rtb_BMS_FltEnaFlag;
  }

  if (rtb_Max < (int32_T)BATTERY_MANAGEMENT_SYSTEM_B.BM_CtctrFlt) {
    rtb_Max = 1U;
  }

  /* RelationalOperator: '<S1>/Relational Operator' incorporates:
   *  Constant: '<S1>/Constant3'
   *  MinMax: '<S2>/Max'
   */
  rtb_OR = (rtb_Max == BATTERY_MANAGEMENT_SYSTEM_P.NrCutoff_C);

  /* Chart: '<S3>/BMS OPERATION MODE' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/Obsr_StsChPlg'
   *  Inport: '<Root>/Obsr_StsIgnOn'
   *  Inport: '<Root>/Obsr_VBatPack'
   *  Inport: '<Root>/Obsr_VBus'
   */
  if (BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 < MAX_uint32_T) {
    BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1++;
  }

  if (BATTERY_MANAGEMENT_SYSTEM_DW.is_active_c3_BATTERY_MANAGEMENT == 0) {
    BATTERY_MANAGEMENT_SYSTEM_DW.is_active_c3_BATTERY_MANAGEMENT = 1U;
    BATTERY_MANAGEMENT_SYSTEM_B.BM_CtctrFlt = false;

    /* Outport: '<Root>/BM_StsCtctrCnct' */
    BATTERY_MANAGEMENT_SYSTEM_Y.BM_StsCtctrCnct = false;
    BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
      BATTERY_MANAGEMENT_SYST_IN_IDLE;
    rtb_MultiportSwitch = 100U;

    /* Outport: '<Root>/BM_CtctrCnctCmd' */
    BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
  } else {
    switch (BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM) {
     case BATT_IN_CONTACTOR_CONNECT_CHECK:
      rtb_MultiportSwitch = 111U;
      if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBus < 0.98 *
          BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBatPack) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BATTE_IN_CONTACTOR_CONNECT_FAIL;
        rtb_MultiportSwitch = 115U;
        BATTERY_MANAGEMENT_SYSTEM_B.BM_CtctrFlt = true;
      } else if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBus >= 0.95 *
                 BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBatPack) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          B_IN_CONTACTOR_CONNECT_SEQUENCE;
        BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
          BA_IN_CONTACTOR_CONNECT_SUCCESS;
        rtb_MultiportSwitch = 120U;

        /* Outport: '<Root>/BM_StsCtctrCnct' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_StsCtctrCnct = true;
      }
      break;

     case BA_IN_CONTACTOR_CONNECT_COMMAND:
      rtb_MultiportSwitch = 110U;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = true;
      if (BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 >= (uint32_T)
          BATTERY_MANAGEMENT_SYSTEM_P.BM_TiCtctrCnct_P) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BATT_IN_CONTACTOR_CONNECT_CHECK;
        rtb_MultiportSwitch = 111U;
      }
      break;

     case BATTE_IN_CONTACTOR_CONNECT_FAIL:
      BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
        BATTERY_MANAGEMENT_SYS_IN_FAULT;
      rtb_MultiportSwitch = MAX_uint8_T;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      break;

     case B_IN_CONTACTOR_CONNECT_SEQUENCE:
      if (rtb_OR) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
          BATTERY_MANA_IN_NO_ACTIVE_CHILD;
        BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 = 0U;
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          IN_CONTACTOR_DISCONNECT_COMMAND;
        rtb_MultiportSwitch = 200U;

        /* Outport: '<Root>/BM_CtctrCnctCmd' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      } else {
        switch (BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE) {
         case BATTERY_MANAGEMENT__IN_CHARGING:
          rtb_MultiportSwitch = 130U;
          rtb_OR = !BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsChPlg;
          if (rtb_OR && BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsIgnOn) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANAGEME_IN_DISCHARGING;
            rtb_MultiportSwitch = 140U;
          } else if (rtb_OR || (rtb_Saturation >= 98.5F)) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANA_IN_NO_ACTIVE_CHILD;
            BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 = 0U;
            BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
              IN_CONTACTOR_DISCONNECT_COMMAND;
            rtb_MultiportSwitch = 200U;

            /* Outport: '<Root>/BM_CtctrCnctCmd' */
            BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
          }
          break;

         case BA_IN_CONTACTOR_CONNECT_SUCCESS:
          rtb_MultiportSwitch = 120U;
          if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsChPlg) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANAGEMENT__IN_CHARGING;
            rtb_MultiportSwitch = 130U;
          } else if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsIgnOn) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANAGEME_IN_DISCHARGING;
            rtb_MultiportSwitch = 140U;
          }
          break;

         default:
          /* case IN_DISCHARGING: */
          rtb_MultiportSwitch = 140U;
          if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsChPlg) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANAGEMENT__IN_CHARGING;
            rtb_MultiportSwitch = 130U;
          } else if ((!BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsIgnOn) ||
                     (rtb_Saturation < 3.0F)) {
            BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
              BATTERY_MANA_IN_NO_ACTIVE_CHILD;
            BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 = 0U;
            BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
              IN_CONTACTOR_DISCONNECT_COMMAND;
            rtb_MultiportSwitch = 200U;

            /* Outport: '<Root>/BM_CtctrCnctCmd' */
            BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
          }
          break;
        }
      }
      break;

     case B_IN_CONTACTOR_DICCONNECT_CHECK:
      if (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBus < 0.2 *
          BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBatPack) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          IN_CONTACTOR_DISCONNECT_SUCCESS;
        rtb_MultiportSwitch = 220U;

        /* Outport: '<Root>/BM_StsCtctrCnct' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_StsCtctrCnct = false;
      } else {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BA_IN_CONTACTOR_DISCONNECT_FAIL;
        rtb_MultiportSwitch = 230U;
        BATTERY_MANAGEMENT_SYSTEM_B.BM_CtctrFlt = true;
      }
      break;

     case IN_CONTACTOR_DISCONNECT_COMMAND:
      rtb_MultiportSwitch = 200U;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      if (BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 >= (uint32_T)
          BATTERY_MANAGEMENT_SYSTEM_P.BM_TiCtctrDCnct_P) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          B_IN_CONTACTOR_DICCONNECT_CHECK;
        rtb_MultiportSwitch = 211U;
      }
      break;

     case BA_IN_CONTACTOR_DISCONNECT_FAIL:
      BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
        BATTERY_MANAGEMENT_SYS_IN_FAULT;
      rtb_MultiportSwitch = MAX_uint8_T;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      break;

     case IN_CONTACTOR_DISCONNECT_SUCCESS:
      if (rtb_OR) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BATTERY_MANAGEMENT_SYS_IN_FAULT;
        rtb_MultiportSwitch = MAX_uint8_T;

        /* Outport: '<Root>/BM_CtctrCnctCmd' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      } else {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BATTERY_MANAGEMENT_SYST_IN_IDLE;
        rtb_MultiportSwitch = 100U;

        /* Outport: '<Root>/BM_CtctrCnctCmd' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      }
      break;

     case BATTERY_MANAGEMENT_SYS_IN_FAULT:
      rtb_MultiportSwitch = MAX_uint8_T;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      if ((!BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsIgnOn) &&
          (!BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsChPlg)) {
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BATTERY_MANAGEMENT_SYST_IN_IDLE;
        rtb_MultiportSwitch = 100U;
      }
      break;

     default:
      /* case IN_IDLE: */
      rtb_MultiportSwitch = 100U;

      /* Outport: '<Root>/BM_CtctrCnctCmd' */
      BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;
      if ((!rtb_OR) && ((BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsIgnOn &&
                         (rtb_Saturation > 3.0F)) ||
                        (BATTERY_MANAGEMENT_SYSTEM_U.Obsr_StsChPlg &&
                         (rtb_Saturation < 98.5F)))) {
        BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 = 0U;
        BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
          BA_IN_CONTACTOR_CONNECT_COMMAND;
        rtb_MultiportSwitch = 110U;

        /* Outport: '<Root>/BM_CtctrCnctCmd' */
        BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = true;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/BMS OPERATION MODE' */

  /* Outport: '<Root>/BM_OperMode' */
  BATTERY_MANAGEMENT_SYSTEM_Y.BM_OperMode = rtb_MultiportSwitch;

  /* Outport: '<Root>/BPC_BattSoc' */
  BATTERY_MANAGEMENT_SYSTEM_Y.BPC_BattSoc = rtb_Saturation;

  /* Outport: '<Root>/BPC_BattWh' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.BPC_BattWh =
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Outport: '<Root>/BPC_BattAmpHr' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.BPC_BattAmpHr =
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outport: '<Root>/MTM_TBat' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<S6>/Cast'
   *  Inport: '<Root>/Obsr_TMdul'
   *  Product: '<S6>/Divide'
   *  Sum: '<S6>/Sum'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.MTM_TBat =
    ((BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[0] +
      BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[1]) +
     BATTERY_MANAGEMENT_SYSTEM_U.Obsr_TMdul[2]) / (real_T)
    BATTERY_MANAGEMENT_SYSTEM_P.NrTMdulSnsr_C;

  /* Outport: '<Root>/BFH_StsBattFlt' incorporates:
   *  MinMax: '<S2>/Max'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.BFH_StsBattFlt = rtb_Max;

  /* Outport: '<Root>/Outport1' */
  BATTERY_MANAGEMENT_SYSTEM_Y.Outport1 = rtb_Saturation;

  /* Outport: '<Root>/Outport2' incorporates:
   *  Outport: '<Root>/BM_CtctrCnctCmd'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.Outport2 =
    BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/Obsr_IBatPack'
   *  Inport: '<Root>/Obsr_VBatPack'
   *  Product: '<S4>/Multiply1'
   */
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE +=
    BATTERY_MANAGEMENT_SYSTEM_U.Obsr_IBatPack *
    BATTERY_MANAGEMENT_SYSTEM_U.Obsr_VBatPack *
    BATTERY_MANAGEMENT_SYSTEM_P.Gain1_Gain *
    BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator1_gainval;
  if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE >
      BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalEnergy_P) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalEnergy_P;
  } else if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE <
             BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator1_LowerSa) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator1_LowerSa;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/Obsr_IBatPack'
   */
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE +=
    BATTERY_MANAGEMENT_SYSTEM_P.Gain_Gain *
    BATTERY_MANAGEMENT_SYSTEM_U.Obsr_IBatPack *
    BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator_gainval;
  if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE >
      BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalCharge_P) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_P.BPC_BattTotalCharge_P;
  } else if (BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE <
             BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator_LowerSat) {
    BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_DSTATE =
      BATTERY_MANAGEMENT_SYSTEM_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE = rtb_Switch2;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_d = rtb_MultiportSwitch;

  /* Update for Memory: '<S14>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput = rtb_Logic_idx_0;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_k = rtb_Switch2_mw;

  /* Update for Memory: '<S17>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_m = rtb_Logic_k_idx_0;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_kw = rtb_Switch2_h;

  /* Update for Memory: '<S20>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_h = rtb_Logic_b_idx_0;

  /* Update for UnitDelay: '<S25>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e = rtb_Switch2_e;

  /* Update for Memory: '<S26>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_a = rtb_Logic_o_idx_0;

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_b = rtb_Switch2_l;

  /* Update for Memory: '<S29>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_l = rtb_Logic_g_idx_0;

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_o = rtb_Switch2_iz;

  /* Update for Memory: '<S32>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_c = rtb_Logic_g4_idx_0;

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_or = rtb_Switch2_p;

  /* Update for Memory: '<S52>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_j = rtb_Logic_ox_idx_0;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e0 = rtb_Switch2_mf;

  /* Update for Memory: '<S55>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hv = rtb_Logic_j_idx_0;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_p = rtb_Switch2_lg;

  /* Update for Memory: '<S58>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_f = rtb_Logic_h_idx_0;

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_on = rtb_Switch2_kz;

  /* Update for Memory: '<S40>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_p = rtb_Logic_f_idx_0;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_c = rtb_Switch2_k1;

  /* Update for Memory: '<S43>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hg = rtb_Logic_a_idx_0;

  /* Update for UnitDelay: '<S45>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_os = rtb_Switch2_c;

  /* Update for Memory: '<S46>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_fv = rtb_Logic_jp_idx_0;

  /* Matfile logging */
  rt_UpdateTXYLogVars(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo,
                      (&BATTERY_MANAGEMENT_SYSTEM_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(BATTERY_MANAGEMENT_SYSTEM_M)!=-1) &&
        !((rtmGetTFinal(BATTERY_MANAGEMENT_SYSTEM_M)-
           BATTERY_MANAGEMENT_SYSTEM_M->Timing.taskTime0) >
          BATTERY_MANAGEMENT_SYSTEM_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BATTERY_MANAGEMENT_SYSTEM_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++BATTERY_MANAGEMENT_SYSTEM_M->Timing.clockTick0)) {
    ++BATTERY_MANAGEMENT_SYSTEM_M->Timing.clockTickH0;
  }

  BATTERY_MANAGEMENT_SYSTEM_M->Timing.taskTime0 =
    BATTERY_MANAGEMENT_SYSTEM_M->Timing.clockTick0 *
    BATTERY_MANAGEMENT_SYSTEM_M->Timing.stepSize0 +
    BATTERY_MANAGEMENT_SYSTEM_M->Timing.clockTickH0 *
    BATTERY_MANAGEMENT_SYSTEM_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void BATTERY_MANAGEMENT_SYSTEM_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BATTERY_MANAGEMENT_SYSTEM_M, 0,
                sizeof(RT_MODEL_BATTERY_MANAGEMENT_S_T));
  rtmSetTFinal(BATTERY_MANAGEMENT_SYSTEM_M, 1000.0);
  BATTERY_MANAGEMENT_SYSTEM_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, (NULL));
    rtliSetLogT(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, "tout");
    rtliSetLogX(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, "");
    rtliSetLogXFinal(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, 0);
    rtliSetLogDecimation(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, 1);
    rtliSetLogY(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &BATTERY_MANAGEMENT_SYSTEM_B), 0,
                sizeof(B_BATTERY_MANAGEMENT_SYSTEM_T));

  /* states (dwork) */
  (void) memset((void *)&BATTERY_MANAGEMENT_SYSTEM_DW, 0,
                sizeof(DW_BATTERY_MANAGEMENT_SYSTEM_T));

  /* external inputs */
  (void)memset(&BATTERY_MANAGEMENT_SYSTEM_U, 0, sizeof
               (ExtU_BATTERY_MANAGEMENT_SYSTE_T));

  /* external outputs */
  (void)memset(&BATTERY_MANAGEMENT_SYSTEM_Y, 0, sizeof
               (ExtY_BATTERY_MANAGEMENT_SYSTE_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(BATTERY_MANAGEMENT_SYSTEM_M->rtwLogInfo, 0.0,
    rtmGetTFinal(BATTERY_MANAGEMENT_SYSTEM_M),
    BATTERY_MANAGEMENT_SYSTEM_M->Timing.stepSize0, (&rtmGetErrorStatus
    (BATTERY_MANAGEMENT_SYSTEM_M)));

  /* Start for DataStoreMemory: '<S4>/Data Store Memory1' */
  BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattAmpHr =
    BATTERY_MANAGEMENT_SYSTEM_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S4>/Data Store Memory2' */
  BATTERY_MANAGEMENT_SYSTEM_DW.BPC_BattWHr =
    BATTERY_MANAGEMENT_SYSTEM_P.DataStoreMemory2_InitialValue;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  BATTERY_MANAGEMENT_SYSTEM_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_d =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_j;

  /* InitializeConditions for Memory: '<S14>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_k =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for Memory: '<S17>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_m =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_l;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_kw =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for Memory: '<S20>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_h =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_c;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_a =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_ln;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_b =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_a;

  /* InitializeConditions for Memory: '<S29>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_l =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_e;

  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_o =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for Memory: '<S32>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_c =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_i;

  /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_or =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_m;

  /* InitializeConditions for Memory: '<S52>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_j =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_n;

  /* InitializeConditions for UnitDelay: '<S54>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_e0 =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for Memory: '<S55>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hv =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_j;

  /* InitializeConditions for UnitDelay: '<S57>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_p =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_ms;

  /* InitializeConditions for Memory: '<S58>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_f =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_ig;

  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_on =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_k;

  /* InitializeConditions for Memory: '<S40>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_p =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_cb;

  /* InitializeConditions for UnitDelay: '<S42>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_c =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_i;

  /* InitializeConditions for Memory: '<S43>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_hg =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_p;

  /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
  BATTERY_MANAGEMENT_SYSTEM_DW.UnitDelay_DSTATE_os =
    BATTERY_MANAGEMENT_SYSTEM_P.UnitDelay_InitialCondition_d;

  /* InitializeConditions for Memory: '<S46>/Memory' */
  BATTERY_MANAGEMENT_SYSTEM_DW.Memory_PreviousInput_fv =
    BATTERY_MANAGEMENT_SYSTEM_P.SRFlipFlop_initial_condition_d;

  /* SystemInitialize for Chart: '<S3>/BMS OPERATION MODE' */
  BATTERY_MANAGEMENT_SYSTEM_DW.temporalCounter_i1 = 0U;
  BATTERY_MANAGEMENT_SYSTEM_B.BM_CtctrFlt = false;

  /* SystemInitialize for Outport: '<Root>/BM_CtctrCnctCmd' incorporates:
   *  Chart: '<S3>/BMS OPERATION MODE'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.BM_CtctrCnctCmd = false;

  /* SystemInitialize for Outport: '<Root>/BM_StsCtctrCnct' incorporates:
   *  Chart: '<S3>/BMS OPERATION MODE'
   */
  BATTERY_MANAGEMENT_SYSTEM_Y.BM_StsCtctrCnct = false;

  /* SystemInitialize for Chart: '<S3>/BMS OPERATION MODE' */
  BATTERY_MANAGEMENT_SYSTEM_DW.is_active_c3_BATTERY_MANAGEMENT = 0U;
  BATTERY_MANAGEMENT_SYSTEM_DW.is_c3_BATTERY_MANAGEMENT_SYSTEM =
    BATTERY_MANA_IN_NO_ACTIVE_CHILD;
  BATTERY_MANAGEMENT_SYSTEM_DW.is_CONTACTOR_CONNECT_SEQUENCE =
    BATTERY_MANA_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void BATTERY_MANAGEMENT_SYSTEM_terminate(void)
{
  /* (no terminate code required) */
}
