/*
 * QBot2_Image_Proc_Line_Following.c
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
#include "QBot2_Image_Proc_Line_Following_dt.h"

/* Block signals (auto storage) */
B_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_B;

/* Continuous states */
X_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_X;

/* Block states (auto storage) */
DW_QBot2_Image_Proc_Line_Foll_T QBot2_Image_Proc_Line_Follow_DW;

/* Real-time model */
RT_MODEL_QBot2_Image_Proc_Lin_T QBot2_Image_Proc_Line_Follow_M_;
RT_MODEL_QBot2_Image_Proc_Lin_T *const QBot2_Image_Proc_Line_Follow_M =
  &QBot2_Image_Proc_Line_Follow_M_;

/* Forward declaration for local functions */
static void QBot2_Image_Proc_Line_Fo_thresh(uint8_T x[307200], const real_T th[2],
  real_T val);
static void QBot2__find_reachability_matrix(const uint8_T img[19200], real_T
  Type, real_T eqtable[2500], real_T limg[19200], real_T *maxlabel);
static void QBot2_Image_Proc_Li_updatetable(const real_T eqtable[2500], real_T
  maxlabel, real_T table[2500]);
static void QBot2_Image_Proc_L_updatetable2(const real_T eqtable[2500], real_T
  maxlabel, real_T table[2500]);
static real_T QBot2_Image_Proc_Line_Follo_sum(const real_T x[50]);
static void QBot2_Image_Proc_L_updatetable3(real_T eqtable[2500], real_T
  maxlabel, real_T idvec[50], real_T *count);
