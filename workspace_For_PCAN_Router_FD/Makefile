#
# makefile for PCAN-Router FD SDK based on
#
# Visual Studio Code (VSCode)
# https://code.visualstudio.com/)
#
# and
#
# GNU Arm Embedded Toolchain
# https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
#
#
# © PEAK-System Technik GmbH Darmstadt, Germany
# www.peak-system.com
#
#


# MCU name and submodel
MCU = cortex-m4

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Target file name (without extension).
TARGET = example_can_fd

# set folders for generated files here
LST_FOLDER = ./lst
DEP_FOLDER = ./dep
OBJ_FOLDER = ./obj
OUT_FOLDER = ./out

# source folder
SRC_FOLDER = ./src
LIB_FOLDER = ./lib

# List C source files here. (C dependencies are automatically generated.)
# use file-extension c for "c-only"-files
CSRC += $(SRC_FOLDER)/startup_ARMCM4.c
CSRC += $(SRC_FOLDER)/system_LPC407x_8x_177x_8x.c
CSRC += $(SRC_FOLDER)/main.c
CSRC += $(SRC_FOLDER)/can_user.c
CSRC += $(SRC_FOLDER)/route_map.c
CSRC += $(SRC_FOLDER)/utils.c
CSRC += $(SRC_FOLDER)/srr520_yg11_v05_in.c
CSRC += $(SRC_FOLDER)/srr520_yg11_v05_out.c
# List C++ source files here.
# use file-extension cpp for C++-files (use extension .cpp)
CPPSRC += 

# List Assembler source files here.
# Make them always end in a capital .S.  Files ending in a lowercase .s
# will not be considered source files but generated files (assembler
# output from the compiler), and will be deleted upon "make clean"!
# Even though the DOS/Win* filesystem matches both .s and .S the same,
# it will preserve the spelling of the filenames, and gcc itself does
# care about how the name is spelled on its command-line.
ASRC +=

# Optimization level, can be [0, 1, 2, 3, s]. 
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = 2

# Debugging format.
# Native formats for AVR-GCC's -g are stabs [default], or dwarf-2.
# AVR (extended) COFF requires stabs, plus an avr-objcopy run.
DEBUG = dwarf-2

# List include directories to look for include files here.
#     Each directory must be seperated by a space.
INC_FOLDERS += ./inc

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CSTANDARD = -std=gnu99

# Place -D or -U options for C here
CDEFS = -DPCAN_ROUTER_FD=1 -DGCC=1 -D__USE_CMSIS -DARMCM4_FP

# Place -D or -U options for ASM here
ADEFS = 

# generate listing for input
LISTING_FILE = -adhlns=$(LST_FOLDER)/$(notdir $(subst $(suffix $@),.lst,$@))

# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#
# Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS += -g$(DEBUG)
CFLAGS += $(CDEFS)
CFLAGS += -O$(OPT)
CFLAGS += -Wall -Wcast-align -Wcast-qual
CFLAGS += -Wpointer-arith -Wswitch
#CFLAGS += -Wredundant-decls   (see discussions on github)
CFLAGS += -Wreturn-type -Wshadow -Wunused
CFLAGS += -Wa,$(LISTING_FILE)
CFLAGS += $(patsubst %,-I%,$(INC_FOLDERS))

# flags only for C
CONLYFLAGS += -Wstrict-prototypes -Wmissing-declarations
#CONLYFLAGS += -Wnested-externs   (see discussions on github)
CONLYFLAGS += -Wmissing-prototypes -Wimplicit
CONLYFLAGS += $(CSTANDARD)

# flags only for C++ (arm-elf-g++)
# CPPFLAGS = -fno-rtti -fno-exceptions
CPPFLAGS += 

# Assembler flags.
#  -Wa,...:   tell GCC to pass this to the assembler.
#  -ahlms:    create listing
#  -gstabs:   have the assembler create line number information; note that
#             for use in COFF files, additional information about filenames
#             and function names needs to be present in the assembler source
#             files -- see avr-libc docs [FIXME: not yet described there]
ASFLAGS += $(ADEFS) -Wa,$(LISTING_FILE),-g$(DEBUG)

# Additional libraries.

# Support for newlibc-lpc (file: libnewlibc-lpc.a)
# NEWLIBLPC = -lnewlib-lpc
NEWLIBLPC =

