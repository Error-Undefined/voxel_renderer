# Define the compiler and the linker.
CXX = gcc
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CFLAGS =  -Og -Wall -Wextra
CFLAGS += -g
#CFLAGS += $(DEPFLAGS)
LDFLAGS = -lm -lglfw -ldl
LDFLAGS += -g

# Targets
PROGS = main
all: $(PROGS)

BIN_NAME = main
GLAD_FILE = ./libs/glad/glad.o

TARGET_O_FILES = $(GLAD_FILE) ./src/main.o ./src/renderer/program_window.o ./src/renderer/graphics/graphics.o ./src/shaders/shader.o ./src/image/image.o

# Targets rely on implicit rules for compiling and linking
main: $(TARGET_O_FILES)
			$(CC) $(TARGET_O_FILES) -o $(BIN_NAME) $(LDFLAGS)

# Phony targets
.PHONY: all all_objs clean 

# Standard clean
clean:
	rm -f ./src/*.o $(PROGS)

# Clean .d files
depclean:
	rm -f *.d

fullclean:
	rm -f *.o *.d $(PROGS)
	rm -f ./src/*.o ./src/*.d
	rm -f $(TARGET_O_FILES)

# Include the *.d files
SRC = $(wildcard *.c)
-include $(SRC:.c=.d)
