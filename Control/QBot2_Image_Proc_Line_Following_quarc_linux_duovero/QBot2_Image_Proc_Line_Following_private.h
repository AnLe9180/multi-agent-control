/*
 * QBot2_Image_Proc_Line_Following_private.h
 *
 * Code generation for model "QBot2_Image_Proc_Line_Following".
 *
 * Model version              : 1.640
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Tue Jan 24 14:34:57 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_QBot2_Image_Proc_Line_Following_private_h_
#define RTW_HEADER_QBot2_Image_Proc_Line_Following_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "QBot2_Image_Proc_Line_Following.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_roundd_snf(real_T u);
void QBot2_Image_Proc_Line_Following_output0(void);
void QBot2_Image_Proc_Line_Following_update0(void);
void QBot2_Image_Proc_Line_Following_output2(void);
void QBot2_Image_Proc_Line_Following_update2(void);/* private model entry point functions */
extern void QBot2_Image_Proc_Line_Following_derivatives(void);

#endif                                 /* RTW_HEADER_QBot2_Image_Proc_Line_Following_private_h_ */
