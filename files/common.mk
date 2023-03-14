CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_USE_MEM_LEAK_DETECTION = Y
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ./MyMemoryLeakDetectorNewMacrosFile.h

CPPUTEST_WARNINGFLAGS += -Wall 
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wfatal-errors
CPPUTEST_WARNINGFLAGS += -Wno-shadow
CPPUTEST_WARNINGFLAGS += -Wno-switch-default

CPPUTEST_CXXFLAGS += -Wno-c++98-compat-pedantic
CPPUTEST_CXXFLAGS += -std=c++11
CPPUTEST_CXXFLAGS += -Wno-c++14-compat
CPPUTEST_CXXFLAGS += -Wno-unused-parameter

CPPUTEST_CFLAGS += -std=c99
CPPUTEST_CFLAGS += -Wno-unused-parameter
CPPUTEST_CFLAGS += -Wno-strict-prototypes
CPPUTEST_CFLAGS += -Wno-missing-prototypes

ifneq ("$(wildcard $(START_POINTS_HOME)/PlatformCompilerFlags.mk)","")
  include $(START_POINTS_HOME)/PlatformCompilerFlags.mk
endif
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