MATH_LIB = -lm

CPLUSPLUS_LIB = -lstdc++

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(OUT_FOLDER)/$(TARGET).map,--cref
LDFLAGS += $(NEWLIBLPC) $(MATH_LIB)
LDFLAGS += -lc -lgcc 
LDFLAGS += $(CPLUSPLUS_LIB)
LDFLAGS += -N
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Tpcan_router_fd.ld

# add project specific libs
PRJLIBS = $(LIB_FOLDER)/libPCAN-Router_FD_02.a



# ---------------------------------------------------------------------------

# Define programs and commands.
ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE = arm-none-eabi-
endif

SHELL = sh
CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
SIZE = $(CROSS_COMPILE)size
NM = $(CROSS_COMPILE)nm
REMOVE = rm -f
COPY = cp
HEX2BIN = hex2bin


# Define Messages
# English
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before:
MSG_SIZE_AFTER = Size after:
MSG_FLASH = Creating load file for Flash:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_ARCHIVE = Build archive:
MSG_COMPILING = Compiling C:
MSG_COMPILINGCPP = Compiling C++:
MSG_COMPILING_SINGLE = Compiling C/C++/ASM file:
MSG_ASSEMBLING = Assembling:
MSG_CLEANING = Cleaning project:
MSG_BIN_FILE = Creating bin file:


# check if we want to compile only a single file using one of:
#
# make singlefile SINGLE_FILE=mypath\myCfile.c              for c files
# make singlefile SINGLE_FILE=mypath\myCppfile.cpp          for cpp files
# make singlefile SINGLE_FILE=mypath\myAsmfile.S            for asm files
#
# if so, shrink down the suitable file list to this single file
# and delete the other lists !!
ifeq ($(MAKECMDGOALS),singlefile)

# substitute '\' by '/' due to make on Windows (e.g. VSCode)
SINGLE_FILE_ = $(subst \,/,$(SINGLE_FILE))

# is it a C file ? modify c file list accordingly. Delete other
ifeq ($(suffix $(SINGLE_FILE_)),.c)
CSRC = $(SINGLE_FILE_)
ASRC =
CPPSRC =
endif

# is it a CPP file ? modify cpp file list accordingly. Delete other
ifeq ($(suffix $(SINGLE_FILE_)),.cpp)
CSRC =
ASRC =
CPPSRC = $(SINGLE_FILE_)
endif

# is it an ASM file ? modify asm file list accordingly. Delete other
ifeq ($(suffix $(SINGLE_FILE_)),.S)
CSRC =
ASRC = $(SINGLE_FILE_)
CPPSRC =
endif

endif

# NOW: Define all object files (from above source lists, or shrinked lists)
COBJ   = $(addprefix $(OBJ_FOLDER)/, $(notdir $(CSRC:.c=.o)))
AOBJ   = $(addprefix $(OBJ_FOLDER)/, $(notdir $(ASRC:.S=.o)))
CPPOBJ = $(addprefix $(OBJ_FOLDER)/, $(notdir $(CPPSRC:.cpp=.o)))

