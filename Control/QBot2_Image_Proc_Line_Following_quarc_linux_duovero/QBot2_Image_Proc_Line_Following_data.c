/*
 * QBot2_Image_Proc_Line_Following_data.c
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

#include "QBot2_Image_Proc_Line_Following.h"
#include "QBot2_Image_Proc_Line_Following_private.h"

/* Block parameters (auto storage) */
P_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_P = {
  /*  Mask Parameter: HILInitialize_analog_input_maxi
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 5.0, 5.0, 5.0, 5.0, 16.5, 3.3, 3.3, 3.3, 3.3 },

  /*  Mask Parameter: HILInitialize_analog_input_mini
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S18>/Step: end_time'
                                        */

  /*  Mask Parameter: HILInitialize_final_other_outpu
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_initial_other_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: SecondOrderLowPassFilter2_input
                                        * Referenced by: '<S15>/wn'
                                        */
  10.0,                                /* Mask Parameter: SecondOrderLowPassFilter2_inp_n
                                        * Referenced by: '<S17>/wn'
                                        */
  50.0,                                /* Mask Parameter: SecondOrderLowPassFilter_input_
                                        * Referenced by: '<S7>/wn'
                                        */
  50.0,                                /* Mask Parameter: SecondOrderLowPassFilter1_input
                                        * Referenced by: '<S8>/wn'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_f
                                        * Referenced by: '<S15>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_l
                                        * Referenced by: '<S17>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter_inpu_b
                                        * Referenced by: '<S7>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_inp_b
                                        * Referenced by: '<S8>/zt'
                                        */
  19531.25,                            /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  3.0,                                 /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  1.0,                                 /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S18>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: DisplayImageHistogram_update_ra
                                        * Referenced by: '<Root>/Display Image (Histogram)'
                                        */
  1,                                   /* Mask Parameter: Image_update_rate
                                        * Referenced by: '<Root>/Image'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  4U,                                  /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<S19>/HIL Read1'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U },

  /*  Mask Parameter: HILRead1_digital_channels
   * Referenced by: '<S19>/HIL Read1'
   */
  { 8U, 9U, 10U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILRead1_encoder_channels
   * Referenced by: '<S19>/HIL Read1'
   */
  { 2U, 3U },
  1002U,                               /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<S19>/HIL Read1'
                                        */

  /*  Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S19>/HIL Write'
   */
  { 2000U, 2001U },

  /*  Mask Parameter: HILInitialize_other_output_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 2000U, 2001U, 14000U, 16000U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: KinectInitialize_active
                                        * Referenced by: '<Root>/Kinect Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: DisplayImageHistogram_orig_size
                                        * Referenced by: '<Root>/Display Image (Histogram)'
                                        */
  0,                                   /* Mask Parameter: Image_orig_size
                                        * Referenced by: '<Root>/Image'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_i
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_jc
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_output_ay
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S1>/red_th1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/unity'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Sum( k=1,n-1, x(k) )'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S21>/zero'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S22>/Vbiased'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S23>/Vunbiased'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Step: end_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Step: end_time'
                                        */

  /*  Expression: [160 255]
   * Referenced by: '<Root>/red_th'
   */
  { 160.0, 255.0 },

  /*  Expression: [160 255]
   * Referenced by: '<Root>/green_th'
   */
  { 160.0, 255.0 },

  /*  Expression: [70 140]
   * Referenced by: '<Root>/blue_th'
   */
  { 70.0, 140.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */

  /*  Expression: [320; 540; 0]
   * Referenced by: '<Root>/Constant2'
   */
  { 320.0, 540.0, 0.0 },
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant5'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.17453292519943295,                 /* Expression: 10*pi/180
                                        * Referenced by: '<Root>/Constant7'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant12'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Constant13'
                                        */
  1.1,                                 /* Expression: 1.1
                                        * Referenced by: '<Root>/Constant10'
                                        */
  0.45,                                /* Expression: 0.45
                                        * Referenced by: '<Root>/Constant6'
                                        */
  0.6,                                 /* Expression: 0.6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  0.6,                                 /* Expression: 0.6
                                        * Referenced by: '<Root>/Constant9'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S9>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator3'
                                        */
  0.1208304866765305,                  /* Expression: 2*pi/52
                                        * Referenced by: '<S14>/ticks to encoder rotation'
                                        */
  0.020168080785264393,                /* Expression: 1/49.5833
                                        * Referenced by: '<S14>/ encoder rotation to wheel rotation (gear ratio)'
                                        */
  35.0,                                /* Expression: 35
                                        * Referenced by: '<S14>/wheel radious (mm)'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S14>/mm to m'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S15>/x0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  0.1208304866765305,                  /* Expression: 2*pi/52
                                        * Referenced by: '<S16>/ticks to encoder rotation'
                                        */
  0.020168080785264393,                /* Expression: 1/49.5833
                                        * Referenced by: '<S16>/ encoder rotation to wheel rotation (gear ratio)'
                                        */
  35.0,                                /* Expression: 35
                                        * Referenced by: '<S16>/wheel radious (mm)'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S16>/mm to m'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S17>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S17>/x0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator2'
                                        */
  0.2156,                              /* Expression: brightness
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1.0,                                 /* Expression: contrast
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0.0,                                 /* Expression: exposure
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0.0,                                 /* Expression: frame_interval
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  2.2,                                 /* Expression: gamma
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0.0,                                 /* Expression: hue
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1.0,                                 /* Expression: saturation
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0.5,                                 /* Expression: sharpness
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  2700.0,                              /* Expression: balance
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S7>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S8>/x0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Integrator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator2'
                                        */
  1,                                   /* Computed Parameter: KinectGetImage_SensorType
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1,                                   /* Computed Parameter: KinectGetImage_Backlight
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1,                                   /* Computed Parameter: KinectGetImage_Flicker
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  0U,                                  /* Computed Parameter: RateTransition1_X0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  0U,                                  /* Computed Parameter: Memory_X0_f
                                        * Referenced by: '<Root>/Memory'
                                        */
  0U,                                  /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<Root>/Rate Transition'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1,                                   /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S19>/HIL Read1'
                                        */
  1,                                   /* Computed Parameter: KinectGetImage_AExposure
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1,                                   /* Computed Parameter: KinectGetImage_ABalance
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  1                                    /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S19>/HIL Write'
                                        */
};
