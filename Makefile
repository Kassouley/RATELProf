# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 

# Directories
CORE_DIR = core
BUILD_DIR = build
LIB_DIR = lib

# Libraries
LIBRATELPROF = libratelprof.so

# Compiler and flags
CC 			= hipcc
CXX			= hipcc
CFLAGS 		= -fPIC -Wall $(INC_FLAGS) -Wno-uninitialized -Wno-deprecated-declarations  -D __HIP_PLATFORM_AMD__ 
LDFLAGS		= -shared 
INC_DIRS   := $(shell find $(CORE_DIR) -type d)
INC_FLAGS  := $(addprefix -I,$(INC_DIRS)) -I$(CORE_DIR) -I/opt/rocm/include/hsa -I/opt/rocm/include/hip 
DEBUG_FLAGS = -D RATELPROF_DEBUG

# Source files
C_SOURCES = $(shell find $(CORE_DIR) -name '*.c')
CPP_SOURCES = $(shell find $(CORE_DIR) -name '*.cpp')

# Generate corresponding object files paths in the build directory
OBJECTS = $(C_SOURCES:$(CORE_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJECTS += $(CPP_SOURCES:$(CORE_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(LIBRATELPROF)

# Rule to compile .c files to .o
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile .cpp files to .o
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create libratelprof.so
$(LIBRATELPROF): $(OBJECTS)
	@mkdir -p $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $(LIB_DIR)/$@ $^ 

# Debug target
debug: CFLAGS += $(DEBUG_FLAGS)
debug: CFLAGS += -g # Optional: Add debugging symbols
debug: clean $(LIBRATELPROF)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)/$(LIBRATELPROF)

.PHONY: all clean
