# Copyright 2014 Quanser, Inc.
#
# File    : quarc_linux_duovero.tmf   $Revision: 1.0.0.0 $
#
# Abstract:
#	Real-Time Workshop template makefile for building a Linux ARM-based
#	stand-alone real-time version of Simulink model using
#	generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#   The following defines can be used to modify the behavior of the build:
#     OPT_OPTS       - Optimization options. Default is -O. To enable
#                          debugging specify as OPT_OPTS=-g.
#                          Because of optimization problems in IBM_RS,
#                          default is no-optimization.
#     CPP_OPTS       - C++ compiler options.
#     OPTS           - User specific compile options.
#     USER_SRCS      - Additional user sources, such as files needed by
#                      S-functions.
#     USER_INCLUDES  - Additional include paths
#                      (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see quarc_linux_duovero.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD          - This is the command used to invoke the make utility
#  MAKEFILE_FILESEP - Replaces all instances of the current file separator 
#                     with the given one. See help for updateFileSeparator.
#  HOST             - What platform this template makefile is targeted for
#                     (i.e. PC or UNIX)
#  BUILD            - Invoke make from the Real-Time Workshop build procedure
#                     (yes/no)?
#  SYS_TARGET_FILE  - Name of system target file.

MAKECMD          = make
MAKEFILE_FILESEP = /
HOST             = PC
BUILD            = yes
SYS_TARGET_FILE  = quarc_linux_duovero.tlc
BUILD_SUCCESS    = \#\#\# Created

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  TGT_FCN_LIB         - Target Funtion library to use
#  MODELREFS           - List of referenced models

MODEL                = QBot2_Image_Proc_Line_Following
MODULES              = QBot2_Image_Proc_Line_Following_data.c QBot2_Image_Proc_Line_Following_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c 
MAKEFILE             = QBot2_Image_Proc_Line_Following.mk
MATLAB_ROOT          = C:/Program Files/MATLAB/R2016a
ALT_MATLAB_ROOT      = C:/PROGRA~1/MATLAB/R2016a
MATLAB_BIN           = C:/Program Files/MATLAB/R2016a/bin
ALT_MATLAB_BIN       = C:/PROGRA~1/MATLAB/R2016a/bin
S_FUNCTIONS          = rtiostream_utils.c
S_FUNCTIONS_LIB      = C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/libhil.a C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LI5A2F~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LIBQUA~4.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LI8DF1~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LIBFRE~1.SO C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LIBUSB~1.SO C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/libudev.so
SOLVER               = 
NUMST                = 3
TID01EQ              = 1
NCSTATES             = 12
COMPUTER             = PCWIN64
BUILDARGS            =  MAT_FILE=0 DEBUG=0 ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DON_TARGET_WAIT_FOR_START=0"
MULTITASKING         = 1
EXT_MODE             = 1
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
RELEASE_VERSION      = R2016a
MEXEXT               = mexw64
TGT_FCN_LIB          = None

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
TARGET_LANG_EXT      = c

#--------------------------- Model and reference models -----------------------
MODELLIB                  = QBot2_Image_Proc_Line_Followinglib.a
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#--------------------------- Additional options -------------------------------

ASSERTACTION     = "Stop model with an error"
HAVESTDIO        =  1
STRIPSYMBOLS     =  0
SHOW_TIMES       =  0

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN = $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications -------------------------------

include $(QUARC)/include/linux_duovero_tools.mk

#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES:=$(MATLAB_ROOT)/simulink/include
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);$(MATLAB_ROOT)/extern/include
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);$(MATLAB_ROOT)/rtw/c/src
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# Additional file include paths

MATLAB_INCLUDES:=$(MATLAB_INCLUDES);$(MATLAB_ROOT)/simulink/include/sf_runtime
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);C:/Users/ale/DOWNLO~1/FINALS~1/FINALS~1/QBot2_Image_Proc_Line_Following_quarc_linux_duovero
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);C:/Users/ale/DOWNLO~1/FINALS~1/FINALS~1
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);C:/Users/ale/Downloads
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils
MATLAB_INCLUDES:=$(MATLAB_INCLUDES);C:/PROGRA~1/Quanser/QUARC/include

QUARC_INCLUDES=$(QUARC)/include

