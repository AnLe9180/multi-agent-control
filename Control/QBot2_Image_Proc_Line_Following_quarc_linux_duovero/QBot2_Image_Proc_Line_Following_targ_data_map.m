  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2_Image_Proc_Line_Followi_P)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_maxi
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_mini
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.BiasRemoval_end_time
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_other_outpu
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_pwm_outputs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 23;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_other_out
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 24;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_pwm_outpu
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 28;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_input
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 29;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_n
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 30;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter_input_
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 31;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter1_input
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 32;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_f
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 33;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 34;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter_inpu_b
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 35;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter1_inp_b
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 36;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 37;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_leading_deadb
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 38;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_trailing_dead
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 39;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outputs
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 40;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_j
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 41;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_p
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 42;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_f
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 43;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.BiasRemoval_start_time
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 44;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.BiasRemoval_switch_id
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_pwm_outp
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_alignment
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_configuration
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_modes
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_polarity
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.DisplayImageHistogram_update_ra
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Image_update_rate
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_chan
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILRead1_digital_channels
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 11;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_encoder_channels
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 14;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILRead1_encoder_channels
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 18;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILRead1_other_channels
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 20;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILWrite_other_channels
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 21;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_other_output_chan
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 23;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels
	  section.data(9).logicalSrcIdx = 41;
	  section.data(9).dtTransOffset = 27;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_quadrature
	  section.data(10).logicalSrcIdx = 42;
	  section.data(10).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectInitialize_active
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_digital_out
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_digital_o
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.DisplayImageHistogram_orig_size
	  section.data(5).logicalSrcIdx = 47;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Image_orig_size
	  section.data(6).logicalSrcIdx = 48;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_input_
	  section.data(7).logicalSrcIdx = 49;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_inpu_m
	  section.data(8).logicalSrcIdx = 50;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_output
	  section.data(9).logicalSrcIdx = 51;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_h
	  section.data(10).logicalSrcIdx = 52;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_i
	  section.data(11).logicalSrcIdx = 53;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_g
	  section.data(12).logicalSrcIdx = 54;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_d
	  section.data(13).logicalSrcIdx = 55;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_m
	  section.data(14).logicalSrcIdx = 56;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_outp_j
	  section.data(15).logicalSrcIdx = 57;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_clock_frequen
	  section.data(16).logicalSrcIdx = 58;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_clock_frequ_h
	  section.data(17).logicalSrcIdx = 59;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_clock_params_
	  section.data(18).logicalSrcIdx = 60;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_clock_param_j
	  section.data(19).logicalSrcIdx = 61;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_outpu
	  section.data(20).logicalSrcIdx = 62;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_out_l
	  section.data(21).logicalSrcIdx = 63;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_out_f
	  section.data(22).logicalSrcIdx = 64;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_out_j
	  section.data(23).logicalSrcIdx = 65;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_ou_jc
	  section.data(24).logicalSrcIdx = 66;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_out_o
	  section.data(25).logicalSrcIdx = 67;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_digital_out_a
	  section.data(26).logicalSrcIdx = 68;
	  section.data(26).dtTransOffset = 25;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_count
	  section.data(27).logicalSrcIdx = 69;
	  section.data(27).dtTransOffset = 26;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_cou_k
	  section.data(28).logicalSrcIdx = 70;
	  section.data(28).dtTransOffset = 27;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_param
	  section.data(29).logicalSrcIdx = 71;
	  section.data(29).dtTransOffset = 28;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_par_k
	  section.data(30).logicalSrcIdx = 72;
	  section.data(30).dtTransOffset = 29;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_l
	  section.data(31).logicalSrcIdx = 73;
	  section.data(31).dtTransOffset = 30;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_a
	  section.data(32).logicalSrcIdx = 74;
	  section.data(32).dtTransOffset = 31;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_p
	  section.data(33).logicalSrcIdx = 75;
	  section.data(33).dtTransOffset = 32;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_output_ay
	  section.data(34).logicalSrcIdx = 76;
	  section.data(34).dtTransOffset = 33;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_k
	  section.data(35).logicalSrcIdx = 77;
	  section.data(35).dtTransOffset = 34;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_o
	  section.data(36).logicalSrcIdx = 78;
	  section.data(36).dtTransOffset = 35;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_params_at
	  section.data(37).logicalSrcIdx = 79;
	  section.data(37).dtTransOffset = 36;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_params__b
	  section.data(38).logicalSrcIdx = 80;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 64;
      section.data(64)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant3_Value
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.red_th1_Value
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Gain_Gain
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.unity_Value
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Sumk1n1xk_InitialCondition
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.zero_Y0
	  section.data(8).logicalSrcIdx = 88;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant_Value
	  section.data(9).logicalSrcIdx = 89;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Vbiased_Y0
	  section.data(10).logicalSrcIdx = 90;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Vunbiased_Y0
	  section.data(11).logicalSrcIdx = 91;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Stepstart_time_Y0
	  section.data(12).logicalSrcIdx = 92;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Stepstart_time_YFinal
	  section.data(13).logicalSrcIdx = 93;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Stepend_time_Y0
	  section.data(14).logicalSrcIdx = 94;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Stepend_time_YFinal
	  section.data(15).logicalSrcIdx = 95;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.red_th_Value
	  section.data(16).logicalSrcIdx = 96;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.green_th_Value
	  section.data(17).logicalSrcIdx = 97;
	  section.data(17).dtTransOffset = 17;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.blue_th_Value
	  section.data(18).logicalSrcIdx = 98;
	  section.data(18).dtTransOffset = 19;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator1_IC
	  section.data(19).logicalSrcIdx = 99;
	  section.data(19).dtTransOffset = 21;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition_l
	  section.data(20).logicalSrcIdx = 100;
	  section.data(20).dtTransOffset = 22;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant2_Value
	  section.data(21).logicalSrcIdx = 101;
	  section.data(21).dtTransOffset = 23;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant5_Value
	  section.data(22).logicalSrcIdx = 102;
	  section.data(22).dtTransOffset = 26;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant4_Value
	  section.data(23).logicalSrcIdx = 103;
	  section.data(23).dtTransOffset = 27;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant7_Value
	  section.data(24).logicalSrcIdx = 104;
	  section.data(24).dtTransOffset = 28;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant12_Value
	  section.data(25).logicalSrcIdx = 105;
	  section.data(25).dtTransOffset = 29;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant13_Value
	  section.data(26).logicalSrcIdx = 106;
	  section.data(26).dtTransOffset = 30;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant10_Value
	  section.data(27).logicalSrcIdx = 107;
	  section.data(27).dtTransOffset = 31;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant6_Value
	  section.data(28).logicalSrcIdx = 108;
	  section.data(28).dtTransOffset = 32;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant8_Value
	  section.data(29).logicalSrcIdx = 109;
	  section.data(29).dtTransOffset = 33;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant9_Value
	  section.data(30).logicalSrcIdx = 110;
	  section.data(30).dtTransOffset = 34;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Memory_X0
	  section.data(31).logicalSrcIdx = 111;
	  section.data(31).dtTransOffset = 35;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator2_IC
	  section.data(32).logicalSrcIdx = 112;
	  section.data(32).dtTransOffset = 36;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator3_IC
	  section.data(33).logicalSrcIdx = 113;
	  section.data(33).dtTransOffset = 37;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.tickstoencoderrotation_Gain
	  section.data(34).logicalSrcIdx = 114;
	  section.data(34).dtTransOffset = 38;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.encoderrotationtowheelrotationg
	  section.data(35).logicalSrcIdx = 115;
	  section.data(35).dtTransOffset = 39;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.wheelradiousmm_Gain
	  section.data(36).logicalSrcIdx = 116;
	  section.data(36).dtTransOffset = 40;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.mmtom_Gain
	  section.data(37).logicalSrcIdx = 117;
	  section.data(37).dtTransOffset = 41;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant_Value_g
	  section.data(38).logicalSrcIdx = 118;
	  section.data(38).dtTransOffset = 42;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.x0_Value
	  section.data(39).logicalSrcIdx = 119;
	  section.data(39).dtTransOffset = 43;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_a
	  section.data(40).logicalSrcIdx = 120;
	  section.data(40).dtTransOffset = 44;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.tickstoencoderrotation_Gain_f
	  section.data(41).logicalSrcIdx = 121;
	  section.data(41).dtTransOffset = 45;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.encoderrotationtowheelrotatio_d
	  section.data(42).logicalSrcIdx = 122;
	  section.data(42).dtTransOffset = 46;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.wheelradiousmm_Gain_d
	  section.data(43).logicalSrcIdx = 123;
	  section.data(43).dtTransOffset = 47;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.mmtom_Gain_c
	  section.data(44).logicalSrcIdx = 124;
	  section.data(44).dtTransOffset = 48;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant_Value_m
	  section.data(45).logicalSrcIdx = 125;
	  section.data(45).dtTransOffset = 49;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.x0_Value_n
	  section.data(46).logicalSrcIdx = 126;
	  section.data(46).dtTransOffset = 50;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_o
	  section.data(47).logicalSrcIdx = 127;
	  section.data(47).dtTransOffset = 51;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Brightness
	  section.data(48).logicalSrcIdx = 128;
	  section.data(48).dtTransOffset = 52;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Contrast
	  section.data(49).logicalSrcIdx = 129;
	  section.data(49).dtTransOffset = 53;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Exposure
	  section.data(50).logicalSrcIdx = 130;
	  section.data(50).dtTransOffset = 54;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_FInterval
	  section.data(51).logicalSrcIdx = 131;
	  section.data(51).dtTransOffset = 55;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Gain
	  section.data(52).logicalSrcIdx = 132;
	  section.data(52).dtTransOffset = 56;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Gamma
	  section.data(53).logicalSrcIdx = 133;
	  section.data(53).dtTransOffset = 57;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Hue
	  section.data(54).logicalSrcIdx = 134;
	  section.data(54).dtTransOffset = 58;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Saturation
	  section.data(55).logicalSrcIdx = 135;
	  section.data(55).dtTransOffset = 59;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Sharpness
	  section.data(56).logicalSrcIdx = 136;
	  section.data(56).dtTransOffset = 60;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Balance
	  section.data(57).logicalSrcIdx = 137;
	  section.data(57).dtTransOffset = 61;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.x0_Value_j
	  section.data(58).logicalSrcIdx = 138;
	  section.data(58).dtTransOffset = 62;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.x0_Value_e
	  section.data(59).logicalSrcIdx = 139;
	  section.data(59).dtTransOffset = 63;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator_IC
	  section.data(60).logicalSrcIdx = 140;
	  section.data(60).dtTransOffset = 64;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant_Value_b
	  section.data(61).logicalSrcIdx = 141;
	  section.data(61).dtTransOffset = 65;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_d
	  section.data(62).logicalSrcIdx = 142;
	  section.data(62).dtTransOffset = 66;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Constant_Value_o
	  section.data(63).logicalSrcIdx = 143;
	  section.data(63).dtTransOffset = 67;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_g
	  section.data(64).logicalSrcIdx = 144;
	  section.data(64).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_SensorType
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Backlight
	  section.data(2).logicalSrcIdx = 146;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Flicker
	  section.data(3).logicalSrcIdx = 147;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.RateTransition1_X0
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.Memory_X0_f
	  section.data(2).logicalSrcIdx = 149;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.RateTransition_X0
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 151;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_P.HILRead1_Active
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_AExposure
	  section.data(2).logicalSrcIdx = 153;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.KinectGetImage_ABalance
	  section.data(3).logicalSrcIdx = 154;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Followi_P.HILWrite_Active
	  section.data(4).logicalSrcIdx = 155;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2_Image_Proc_Line_Followi_B)
    ;%
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_B.HILRead1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.HILRead1_o4
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Integrator1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Integrator2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Integrator3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.mmtom
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Constant
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.x0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.wn
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.zt
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product_b
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.mmtom_a
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Constant_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.x0_g
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.wn_d
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.zt_m
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product_k
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product1_g
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.ManualSwitch
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.x0_j
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.x0_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Constant_g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.wn_a
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.zt_i
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product_d
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product1_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Constant_i
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.wn_h
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.zt_o
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product_p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Product1_j
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Vf
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.W
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.states
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.vR
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.vL
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.x_dot
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.y_dot
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.psi_dot
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Omega
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.VVavg
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Vin
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Constant_c
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Count
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Sum
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.div
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.n
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_B.RateTransition1
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o2
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Followi_B.RateTransition
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.cimage
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 921600;
	
	  ;% QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o1
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 1843200;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2_Image_Proc_Line_Follow_DW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE_h
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Sumk1n1xk_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 24;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 28;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 32;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_OOValues
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 36;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 40;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILWrite_OtherBuffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 41;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Vf_1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 43;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.end_flag
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.DisplayImageHistogram_PWORK
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILRead1_PWORK
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Image_PWORK
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.KinectGetImage_PWORK
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILWrite_PWORK
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 8;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 12;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 16;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILRead1_EncoderBuffer
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.RateTransition1_Buffer0
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput_p
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.DisplayImageHistogram_IWORK
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Image_IWORK
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_b
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_a
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_bz
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_SubsysRanB
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.SwitchCase_ActiveSubsystem
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.RateTransition_Buffer0
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3314933472;
  targMap.checksum1 = 134756000;
  targMap.checksum2 = 791420137;
  targMap.checksum3 = 1002067058;