static void QBot2_Image_Proc_Li_label_image(real_T limg[19200], const real_T
  idvec[50], real_T maxlabel);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(QBot2_Image_Proc_Line_Follow_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(QBot2_Image_Proc_Line_Follow_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (QBot2_Image_Proc_Line_Follow_M->Timing.TaskCounters.TID[1] == 0) {
    QBot2_Image_Proc_Line_Follow_M->Timing.RateInteraction.TID1_2 =
      (QBot2_Image_Proc_Line_Follow_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QBot2_Image_Proc_Line_Follow_M->Timing.perTaskSampleHits[5] =
      QBot2_Image_Proc_Line_Follow_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (QBot2_Image_Proc_Line_Follow_M->Timing.TaskCounters.TID[2])++;
  if ((QBot2_Image_Proc_Line_Follow_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    QBot2_Image_Proc_Line_Follow_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  QBot2_Image_Proc_Line_Following_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/Thresholding' */
static void QBot2_Image_Proc_Line_Fo_thresh(uint8_T x[307200], const real_T th[2],
  real_T val)
{
  int32_T i;
  int32_T j;
  real_T tmp;

  /* '<S11>:1:30' */
  /* -------------------------------------------------------------------------- */
  /* '<S11>:1:33' */
  for (i = 0; i < 480; i++) {
    /* '<S11>:1:33' */
    /* '<S11>:1:34' */
    for (j = 0; j < 640; j++) {
      /* '<S11>:1:34' */
      if ((x[480 * j + i] >= th[0]) && (x[480 * j + i] <= th[1])) {
        /* '<S11>:1:35' */
        /* '<S11>:1:36' */
        tmp = rt_roundd_snf(val);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            x[i + 480 * j] = (uint8_T)tmp;
          } else {
            x[i + 480 * j] = 0U;
          }
        } else {
          x[i + 480 * j] = MAX_uint8_T;
        }
      } else {
        /* '<S11>:1:38' */
        x[i + 480 * j] = 0U;
      }

      /* '<S11>:1:34' */
    }

    /* '<S11>:1:33' */
  }

  /* -------------------------------------------------------------------------- */
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static void QBot2__find_reachability_matrix(const uint8_T img[19200], real_T
  Type, real_T eqtable[2500], real_T limg[19200], real_T *maxlabel)
{
  real_T type;
  int32_T label;
  int32_T i;
  int32_T j;

  /* -------------------------------------------------------------------------- */
  /* '<S12>:1:75' */
  /* '<S12>:1:77' */
  type = Type;
  if ((Type != 4.0) && (Type != 8.0)) {
    /* '<S12>:1:78' */
    /* '<S12>:1:79' */
    type = 8.0;
  }

  /*  Step 1: Label 8 or 4 connected components */
  /* '<S12>:1:83' */
  memset(&limg[0], 0, 19200U * sizeof(real_T));

  /* '<S12>:1:84' */
  label = 0;

  /* '<S12>:1:85' */
  /* '<S12>:1:86' */
  for (i = 0; i < 120; i++) {
    /* '<S12>:1:86' */
    /* '<S12>:1:87' */
    for (j = 0; j < 160; j++) {
      /* '<S12>:1:87' */
      if ((img[120 * j + i] > 0) && (limg[120 * j + i] == 0.0)) {
        /* '<S12>:1:88' */
        if ((j >= 1) && (img[(j - 1) * 120 + i] > 0)) {
          /* '<S12>:1:89' */
          /* '<S12>:1:90' */
          limg[i + 120 * j] = limg[(j - 1) * 120 + i];
        } else if (label <= 49) {
          /* '<S12>:1:92' */
          /* '<S12>:1:93' */
          label++;

          /* '<S12>:1:94' */
          limg[i + 120 * j] = label;
        } else {
          /* '<S12>:1:96' */
          limg[i + 120 * j] = 0.0;
        }
      }

      /* '<S12>:1:87' */
    }

    /* '<S12>:1:86' */
  }

  /*  Find the reachability matrix */
  /* '<S12>:1:104' */
  *maxlabel = label;

  /* '<S12>:1:105' */
  memset(&eqtable[0], 0, 2500U * sizeof(real_T));
  for (i = 0; i < 50; i++) {
    eqtable[i + 50 * i] = 1.0;
  }

  if (!(label < 1)) {
    /*  eqtable = eye(maxlabel, maxlabel); */
    /* '<S12>:1:110' */
    for (label = 0; label < 119; label++) {
      /* '<S12>:1:110' */
      /* '<S12>:1:111' */
      for (i = 0; i < 160; i++) {
        /* '<S12>:1:111' */
        if (type == 4.0) {
          /* '<S12>:1:112' */
          if ((img[(120 * i + label) + 1] > 0) && (img[120 * i + label] > 0) &&
              (limg[(120 * i + label) + 1] != 0.0)) {
            /* '<S12>:1:113' */
            /* '<S12>:1:114' */
            /* '<S12>:1:115' */
            eqtable[((int32_T)limg[(label + 120 * i) + 1] + 50 * ((int32_T)
                      limg[label + 120 * i] - 1)) - 1] = 1.0;

            /* '<S12>:1:116' */
            eqtable[((int32_T)limg[label + 120 * i] + 50 * ((int32_T)limg[(label
                       + 120 * i) + 1] - 1)) - 1] = 1.0;
          }
        } else {
          if ((type == 8.0) && (img[(120 * i + label) + 1] > 0) && (limg[(120 *
                i + label) + 1] != 0.0)) {
            /* '<S12>:1:119' */
            /* '<S12>:1:120' */
            if ((i >= 1) && (img[(i - 1) * 120 + label] > 0)) {
              /* '<S12>:1:121' */
              /* '<S12>:1:122' */
              eqtable[((int32_T)limg[(label + 120 * i) + 1] + 50 * ((int32_T)
                        limg[label + 120 * (i - 1)] - 1)) - 1] = 1.0;

              /* '<S12>:1:123' */
              eqtable[((int32_T)limg[label + 120 * (i - 1)] + 50 * ((int32_T)
                        limg[(label + 120 * i) + 1] - 1)) - 1] = 1.0;
            }

            if (img[120 * i + label] > 0) {
              /* '<S12>:1:125' */
              /* '<S12>:1:126' */
              eqtable[((int32_T)limg[(label + 120 * i) + 1] + 50 * ((int32_T)
                        limg[label + 120 * i] - 1)) - 1] = 1.0;

              /* '<S12>:1:127' */
              eqtable[((int32_T)limg[label + 120 * i] + 50 * ((int32_T)limg
                        [(label + 120 * i) + 1] - 1)) - 1] = 1.0;
            }

            if ((2 + i <= 160) && (img[(1 + i) * 120 + label] > 0)) {
              /* '<S12>:1:129' */
              /* '<S12>:1:130' */
              eqtable[((int32_T)limg[(label + 120 * i) + 1] + 50 * ((int32_T)
                        limg[label + 120 * (1 + i)] - 1)) - 1] = 1.0;

              /* '<S12>:1:131' */
              eqtable[((int32_T)limg[label + 120 * (1 + i)] + 50 * ((int32_T)
                        limg[(label + 120 * i) + 1] - 1)) - 1] = 1.0;
            }
          }
        }

        /* '<S12>:1:111' */
      }

      /* '<S12>:1:110' */
    }
  } else {
    /* '<S12>:1:106' */
  }
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static void QBot2_Image_Proc_Li_updatetable(const real_T eqtable[2500], real_T
  maxlabel, real_T table[2500])
{
  real_T tmp1[50];
  real_T tmp2[50];
  real_T iscommon;
  int32_T i;
  int32_T j;
  int32_T b;
  int8_T x[50];
  int32_T k;
  int32_T i_0;

  /* -------------------------------------------------------------------------- */
  /* '<S12>:1:144' */
  memset(&table[0], 0, 2500U * sizeof(real_T));

  /*  etable = eqtable; */
  /* '<S12>:1:146' */
  for (i = 0; i < (int32_T)maxlabel; i++) {
    /* '<S12>:1:146' */
    /* '<S12>:1:147' */
    for (k = 0; k < 50; k++) {
      tmp1[k] = eqtable[50 * k + i];
    }

    /* '<S12>:1:148' */
    b = (int32_T)((1.0 - ((1.0 + (real_T)i) + 1.0)) + maxlabel);

    /* '<S12>:1:148' */
    for (j = 0; j < b; j++) {
      /* '<S12>:1:148' */
      /* '<S12>:1:149' */
      k = (int32_T)(((1.0 + (real_T)i) + 1.0) + (real_T)j);

      /* '<S12>:1:150' */
      for (i_0 = 0; i_0 < 50; i_0++) {
        x[i_0] = (int8_T)((tmp1[i_0] != 0.0) && (eqtable[(50 * i_0 + k) - 1] !=
          0.0));
        tmp2[i_0] = eqtable[(50 * i_0 + k) - 1];
      }

      iscommon = x[0];
      for (k = 0; k < 49; k++) {
        iscommon += (real_T)x[k + 1];
      }

      if (iscommon != 0.0) {
        /* '<S12>:1:152' */
        for (k = 0; k < 50; k++) {
          tmp1[k] = ((tmp1[k] != 0.0) || (tmp2[k] != 0.0));
        }
      }

      /* '<S12>:1:148' */
    }

    /* '<S12>:1:155' */
    for (k = 0; k < 50; k++) {
      table[i + 50 * k] = tmp1[k];
    }

    /* '<S12>:1:146' */
  }
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static void QBot2_Image_Proc_L_updatetable2(const real_T eqtable[2500], real_T
  maxlabel, real_T table[2500])
{
  real_T i;
  real_T tmp1[50];
  real_T tmp2[50];
  real_T iscommon;
  int32_T b_i;
  int32_T j;
  int8_T x[50];
  int32_T i_0;
  int32_T i_1;

  /* -------------------------------------------------------------------------- */
  /* '<S12>:1:163' */
  memset(&table[0], 0, 2500U * sizeof(real_T));

  /*  etable = eqtable; */
  /* '<S12>:1:165' */
  for (b_i = 0; b_i < (int32_T)-((-1.0 - maxlabel) + 1.0); b_i++) {
    /* '<S12>:1:165' */
    i = maxlabel + -(real_T)b_i;

    /* '<S12>:1:166' */
    i_0 = (int32_T)i;
    for (i_1 = 0; i_1 < 50; i_1++) {
      tmp1[i_1] = eqtable[(50 * i_1 + i_0) - 1];
    }

    /*          i */
    /*          count = count + 1; */
    /*          idvec(i) = count; */
    /* '<S12>:1:170' */
    for (j = 0; j < (int32_T)-((-1.0 - (i - 1.0)) + 1.0); j++) {
      /* '<S12>:1:170' */
      /* '<S12>:1:171' */
      i_0 = (int32_T)((i - 1.0) + -(real_T)j);

      /* '<S12>:1:172' */
      for (i_1 = 0; i_1 < 50; i_1++) {
        x[i_1] = (int8_T)((tmp1[i_1] != 0.0) && (eqtable[(50 * i_1 + i_0) - 1]
          != 0.0));
        tmp2[i_1] = eqtable[(50 * i_1 + i_0) - 1];
      }

      iscommon = x[0];
      for (i_0 = 0; i_0 < 49; i_0++) {
        iscommon += (real_T)x[i_0 + 1];
      }

      if (iscommon != 0.0) {
        /* '<S12>:1:174' */
        for (i_1 = 0; i_1 < 50; i_1++) {
          tmp1[i_1] = ((tmp1[i_1] != 0.0) || (tmp2[i_1] != 0.0));
        }

        /*                  find(tmp1==1) */
        /*                  pause */
      }

      /* '<S12>:1:170' */
    }

    /* '<S12>:1:179' */
    i_0 = (int32_T)i;
    for (i_1 = 0; i_1 < 50; i_1++) {
      table[(i_0 + 50 * i_1) - 1] = tmp1[i_1];
    }

    /* '<S12>:1:165' */
  }
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static real_T QBot2_Image_Proc_Line_Follo_sum(const real_T x[50])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 49; k++) {
    y += x[k + 1];
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static void QBot2_Image_Proc_L_updatetable3(real_T eqtable[2500], real_T
  maxlabel, real_T idvec[50], real_T *count)
{
  real_T tmp1[50];
  real_T j;
  real_T tmp2[50];
  int32_T i;
  int32_T b_j;
  int32_T b;
  real_T tmp1_0[50];
  int32_T i_0;
  int32_T j_0;
  int32_T j_1;

  /* '<S12>:1:192' */
  /* -------------------------------------------------------------------------- */
  /* '<S12>:1:187' */
  memset(&QBot2_Image_Proc_Line_Followi_B.table[0], 0, 2500U * sizeof(real_T));

  /* '<S12>:1:188' */
  *count = 0.0;

  /* '<S12>:1:189' */
  memset(&idvec[0], 0, 50U * sizeof(real_T));

  /*  etable = eqtable; */
  /* '<S12>:1:191' */
  for (i = 0; i < (int32_T)maxlabel; i++) {
    /* '<S12>:1:191' */
    /* '<S12>:1:192' */
    for (i_0 = 0; i_0 < 50; i_0++) {
      tmp1[i_0] = eqtable[50 * i_0 + i];
    }

    if (eqtable[50 * i + i] != 0.0) {
      /* '<S12>:1:193' */
      /* '<S12>:1:194' */
      (*count)++;

      /* '<S12>:1:195' */
      idvec[i] = *count;

      /* '<S12>:1:196' */
      b = (int32_T)((1.0 - ((1.0 + (real_T)i) + 1.0)) + maxlabel);

      /* '<S12>:1:196' */
      for (b_j = 0; b_j < b; b_j++) {
        /* '<S12>:1:196' */
        /* '<S12>:1:197' */
        i_0 = (int32_T)(((1.0 + (real_T)i) + 1.0) + (real_T)b_j);

        /* '<S12>:1:198' */
        for (j_0 = 0; j_0 < 50; j_0++) {
          tmp1_0[j_0] = ((tmp1[j_0] != 0.0) && (eqtable[(50 * j_0 + i_0) - 1] !=
            0.0));
          tmp2[j_0] = eqtable[(50 * j_0 + i_0) - 1];
        }

        if (QBot2_Image_Proc_Line_Follo_sum(tmp1_0) != 0.0) {
          /* '<S12>:1:200' */
          for (i_0 = 0; i_0 < 50; i_0++) {
            tmp1[i_0] = ((tmp1[i_0] != 0.0) || (tmp2[i_0] != 0.0));
          }
        }

        /* '<S12>:1:196' */
      }

      /* '<S12>:1:203' */
      for (i_0 = 0; i_0 < 50; i_0++) {
        QBot2_Image_Proc_Line_Followi_B.table[i + 50 * i_0] = tmp1[i_0];
      }

      /* '<S12>:1:204' */
      b = (int32_T)((1.0 - ((1.0 + (real_T)i) + 1.0)) + maxlabel);

      /* '<S12>:1:204' */
      for (b_j = 0; b_j < b; b_j++) {
        /* '<S12>:1:204' */
        j = ((1.0 + (real_T)i) + 1.0) + (real_T)b_j;
        if (tmp1[(int32_T)j - 1] == 1.0) {
          /* '<S12>:1:205' */
          /* '<S12>:1:206' */
          idvec[(int32_T)j - 1] = *count;

          /* '<S12>:1:207' */
          j_0 = (int32_T)j;
          j_1 = (int32_T)j;
          for (i_0 = 0; i_0 < 50; i_0++) {
            eqtable[(j_1 + 50 * i_0) - 1] =
              QBot2_Image_Proc_Line_Followi_B.table[(50 * i_0 + j_0) - 1];
          }
        }

        /* '<S12>:1:204' */
      }
    }

    /* '<S12>:1:191' */
  }
}

/* Function for MATLAB Function: '<S1>/find blobs' */
static void QBot2_Image_Proc_Li_label_image(real_T limg[19200], const real_T
  idvec[50], real_T maxlabel)
{
  int32_T i;
  int32_T j;
  real_T tmp;

  /* -------------------------------------------------------------------------- */
  /* '<S12>:1:218' */
  /* '<S12>:1:219' */
  for (i = 0; i < 120; i++) {
    /* '<S12>:1:219' */
    /* '<S12>:1:220' */
    for (j = 0; j < 160; j++) {
      /* '<S12>:1:220' */
      if ((limg[120 * j + i] > 0.0) && (limg[120 * j + i] <= maxlabel)) {
        /* '<S12>:1:221' */
        /*              if count<=255 */
        /*                  Limg(i, j) = uint8(round((255/count)*idvec(Limg(i, j)))); */
        /*              else */
        /* '<S12>:1:225' */
        tmp = rt_roundd_snf(idvec[(int32_T)limg[120 * j + i] - 1]);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            limg[i + 120 * j] = (uint8_T)tmp;
          } else {
            limg[i + 120 * j] = 0.0;
          }
        } else {
          limg[i + 120 * j] = 255.0;
        }

        /*              end */
      }

      /* '<S12>:1:220' */
    }

    /* '<S12>:1:219' */
  }

  /* -------------------------------------------------------------------------- */
}

/* Model output function for TID0 */
void QBot2_Image_Proc_Line_Following_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILRead1_o2[2];
  boolean_T rtb_HILRead1_o3[3];
  real_T rw;
  real_T y;
  real_T X[50];
  real_T Y[50];
  real_T N[50];
  real_T maxN;
  real_T maxNid;
  int32_T L;
  real_T d;
  int32_T c_j;
  int32_T e;
  int8_T rtPrevAction;
  int8_T rtAction;
  int32_T i;
  real_T rw_0;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* set solver stop time */
    if (!(QBot2_Image_Proc_Line_Follow_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                            ((QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH0
        + 1) * QBot2_Image_Proc_Line_Follow_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                            ((QBot2_Image_Proc_Line_Follow_M->Timing.clockTick0
        + 1) * QBot2_Image_Proc_Line_Follow_M->Timing.stepSize0 +
        QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH0 *
        QBot2_Image_Proc_Line_Follow_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    QBot2_Image_Proc_Line_Follow_M->Timing.t[0] = rtsiGetT
      (&QBot2_Image_Proc_Line_Follow_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  RateTransition: '<Root>/Rate Transition1'
     */
    if (QBot2_Image_Proc_Line_Follow_M->Timing.RateInteraction.TID1_2) {
      memcpy(&QBot2_Image_Proc_Line_Followi_B.RateTransition[0],
             &QBot2_Image_Proc_Line_Follow_DW.RateTransition_Buffer0[0], 921600U
             * sizeof(uint8_T));
      QBot2_Image_Proc_Line_Followi_B.RateTransition1 =
        QBot2_Image_Proc_Line_Follow_DW.RateTransition1_Buffer0;
    }

    /* End of RateTransition: '<Root>/Rate Transition' */

    /* Outputs for Enabled SubSystem: '<Root>/ Blob_Detection_and_Tracking (Enabled)' incorporates:
     *  EnablePort: '<S1>/Enable'
     */
    /* Sum: '<Root>/Add' incorporates:
     *  Memory: '<Root>/Memory'
     */
    if (QBot2_Image_Proc_Line_Followi_B.RateTransition1 -
        QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput_p > 0U) {
      /* MATLAB Function: '<S1>/Thresholding' incorporates:
       *  Constant: '<Root>/blue_th'
       *  Constant: '<Root>/green_th'
       *  Constant: '<Root>/red_th'
       *  Selector: '<S10>/Blue'
       *  Selector: '<S10>/Green'
       *  Selector: '<S10>/Red'
       */
      /* MATLAB Function ' Blob_Detection_and_Tracking (Enabled)/Thresholding': '<S11>:1' */
      /*  This block supports the Embedded MATLAB subset. */
      /*  See the help menu for details.  */
      /* '<S11>:1:6' */
      for (i = 0; i < 640; i++) {
        memcpy(&QBot2_Image_Proc_Line_Followi_B.bin[i * 480],
               &QBot2_Image_Proc_Line_Followi_B.RateTransition[i * 480], 480U *
               sizeof(uint8_T));
      }

      QBot2_Image_Proc_Line_Fo_thresh(QBot2_Image_Proc_Line_Followi_B.bin,
        QBot2_Image_Proc_Line_Followi_P.red_th_Value, 1.0);

      /* '<S11>:1:8' */
      for (i = 0; i < 640; i++) {
        memcpy(&QBot2_Image_Proc_Line_Followi_B.green_vec[i * 480],
               &QBot2_Image_Proc_Line_Followi_B.RateTransition[i * 480 + 307200],
               480U * sizeof(uint8_T));
      }

      QBot2_Image_Proc_Line_Fo_thresh(QBot2_Image_Proc_Line_Followi_B.green_vec,
        QBot2_Image_Proc_Line_Followi_P.green_th_Value, 1.0);

      /* '<S11>:1:10' */
      for (i = 0; i < 640; i++) {
        memcpy(&QBot2_Image_Proc_Line_Followi_B.blue_vec[i * 480],
               &QBot2_Image_Proc_Line_Followi_B.RateTransition[i * 480 + 614400],
               480U * sizeof(uint8_T));
      }

      QBot2_Image_Proc_Line_Fo_thresh(QBot2_Image_Proc_Line_Followi_B.blue_vec,
        QBot2_Image_Proc_Line_Followi_P.blue_th_Value, 1.0);

      /* '<S11>:1:12' */
      /* '<S11>:1:13' */
      /* '<S11>:1:14' */
      /*  background = uint8(255*double(not(tmp_blob))); */
      /*  r = uint8(red.*tmp_blob + background); */
      /*  g = uint8(green.*tmp_blob + background); */
      /*  b = uint8(blue.*tmp_blob + background); */
      /* '<S11>:1:21' */
      /* '<S11>:1:22' */
      /* '<S11>:1:23' */
      for (i = 0; i < 307200; i++) {
        QBot2_Image_Proc_Line_Followi_B.bin[i] = (uint8_T)
          (((QBot2_Image_Proc_Line_Followi_B.bin[i] != 0) &&
            (QBot2_Image_Proc_Line_Followi_B.green_vec[i] != 0) &&
            (QBot2_Image_Proc_Line_Followi_B.blue_vec[i] != 0)) * 255U);
      }

      /* End of MATLAB Function: '<S1>/Thresholding' */

      /* MATLAB Function: '<S1>/find blobs' incorporates:
       *  Constant: '<S1>/red_th1'
       */
      /* MATLAB Function ' Blob_Detection_and_Tracking (Enabled)/find blobs': '<S12>:1' */
      /*  This block supports the Embedded MATLAB subset. */
      /*  See the help menu for details.  */
      /* { */
      /* if ROW>120 || COL>160 */
      /*     r = uint8(BIN); */
      /*     g = uint8(BIN); */
      /*     b = uint8(BIN); */
      /*     n = -1; */
      /*     return; */
      /* end */
      /* } */
      /* '<S12>:1:22' */
      memset(&QBot2_Image_Proc_Line_Followi_B.r[0], 0, 19200U * sizeof(uint8_T));

      /* '<S12>:1:24' */
      rw = 0.0;

      /*  for i=dwnsmple+1:dwnsmple:ROW */
      /* '<S12>:1:26' */
      for (i = 0; i < 120; i++) {
        /* '<S12>:1:26' */
        L = i << 2;

        /* '<S12>:1:27' */
        rw++;

        /* '<S12>:1:28' */
        y = 0.0;

        /* '<S12>:1:29' */
        for (e = 0; e < 160; e++) {
          /* '<S12>:1:29' */
          /* '<S12>:1:30' */
          y++;

          /* '<S12>:1:31' */
          QBot2_Image_Proc_Line_Followi_B.r[((int32_T)rw + 120 * ((int32_T)y - 1))
            - 1] = QBot2_Image_Proc_Line_Followi_B.bin[(e << 2) * 480 + L];

          /* '<S12>:1:29' */
        }

        /* '<S12>:1:26' */
      }

      /*  r = uint8(zeros(row, col)); */
      /*  g = uint8(zeros(row, col)); */
      /*  b = uint8(zeros(row, col)); */
      /* '<S12>:1:38' */
      /* '<S12>:1:39' */
      /* '<S12>:1:40' */
      /* '<S12>:1:41' */
      y = -1.0;

      /* count; */
      /*  Bin = double(bin)/255; */
      /*  binsum = sum(Bin(:)); */
      /*  ratio = binsum/(row*col); */
      /*  if ratio<=0.1 */
      /*  Find the 4 or 8 connected reachability matrix */
      /* '<S12>:1:49' */
      QBot2__find_reachability_matrix(QBot2_Image_Proc_Line_Followi_B.r,
        QBot2_Image_Proc_Line_Followi_P.red_th1_Value,
        QBot2_Image_Proc_Line_Followi_B.table2,
        QBot2_Image_Proc_Line_Followi_B.Limg, &rw);
      if (rw >= 1.0) {
        /* '<S12>:1:50' */
        /*  Find equivalent labels */
        /* '<S12>:1:52' */
        QBot2_Image_Proc_Li_updatetable(QBot2_Image_Proc_Line_Followi_B.table2,
          rw, QBot2_Image_Proc_Line_Followi_B.table1);

        /* '<S12>:1:53' */
        /* '<S12>:1:54' */
        /* '<S12>:1:55' */
        QBot2_Image_Proc_L_updatetable2(QBot2_Image_Proc_Line_Followi_B.table1,
          rw, QBot2_Image_Proc_Line_Followi_B.table2);
        for (i = 0; i < 2500; i++) {
          QBot2_Image_Proc_Line_Followi_B.table1_m[i] =
            ((QBot2_Image_Proc_Line_Followi_B.table1[i] != 0.0) ||
             (QBot2_Image_Proc_Line_Followi_B.table2[i] != 0.0));
        }

        QBot2_Image_Proc_L_updatetable3(QBot2_Image_Proc_Line_Followi_B.table1_m,
          rw, X, &y);

        /* '<S12>:1:55' */
        /*       */
        /*          % Label the final image */
        /* '<S12>:1:59' */
        QBot2_Image_Proc_Li_label_image(QBot2_Image_Proc_Line_Followi_B.Limg, X,
          rw);

        /* '<S12>:1:60' */
        for (i = 0; i < 19200; i++) {
          maxN = rt_roundd_snf(QBot2_Image_Proc_Line_Followi_B.Limg[i]);
          if (maxN < 256.0) {
            if (maxN >= 0.0) {
              QBot2_Image_Proc_Line_Followi_B.r[i] = (uint8_T)maxN;
            } else {
              QBot2_Image_Proc_Line_Followi_B.r[i] = 0U;
            }
          } else {
            QBot2_Image_Proc_Line_Followi_B.r[i] = MAX_uint8_T;
          }
        }

        /* '<S12>:1:61' */
        /* '<S12>:1:62' */
      }

      /*      r = uint8(limg); */
      /*      g = uint8(limg); */
      /*      b = uint8(limg); */
      /*  end */
      QBot2_Image_Proc_Line_Followi_B.n = y;

      /* End of MATLAB Function: '<S1>/find blobs' */

      /* MATLAB Function: '<S1>/find centroid1' */
      /* MATLAB Function ' Blob_Detection_and_Tracking (Enabled)/find centroid1': '<S13>:1' */
      /*  This block supports the Embedded MATLAB subset. */
      /*  See the help menu for details.  */
      /* '<S13>:1:6' */
      /* '<S13>:1:7' */
      /* '<S13>:1:8' */
      for (i = 0; i < 307200; i++) {
        QBot2_Image_Proc_Line_Followi_B.cimage[i] =
          QBot2_Image_Proc_Line_Followi_B.bin[i];
        QBot2_Image_Proc_Line_Followi_B.cimage[i + 307200] =
          QBot2_Image_Proc_Line_Followi_B.bin[i];
        QBot2_Image_Proc_Line_Followi_B.cimage[i + 614400] =
          QBot2_Image_Proc_Line_Followi_B.bin[i];
      }

      /* '<S13>:1:10' */
      rw = 320.0;

      /* '<S13>:1:11' */
      y = 520.0;

      /* '<S13>:1:12' */
      if (QBot2_Image_Proc_Line_Followi_B.n > 50.0) {
        /* '<S13>:1:13' */
        /* '<S13>:1:14' */
        rw = 320.0;

        /* '<S13>:1:15' */
        y = 520.0;
      } else {
        /* '<S13>:1:18' */
        /* '<S13>:1:19' */
        /* '<S13>:1:20' */
        memset(&X[0], 0, 50U * sizeof(real_T));
        memset(&Y[0], 0, 50U * sizeof(real_T));
        memset(&N[0], 0, 50U * sizeof(real_T));

        /* '<S13>:1:21' */
        for (L = 0; L < (int32_T)QBot2_Image_Proc_Line_Followi_B.n; L++) {
          /* '<S13>:1:21' */
          /* '<S13>:1:22' */
          for (i = 0; i < 120; i++) {
            /* '<S13>:1:22' */
            /*  for 3/4 of the image (bottom) use 640/4/4:row */
            /* '<S13>:1:23' */
            for (e = 0; e < 149; e++) {
              /* '<S13>:1:23' */
              if (QBot2_Image_Proc_Line_Followi_B.r[(e + 5) * 120 + i] == 1.0 +
                  (real_T)L) {
                /* '<S13>:1:24' */
                /* '<S13>:1:25' */
                X[L] += 6.0 + (real_T)e;

                /* '<S13>:1:26' */
                Y[L] += 1.0 + (real_T)i;

                /* '<S13>:1:27' */
                N[L]++;
              }

              /* '<S13>:1:23' */
            }

            /* '<S13>:1:22' */
          }

          /* '<S13>:1:21' */
        }

        /* '<S13>:1:33' */
        maxN = -1.0;

        /* '<S13>:1:34' */
        maxNid = -1.0;

        /* '<S13>:1:35' */
        for (i = 0; i < (int32_T)QBot2_Image_Proc_Line_Followi_B.n; i++) {
          /* '<S13>:1:35' */
          /* '<S13>:1:36' */
          if (N[i] > maxN) {
            /* '<S13>:1:37' */
            /* '<S13>:1:38' */
            maxN = N[i];

            /* '<S13>:1:39' */
            maxNid = 1.0 + (real_T)i;
          }

          /* '<S13>:1:35' */
        }

        if ((maxN > 0.0) && (N[(int32_T)maxNid - 1] > 20.0)) {
          /* '<S13>:1:43' */
          /* '<S13>:1:44' */
          rw = X[(int32_T)maxNid - 1] / N[(int32_T)maxNid - 1] * 4.0;

          /* '<S13>:1:45' */
          y = Y[(int32_T)maxNid - 1] / N[(int32_T)maxNid - 1] * 4.0;

          /* '<S13>:1:47' */
          if (y - 2.0 < 0.0) {
            maxN = ceil(y - 2.0);
          } else {
            maxN = floor(y - 2.0);
          }

          /* '<S13>:1:47' */
          if (y + 2.0 < 0.0) {
            maxNid = ceil(y + 2.0);
          } else {
            maxNid = floor(y + 2.0);
          }

          i = (int32_T)((1.0 - maxN) + maxNid);

          /* '<S13>:1:47' */
          for (L = 0; L < i; L++) {
            /* '<S13>:1:47' */
            maxNid = maxN + (real_T)L;
            if ((maxNid >= 1.0) && (maxNid <= 480.0)) {
              /* '<S13>:1:48' */
              /* '<S13>:1:49' */
              if (rw - 2.0 < 0.0) {
                d = ceil(rw - 2.0);
              } else {
                d = floor(rw - 2.0);
              }

              /* '<S13>:1:49' */
              if (rw + 2.0 < 0.0) {
                rw_0 = ceil(rw + 2.0);
              } else {
                rw_0 = floor(rw + 2.0);
              }

              e = (int32_T)((1.0 - d) + rw_0);

              /* '<S13>:1:49' */
              for (c_j = 0; c_j < e; c_j++) {
                /* '<S13>:1:49' */
                rw_0 = d + (real_T)c_j;
                if ((rw_0 >= 1.0) && (rw_0 <= 640.0)) {
                  /* '<S13>:1:50' */
                  /* '<S13>:1:51' */
                  QBot2_Image_Proc_Line_Followi_B.cimage[((int32_T)maxNid + 480 *
                    ((int32_T)rw_0 - 1)) - 1] = 0U;

                  /* '<S13>:1:52' */
                  QBot2_Image_Proc_Line_Followi_B.cimage[((int32_T)maxNid + 480 *
                    ((int32_T)rw_0 + 639)) - 1] = 0U;

                  /* '<S13>:1:53' */
                  QBot2_Image_Proc_Line_Followi_B.cimage[((int32_T)maxNid + 480 *
                    ((int32_T)rw_0 + 1279)) - 1] = MAX_uint8_T;
                }

                /* '<S13>:1:49' */
              }
            }

            /* '<S13>:1:47' */
          }
        }

        /* '<S13>:1:61' */
        /* '<S13>:1:62' */
      }

      /* End of MATLAB Function: '<S1>/find centroid1' */

      /* Gain: '<S1>/Gain' */
      /* -------------------------------------------------------------------------- */
      QBot2_Image_Proc_Line_Followi_B.Gain[0] =
        QBot2_Image_Proc_Line_Followi_P.Gain_Gain * rw;
      QBot2_Image_Proc_Line_Followi_B.Gain[1] =
        QBot2_Image_Proc_Line_Followi_P.Gain_Gain * y;
      if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
        srUpdateBC
          (QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab);
      }
    }

    /* End of Sum: '<Root>/Add' */
    /* End of Outputs for SubSystem: '<Root>/ Blob_Detection_and_Tracking (Enabled)' */

    /* S-Function (hil_read_block): '<S19>/HIL Read1' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/QBot_Basic/QBot2_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read
        (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
         &QBot2_Image_Proc_Line_Followi_P.HILRead1_analog_channels, 1U,
         QBot2_Image_Proc_Line_Followi_P.HILRead1_encoder_channels, 2U,
         QBot2_Image_Proc_Line_Followi_P.HILRead1_digital_channels, 3U,
         &QBot2_Image_Proc_Line_Followi_P.HILRead1_other_channels, 1U,
         &QBot2_Image_Proc_Line_Followi_B.HILRead1_o1,
         &QBot2_Image_Proc_Line_Follow_DW.HILRead1_EncoderBuffer[0],
         (t_boolean *)&rtb_HILRead1_o3[0],
         &QBot2_Image_Proc_Line_Followi_B.HILRead1_o4
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] =
          QBot2_Image_Proc_Line_Follow_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] =
          QBot2_Image_Proc_Line_Follow_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S4>/Bias Removal' */
    /* Step: '<S18>/Step: end_time' */
    if (QBot2_Image_Proc_Line_Follow_M->Timing.t[1] <
        QBot2_Image_Proc_Line_Followi_P.BiasRemoval_end_time) {
      y = QBot2_Image_Proc_Line_Followi_P.Stepend_time_Y0;
    } else {
      y = QBot2_Image_Proc_Line_Followi_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S18>/Step: end_time' */

    /* Step: '<S18>/Step: start_time' */
    if (QBot2_Image_Proc_Line_Follow_M->Timing.t[1] <
        QBot2_Image_Proc_Line_Followi_P.BiasRemoval_start_time) {
      maxN = QBot2_Image_Proc_Line_Followi_P.Stepstart_time_Y0;
    } else {
      maxN = QBot2_Image_Proc_Line_Followi_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S18>/Step: start_time' */

    /* Outputs for Enabled SubSystem: '<S18>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S20>/Enable'
     */
    /* Logic: '<S18>/Logical Operator' incorporates:
     *  Logic: '<S18>/Logical Operator1'
     */
    if ((maxN != 0.0) && (!(y != 0.0))) {
      if (!QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
        QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE_h =
          QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S20>/Sum( k=1,n-1, x(k) )' */
        QBot2_Image_Proc_Line_Follow_DW.Sumk1n1xk_DSTATE =
          QBot2_Image_Proc_Line_Followi_P.Sumk1n1xk_InitialCondition;
        QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S24>/Count' incorporates:
       *  Constant: '<S24>/unity'
       *  UnitDelay: '<S24>/Unit Delay'
       */
      QBot2_Image_Proc_Line_Followi_B.Count =
        QBot2_Image_Proc_Line_Followi_P.unity_Value +
        QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE_h;

      /* Sum: '<S20>/Sum' incorporates:
       *  UnitDelay: '<S20>/Sum( k=1,n-1, x(k) )'
       */
      QBot2_Image_Proc_Line_Followi_B.Sum =
        QBot2_Image_Proc_Line_Followi_B.HILRead1_o4 +
        QBot2_Image_Proc_Line_Follow_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S20>/div' */
      QBot2_Image_Proc_Line_Followi_B.div = QBot2_Image_Proc_Line_Followi_B.Sum /
        QBot2_Image_Proc_Line_Followi_B.Count;
      srUpdateBC(QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE) {
        QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S18>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S18>/Enabled Moving Average' */

    /* Sum: '<S18>/Sum' */
    rw = QBot2_Image_Proc_Line_Followi_B.HILRead1_o4 -
      QBot2_Image_Proc_Line_Followi_B.div;

    /* SwitchCase: '<S18>/Switch Case' incorporates:
     *  Constant: '<S21>/Constant'
     *  Inport: '<S22>/Vin'
     *  Inport: '<S23>/V-Vavg'
     */
    rtPrevAction = QBot2_Image_Proc_Line_Follow_DW.SwitchCase_ActiveSubsystem;
    rtAction = -1;
    if (QBot2_Image_Proc_Line_Followi_P.BiasRemoval_switch_id < 0.0) {
      maxN = ceil(QBot2_Image_Proc_Line_Followi_P.BiasRemoval_switch_id);
    } else {
      maxN = floor(QBot2_Image_Proc_Line_Followi_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(maxN) || rtIsInf(maxN)) {
      maxN = 0.0;
    } else {
      maxN = fmod(maxN, 4.294967296E+9);
    }

    switch (maxN < 0.0 ? -(int32_T)(uint32_T)-maxN : (int32_T)(uint32_T)maxN) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    QBot2_Image_Proc_Line_Follow_DW.SwitchCase_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S21>/zero' incorporates:
         *  Outport: '<S21>/zero'
         */
        QBot2_Image_Proc_Line_Followi_B.Constant_c =
          QBot2_Image_Proc_Line_Followi_P.zero_Y0;
        break;

       case 1:
        /* Disable for Outport: '<S22>/Vbiased' incorporates:
         *  Outport: '<S22>/Vbiased'
         */
        QBot2_Image_Proc_Line_Followi_B.Vin =
          QBot2_Image_Proc_Line_Followi_P.Vbiased_Y0;
        break;

       case 2:
        /* Disable for Outport: '<S23>/Vunbiased' incorporates:
         *  Outport: '<S23>/Vunbiased'
         */
        QBot2_Image_Proc_Line_Followi_B.VVavg =
          QBot2_Image_Proc_Line_Followi_P.Vunbiased_Y0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S18>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      QBot2_Image_Proc_Line_Followi_B.Constant_c =
        QBot2_Image_Proc_Line_Followi_P.Constant_Value;
      srUpdateBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem_Subsy);

      /* End of Outputs for SubSystem: '<S18>/Switch Case Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S18>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      QBot2_Image_Proc_Line_Followi_B.Vin =
        QBot2_Image_Proc_Line_Followi_B.HILRead1_o4;
      srUpdateBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S18>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S18>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      QBot2_Image_Proc_Line_Followi_B.VVavg = rw;
      srUpdateBC(QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S18>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S18>/Switch Case' */

    /* Switch: '<S18>/Switch' incorporates:
     *  Logic: '<S18>/Logical Operator2'
     *  Sum: '<S18>/Sum1'
     */
    if (!(y != 0.0)) {
      rw = (QBot2_Image_Proc_Line_Followi_B.Constant_c +
            QBot2_Image_Proc_Line_Followi_B.Vin) +
        QBot2_Image_Proc_Line_Followi_B.VVavg;
    }

    /* End of Switch: '<S18>/Switch' */
    /* End of Outputs for SubSystem: '<S4>/Bias Removal' */

    /* Product: '<S4>/Product' */
    QBot2_Image_Proc_Line_Followi_B.Product = rw * y;

    /* MATLAB Function: '<S9>/Way Point Control' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Constant: '<Root>/Constant12'
     *  Constant: '<Root>/Constant13'
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     *  Constant: '<Root>/Constant6'
     *  Constant: '<Root>/Constant7'
     *  Constant: '<Root>/Constant8'
     *  Constant: '<Root>/Constant9'
     *  Memory: '<S9>/Memory'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    /* MATLAB Function 'Trajectory control (Way-points from Kinect Camera Image)/Way Point Control': '<S30>:1' */
    /*  Initialize output variables */
    /* robot_xyt=[robot_xyt(2);robot_xyt(1);robot_xyt(3)] /1000; % estimate of robot xy from pixel location */
    /* target_list = [target_list(2) target_list(1)] /1000; % estimate of target xy from target in pixels */
    /* '<S30>:1:11' */
    QBot2_Image_Proc_Line_Followi_B.Vf = 0.0;

    /* '<S30>:1:12' */
    QBot2_Image_Proc_Line_Followi_B.W = 0.0;

    /* '<S30>:1:23' */
    y = QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput;

    /* '<S30>:1:25' */
    /* '<S30>:1:26' */
    /* '<S30>:1:27' */
    /* -------------------------------------------------------------------------- */
    /* '<S30>:1:112' */
    rw = QBot2_Image_Proc_Line_Followi_P.Constant2_Value[2];
    if (QBot2_Image_Proc_Line_Followi_P.Constant2_Value[2] > 3.1415926535897931)
    {
      /* '<S30>:1:113' */
      /* '<S30>:1:114' */
      rw = QBot2_Image_Proc_Line_Followi_P.Constant2_Value[2] -
        6.2831853071795862;
    } else {
      if (QBot2_Image_Proc_Line_Followi_P.Constant2_Value[2] <
          -3.1415926535897931) {
        /* '<S30>:1:115' */
        /* '<S30>:1:116' */
        rw = QBot2_Image_Proc_Line_Followi_P.Constant2_Value[2] +
          6.2831853071795862;
      }
    }

    /* '<S30>:1:31' */
    /* '<S30>:1:32' */
    /* '<S30>:1:43' */
    /* '<S30>:1:44' */
    /* '<S30>:1:45' */
    /*  ------------------------------------------------------------------------- */
    /* '<S30>:1:121' */
    maxN = QBot2_Image_Proc_Line_Followi_P.Constant2_Value[1] -
      QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[1];
    maxNid = QBot2_Image_Proc_Line_Followi_P.Constant2_Value[0] -
      QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0];

    /* '<S30>:1:46' */
    maxN = sqrt(maxN * maxN + maxNid * maxNid) / 1000.0;

    /*  ang_to_tar= find_theta(rx, ry, rtheta, tx, ty); */
    /*  for image  */
    /* '<S30>:1:51' */
    /* '<S30>:1:52' */
    maxNid = (QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0] -
              QBot2_Image_Proc_Line_Followi_P.Constant2_Value[0]) * -0.005;

    /* '<S30>:1:53' */
    /* -------------------------------------------------------------------------- */
    /* '<S30>:1:112' */
    if (maxNid > 3.1415926535897931) {
      /* '<S30>:1:113' */
      /* '<S30>:1:114' */
      maxNid -= 6.2831853071795862;
    } else {
      if (maxNid < -3.1415926535897931) {
        /* '<S30>:1:115' */
        /* '<S30>:1:116' */
        maxNid += 6.2831853071795862;
      }
    }

    /* -------------------------------------------------------------------------- */
    /* '<S30>:1:112' */
    if (rw > 3.1415926535897931) {
      /* '<S30>:1:113' */
      /* '<S30>:1:114' */
      rw -= 6.2831853071795862;
    } else {
      if (rw < -3.1415926535897931) {
        /* '<S30>:1:115' */
        /* '<S30>:1:116' */
        rw += 6.2831853071795862;
      }
    }

    rw = maxNid - rw;

    /* -------------------------------------------------------------------------- */
    /* '<S30>:1:112' */
    if (rw > 3.1415926535897931) {
      /* '<S30>:1:113' */
      /* '<S30>:1:114' */
      rw -= 6.2831853071795862;
    } else {
      if (rw < -3.1415926535897931) {
        /* '<S30>:1:115' */
        /* '<S30>:1:116' */
        rw += 6.2831853071795862;
      }
    }

    if ((QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput == 1.0) && (maxN <=
         QBot2_Image_Proc_Line_Followi_P.Constant4_Value)) {
      /* '<S30>:1:56' */
      /* || states(1) == -1 */
      /*  %        states(1) = -1; */
      /*  right_vel = int16(0); */
      /*  left_vel = int16(0); */
      /*   %       target_distance = 0; */
      /* '<S30>:1:61' */
      QBot2_Image_Proc_Line_Followi_B.Vf = 0.0;

      /* '<S30>:1:62' */
      QBot2_Image_Proc_Line_Followi_B.W = 0.0;

      /* if (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d  */
      /*      [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1);  */
      /*       Vf_1=Vf; */
      /* end */
    } else if ((maxN <= QBot2_Image_Proc_Line_Followi_P.Constant4_Value) &&
               (QBot2_Image_Proc_Line_Follow_DW.end_flag == 0.0)) {
      /* '<S30>:1:72' */
      /* '<S30>:1:73' */
      y = QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput +
        QBot2_Image_Proc_Line_Followi_P.Constant13_Value;

      /* 1; */
      while ((fabs(QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0] -
                   QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0]) < 2.0 *
              QBot2_Image_Proc_Line_Followi_P.Constant4_Value) && (fabs
              (QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[1] -
               QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[1]) < 2.0 *
              QBot2_Image_Proc_Line_Followi_P.Constant4_Value)) {
        /* '<S30>:1:75' */
        if (y <= 1.0 - QBot2_Image_Proc_Line_Followi_P.Constant13_Value) {
          /* '<S30>:1:76' */
          /* '<S30>:1:77' */
          y += QBot2_Image_Proc_Line_Followi_P.Constant13_Value;

          /* 1; */
        } else {
          /* '<S30>:1:79' */
          y = 1.0;
        }
      }

      if (y >= 1.0) {
        /* '<S30>:1:84' */
        /* '<S30>:1:85' */
        y = 1.0;

        /* '<S30>:1:86' */
        QBot2_Image_Proc_Line_Follow_DW.end_flag = 1.0;
      }

      /*   elseif (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d  */
      /*           [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1);  */
      /*            Vf_1=Vf; */
    } else if (QBot2_Image_Proc_Line_Followi_P.Constant12_Value == 2.0) {
      /* '<S30>:1:96' */
      /* '<S30>:1:97' */
      /*  ------------------------------------------------------------------------- */
      /* '<S30>:1:138' */
      maxNid = 2.0 * QBot2_Image_Proc_Line_Followi_P.Constant5_Value;

      /* '<S30>:1:139' */
      rw *= QBot2_Image_Proc_Line_Followi_P.Constant9_Value;

      /* if abs(theta)<pi */
      /* '<S30>:1:142' */
      maxN *= QBot2_Image_Proc_Line_Followi_P.Constant8_Value;

      /* else */
      /*     Vf=0; */
      /* end */
      /* '<S30>:1:147' */
      if (fabs(rw) > maxNid) {
        /* '<S30>:1:148' */
        /* '<S30>:1:149' */
        if (rw < 0.0) {
          rw = -1.0;
        } else if (rw > 0.0) {
          rw = 1.0;
        } else {
          if (rw == 0.0) {
            rw = 0.0;
          }
        }

        rw *= maxNid;
      }

      if (fabs(maxN) > QBot2_Image_Proc_Line_Followi_P.Constant5_Value) {
        /* '<S30>:1:151' */
        /* '<S30>:1:152' */
        maxN = fabs(maxN) * QBot2_Image_Proc_Line_Followi_P.Constant5_Value;
      }

      /* '<S30>:1:97' */
      QBot2_Image_Proc_Line_Followi_B.Vf = maxN;

      /* '<S30>:1:97' */
      QBot2_Image_Proc_Line_Followi_B.W = rw;
    } else {
      /*             [right_vel, left_vel] = rotate_and_go(ang_to_tar, vlimit, ang_thr); */
      /* '<S30>:1:100' */
      /* '<S30>:1:161' */
      maxNid = 2.0 * QBot2_Image_Proc_Line_Followi_P.Constant5_Value;
      if (((fabs(rw) > QBot2_Image_Proc_Line_Followi_P.Constant7_Value) &&
           (QBot2_Image_Proc_Line_Follow_DW.Vf_1 < 0.01)) || (fabs(rw) > 5.0 *
           QBot2_Image_Proc_Line_Followi_P.Constant7_Value)) {
        /* '<S30>:1:163' */
        /*  once rotated, then moves. once started moving, it won't turn unless the heading is too off target or have reached the previous target. */
        /* '<S30>:1:164' */
        d = QBot2_Image_Proc_Line_Followi_P.Constant6_Value * rw;

        /* '<S30>:1:165' */
        maxN = 0.0;
        if (fabs(d) > maxNid) {
          /* '<S30>:1:166' */
          /* '<S30>:1:167' */
          if (rw < 0.0) {
            rw = -1.0;
          } else if (rw > 0.0) {
            rw = 1.0;
          } else {
            if (rw == 0.0) {
              rw = 0.0;
            }
          }

          d = rw * maxNid;
        }
      } else {
        /* '<S30>:1:170' */
        maxN *= QBot2_Image_Proc_Line_Followi_P.Constant10_Value;
        if (fabs(maxN) > QBot2_Image_Proc_Line_Followi_P.Constant5_Value) {
          /* '<S30>:1:172' */
          /* '<S30>:1:173' */
          if (maxN < 0.0) {
            maxN = -1.0;
          } else if (maxN > 0.0) {
            maxN = 1.0;
          } else {
            if (maxN == 0.0) {
              maxN = 0.0;
            }
          }

          maxN *= QBot2_Image_Proc_Line_Followi_P.Constant5_Value;
        }

        /*  if (abs(theta) > 2*ang_thr) */
        /*    W=Kw*theta; */
        /*    Vf=0.4*Vf; */
        /*  else */
        /* '<S30>:1:179' */
        d = 0.0;

        /*  end */
        /*  if abs(W)> wmax */
        /*      W=sign(theta)*wmax; */
        /*  end */
      }

      /* { */
      /* function [vr, vl] = solve_inv_kin(dist, theta, vlimit, delta_t) */
      /*  */
      /* d = 0.23; */
      /* vmax = vlimit(2); */
      /* wmax = (2*vmax)/d; */
      /* w = theta/delta_t; */
      /* w_sign = sign(w); */
      /* if abs(w) > wmax */
      /*     w = w_sign*wmax; */
      /*     vr = int16(round((d*w)/2)); */
      /*     vl = int16(-vr); */
      /* else */
      /*     v = dist/delta_t; */
      /*     vr_tmp = (2*v + d*w)/2; */
      /*     vl_tmp = 2*v - vr_tmp; */
      /*      */
      /*     max_of_vrvl = abs(max(vr_tmp, vl_tmp)); */
      /*     if max_of_vrvl > vmax */
      /*         vr_tmp = (vr_tmp/max_of_vrvl)*vmax; */
      /*         vl_tmp = (vl_tmp/max_of_vrvl)*vmax; */
      /*     end */
      /*     vr = int16(vr_tmp); */
      /*     vl = int16(vl_tmp); */
      /*  */
      /* end */
      /*  */
      /* return; */
      /* } */
      /* { */
      /*  ------------------------------------------------------------------------- */
      /* function [vr, vl] = rotate_and_go(theta, vlimit, ang_thr) */
      /*  */
      /* if abs(theta) > ang_thr */
      /*     if theta >= 0 */
      /*         vr = int16(vlimit(1)); */
      /*         vl = int16(-vlimit(1)); */
      /*     else */
      /*         vr = int16(-vlimit(1)); */
      /*         vl = int16(vlimit(1)); */
      /*     end */
      /* else */
      /*         vr = int16(vlimit(2)); */
      /*         vl = int16(vlimit(2)); */
      /* end */
      /*  */
      /* return; */
      /*  ------------------------------------------------------------------------- */
      /* } */
      /* '<S30>:1:100' */
      QBot2_Image_Proc_Line_Followi_B.Vf = maxN;

      /* '<S30>:1:100' */
      QBot2_Image_Proc_Line_Followi_B.W = d;

      /* '<S30>:1:101' */
      QBot2_Image_Proc_Line_Follow_DW.Vf_1 = maxN;
    }

    QBot2_Image_Proc_Line_Followi_B.states = y;

    /* End of MATLAB Function: '<S9>/Way Point Control' */
  }

  /* Integrator: '<S5>/Integrator1' */
  QBot2_Image_Proc_Line_Followi_B.Integrator1 =
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE;

  /* Integrator: '<S5>/Integrator2' */
  QBot2_Image_Proc_Line_Followi_B.Integrator2 =
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE;

  /* Integrator: '<S5>/Integrator3' */
  QBot2_Image_Proc_Line_Followi_B.Integrator3 =
    QBot2_Image_Proc_Line_Followi_X.Integrator3_CSTATE;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* Gain: '<S14>/mm to m' incorporates:
     *  Gain: '<S14>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S14>/ticks to encoder rotation'
     *  Gain: '<S14>/wheel radious (mm)'
     */
    QBot2_Image_Proc_Line_Followi_B.mmtom =
      QBot2_Image_Proc_Line_Followi_P.tickstoencoderrotation_Gain *
      rtb_HILRead1_o2[0] *
      QBot2_Image_Proc_Line_Followi_P.encoderrotationtowheelrotationg *
      QBot2_Image_Proc_Line_Followi_P.wheelradiousmm_Gain *
      QBot2_Image_Proc_Line_Followi_P.mmtom_Gain;

    /* Constant: '<S15>/Constant' */
    QBot2_Image_Proc_Line_Followi_B.Constant =
      QBot2_Image_Proc_Line_Followi_P.Constant_Value_g;

    /* Constant: '<S15>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0 =
      QBot2_Image_Proc_Line_Followi_P.x0_Value;

    /* Constant: '<S15>/wn' */
    QBot2_Image_Proc_Line_Followi_B.wn =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_input;

    /* Constant: '<S15>/zt' */
    QBot2_Image_Proc_Line_Followi_B.zt =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_f;
  }

  /* Integrator: '<S15>/Integrator1' */
  if (QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK != 0) {
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_p =
      QBot2_Image_Proc_Line_Followi_B.x0;
  }

  /* Product: '<S15>/Product' incorporates:
   *  Integrator: '<S15>/Integrator1'
   *  Integrator: '<S15>/Integrator2'
   *  Product: '<S15>/Product2'
   *  Sum: '<S15>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  QBot2_Image_Proc_Line_Followi_B.Product_b =
    ((QBot2_Image_Proc_Line_Followi_B.mmtom -
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_p) -
     QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_p *
     QBot2_Image_Proc_Line_Followi_B.Constant *
     QBot2_Image_Proc_Line_Followi_B.zt) * QBot2_Image_Proc_Line_Followi_B.wn;

  /* Product: '<S15>/Product1' incorporates:
   *  Integrator: '<S15>/Integrator2'
   */
  QBot2_Image_Proc_Line_Followi_B.Product1 = QBot2_Image_Proc_Line_Followi_B.wn *
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_p;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* Gain: '<S16>/mm to m' incorporates:
     *  Gain: '<S16>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S16>/ticks to encoder rotation'
     *  Gain: '<S16>/wheel radious (mm)'
     */
    QBot2_Image_Proc_Line_Followi_B.mmtom_a =
      QBot2_Image_Proc_Line_Followi_P.tickstoencoderrotation_Gain_f *
      rtb_HILRead1_o2[1] *
      QBot2_Image_Proc_Line_Followi_P.encoderrotationtowheelrotatio_d *
      QBot2_Image_Proc_Line_Followi_P.wheelradiousmm_Gain_d *
      QBot2_Image_Proc_Line_Followi_P.mmtom_Gain_c;

    /* Constant: '<S17>/Constant' */
    QBot2_Image_Proc_Line_Followi_B.Constant_n =
      QBot2_Image_Proc_Line_Followi_P.Constant_Value_m;

    /* Constant: '<S17>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_g =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_n;

    /* Constant: '<S17>/wn' */
    QBot2_Image_Proc_Line_Followi_B.wn_d =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_n;

    /* Constant: '<S17>/zt' */
    QBot2_Image_Proc_Line_Followi_B.zt_m =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter2_inp_l;
  }

  /* Integrator: '<S17>/Integrator1' */
  if (QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_b != 0) {
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_l =
      QBot2_Image_Proc_Line_Followi_B.x0_g;
  }

  /* Product: '<S17>/Product' incorporates:
   *  Integrator: '<S17>/Integrator1'
   *  Integrator: '<S17>/Integrator2'
   *  Product: '<S17>/Product2'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S17>/Sum1'
   */
  QBot2_Image_Proc_Line_Followi_B.Product_k =
    ((QBot2_Image_Proc_Line_Followi_B.mmtom_a -
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_l) -
     QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_a *
     QBot2_Image_Proc_Line_Followi_B.Constant_n *
     QBot2_Image_Proc_Line_Followi_B.zt_m) *
    QBot2_Image_Proc_Line_Followi_B.wn_d;

  /* Product: '<S17>/Product1' incorporates:
   *  Integrator: '<S17>/Integrator2'
   */
  QBot2_Image_Proc_Line_Followi_B.Product1_g =
    QBot2_Image_Proc_Line_Followi_B.wn_d *
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant3'
     */
    if (QBot2_Image_Proc_Line_Followi_P.ManualSwitch_CurrentSetting == 1) {
      QBot2_Image_Proc_Line_Followi_B.ManualSwitch =
        QBot2_Image_Proc_Line_Followi_P.Constant3_Value;
    } else {
      QBot2_Image_Proc_Line_Followi_B.ManualSwitch =
        QBot2_Image_Proc_Line_Followi_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Constant: '<S7>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_j =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_j;
  }

  /* Integrator: '<S7>/Integrator1' */
  if (QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_a != 0) {
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_o =
      QBot2_Image_Proc_Line_Followi_B.x0_j;
  }

  /* Product: '<Root>/Product1' incorporates:
   *  Integrator: '<S7>/Integrator1'
   */
  rw = QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_o *
    QBot2_Image_Proc_Line_Followi_B.ManualSwitch;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* Constant: '<S8>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_e =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_e;
  }

  /* Integrator: '<S8>/Integrator1' */
  if (QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_bz != 0) {
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_lo =
      QBot2_Image_Proc_Line_Followi_B.x0_e;
  }

  /* Product: '<Root>/Product2' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  y = QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_lo *
    QBot2_Image_Proc_Line_Followi_B.ManualSwitch;

  /* MATLAB Function: '<S6>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  /* MATLAB Function 'Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)': '<S29>:1' */
  /* '<S29>:1:4' */
  /*  Eqn Based on the eqn 4.52 (W is the angular velocity) */
  /* '<S29>:1:7' */
  QBot2_Image_Proc_Line_Followi_B.vR = y * 0.235 / 2.0 + rw;

  /* '<S29>:1:8' */
  QBot2_Image_Proc_Line_Followi_B.vL = rw - y * 0.235 / 2.0;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* S-Function (hil_write_block): '<S19>/HIL Write' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/QBot_Basic/QBot2_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      QBot2_Image_Proc_Line_Follow_DW.HILWrite_OtherBuffer[0] =
        QBot2_Image_Proc_Line_Followi_B.vR;
      QBot2_Image_Proc_Line_Follow_DW.HILWrite_OtherBuffer[1] =
        QBot2_Image_Proc_Line_Followi_B.vL;
      result = hil_write(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         QBot2_Image_Proc_Line_Followi_P.HILWrite_other_channels,
                         2U,
                         NULL,
                         NULL,
                         NULL,
                         &QBot2_Image_Proc_Line_Follow_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
      }
    }

    /* Constant: '<S7>/Constant' */
    QBot2_Image_Proc_Line_Followi_B.Constant_g =
      QBot2_Image_Proc_Line_Followi_P.Constant_Value_b;

    /* Constant: '<S7>/wn' */
    QBot2_Image_Proc_Line_Followi_B.wn_a =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter_input_;

    /* Constant: '<S7>/zt' */
    QBot2_Image_Proc_Line_Followi_B.zt_i =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter_inpu_b;
  }

  /* MATLAB Function: '<S25>/Qbot2_Diff_Drive_Kinematics' */
  /* MATLAB Function 'Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics': '<S27>:1' */
  /* '<S27>:1:6' */
  rw = (QBot2_Image_Proc_Line_Followi_B.Product1_g +
        QBot2_Image_Proc_Line_Followi_B.Product1) * 0.5;

  /* '<S27>:1:7' */
  QBot2_Image_Proc_Line_Followi_B.Omega =
    (QBot2_Image_Proc_Line_Followi_B.Product1 -
     QBot2_Image_Proc_Line_Followi_B.Product1_g) * 4.25531914893617;

  /* MATLAB Function: '<S26>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' incorporates:
   *  Integrator: '<S26>/Integrator'
   */
  /* MATLAB Function 'Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)': '<S28>:1' */
  /* '<S28>:1:5' */
  QBot2_Image_Proc_Line_Followi_B.x_dot = cos
    (QBot2_Image_Proc_Line_Followi_X.Integrator_CSTATE) * rw;

  /* '<S28>:1:6' */
  QBot2_Image_Proc_Line_Followi_B.y_dot = sin
    (QBot2_Image_Proc_Line_Followi_X.Integrator_CSTATE) * rw;

  /* '<S28>:1:7' */
  QBot2_Image_Proc_Line_Followi_B.psi_dot =
    QBot2_Image_Proc_Line_Followi_B.Omega;

  /* Product: '<S7>/Product' incorporates:
   *  Integrator: '<S7>/Integrator1'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  QBot2_Image_Proc_Line_Followi_B.Product_d =
    ((QBot2_Image_Proc_Line_Followi_B.Vf -
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_o) -
     QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_o *
     QBot2_Image_Proc_Line_Followi_B.Constant_g *
     QBot2_Image_Proc_Line_Followi_B.zt_i) *
    QBot2_Image_Proc_Line_Followi_B.wn_a;

  /* Product: '<S7>/Product1' incorporates:
   *  Integrator: '<S7>/Integrator2'
   */
  QBot2_Image_Proc_Line_Followi_B.Product1_b =
    QBot2_Image_Proc_Line_Followi_B.wn_a *
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_o;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* Constant: '<S8>/Constant' */
    QBot2_Image_Proc_Line_Followi_B.Constant_i =
      QBot2_Image_Proc_Line_Followi_P.Constant_Value_o;

    /* Constant: '<S8>/wn' */
    QBot2_Image_Proc_Line_Followi_B.wn_h =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter1_input;

    /* Constant: '<S8>/zt' */
    QBot2_Image_Proc_Line_Followi_B.zt_o =
      QBot2_Image_Proc_Line_Followi_P.SecondOrderLowPassFilter1_inp_b;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Integrator: '<S8>/Integrator1'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  QBot2_Image_Proc_Line_Followi_B.Product_p =
    ((QBot2_Image_Proc_Line_Followi_B.W -
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_lo) -
     QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_m *
     QBot2_Image_Proc_Line_Followi_B.Constant_i *
     QBot2_Image_Proc_Line_Followi_B.zt_o) *
    QBot2_Image_Proc_Line_Followi_B.wn_h;

  /* Product: '<S8>/Product1' incorporates:
   *  Integrator: '<S8>/Integrator2'
   */
  QBot2_Image_Proc_Line_Followi_B.Product1_j =
    QBot2_Image_Proc_Line_Followi_B.wn_h *
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_m;
}

/* Model update function for TID0 */
void QBot2_Image_Proc_Line_Following_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    /* Update for Memory: '<Root>/Memory' */
    QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput_p =
      QBot2_Image_Proc_Line_Followi_B.RateTransition1;

    /* Update for Atomic SubSystem: '<S4>/Bias Removal' */
    /* Update for Enabled SubSystem: '<S18>/Enabled Moving Average' incorporates:
     *  Update for EnablePort: '<S20>/Enable'
     */
    if (QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE) {
      /* Update for UnitDelay: '<S24>/Unit Delay' */
      QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE_h =
        QBot2_Image_Proc_Line_Followi_B.Count;

      /* Update for UnitDelay: '<S20>/Sum( k=1,n-1, x(k) )' */
      QBot2_Image_Proc_Line_Follow_DW.Sumk1n1xk_DSTATE =
        QBot2_Image_Proc_Line_Followi_B.Sum;
    }

    /* End of Update for SubSystem: '<S18>/Enabled Moving Average' */
    /* End of Update for SubSystem: '<S4>/Bias Removal' */

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0] =
      QBot2_Image_Proc_Line_Followi_B.Gain[0];
    QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[1] =
      QBot2_Image_Proc_Line_Followi_B.Gain[1];

    /* Update for Memory: '<S9>/Memory' */
    QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput =
      QBot2_Image_Proc_Line_Followi_B.states;
  }

  /* Update for Integrator: '<S15>/Integrator1' */
  QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S17>/Integrator1' */
  QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_b = 0;

  /* Update for Integrator: '<S7>/Integrator1' */
  QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_a = 0;

  /* Update for Integrator: '<S8>/Integrator1' */
  QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_bz = 0;
  if (rtmIsMajorTimeStep(QBot2_Image_Proc_Line_Follow_M)) {
    rt_ertODEUpdateContinuousStates(&QBot2_Image_Proc_Line_Follow_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2_Image_Proc_Line_Follow_M->Timing.clockTick0)) {
    ++QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH0;
  }

  QBot2_Image_Proc_Line_Follow_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QBot2_Image_Proc_Line_Follow_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2_Image_Proc_Line_Follow_M->Timing.clockTick1)) {
    ++QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH1;
  }

  QBot2_Image_Proc_Line_Follow_M->Timing.t[1] =
    QBot2_Image_Proc_Line_Follow_M->Timing.clockTick1 *
    QBot2_Image_Proc_Line_Follow_M->Timing.stepSize1 +
    QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH1 *
    QBot2_Image_Proc_Line_Follow_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void QBot2_Image_Proc_Line_Following_derivatives(void)
{
  XDot_QBot2_Image_Proc_Line_Fo_T *_rtXdot;
  _rtXdot = ((XDot_QBot2_Image_Proc_Line_Fo_T *)
             QBot2_Image_Proc_Line_Follow_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = QBot2_Image_Proc_Line_Followi_B.psi_dot;

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = QBot2_Image_Proc_Line_Followi_B.x_dot;

  /* Derivatives for Integrator: '<S5>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = QBot2_Image_Proc_Line_Followi_B.y_dot;

  /* Derivatives for Integrator: '<S15>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = QBot2_Image_Proc_Line_Followi_B.Product1;

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_p = QBot2_Image_Proc_Line_Followi_B.Product_b;

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_l = QBot2_Image_Proc_Line_Followi_B.Product1_g;

  /* Derivatives for Integrator: '<S17>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = QBot2_Image_Proc_Line_Followi_B.Product_k;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_o = QBot2_Image_Proc_Line_Followi_B.Product1_b;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_lo = QBot2_Image_Proc_Line_Followi_B.Product1_j;

  /* Derivatives for Integrator: '<S26>/Integrator' */
  _rtXdot->Integrator_CSTATE = QBot2_Image_Proc_Line_Followi_B.Omega;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = QBot2_Image_Proc_Line_Followi_B.Product_d;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_m = QBot2_Image_Proc_Line_Followi_B.Product_p;
}

/* Model output function for TID2 */
void QBot2_Image_Proc_Line_Following_output2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_KinectGetImage_o3;
  int32_T rtb_KinectInitialize;

  /* S-Function (kinect_initialize_block): '<Root>/Kinect Initialize' */

  /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Initialize (kinect_initialize_block) */
  {
    rtb_KinectInitialize = kinect_get_status
      (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect);
  }

  /* S-Function (kinect_get_image_block): '<Root>/Kinect Get Image' */

  /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Get Image (kinect_get_image_block) */
  {
    t_error result;
    result = kinect_get_color_image
      (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
       IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
       &QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o1[0],
       &QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o2,
       &rtb_KinectGetImage_o3);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
    }
  }
}

