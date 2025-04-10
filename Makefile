# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -I./include

# Target executable
TARGET = app
TEST_TARGET = test_runner

# Directories
SRCDIR = src
OBJDIR = obj
TESTDIR = test

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
SRCS_NO_MAIN = $(filter-out $(SRCDIR)/main.c, $(SRCS))
OBJS_NO_MAIN = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS_NO_MAIN))

# Test source files
TEST_SRCS = $(wildcard $(TESTDIR)/*.c)
TEST_OBJS = $(patsubst $(TESTDIR)/%.c, $(OBJDIR)/%.o, $(TEST_SRCS))

# Default target
all: clean build

# Build
build: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files to object files
$(OBJDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(TARGET) $(TEST_TARGET)

# Run the app
run: all
	./$(TARGET)

# Run tests
test: $(OBJS_NO_MAIN) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)