CPATH:=;$(RELATIVE_PATH_TO_ANCHOR);$(QUARC_INCLUDES);$(MATLAB_INCLUDES);$(ADD_INCLUDES);$(USER_INCLUDES);$(INSTRUMENT_INCLUDES);$(MODELREF_INC_PATH)

ifneq ($(SHARED_SRC_DIR),)
CPATH:=$(CPATH);$(SHARED_SRC_DIR)
endif

export CPATH

#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -D$(COMPUTER) -DMODEL_URI="$(MODEL_URI)" -DVERBOSE
  EXT_LIB     =
  EXT_SRC     =
  LINT_EXT_COMMON_SRC =
  LINT_EXT_TCPIP_SRC  =
  ifeq ($(EXTMODE_TRANSPORT),0) # quarc_comm
    EXT_SRC =
    EXT_LIB = -lextmode_quarc_r2013b -lquanser_communications
    LINT_EXT_COMMON_SRC = ext_svr_quarc.c updown.c ext_work.c
    LINT_EXT_TCPIP_SRC  = ext_svr_quarc_transport.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC             += mem_mgr.c
    LINT_EXT_COMMON_SRC += mem_mgr.c
    EXT_CC_OPTS         += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#
# .mat File Logging
#
ifeq ($(MAT_FILE),1)
LOG_OPTS  = -DMAT_FILE
endif

#----------------------------- Real-Time Model ---------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------------- C Flags --------------------------------------

# Optimization Options. The DEFAULT_OPT_OPTS macro depends on the build configuration.
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# Required Options
REQ_OPTS = -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon -mtune=cortex-a9 \
           -Wall -fmessage-length=0 -MMD -MP -fpic -feliminate-unused-debug-types

# General User Options
OPTS = -Wno-unused-but-set-variable -Wno-unused-variable

# Compiler options, etc:
CC_OPTS = $(OPT_OPTS) $(REQ_OPTS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)

ifeq ($(ASSERTACTION), "Ignore")
  ASSERT_DEFINES = -DASSERTIONS=0
else 
  ifeq ($(ASSERTACTION), "Stop model with an error")
    ASSERT_DEFINES = -DASSERTIONS=1 -DDOASSERTS
  else 
    ifeq ($(ASSERTACTION), "Print assertion")
      ASSERT_DEFINES = -DASSERTIONS=2 -DDOASSERTS
    endif
  endif
endif

ifeq ($(HAVESTDIO),1)
STDIO_DEFINES = -DHAVESTDIO
else
STDIO_DEFINES =
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMULTITASKING=$(MULTITASKING) $(STDIO_DEFINES) \
                  -DVXWORKS -DQUARC -D_GUMSTIX -DTARGET_TYPE=linux_duovero -D_DUOVERO \
                  $(ASSERT_DEFINES) $(OPT_DEFINES)

CFLAGS   = $(SYSROOT) $(CC_OPTS) $(ANSI_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(SYSROOT) $(CPP_OPTS) $(CC_OPTS) $(CPP_ANSI_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)
LDFLAGS := $(SYSROOT) $(LDFLAGS) -Wl,--hash-style=gnu -Wl,--as-needed -L$(QUARC)/lib/linux_duovero

#-------------------------- Additional Libraries ------------------------------

# rtwmakecfg mechanism appears to fail for the Linux ARM target since the S_FUNCTIONS_LIB
# macro is not generated correctly. This shortcoming appears to be a bug in RTW.
# Hence, add additional libraries required here.

QUARC_LIBS = \
	-lquanser_runtime \
	-lquanser_common

SYSLIBS = $(EXT_LIB) $(QUARC_LIBS) -lrt -lpthread -ldl -lm

LIBS =
 

# See rtwmakecfg.m documentation

LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(MODULES) $(S_FUNCTIONS)

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(TARGET_EXT)
    BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "executable"
    SRCS              += $(MODEL).$(TARGET_LANG_EXT) $(MODEL)_main.c rt_sim.c $(EXT_SRC) $(SOLVER)
else
    # Model reference rtw target
    PRODUCT            = $(MODELLIB)
    BUILD_PRODUCT_TYPE = "library"
endif

ifneq ($(findstring .cpp,$(suffix $(SRCS), $(USER_SRCS))),)
  LD = $(CPP)
  SYSLIBS += $(CPP_SYS_LIBS) 
endif

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(sort $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS))

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))

