/*
 * QBot2_Image_Proc_Line_Following.h
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

#ifndef RTW_HEADER_QBot2_Image_Proc_Line_Following_h_
#define RTW_HEADER_QBot2_Image_Proc_Line_Following_h_
#include <math.h>
#include <string.h>
#ifndef QBot2_Image_Proc_Line_Following_COMMON_INCLUDES_
# define QBot2_Image_Proc_Line_Following_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_kinect.h"
#include "quanser_extern.h"
#endif                                 /* QBot2_Image_Proc_Line_Following_COMMON_INCLUDES_ */

#include "QBot2_Image_Proc_Line_Following_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define QBot2_Image_Proc_Line_Following_rtModel RT_MODEL_QBot2_Image_Proc_Lin_T

/* Block signals (auto storage) */
typedef struct {
  uint8_T blue_vec[307200];
  uint8_T bin[307200];                 /* '<S1>/Thresholding' */
  real_T Limg[19200];
  real_T table1[2500];
  real_T table2[2500];
  real_T table1_m[2500];
  real_T table[2500];
  uint8_T r[19200];                    /* '<S1>/find blobs' */
  real_T HILRead1_o1;                  /* '<S19>/HIL Read1' */
  real_T HILRead1_o4;                  /* '<S19>/HIL Read1' */
  real_T Product;                      /* '<S4>/Product' */
  real_T Integrator1;                  /* '<S5>/Integrator1' */
  real_T Integrator2;                  /* '<S5>/Integrator2' */
  real_T Integrator3;                  /* '<S5>/Integrator3' */
  real_T mmtom;                        /* '<S14>/mm to m' */
  real_T Constant;                     /* '<S15>/Constant' */
  real_T x0;                           /* '<S15>/x0' */
  real_T wn;                           /* '<S15>/wn' */
  real_T zt;                           /* '<S15>/zt' */
  real_T Product_b;                    /* '<S15>/Product' */
  real_T Product1;                     /* '<S15>/Product1' */
  real_T mmtom_a;                      /* '<S16>/mm to m' */
  real_T Constant_n;                   /* '<S17>/Constant' */
  real_T x0_g;                         /* '<S17>/x0' */
  real_T wn_d;                         /* '<S17>/wn' */
  real_T zt_m;                         /* '<S17>/zt' */
  real_T Product_k;                    /* '<S17>/Product' */
  real_T Product1_g;                   /* '<S17>/Product1' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T x0_j;                         /* '<S7>/x0' */
  real_T x0_e;                         /* '<S8>/x0' */
  real_T Constant_g;                   /* '<S7>/Constant' */
  real_T wn_a;                         /* '<S7>/wn' */
  real_T zt_i;                         /* '<S7>/zt' */
  real_T Product_d;                    /* '<S7>/Product' */
  real_T Product1_b;                   /* '<S7>/Product1' */
  real_T Constant_i;                   /* '<S8>/Constant' */
  real_T wn_h;                         /* '<S8>/wn' */
  real_T zt_o;                         /* '<S8>/zt' */
  real_T Product_p;                    /* '<S8>/Product' */
  real_T Product1_j;                   /* '<S8>/Product1' */
  real_T Vf;                           /* '<S9>/Way Point Control' */
  real_T W;                            /* '<S9>/Way Point Control' */
  real_T states;                       /* '<S9>/Way Point Control' */
  real_T vR;                           /* '<S6>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  real_T vL;                           /* '<S6>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  real_T x_dot;                        /* '<S26>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T y_dot;                        /* '<S26>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T psi_dot;                      /* '<S26>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T Omega;                        /* '<S25>/Qbot2_Diff_Drive_Kinematics' */
  real_T VVavg;                        /* '<S23>/V-Vavg' */
  real_T Vin;                          /* '<S22>/Vin' */
  real_T Constant_c;                   /* '<S21>/Constant' */
  real_T Count;                        /* '<S24>/Count' */
  real_T Sum;                          /* '<S20>/Sum' */
  real_T div;                          /* '<S20>/div' */
  real_T Gain[2];                      /* '<S1>/Gain' */
  real_T n;                            /* '<S1>/find blobs' */
  uint32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  uint32_T KinectGetImage_o2;          /* '<Root>/Kinect Get Image' */
  uint8_T RateTransition[921600];      /* '<Root>/Rate Transition' */
  uint8_T cimage[921600];              /* '<Root>/cimage' */
  uint8_T KinectGetImage_o1[921600];   /* '<Root>/Kinect Get Image' */
  uint8_T green_vec[307200];
} B_QBot2_Image_Proc_Line_Follo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[2];          /* '<Root>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S24>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S20>/Sum( k=1,n-1, x(k) )' */
  real_T HILInitialize_AIMinimums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POValues[4];    /* '<Root>/HIL Initialize' */
  real_T HILInitialize_OOValues[4];    /* '<Root>/HIL Initialize' */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T HILWrite_OtherBuffer[2];      /* '<S19>/HIL Write' */
  real_T Vf_1;                         /* '<S9>/Way Point Control' */
  real_T end_flag;                     /* '<S9>/Way Point Control' */
  t_kinect KinectInitialize_Kinect;    /* '<Root>/Kinect Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *DisplayImageHistogram_PWORK;   /* '<Root>/Display Image (Histogram)' */
  void *HILRead1_PWORK;                /* '<S19>/HIL Read1' */
  void *Image_PWORK;                   /* '<Root>/Image' */
  void *KinectGetImage_PWORK;          /* '<Root>/Kinect Get Image' */
  void *HILWrite_PWORK;                /* '<S19>/HIL Write' */
  int32_T HILInitialize_QuadratureModes[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[4];/* '<Root>/HIL Initialize' */
  int32_T HILRead1_EncoderBuffer[2];   /* '<S19>/HIL Read1' */
  uint32_T HILInitialize_POSortedChans[4];/* '<Root>/HIL Initialize' */
  uint32_T RateTransition1_Buffer0;    /* '<Root>/Rate Transition1' */
  uint32_T Memory_PreviousInput_p;     /* '<Root>/Memory' */
  int_T DisplayImageHistogram_IWORK;   /* '<Root>/Display Image (Histogram)' */
  int_T Image_IWORK;                   /* '<Root>/Image' */
  int_T Integrator1_IWORK;             /* '<S15>/Integrator1' */
  int_T Integrator1_IWORK_b;           /* '<S17>/Integrator1' */
  int_T Integrator1_IWORK_a;           /* '<S7>/Integrator1' */
  int_T Integrator1_IWORK_bz;          /* '<S8>/Integrator1' */
  int8_T Blob_Detection_and_TrackingEnab;/* '<Root>/ Blob_Detection_and_Tracking (Enabled)' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S18>/Enabled Moving Average' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S18>/Switch Case' */
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S18>/Switch Case Action Subsystem' */
  int8_T SwitchCaseActionSubsystem1_Subs;/* '<S18>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem2_Subs;/* '<S18>/Switch Case Action Subsystem2' */
  uint8_T RateTransition_Buffer0[921600];/* '<Root>/Rate Transition' */
  boolean_T EnabledMovingAverage_MODE; /* '<S18>/Enabled Moving Average' */
} DW_QBot2_Image_Proc_Line_Foll_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S5>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S5>/Integrator3' */
  real_T Integrator1_CSTATE_p;         /* '<S15>/Integrator1' */
  real_T Integrator2_CSTATE_p;         /* '<S15>/Integrator2' */
  real_T Integrator1_CSTATE_l;         /* '<S17>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S17>/Integrator2' */
  real_T Integrator1_CSTATE_o;         /* '<S7>/Integrator1' */
  real_T Integrator1_CSTATE_lo;        /* '<S8>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S26>/Integrator' */
  real_T Integrator2_CSTATE_o;         /* '<S7>/Integrator2' */
  real_T Integrator2_CSTATE_m;         /* '<S8>/Integrator2' */
} X_QBot2_Image_Proc_Line_Follo_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S5>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S5>/Integrator3' */
  real_T Integrator1_CSTATE_p;         /* '<S15>/Integrator1' */
  real_T Integrator2_CSTATE_p;         /* '<S15>/Integrator2' */
  real_T Integrator1_CSTATE_l;         /* '<S17>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S17>/Integrator2' */
  real_T Integrator1_CSTATE_o;         /* '<S7>/Integrator1' */
  real_T Integrator1_CSTATE_lo;        /* '<S8>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S26>/Integrator' */
  real_T Integrator2_CSTATE_o;         /* '<S7>/Integrator2' */
  real_T Integrator2_CSTATE_m;         /* '<S8>/Integrator2' */
} XDot_QBot2_Image_Proc_Line_Fo_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S5>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S5>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<S5>/Integrator3' */
  boolean_T Integrator1_CSTATE_p;      /* '<S15>/Integrator1' */
  boolean_T Integrator2_CSTATE_p;      /* '<S15>/Integrator2' */
  boolean_T Integrator1_CSTATE_l;      /* '<S17>/Integrator1' */
  boolean_T Integrator2_CSTATE_a;      /* '<S17>/Integrator2' */
  boolean_T Integrator1_CSTATE_o;      /* '<S7>/Integrator1' */
  boolean_T Integrator1_CSTATE_lo;     /* '<S8>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S26>/Integrator' */
  boolean_T Integrator2_CSTATE_o;      /* '<S7>/Integrator2' */
  boolean_T Integrator2_CSTATE_m;      /* '<S8>/Integrator2' */
} XDis_QBot2_Image_Proc_Line_Fo_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            QBot2_Image_Proc_Line_Followi_B
#define BlockIO                        B_QBot2_Image_Proc_Line_Follo_T
#define rtX                            QBot2_Image_Proc_Line_Followi_X
#define ContinuousStates               X_QBot2_Image_Proc_Line_Follo_T
#define rtXdot                         QBot2_Image_Proc_Line_Foll_XDot
#define StateDerivatives               XDot_QBot2_Image_Proc_Line_Fo_T
#define tXdis                          QBot2_Image_Proc_Line_Foll_XDis
#define StateDisabled                  XDis_QBot2_Image_Proc_Line_Fo_T
#define rtP                            QBot2_Image_Proc_Line_Followi_P
#define Parameters                     P_QBot2_Image_Proc_Line_Follo_T
#define rtDWork                        QBot2_Image_Proc_Line_Follow_DW
#define D_Work                         DW_QBot2_Image_Proc_Line_Foll_T