/* Model update function for TID2 */
void QBot2_Image_Proc_Line_Following_update2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Update for RateTransition: '<Root>/Rate Transition' */
  memcpy(&QBot2_Image_Proc_Line_Follow_DW.RateTransition_Buffer0[0],
         &QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o1[0], 921600U * sizeof
         (uint8_T));

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  QBot2_Image_Proc_Line_Follow_DW.RateTransition1_Buffer0 =
    QBot2_Image_Proc_Line_Followi_B.KinectGetImage_o2;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2_Image_Proc_Line_Follow_M->Timing.clockTick2)) {
    ++QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH2;
  }

  QBot2_Image_Proc_Line_Follow_M->Timing.t[2] =
    QBot2_Image_Proc_Line_Follow_M->Timing.clockTick2 *
    QBot2_Image_Proc_Line_Follow_M->Timing.stepSize2 +
    QBot2_Image_Proc_Line_Follow_M->Timing.clockTickH2 *
    QBot2_Image_Proc_Line_Follow_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void QBot2_Image_Proc_Line_Following_output(int_T tid)
{
  switch (tid) {
   case 0 :
    QBot2_Image_Proc_Line_Following_output0();
    break;

   case 2 :
    QBot2_Image_Proc_Line_Following_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void QBot2_Image_Proc_Line_Following_update(int_T tid)
{
  switch (tid) {
   case 0 :
    QBot2_Image_Proc_Line_Following_update0();
    break;

   case 2 :
    QBot2_Image_Proc_Line_Following_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void QBot2_Image_Proc_Line_Following_initialize(void)
{
  {
    int32_T i;

    /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("qbot2", "0",
                        &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
        return;
      }

      is_switching = false;
      result = hil_set_card_specific_options
        (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
         "enc0_dir=0;enc0_filter=1;enc0_a=0;enc0_b=0;enc0_z=1;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=0;enc1_b=0;enc1_z=1;enc1_reload=0;pwm0_immediate=0;pwm1_immediate=0;pwm2_immediate=0;pwm3_immediate=0;",
         201);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
        return;
      }

      result = hil_watchdog_clear
        (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
        return;
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_input_ &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_analog_inpu_m &&
           is_switching)) {
        {
          int_T i1;
          const real_T *p_HILInitialize_analog_input_mini =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_mini;
          real_T *dw_AIMinimums =
            &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMinimums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AIMinimums[i1] = p_HILInitialize_analog_input_mini[i1];
          }
        }

        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMinimums[8] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_mini[8];
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMinimums[9] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_mini[8];

        {
          int_T i1;
          const real_T *p_HILInitialize_analog_input_maxi =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_maxi;
          real_T *dw_AIMaximums =
            &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMaximums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AIMaximums[i1] = p_HILInitialize_analog_input_maxi[i1];
          }
        }

        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMaximums[8] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_maxi[8];
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMaximums[9] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_maxi[8];
        result = hil_set_analog_input_ranges
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_analog_input_chan, 10U,
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMinimums[0],
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_param &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_par_k &&
           is_switching)) {
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_quadrature;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_quadrature;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_quadrature;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_quadrature;
        result = hil_set_encoder_quadrature_mode
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_encoder_channels, 4U,
           (t_encoder_quadrature_mode *)
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_count &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_encoder_cou_k &&
           is_switching)) {
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_encoder_c;
        result = hil_set_encoder_counts
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_encoder_channels, 4U,
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_params_at &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_params__b &&
           is_switching)) {
        uint32_T num_duty_cycle_modes = 0;
        uint32_T num_frequency_modes = 0;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_modes;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_modes;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_modes;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_modes;
        result = hil_set_pwm_mode
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels, 4U,
           (t_pwm_mode *)
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }

        if (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0] ==
            PWM_DUTY_CYCLE_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0] ==
            PWM_ONE_SHOT_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0] ==
            PWM_TIME_MODE) {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[0];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_duty_cycle_modes++;
        } else {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[0];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_frequency_modes++;
        }

        if (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[1] ==
            PWM_DUTY_CYCLE_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[1] ==
            PWM_ONE_SHOT_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[1] ==
            PWM_TIME_MODE) {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[1];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_duty_cycle_modes++;
        } else {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[1];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_frequency_modes++;
        }

        if (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[2] ==
            PWM_DUTY_CYCLE_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[2] ==
            PWM_ONE_SHOT_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[2] ==
            PWM_TIME_MODE) {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[2];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_duty_cycle_modes++;
        } else {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[2];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_frequency_modes++;
        }

        if (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[3] ==
            PWM_DUTY_CYCLE_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[3] ==
            PWM_ONE_SHOT_MODE ||
            QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[3] ==
            PWM_TIME_MODE) {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[3];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
            = QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_duty_cycle_modes++;
        } else {
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels[3];
          QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[3U -
            num_frequency_modes] =
            QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_frequency;
          num_frequency_modes++;
        }

        if (num_duty_cycle_modes > 0) {
          result = hil_set_pwm_frequency
            (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
             &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[0],
             num_duty_cycle_modes,
             &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[0]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
            return;
          }
        }

        if (num_frequency_modes > 0) {
          result = hil_set_pwm_duty_cycle
            (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
             &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
             num_frequency_modes,
             &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
            return;
          }
        }

        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_configuration;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_configuration;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_configuration;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_configuration;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_alignment;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_alignment;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_alignment;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_alignment;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_polarity;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_polarity;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_polarity;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_polarity;
        result = hil_set_pwm_configuration
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels, 4U,
           (t_pwm_configuration *)
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POModeValues[0],
           (t_pwm_alignment *)
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POAlignValues[0],
           (t_pwm_polarity *)
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POPolarityVals[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }

        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_leading_deadb;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_leading_deadb;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_leading_deadb;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_leading_deadb;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_trailing_dead;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_trailing_dead;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_trailing_dead;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_trailing_dead;
        result = hil_set_pwm_deadband
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels, 4U,
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POSortedFreqs[0],
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_a &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_p &&
           is_switching)) {
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_pwm_outpu;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_pwm_outpu;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_pwm_outpu;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_pwm_outpu;
        result = hil_write_pwm
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels, 4U,
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_o) {
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_pwm_outp;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[1] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_pwm_outp;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[2] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_pwm_outp;
        QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[3] =
          QBot2_Image_Proc_Line_Followi_P.HILInitialize_watchdog_pwm_outp;
        result = hil_watchdog_set_pwm_expiration_state
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels, 4U,
           &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }

      if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outputs &&
           !is_switching) ||
          (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_j &&
           is_switching)) {
        result = hil_write_other
          (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_other_output_chan, 4U,
           QBot2_Image_Proc_Line_Followi_P.HILInitialize_initial_other_out);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for S-Function (kinect_initialize_block): '<Root>/Kinect Initialize' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Initialize (kinect_initialize_block) */
    {
      t_error result = kinect_open("0", (t_kinect_type) 1,
        &QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
        return;
      }
    }

    /* Start for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 921600; i++) {
      QBot2_Image_Proc_Line_Followi_B.RateTransition[i] =
        QBot2_Image_Proc_Line_Followi_P.RateTransition_X0;
    }

    /* End of Start for RateTransition: '<Root>/Rate Transition' */

    /* Start for RateTransition: '<Root>/Rate Transition1' */
    QBot2_Image_Proc_Line_Followi_B.RateTransition1 =
      QBot2_Image_Proc_Line_Followi_P.RateTransition1_X0;

    /* Start for Atomic SubSystem: '<S4>/Bias Removal' */
    /* Start for Enabled SubSystem: '<S18>/Enabled Moving Average' */
    QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_MODE = false;

    /* End of Start for SubSystem: '<S18>/Enabled Moving Average' */

    /* Start for SwitchCase: '<S18>/Switch Case' */
    QBot2_Image_Proc_Line_Follow_DW.SwitchCase_ActiveSubsystem = -1;

    /* End of Start for SubSystem: '<S4>/Bias Removal' */

    /* Start for Constant: '<S15>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0 =
      QBot2_Image_Proc_Line_Followi_P.x0_Value;

    /* Start for Constant: '<S17>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_g =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_n;

    /* Start for S-Function (kinect_get_image_block): '<Root>/Kinect Get Image' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Get Image (kinect_get_image_block) */
    {
      /* Ensure the image stream is enabled */
      t_error result = kinect_enable_features
        (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
         KINECT_FEATURE_COLOR);
      if (result == 0) {
        result = kinect_set_image_resolution
          (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
           KINECT_IMAGE_TYPE_COLOR, KINECT_IMAGE_RESOLUTION_640x480);
        if (result == 0) {
          result = kinect_set_color_image_source
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             KINECT_IMAGE_SOURCE_RGB);
        }
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
      }
    }

    /* Start for Constant: '<S7>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_j =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_j;

    /* Start for Constant: '<S8>/x0' */
    QBot2_Image_Proc_Line_Followi_B.x0_e =
      QBot2_Image_Proc_Line_Followi_P.x0_Value_e;
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (kinect_initialize_block): '<Root>/Kinect Initialize' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Initialize (kinect_initialize_block) */
    {
      if (rtmIsFirstInitCond(QBot2_Image_Proc_Line_Follow_M)) {
        t_error result = kinect_initialize
          (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }
    }

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 921600; i++) {
      QBot2_Image_Proc_Line_Follow_DW.RateTransition_Buffer0[i] =
        QBot2_Image_Proc_Line_Followi_P.RateTransition_X0;
    }

    /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
    QBot2_Image_Proc_Line_Follow_DW.RateTransition1_Buffer0 =
      QBot2_Image_Proc_Line_Followi_P.RateTransition1_X0;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput_p =
      QBot2_Image_Proc_Line_Followi_P.Memory_X0_f;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE =
      QBot2_Image_Proc_Line_Followi_P.Integrator1_IC;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[0] =
      QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition_l;
    QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE[1] =
      QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    QBot2_Image_Proc_Line_Follow_DW.Memory_PreviousInput =
      QBot2_Image_Proc_Line_Followi_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE =
      QBot2_Image_Proc_Line_Followi_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator3' */
    QBot2_Image_Proc_Line_Followi_X.Integrator3_CSTATE =
      QBot2_Image_Proc_Line_Followi_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S15>/Integrator1' incorporates:
     *  InitializeConditions for Integrator: '<S17>/Integrator1'
     */
    if (rtmIsFirstInitCond(QBot2_Image_Proc_Line_Follow_M)) {
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_p = 0.0;
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_l = 0.0;
    }

    QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S15>/Integrator1' */

    /* InitializeConditions for Integrator: '<S15>/Integrator2' */
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_p =
      QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_a;

    /* InitializeConditions for Integrator: '<S17>/Integrator1' */
    QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_b = 1;

    /* InitializeConditions for Integrator: '<S17>/Integrator2' */
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_a =
      QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_o;

    /* InitializeConditions for S-Function (kinect_get_image_block): '<Root>/Kinect Get Image' */

    /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Get Image (kinect_get_image_block) */
    {
      if (rtmIsFirstInitCond(QBot2_Image_Proc_Line_Follow_M)) {
        t_error result;
        do {
          result = kinect_set_backlight_compensation
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             (t_kinect_backlight_compensation)
             (QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Backlight - 1));
          if (result < 0)
            break;
          result = kinect_set_brightness
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Brightness);
          if (result < 0)
            break;
          result = kinect_set_contrast
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Contrast);
          if (result < 0)
            break;
          if (QBot2_Image_Proc_Line_Followi_P.KinectGetImage_AExposure != false)
            result = kinect_set_exposure_time
              (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect, -1);
          else
            result = kinect_set_exposure_time
              (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
               QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Exposure);
          if (result < 0)
            break;
          result = kinect_set_frame_interval
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_FInterval);
          if (result < 0)
            break;
          result = kinect_set_gain
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Gain);
          if (result < 0)
            break;
          result = kinect_set_gamma
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Gamma);
          if (result < 0)
            break;
          result = kinect_set_hue
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Hue);
          if (result < 0)
            break;
          result = kinect_set_flicker_reduction
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             (t_kinect_flicker_reduction)
             (QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Flicker - 1));
          if (result < 0)
            break;
          result = kinect_set_saturation
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Saturation);
          if (result < 0)
            break;
          result = kinect_set_sharpness
            (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
             QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Sharpness);
          if (result < 0)
            break;
          if (QBot2_Image_Proc_Line_Followi_P.KinectGetImage_ABalance != 0)
            result = kinect_set_white_balance
              (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect, -1);
          else
            result = kinect_set_white_balance
              (QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect,
               QBot2_Image_Proc_Line_Followi_P.KinectGetImage_Balance);
        } while (false);

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
          return;
        }
      }
    }

    /* InitializeConditions for Integrator: '<S7>/Integrator1' incorporates:
     *  InitializeConditions for Integrator: '<S8>/Integrator1'
     */
    if (rtmIsFirstInitCond(QBot2_Image_Proc_Line_Follow_M)) {
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_o = 0.0;
      QBot2_Image_Proc_Line_Followi_X.Integrator1_CSTATE_lo = 0.0;
    }

    QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_a = 1;

    /* End of InitializeConditions for Integrator: '<S7>/Integrator1' */

    /* InitializeConditions for Integrator: '<S8>/Integrator1' */
    QBot2_Image_Proc_Line_Follow_DW.Integrator1_IWORK_bz = 1;

    /* InitializeConditions for Integrator: '<S26>/Integrator' */
    QBot2_Image_Proc_Line_Followi_X.Integrator_CSTATE =
      QBot2_Image_Proc_Line_Followi_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S7>/Integrator2' */
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_o =
      QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_d;

    /* InitializeConditions for Integrator: '<S8>/Integrator2' */
    QBot2_Image_Proc_Line_Followi_X.Integrator2_CSTATE_m =
      QBot2_Image_Proc_Line_Followi_P.Integrator2_IC_g;

    /* SystemInitialize for Atomic SubSystem: '<S4>/Bias Removal' */
    /* SystemInitialize for Enabled SubSystem: '<S18>/Enabled Moving Average' */
    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
    QBot2_Image_Proc_Line_Follow_DW.UnitDelay_DSTATE_h =
      QBot2_Image_Proc_Line_Followi_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S20>/Sum( k=1,n-1, x(k) )' */
    QBot2_Image_Proc_Line_Follow_DW.Sumk1n1xk_DSTATE =
      QBot2_Image_Proc_Line_Followi_P.Sumk1n1xk_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S18>/Enabled Moving Average' */

    /* SystemInitialize for IfAction SubSystem: '<S18>/Switch Case Action Subsystem' */
    /* SystemInitialize for Outport: '<S21>/zero' */
    QBot2_Image_Proc_Line_Followi_B.Constant_c =
      QBot2_Image_Proc_Line_Followi_P.zero_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Switch Case Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S18>/Switch Case Action Subsystem1' */
    /* SystemInitialize for Outport: '<S22>/Vbiased' */
    QBot2_Image_Proc_Line_Followi_B.Vin =
      QBot2_Image_Proc_Line_Followi_P.Vbiased_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Switch Case Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S18>/Switch Case Action Subsystem2' */
    /* SystemInitialize for Outport: '<S23>/Vunbiased' */
    QBot2_Image_Proc_Line_Followi_B.VVavg =
      QBot2_Image_Proc_Line_Followi_P.Vunbiased_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Switch Case Action Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S4>/Bias Removal' */

    /* SystemInitialize for MATLAB Function: '<S9>/Way Point Control' */
    QBot2_Image_Proc_Line_Follow_DW.Vf_1 = 0.0;
    QBot2_Image_Proc_Line_Follow_DW.end_flag = 0.0;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(QBot2_Image_Proc_Line_Follow_M)) {
      rtmSetFirstInitCond(QBot2_Image_Proc_Line_Follow_M, 0);
    }
  }
}

