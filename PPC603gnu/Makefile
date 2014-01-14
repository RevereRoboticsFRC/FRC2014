# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/FRC2014



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = IterativeTemplate/$(MODE_DIR)/IterativeTemplate.out \
	 IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage.o


#Rules

# IterativeTemplate
ifeq ($(DEBUG_MODE),1)
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
IterativeTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
IterativeTemplate/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
IterativeTemplate/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
IterativeTemplate/$(MODE_DIR)/% : IDE_DEFINES = 
IterativeTemplate/$(MODE_DIR)/% : PROJECT_TYPE = DKM
IterativeTemplate/$(MODE_DIR)/% : DEFINES = 
IterativeTemplate/$(MODE_DIR)/% : EXPAND_DBG = 0
IterativeTemplate/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
IterativeTemplate/$(MODE_DIR)/% : CPU = PPC603
IterativeTemplate/$(MODE_DIR)/% : TOOL_FAMILY = gnu
IterativeTemplate/$(MODE_DIR)/% : TOOL = gnu
IterativeTemplate/$(MODE_DIR)/% : TOOL_PATH = 
IterativeTemplate/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
IterativeTemplate/$(MODE_DIR)/% : LIBPATH = 
IterativeTemplate/$(MODE_DIR)/% : LIBS = 
IterativeTemplate/$(MODE_DIR)/% : OBJ_DIR := IterativeTemplate/$(MODE_DIR)

OBJECTS_IterativeTemplate = IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage.o

IterativeTemplate/$(MODE_DIR)/IterativeTemplate.out : $(OBJECTS_IterativeTemplate)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_IterativeTemplate) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_IterativeTemplate) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

IterativeTemplate/$(MODE_DIR)/IterativeTemplate_compile_file : $(FILE) ;

_clean :: IterativeTemplate/$(MODE_DIR)/IterativeTemplate_clean

IterativeTemplate/$(MODE_DIR)/IterativeTemplate_clean : 
	$(TRACE_FLAG)if [ -d "IterativeTemplate" ]; then cd "IterativeTemplate"; rm -rf $(MODE_DIR); fi


# IterativeTemplate_partialImage
ifeq ($(DEBUG_MODE),1)
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
IterativeTemplate_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
IterativeTemplate_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
IterativeTemplate_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
IterativeTemplate_partialImage/$(MODE_DIR)/% : DEFINES = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
IterativeTemplate_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
IterativeTemplate_partialImage/$(MODE_DIR)/% : CPU = PPC603
IterativeTemplate_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
IterativeTemplate_partialImage/$(MODE_DIR)/% : TOOL = gnu
IterativeTemplate_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
IterativeTemplate_partialImage/$(MODE_DIR)/% : LIBPATH = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : LIBS = 
IterativeTemplate_partialImage/$(MODE_DIR)/% : OBJ_DIR := IterativeTemplate_partialImage/$(MODE_DIR)

IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/Utils/Logger.o : $(PRJ_ROOT_DIR)/Utils/Logger.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_IterativeTemplate_partialImage = IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/MyRobot.o \
	 IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/Utils/Logger.o

IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage.o : $(OBJECTS_IterativeTemplate_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_IterativeTemplate_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage_compile_file : $(FILE) ;

_clean :: IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage_clean

IterativeTemplate_partialImage/$(MODE_DIR)/IterativeTemplate_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "IterativeTemplate_partialImage" ]; then cd "IterativeTemplate_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/MyRobot.d IterativeTemplate_partialImage/$(MODE_DIR)/Objects/FRC2014/Utils/Logger.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
