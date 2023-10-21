CXX = g++
CXX_FLAGS = -Wall -Wextra -std=c++11 -g
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
LIBDIR :=
LIBS :=
TARGET ?= main
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(patsubst %.cpp, ${BUILD_DIR}/%.cpp.o, $(notdir $(SRCS)))

DEPS := $(OBJS:.o=.d)
INC_DIRS := ./includes
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPP_FLAGS ?= $(INC_FLAGS) -MMD -MP

${BUILD_DIR}/${TARGET} : $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: $(SRC_DIRS)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) -c $< -o $@

.PHONY: all clean
all: ${BUILD_DIR}/${TARGET}
clean:
	$(RM) $(DEPS) $(OBJS) ${BUILD_DIR}/${TARGET}

-include $(DEPS)

MKDIR_P ?= mkdir -p
