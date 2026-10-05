#!/bin/bash

# Verificar que se haya pasado al menos un argumento
if [ $# -lt 1 ]; then
    echo "Uso: $0 archivo1.c [archivo2.c ...] [opciones gcc ...]"
    echo
    echo "Ejemplo:"
    echo "  $0 main.c funciones.c -lm"
    echo "  $0 main.c funciones.c -Iinclude -lm -O2"
    exit 1
fi

# ---------------------------------------------------------
# Buscar el primer archivo .c para utilizar su nombre
# como nombre del ejecutable.
# ---------------------------------------------------------

C_FILE=""

for ARG in "$@"; do
    if [[ "$ARG" == *.c ]]; then
        C_FILE="$ARG"
        break
    fi
done

# Verificar que haya al menos un archivo .c
if [ -z "$C_FILE" ]; then
    echo "Error: debes proporcionar al menos un archivo .c."
    exit 1
fi

# ---------------------------------------------------------
# Verificar que los archivos .c existan
# ---------------------------------------------------------

for ARG in "$@"; do
    if [[ "$ARG" == *.c ]]; then
        if [ ! -f "$ARG" ]; then
            echo "Error: el archivo '$ARG' no existe."
            exit 1
        fi
    fi
done

# ---------------------------------------------------------
# Crear directorio build
# ---------------------------------------------------------

mkdir -p ./build

# ---------------------------------------------------------
# Obtener nombre del programa a partir del primer .c
# ---------------------------------------------------------

PROGRAM_NAME="${C_FILE##*/}"
PROGRAM_NAME="${PROGRAM_NAME%.c}"

OUTPUT="./build/$PROGRAM_NAME.out"

# ---------------------------------------------------------
# Compilar
#
# "$@" permite pasar todos los argumentos directamente
# a gcc:
#
#   archivos .c
#   -lm
#   -lpthread
#   -Iinclude
#   -DDEBUG
#   -O2
#   etc.
# ---------------------------------------------------------

echo "Compilando..."
echo "gcc -Wall -Werror -std=c17 $* -o $OUTPUT"
echo

if gcc -Wall -Werror -std=c17 "$@" -o "$OUTPUT" &> ./compile.out; then
    echo "Compilación exitosa."
    echo "Ejecutable: $OUTPUT"
    echo
    echo "Ejecutando..."
    echo

    "$OUTPUT"
else
    echo "Error de compilación:"
    echo
    cat ./compile.out
    exit 1
fi

