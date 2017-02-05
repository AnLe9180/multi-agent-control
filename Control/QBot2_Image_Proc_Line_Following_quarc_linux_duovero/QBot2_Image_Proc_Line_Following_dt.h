/*
 * QBot2_Image_Proc_Line_Following_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_kinect),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_kinect",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QBot2_Image_Proc_Line_Followi_B.HILRead1_o1), 0, 0, 51 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_B.RateTransition1), 7, 0, 2 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_B.RateTransition[0]), 3, 0,
    2764800 }
  ,

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0]), 0, 0, 45 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect), 14, 0,
    1 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.DisplayImageHistogram_PWORK), 11,
    0, 5 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[0]),
    6, 0, 22 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[0]),
    7, 0, 6 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.DisplayImageHistogram_IWORK), 10,
    0, 6 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab),
    2, 0, 6 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.RateTransition_Buffer0[0]), 3, 0,
    921600 },

  { (char_T *)(&QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE), 8, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_maxi
               [0]), 0, 0, 47 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c),
    6, 0, 8 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.HILRead1_analog_channels), 7, 0,
    32 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.HILInitialize_active), 8, 0, 38
  },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.Constant1_Value), 0, 0, 69 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.KinectGetImage_SensorType), 6, 0,
    3 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.RateTransition1_X0), 7, 0, 2 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.RateTransition_X0), 3, 0, 2 },

  { (char_T *)(&QBot2_Image_Proc_Line_Followi_P.HILRead1_Active), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] QBot2_Image_Proc_Line_Following_dt.h */
