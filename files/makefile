#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = CircularBuffer

#--- Inputs ----#
PROJECT_HOME_DIR = .

SRC_FILES = CircularBuffer.c

TEST_SRC_FILES = CircularBufferTest.cpp AllTests.cpp

CPPUTEST_OBJS_DIR = objs
CPPUTEST_LIB_DIR = lib

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\

include common.mk
