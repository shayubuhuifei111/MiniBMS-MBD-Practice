/*
 * BATTERY_MANAGEMENT_SYSTEM_private.h
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

#ifndef BATTERY_MANAGEMENT_SYSTEM_private_h_
#define BATTERY_MANAGEMENT_SYSTEM_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "BATTERY_MANAGEMENT_SYSTEM_types.h"
#include "BATTERY_MANAGEMENT_SYSTEM.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern uint32_T plook_u32u8_binckan(uint8_T u, const uint8_T bp[], uint32_T
  maxIndex);
extern uint32_T binsearch_u32u8(uint8_T u, const uint8_T bp[], uint32_T
  startIndex, uint32_T maxIndex);

#endif                                /* BATTERY_MANAGEMENT_SYSTEM_private_h_ */
