# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror

# Target executable
TARGET = app

# Source files
MAIN = main.c
TRANSFORM_NUMBER = transform_number.c

# Object files
OBJS = main.o transform_number.o

# Default target (uses version 1)
all: clean build

# Build using version 1
build: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean build files
clean:
	rm -f *.o $(TARGET)