#------------- Test Compile using gcc -Wall to look for warnings ---------------
#
# DO_GCC_TEST=1 runs gcc with compiler warning flags on all the source files
# used in this build. This includes the generated code, and any user source
# files needed for the build and placed in this directory.
#
# See $(QUARC)/include/linux_arm_tools.mk for the definition of GCC_WARN_OPTS
GCC_TEST_CMD  := echo
GCC_TEST_OUT  := > nul:
ifeq ($(DO_GCC_TEST), 1)
  GCC_TEST := gcc -c -o nul: $(GCC_WARN_OPTS_MAX) $(CPP_REQ_DEFINES) \
                                     $(INCLUDES)
  GCC_TEST_CMD := echo; echo "\#\#\# GCC_TEST $(GCC_TEST) $<"; $(GCC_TEST)
  GCC_TEST_OUT := ; echo
endif

#----------------------------- Lint (sol2 only) --------------------------------

LINT_SRCS = $(MODEL)_main.c $(MATLAB_ROOT)/rtw/c/src/rt_sim.c
ifneq ($(SOLVER), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/$(SOLVER)
endif
ifneq ($(LINT_EXT_COMMON_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/$(LINT_EXT_COMMON_SRC)
endif
ifneq ($(LINT_EXT_TCPIP_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/$(LINT_EXT_TCPIP_SRC)
endif
LINT_SRCS += $(MODEL).$(TARGET_LANG_EXT) $(MODULES) $(USER_SRCS) $(S_FUNCTIONS)
LINTOPTSFILE = $(MODEL).lintopts

LINT_ERROFF1 = E_NAME_DEF_NOT_USED2,E_NAME_DECL_NOT_USED_DEF2
LINT_ERROFF2 = $(LINT_ERROFF1),E_FUNC_ARG_UNUSED
LINT_ERROFF  = $(LINT_ERROFF2),E_INDISTING_FROM_TRUNC2,E_NAME_USED_NOT_DEF2

# Define a BUILD_SUCCESS macro that accounts for the difference in escape
# characters between make and the shell.
BUILD_SUCCESS_EX := \$(BUILD_SUCCESS)

#--------------------------------- Rules ---------------------------------------
ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS) $(SYSLIBS)
ifeq ($(STRIPSYMBOLS),1)
	$(STRIP) --strip-debug --strip-unneeded $(PRODUCT)
endif
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
else
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo $(BUILD_SUCCESS_EX) $(MODELLIB)
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
endif

ifneq ($(SHARED_SRC_DIR),)
$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	cd $(SHARED_BIN_DIR) && $(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(notdir $?)

$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.cpp
	cd $(SHARED_BIN_DIR) && $(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) $(notdir $?)
endif

%.o : %.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : %.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<

%.o : $(QUARC)/quarc/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(QUARC)/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<

#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo \#\#\# Creating $@
	$(AR) ruvs $@ $(SHARED_OBJS)
	@echo \#\#\# $@ Created


#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo \#\#\# Deleting the generated source code for $(MODEL)
	@del /q $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo \#\#\# Deleting the objects and $(PRODUCT)
	@del /q $(LINK_OBJS) $(PRODUCT)

lint  : rtwlib.ln
	@lint -errchk -errhdr=%user -errtags=yes -F -L. -lrtwlib -x -Xc \
	      -erroff=$(LINT_ERROFF) \
	      -D_POSIX_C_SOURCE $(CFLAGS) $(LINT_SRCS)
	@del /q $(LINTOPTSFILE)
	@echo
	@echo \#\#\# Created lint output only, no executable
	@echo

rtwlib.ln : $(MAKEFILE) rtw_proj.tmw
	@echo
	@echo \#\#\# Linting ...
	@echo
	@del /q llib-lrtwlib.ln $(LINTOPTSFILE)
	@echo "-dirout=. -errchk -errhdr=%user " >> $(LINTOPTSFILE)
	@echo "-errtags -F -ortwlib -x -Xc " >> $(LINTOPTSFILE)
	@echo "-erroff=$(LINT_ERROFF) " >> $(LINTOPTSFILE)
	@echo "-D_POSIX_C_SOURCE $(CFLAGS) " >> $(LINTOPTSFILE)
	@for %%file in ($(MATLAB_ROOT)/rtw/c/libsrc/*.c) do echo "%file " >> $(LINTOPTSFILE);
	lint -flagsrc=$(LINTOPTSFILE)

# EOF: quarc_linux_duovero.tmf
