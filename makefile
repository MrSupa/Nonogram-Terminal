# 1. Variables
CC       := clang
CFLAGS   := -Wall -Wextra -g -Isrc -MMD -MP  # -MMD generates .d files; -MP prevents errors if headers are deleted
SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin
TARGET   := $(BIN_DIR)/nonogram.exe

# 2. File Discovery
SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Generate a list of dependency files corresponding to each object file
DEPS     := $(OBJS:.o=.d)

# 3. Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 4. Include the generated dependency files
# The '-' prefix tells make to ignore files that don't exist yet (first build)
-include $(DEPS)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