/* Parameters (auto storage) */
struct P_QBot2_Image_Proc_Line_Follo_T_ {
  real_T HILInitialize_analog_input_maxi[9];/* Mask Parameter: HILInitialize_analog_input_maxi
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_analog_input_mini[9];/* Mask Parameter: HILInitialize_analog_input_mini
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S18>/Step: end_time'
                                        */
  real_T HILInitialize_final_other_outpu[4];/* Mask Parameter: HILInitialize_final_other_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_other_out[4];/* Mask Parameter: HILInitialize_initial_other_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T SecondOrderLowPassFilter2_input;/* Mask Parameter: SecondOrderLowPassFilter2_input
                                          * Referenced by: '<S15>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_n;/* Mask Parameter: SecondOrderLowPassFilter2_inp_n
                                          * Referenced by: '<S17>/wn'
                                          */
  real_T SecondOrderLowPassFilter_input_;/* Mask Parameter: SecondOrderLowPassFilter_input_
                                          * Referenced by: '<S7>/wn'
                                          */
  real_T SecondOrderLowPassFilter1_input;/* Mask Parameter: SecondOrderLowPassFilter1_input
                                          * Referenced by: '<S8>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_f;/* Mask Parameter: SecondOrderLowPassFilter2_inp_f
                                          * Referenced by: '<S15>/zt'
                                          */
  real_T SecondOrderLowPassFilter2_inp_l;/* Mask Parameter: SecondOrderLowPassFilter2_inp_l
                                          * Referenced by: '<S17>/zt'
                                          */
  real_T SecondOrderLowPassFilter_inpu_b;/* Mask Parameter: SecondOrderLowPassFilter_inpu_b
                                          * Referenced by: '<S7>/zt'
                                          */
  real_T SecondOrderLowPassFilter1_inp_b;/* Mask Parameter: SecondOrderLowPassFilter1_inp_b
                                          * Referenced by: '<S8>/zt'
                                          */
  real_T HILInitialize_pwm_frequency;  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_pwm_leading_deadb;/* Mask Parameter: HILInitialize_pwm_leading_deadb
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_pwm_trailing_dead;/* Mask Parameter: HILInitialize_pwm_trailing_dead
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_j;/* Mask Parameter: HILInitialize_set_other_outpu_j
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_p;/* Mask Parameter: HILInitialize_set_other_outpu_p
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_f;/* Mask Parameter: HILInitialize_set_other_outpu_f
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T HILInitialize_watchdog_pwm_outp;/* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILInitialize_initial_encoder_c;/* Mask Parameter: HILInitialize_initial_encoder_c
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_alignment; /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_configuration;/* Mask Parameter: HILInitialize_pwm_configuration
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_modes;     /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_polarity;  /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T DisplayImageHistogram_update_ra;/* Mask Parameter: DisplayImageHistogram_update_ra
                                           * Referenced by: '<Root>/Display Image (Histogram)'
                                           */
  int32_T Image_update_rate;           /* Mask Parameter: Image_update_rate
                                        * Referenced by: '<Root>/Image'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  uint32_T HILRead1_analog_channels;   /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<S19>/HIL Read1'
                                        */
  uint32_T HILInitialize_analog_input_chan[10];/* Mask Parameter: HILInitialize_analog_input_chan
                                                * Referenced by: '<Root>/HIL Initialize'
                                                */
  uint32_T HILRead1_digital_channels[3];/* Mask Parameter: HILRead1_digital_channels
                                         * Referenced by: '<S19>/HIL Read1'
                                         */
  uint32_T HILInitialize_encoder_channels[4];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<Root>/HIL Initialize'
                                              */
  uint32_T HILRead1_encoder_channels[2];/* Mask Parameter: HILRead1_encoder_channels
                                         * Referenced by: '<S19>/HIL Read1'
                                         */
  uint32_T HILRead1_other_channels;    /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<S19>/HIL Read1'
                                        */
  uint32_T HILWrite_other_channels[2]; /* Mask Parameter: HILWrite_other_channels
                                        * Referenced by: '<S19>/HIL Write'
                                        */
  uint32_T HILInitialize_other_output_chan[4];/* Mask Parameter: HILInitialize_other_output_chan
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_pwm_channels[4];/* Mask Parameter: HILInitialize_pwm_channels
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T KinectInitialize_active;   /* Mask Parameter: KinectInitialize_active
                                        * Referenced by: '<Root>/Kinect Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out;/* Mask Parameter: HILInitialize_final_digital_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_initial_digital_o;/* Mask Parameter: HILInitialize_initial_digital_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T DisplayImageHistogram_orig_size;/* Mask Parameter: DisplayImageHistogram_orig_size
                                             * Referenced by: '<Root>/Display Image (Histogram)'
                                             */
  boolean_T Image_orig_size;           /* Mask Parameter: Image_orig_size
                                        * Referenced by: '<Root>/Image'
                                        */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_m;/* Mask Parameter: HILInitialize_set_analog_inpu_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_h;/* Mask Parameter: HILInitialize_set_analog_outp_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_i;/* Mask Parameter: HILInitialize_set_analog_outp_i
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_g;/* Mask Parameter: HILInitialize_set_analog_outp_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_d;/* Mask Parameter: HILInitialize_set_analog_outp_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_m;/* Mask Parameter: HILInitialize_set_analog_outp_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_j;/* Mask Parameter: HILInitialize_set_analog_outp_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_h;/* Mask Parameter: HILInitialize_set_clock_frequ_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_j;/* Mask Parameter: HILInitialize_set_clock_param_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_l;/* Mask Parameter: HILInitialize_set_digital_out_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_f;/* Mask Parameter: HILInitialize_set_digital_out_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_jc;/* Mask Parameter: HILInitialize_set_digital_ou_jc
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_o;/* Mask Parameter: HILInitialize_set_digital_out_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_a;/* Mask Parameter: HILInitialize_set_digital_out_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_k;/* Mask Parameter: HILInitialize_set_encoder_cou_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_k;/* Mask Parameter: HILInitialize_set_encoder_par_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_l;/* Mask Parameter: HILInitialize_set_other_outpu_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_p;/* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_output_ay;/* Mask Parameter: HILInitialize_set_pwm_output_ay
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_k;/* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__b;/* Mask Parameter: HILInitialize_set_pwm_params__b
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T red_th1_Value;                /* Expression: 8
                                        * Referenced by: '<S1>/red_th1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S24>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S20>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S21>/zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S22>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S23>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S18>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S18>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S18>/Step: end_time'
                                        */
  real_T red_th_Value[2];              /* Expression: [160 255]
                                        * Referenced by: '<Root>/red_th'
                                        */
  real_T green_th_Value[2];            /* Expression: [160 255]
                                        * Referenced by: '<Root>/green_th'
                                        */
  real_T blue_th_Value[2];             /* Expression: [70 140]
                                        * Referenced by: '<Root>/blue_th'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant2_Value[3];           /* Expression: [320; 540; 0]
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant7_Value;              /* Expression: 10*pi/180
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant12_Value;             /* Expression: 2
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant10_Value;             /* Expression: 1.1
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant6_Value;              /* Expression: 0.45
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant8_Value;              /* Expression: 0.6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0.6
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Memory_X0;                    /* Expression: [0]
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S5>/Integrator3'
                                        */
  real_T tickstoencoderrotation_Gain;  /* Expression: 2*pi/52
                                        * Referenced by: '<S14>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotationg;/* Expression: 1/49.5833
                                          * Referenced by: '<S14>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain;          /* Expression: 35
                                        * Referenced by: '<S14>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S14>/mm to m'
                                        */
  real_T Constant_Value_g;             /* Expression: 2
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S15>/x0'
                                        */
  real_T Integrator2_IC_a;             /* Expression: 0
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  real_T tickstoencoderrotation_Gain_f;/* Expression: 2*pi/52
                                        * Referenced by: '<S16>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotatio_d;/* Expression: 1/49.5833
                                          * Referenced by: '<S16>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain_d;        /* Expression: 35
                                        * Referenced by: '<S16>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain_c;                 /* Expression: 1/1000
                                        * Referenced by: '<S16>/mm to m'
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T x0_Value_n;                   /* Expression: input_init
                                        * Referenced by: '<S17>/x0'
                                        */
  real_T Integrator2_IC_o;             /* Expression: 0
                                        * Referenced by: '<S17>/Integrator2'
                                        */
  real_T KinectGetImage_Brightness;    /* Expression: brightness
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Contrast;      /* Expression: contrast
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Exposure;      /* Expression: exposure
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_FInterval;     /* Expression: frame_interval
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Gain;          /* Expression: gain
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Gamma;         /* Expression: gamma
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Hue;           /* Expression: hue
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Saturation;    /* Expression: saturation
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Sharpness;     /* Expression: sharpness
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T KinectGetImage_Balance;       /* Expression: balance
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  real_T x0_Value_j;                   /* Expression: input_init
                                        * Referenced by: '<S7>/x0'
                                        */
  real_T x0_Value_e;                   /* Expression: input_init
                                        * Referenced by: '<S8>/x0'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S26>/Integrator'
                                        */
  real_T Constant_Value_b;             /* Expression: 2
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Integrator2_IC_d;             /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  real_T Constant_Value_o;             /* Expression: 2
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S8>/Integrator2'
                                        */
  int32_T KinectGetImage_SensorType;   /* Computed Parameter: KinectGetImage_SensorType
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  int32_T KinectGetImage_Backlight;    /* Computed Parameter: KinectGetImage_Backlight
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  int32_T KinectGetImage_Flicker;      /* Computed Parameter: KinectGetImage_Flicker
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  uint32_T RateTransition1_X0;         /* Computed Parameter: RateTransition1_X0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  uint32_T Memory_X0_f;                /* Computed Parameter: Memory_X0_f
                                        * Referenced by: '<Root>/Memory'
                                        */
  uint8_T RateTransition_X0;           /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<Root>/Rate Transition'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S19>/HIL Read1'
                                        */
  boolean_T KinectGetImage_AExposure;  /* Computed Parameter: KinectGetImage_AExposure
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  boolean_T KinectGetImage_ABalance;   /* Computed Parameter: KinectGetImage_ABalance
                                        * Referenced by: '<Root>/Kinect Get Image'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S19>/HIL Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_QBot2_Image_Proc_Line_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][12];
    ODE1_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_P;

/* Block signals (auto storage) */
extern B_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_B;

/* Continuous states (auto storage) */
extern X_QBot2_Image_Proc_Line_Follo_T QBot2_Image_Proc_Line_Followi_X;

/* Block states (auto storage) */
extern DW_QBot2_Image_Proc_Line_Foll_T QBot2_Image_Proc_Line_Follow_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void QBot2_Image_Proc_Line_Following_initialize(void);
extern void QBot2_Image_Proc_Line_Following_output0(void);
extern void QBot2_Image_Proc_Line_Following_update0(void);
extern void QBot2_Image_Proc_Line_Following_output(int_T tid);
extern void QBot2_Image_Proc_Line_Following_update(int_T tid);
extern void QBot2_Image_Proc_Line_Following_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern QBot2_Image_Proc_Line_Following_rtModel *QBot2_Image_Proc_Line_Following
  (void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_QBot2_Image_Proc_Lin_T *const QBot2_Image_Proc_Line_Follow_M;

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
 * '<Root>' : 'QBot2_Image_Proc_Line_Following'
 * '<S1>'   : 'QBot2_Image_Proc_Line_Following/ Blob_Detection_and_Tracking (Enabled)'
 * '<S2>'   : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity1'
 * '<S3>'   : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity2'
 * '<S4>'   : 'QBot2_Image_Proc_Line_Following/QBot_Basic'
 * '<S5>'   : 'QBot2_Image_Proc_Line_Following/Qbot2_Full_Kinematics (No Gyro)1'
 * '<S6>'   : 'QBot2_Image_Proc_Line_Following/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)'
 * '<S7>'   : 'QBot2_Image_Proc_Line_Following/Second-Order Low-Pass Filter'
 * '<S8>'   : 'QBot2_Image_Proc_Line_Following/Second-Order Low-Pass Filter1'
 * '<S9>'   : 'QBot2_Image_Proc_Line_Following/Trajectory control (Way-points from Kinect Camera Image)'
 * '<S10>'  : 'QBot2_Image_Proc_Line_Following/ Blob_Detection_and_Tracking (Enabled)/Image Channels'
 * '<S11>'  : 'QBot2_Image_Proc_Line_Following/ Blob_Detection_and_Tracking (Enabled)/Thresholding'
 * '<S12>'  : 'QBot2_Image_Proc_Line_Following/ Blob_Detection_and_Tracking (Enabled)/find blobs'
 * '<S13>'  : 'QBot2_Image_Proc_Line_Following/ Blob_Detection_and_Tracking (Enabled)/find centroid1'
 * '<S14>'  : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity1/Encoder to Distance'
 * '<S15>'  : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity1/Second-Order Low-Pass Filter2'
 * '<S16>'  : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity2/Encoder to Distance'
 * '<S17>'  : 'QBot2_Image_Proc_Line_Following/Encoder_to_Velocity2/Second-Order Low-Pass Filter2'
 * '<S18>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal'
 * '<S19>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/QBot2_IO_Basic'
 * '<S20>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal/Enabled Moving Average'
 * '<S21>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal/Switch Case Action Subsystem'
 * '<S22>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal/Switch Case Action Subsystem1'
 * '<S23>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal/Switch Case Action Subsystem2'
 * '<S24>'  : 'QBot2_Image_Proc_Line_Following/QBot_Basic/Bias Removal/Enabled Moving Average/Increment'
 * '<S25>'  : 'QBot2_Image_Proc_Line_Following/Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Diff_Drive_Kinematics'
 * '<S26>'  : 'QBot2_Image_Proc_Line_Following/Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Kinematics (No Gyro)'
 * '<S27>'  : 'QBot2_Image_Proc_Line_Following/Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics'
 * '<S28>'  : 'QBot2_Image_Proc_Line_Following/Qbot2_Full_Kinematics (No Gyro)1/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)'
 * '<S29>'  : 'QBot2_Image_Proc_Line_Following/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)'
 * '<S30>'  : 'QBot2_Image_Proc_Line_Following/Trajectory control (Way-points from Kinect Camera Image)/Way Point Control'
 */
#endif                                 /* RTW_HEADER_QBot2_Image_Proc_Line_Following_h_ */
