#!/bin/sh
set -e
: "${CC:=gcc}"
: "${CFLAGS:=-std=c99 -Wall -Wextra -Werror}"
$CC $CFLAGS \
    tests/main.c \
    tests/test_ft_bzero.c \
    tests/test_ft_char.c \
    tests/test_ft_memcmp.c \
    tests/test_ft_memmove.c \
    tests/test_ft_memset.c \
    tests/test_ft_strlcat.c \
    tests/test_ft_strlcpy.c \
    tests/test_ft_strlen.c \
    tests/test_ft_strncmp.c \
    tests/shim_ft_memset.c \
    code/ft_bzero.c \
    code/ft_isalnum.c \
    code/ft_isalpha.c \
    code/ft_isascii.c \
    code/ft_isdigit.c \
    code/ft_isprint.c \
    code/ft_memcmp.c \
    code/ft_memove.c \
    code/ft_strlcat.c \
    code/ft_strlcpy.c \
    code/ft_strlen.c \
    code/ft_strncmp.c \
    -o tests/tests_runner
./tests/tests_runner
