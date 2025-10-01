#!/bin/sh
set -eu

SCRIPT_DIR=$(cd -- "$(dirname "$0")" && pwd)
PROJECT_DIR=$(cd -- "$SCRIPT_DIR/.." && pwd)

: "${CC:=gcc}"
: "${CFLAGS:=-std=c99 -Wall -Wextra -Werror}"
OUTPUT="$SCRIPT_DIR/tests_runner"

"$CC" $CFLAGS \
    "$SCRIPT_DIR/main.c" \
    "$SCRIPT_DIR/test_ft_bzero.c" \
    "$SCRIPT_DIR/test_ft_char.c" \
    "$SCRIPT_DIR/test_ft_memcmp.c" \
    "$SCRIPT_DIR/test_ft_memmove.c" \
    "$SCRIPT_DIR/test_ft_memset.c" \
    "$SCRIPT_DIR/test_ft_strlcat.c" \
    "$SCRIPT_DIR/test_ft_strlcpy.c" \
    "$SCRIPT_DIR/test_ft_strlen.c" \
    "$SCRIPT_DIR/test_ft_strncmp.c" \
    "$SCRIPT_DIR/shim_ft_memset.c" \
    "$PROJECT_DIR/code/ft_bzero.c" \
    "$PROJECT_DIR/code/ft_isalnum.c" \
    "$PROJECT_DIR/code/ft_isalpha.c" \
    "$PROJECT_DIR/code/ft_isascii.c" \
    "$PROJECT_DIR/code/ft_isdigit.c" \
    "$PROJECT_DIR/code/ft_isprint.c" \
    "$PROJECT_DIR/code/ft_memcmp.c" \
    "$PROJECT_DIR/code/ft_memove.c" \
    "$PROJECT_DIR/code/ft_strlcat.c" \
    "$PROJECT_DIR/code/ft_strlcpy.c" \
    "$PROJECT_DIR/code/ft_strlen.c" \
    "$PROJECT_DIR/code/ft_strncmp.c" \
    -o "$OUTPUT"

"$OUTPUT"
