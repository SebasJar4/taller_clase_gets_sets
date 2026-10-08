CC       := gcc
CFLAGS   := -Wall -Wextra -std=c17 -I../include
LDFLAGS  := -L../build/obj -lspecifics -lgenerals

OBJ_DIR  := ../build/obj/test
BIN_DIR  := ../build/bin

TARGET   := $(BIN_DIR)/test_runner.out
SRC      := test.c
OBJ      := $(OBJ_DIR)/test.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar y ejecutar directamente los tests
run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)