/* Model terminate function */
void QBot2_Image_Proc_Line_Following_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: QBot2_Image_Proc_Line_Following/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
    hil_monitor_stop_all(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
    is_switching = false;
    if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_outputs_k &&
         !is_switching) ||
        (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_pwm_output_ay &&
         is_switching)) {
      QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0] =
        QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_pwm_outputs;
      QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[1] =
        QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_pwm_outputs;
      QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[2] =
        QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_pwm_outputs;
      QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[3] =
        QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_pwm_outputs;
      num_final_pwm_outputs = 4U;
    }

    if ((QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_f &&
         !is_switching) ||
        (QBot2_Image_Proc_Line_Followi_P.HILInitialize_set_other_outpu_p &&
         is_switching)) {
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card
                         , NULL, 0
                         ,
                         QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         ,
                         QBot2_Image_Proc_Line_Followi_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , NULL
                         ,
                         &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[
                         0]
                         , (t_boolean *) NULL
                         ,
                         QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
             QBot2_Image_Proc_Line_Followi_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &QBot2_Image_Proc_Line_Follow_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card,
             QBot2_Image_Proc_Line_Followi_P.HILInitialize_other_output_chan,
             num_final_other_outputs,
             QBot2_Image_Proc_Line_Followi_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2_Image_Proc_Line_Follow_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
    hil_monitor_delete_all(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
    hil_close(QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card);
    QBot2_Image_Proc_Line_Follow_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (kinect_initialize_block): '<Root>/Kinect Initialize' */

  /* S-Function Block: QBot2_Image_Proc_Line_Following/Kinect Initialize (kinect_initialize_block) */
  {
    kinect_close(QBot2_Image_Proc_Line_Follow_DW.KinectInitialize_Kinect);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QBot2_Image_Proc_Line_Following_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QBot2_Image_Proc_Line_Following_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  QBot2_Image_Proc_Line_Following_initialize();
}

void MdlTerminate(void)
{
  QBot2_Image_Proc_Line_Following_terminate();
}

/* Registration function */
RT_MODEL_QBot2_Image_Proc_Lin_T *QBot2_Image_Proc_Line_Following(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QBot2_Image_Proc_Line_Follow_M, 0,
                sizeof(RT_MODEL_QBot2_Image_Proc_Lin_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                          &QBot2_Image_Proc_Line_Follow_M->Timing.simTimeStep);
    rtsiSetTPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo, &rtmGetTPtr
                (QBot2_Image_Proc_Line_Follow_M));
    rtsiSetStepSizePtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                       &QBot2_Image_Proc_Line_Follow_M->Timing.stepSize0);
    rtsiSetdXPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                 &QBot2_Image_Proc_Line_Follow_M->ModelData.derivs);
    rtsiSetContStatesPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo, (real_T **)
                         &QBot2_Image_Proc_Line_Follow_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
      &QBot2_Image_Proc_Line_Follow_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
      &QBot2_Image_Proc_Line_Follow_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&QBot2_Image_Proc_Line_Follow_M->solverInfo,
       &QBot2_Image_Proc_Line_Follow_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&QBot2_Image_Proc_Line_Follow_M->solverInfo,
       &QBot2_Image_Proc_Line_Follow_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                          (&rtmGetErrorStatus(QBot2_Image_Proc_Line_Follow_M)));
    rtsiSetRTModelPtr(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                      QBot2_Image_Proc_Line_Follow_M);
  }

  rtsiSetSimTimeStep(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                     MAJOR_TIME_STEP);
  QBot2_Image_Proc_Line_Follow_M->ModelData.intgData.f[0] =
    QBot2_Image_Proc_Line_Follow_M->ModelData.odeF[0];
  QBot2_Image_Proc_Line_Follow_M->ModelData.contStates = ((real_T *)
    &QBot2_Image_Proc_Line_Followi_X);
  rtsiSetSolverData(&QBot2_Image_Proc_Line_Follow_M->solverInfo, (void *)
                    &QBot2_Image_Proc_Line_Follow_M->ModelData.intgData);
  rtsiSetSolverName(&QBot2_Image_Proc_Line_Follow_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimes =
      (&QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimesArray[0]);
    QBot2_Image_Proc_Line_Follow_M->Timing.offsetTimes =
      (&QBot2_Image_Proc_Line_Follow_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimes[0] = (0.0);
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimes[1] = (0.01);
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    QBot2_Image_Proc_Line_Follow_M->Timing.offsetTimes[0] = (0.0);
    QBot2_Image_Proc_Line_Follow_M->Timing.offsetTimes[1] = (0.0);
    QBot2_Image_Proc_Line_Follow_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(QBot2_Image_Proc_Line_Follow_M,
             &QBot2_Image_Proc_Line_Follow_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QBot2_Image_Proc_Line_Follow_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      QBot2_Image_Proc_Line_Follow_M->Timing.perTaskSampleHitsArray;
    QBot2_Image_Proc_Line_Follow_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    QBot2_Image_Proc_Line_Follow_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QBot2_Image_Proc_Line_Follow_M, -1);
  QBot2_Image_Proc_Line_Follow_M->Timing.stepSize0 = 0.01;
  QBot2_Image_Proc_Line_Follow_M->Timing.stepSize1 = 0.01;
  QBot2_Image_Proc_Line_Follow_M->Timing.stepSize2 = 0.1;
  rtmSetFirstInitCond(QBot2_Image_Proc_Line_Follow_M, 1);

  /* External mode info */
  QBot2_Image_Proc_Line_Follow_M->Sizes.checksums[0] = (3314933472U);
  QBot2_Image_Proc_Line_Follow_M->Sizes.checksums[1] = (134756000U);
  QBot2_Image_Proc_Line_Follow_M->Sizes.checksums[2] = (791420137U);
  QBot2_Image_Proc_Line_Follow_M->Sizes.checksums[3] = (1002067058U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    QBot2_Image_Proc_Line_Follow_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab;
    systemRan[4] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab;
    systemRan[5] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab;
    systemRan[6] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.Blob_Detection_and_TrackingEnab;
    systemRan[7] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[8] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[9] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[10] = (sysRanDType *)
      &QBot2_Image_Proc_Line_Follow_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QBot2_Image_Proc_Line_Follow_M->extModeInfo,
      &QBot2_Image_Proc_Line_Follow_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QBot2_Image_Proc_Line_Follow_M->extModeInfo,
                        QBot2_Image_Proc_Line_Follow_M->Sizes.checksums);
    rteiSetTPtr(QBot2_Image_Proc_Line_Follow_M->extModeInfo, rtmGetTPtr
                (QBot2_Image_Proc_Line_Follow_M));
  }

  QBot2_Image_Proc_Line_Follow_M->solverInfoPtr =
    (&QBot2_Image_Proc_Line_Follow_M->solverInfo);
  QBot2_Image_Proc_Line_Follow_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&QBot2_Image_Proc_Line_Follow_M->solverInfo, 0.01);
  rtsiSetSolverMode(&QBot2_Image_Proc_Line_Follow_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  QBot2_Image_Proc_Line_Follow_M->ModelData.blockIO = ((void *)
    &QBot2_Image_Proc_Line_Followi_B);
  (void) memset(((void *) &QBot2_Image_Proc_Line_Followi_B), 0,
                sizeof(B_QBot2_Image_Proc_Line_Follo_T));

  /* parameters */
  QBot2_Image_Proc_Line_Follow_M->ModelData.defaultParam = ((real_T *)
    &QBot2_Image_Proc_Line_Followi_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QBot2_Image_Proc_Line_Followi_X;
    QBot2_Image_Proc_Line_Follow_M->ModelData.contStates = (x);
    (void) memset((void *)&QBot2_Image_Proc_Line_Followi_X, 0,
                  sizeof(X_QBot2_Image_Proc_Line_Follo_T));
  }

  /* states (dwork) */
  QBot2_Image_Proc_Line_Follow_M->ModelData.dwork = ((void *)
    &QBot2_Image_Proc_Line_Follow_DW);
  (void) memset((void *)&QBot2_Image_Proc_Line_Follow_DW, 0,
                sizeof(DW_QBot2_Image_Proc_Line_Foll_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QBot2_Image_Proc_Line_Follow_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numContStates = (12);/* Number of continuous states */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numY = (0);/* Number of model outputs */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numU = (0);/* Number of model inputs */
  QBot2_Image_Proc_Line_Follow_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numSampTimes = (3);/* Number of sample times */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numBlocks = (143);/* Number of blocks */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numBlockIO = (57);/* Number of block outputs */
  QBot2_Image_Proc_Line_Follow_M->Sizes.numBlockPrms = (205);/* Sum of parameter "widths" */
  return QBot2_Image_Proc_Line_Follow_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