# Compiler flags to generate dependency files.
### GENDEPFLAGS = -Wp,-M,-MP,-MT,$(*F).o,-MF,.dep/$(@F).d
GENDEPFLAGS = -MD -MP -MF $(DEP_FOLDER)/$(@F).d

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = -mcpu=$(MCU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I. $(CFLAGS) $(GENDEPFLAGS)
ALL_ASFLAGS = -mcpu=$(MCU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I. -x assembler-with-cpp $(ASFLAGS)


# Default target.
all: begin gccversion sizebefore build sizeafter finished end

build: dirs elf hex lss sym bin

singlefile: begin gccversion dirs $(AOBJ) $(COBJ) $(CPPOBJ)

elf: $(TARGET).elf
hex: $(TARGET).hex
arc: $(TARGET).a
lss: $(TARGET).lss
sym: $(TARGET).sym
bin: $(TARGET).bin

# create output folders
dirs:
	@mkdir -p $(LST_FOLDER)
	@mkdir -p $(DEP_FOLDER)
	@mkdir -p $(OBJ_FOLDER)
	@mkdir -p $(OUT_FOLDER)

# Eye candy.
begin:
	@echo
	@echo $(MSG_BEGIN)

finished:
	@echo
	@echo $(MSG_ERRORS_NONE)

end:
	@echo
	@echo $(MSG_END)
	@echo


# Display size of file
HEXSIZE = $(SIZE) --target=$(FORMAT) $(OUT_FOLDER)/$(TARGET).hex
ELFSIZE = $(SIZE) -A $(OUT_FOLDER)/$(TARGET).elf

sizebefore:
	@echo
	@if [ -f $(OUT_FOLDER)/$(TARGET).elf ]; then echo; echo $(MSG_SIZE_BEFORE); $(ELFSIZE); echo; fi

sizeafter:
	@echo
	@if [ -f $(OUT_FOLDER)/$(TARGET).elf ]; then echo; echo $(MSG_SIZE_AFTER); $(ELFSIZE); echo; fi


# Display compiler version information
gccversion:
	@echo
	@$(CC) --version


# create hex from ELF
%.hex: %.elf
	@echo
	@echo $(MSG_FLASH) $@
	$(OBJCOPY) -O $(FORMAT) $(OUT_FOLDER)/$< $(OUT_FOLDER)/$@


# create extended listing file from ELF
%.lss: %.elf
	@echo
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S -C $(OUT_FOLDER)/$< > $(OUT_FOLDER)/$@


# create a symbol table from ELF
%.sym: %.elf
	@echo
	@echo $(MSG_SYMBOL_TABLE) $@
	$(NM) -n $(OUT_FOLDER)/$< > $(OUT_FOLDER)/$@


# create bin file from hex
%.bin: %.hex
	@echo
	@echo $(MSG_BIN_FILE) $@
	$(HEX2BIN) -s 0000 $(OUT_FOLDER)/$<


# Link: create ELF output file from object files
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(AOBJ) $(COBJ) $(CPPOBJ)
%.elf:  $(AOBJ) $(COBJ) $(CPPOBJ)
	@echo
	@echo $(MSG_LINKING) $@
	$(CC) $(ALL_CFLAGS) $(AOBJ) $(COBJ) $(CPPOBJ) $(PRJLIBS) --output $(OUT_FOLDER)/$@ $(LDFLAGS)

# Compile: create object files from C source files. Look up path from source list
LOOK_C_FILE_ = $(filter %$(addprefix /, $(notdir $(subst .o,.c,$@))), $(CSRC))

$(COBJ) : %.o :
	@echo
	@echo $(MSG_COMPILING) $(LOOK_C_FILE_)
	$(CC) -c $(ALL_CFLAGS) $(CONLYFLAGS) $(LOOK_C_FILE_) -o $@

# Compile: create object files from C++ source files. Look up path from source list
LOOK_CPP_FILE_ = $(filter %$(addprefix /, $(notdir $(subst .o,.cpp,$@))), $(CPPSRC))

$(CPPOBJ) : %.o :
	@echo
	@echo $(MSG_COMPILINGCPP) $(LOOK_CPP_FILE_)
	$(CPP) -c $(ALL_CFLAGS) $(CPPFLAGS) $(LOOK_CPP_FILE_) -o $@

# Assemble: create object files from assembler source files. Look up path from source list
LOOK_S_FILE_ = $(filter %$(addprefix /, $(notdir $(subst .o,.S,$@))), $(ASRC))

$(AOBJ) : %.o :
	@echo
	@echo $(MSG_ASSEMBLING) $(LOOK_S_FILE_)
	$(CC) -c $(ALL_ASFLAGS) $(LOOK_S_FILE_) -o $@


# clean project
clean: begin clean_list finished end

# just clean output folders
clean_list:
	@echo
	@echo $(MSG_CLEANING)
	$(REMOVE) $(DEP_FOLDER)/*
	$(REMOVE) $(LST_FOLDER)/*
	$(REMOVE) $(OBJ_FOLDER)/*
	$(REMOVE) $(OUT_FOLDER)/*


# Include the dependency files.
ifneq ($(MAKECMDGOALS),clean)
# only on compile/build
-include $(shell mkdir $(DEP_FOLDER) 2>/dev/null) $(wildcard $(DEP_FOLDER)/*)
endif


# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex lss sym clean clean_list singlefile
