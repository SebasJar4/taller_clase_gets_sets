CC       := gcc
CFLAGS   := -Wall -Wextra -std=c11 -g -Iinclude
LDFLAGS := -Lbuild/obj -lspecifics -lgenerals

# Carpetas de salida
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

# Archivo objetivo principal
TARGET    := $(BIN_DIR)/app.out

# Fuentes del nucleo y librerias
MAIN_SRC  := src/main.c
GEN_SRCS  := $(wildcard src/generals/*.c)
SPEC_SRCS := $(wildcard src/specifics/*.c)

# Objetos intermediarios
GEN_OBJS  := $(patsubst src/generals/%.c, $(OBJ_DIR)/generals/%.o, $(GEN_SRCS))
SPEC_OBJS := $(patsubst src/specifics/%.c, $(OBJ_DIR)/specifics/%.o, $(SPEC_SRCS))
MAIN_OBJ  := $(OBJ_DIR)/main.o

# Librerias estaticas internas
LIB_GEN   := $(OBJ_DIR)/libgenerals.a
LIB_SPEC  := $(OBJ_DIR)/libspecifics.a

.PHONY: all clean test libs

all: $(TARGET)

# 1. Crear las librerias estaticas internas (.a)
libs: $(LIB_GEN) $(LIB_SPEC)

$(LIB_GEN): $(GEN_OBJS)
	@mkdir -p $(OBJ_DIR)
	ar rcs $@ $^

$(LIB_SPEC): $(SPEC_OBJS)
	@mkdir -p $(OBJ_DIR)
	ar rcs $@ $^

# Compilacion de objetos individuales (.o)
$(OBJ_DIR)/generals/%.o: src/generals/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/specifics/%.o: src/specifics/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 2. Enlazar el ejecutable final
$(TARGET): libs $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(MAIN_OBJ) $(LDFLAGS) -o $@

# 3. Delegar ejecucion de tests
test: libs
	$(MAKE) -C test

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C test clean