#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t  ft_strlen(const char *s);

#define STRLCPY_MAX 64
#define STRLCPY_SENTINEL '\xA5'

static size_t reference_strlcpy(char *dest, const char *src, size_t dsize)
{
    size_t src_len = strlen(src);
    size_t copy_len = 0;

    if (dsize != 0)
    {
        while (copy_len < dsize - 1 && src[copy_len] != '\0')
        {
            dest[copy_len] = src[copy_len];
            copy_len++;
        }
        dest[copy_len] = '\0';
    }
    return (src_len);
}

static void check_sentinels(const char *buffer, size_t dsize, const char *label)
{
    size_t boundary = (dsize == 0) ? 0 : dsize;

    if (boundary >= STRLCPY_MAX)
        return ;
    for (size_t idx = boundary; idx < STRLCPY_MAX; ++idx)
    {
        if ((unsigned char)buffer[idx] != (unsigned char)STRLCPY_SENTINEL)
        {
            fprintf(stderr, "[ft_strlcpy] Sentinel overwritten in case '%s' at index %zu\n", label, idx);
            assert(0);
        }
    }
}

static void run_case(const char *label, const char *src, size_t dsize)
{
    char actual[STRLCPY_MAX];
    char expected[STRLCPY_MAX];
    size_t expected_ret;
    size_t actual_ret;

    memset(actual, STRLCPY_SENTINEL, sizeof(actual));
    memset(expected, STRLCPY_SENTINEL, sizeof(expected));
    expected_ret = reference_strlcpy(expected, src, dsize);
    actual_ret = ft_strlcpy(actual, src, dsize);
    if (actual_ret != expected_ret)
    {
        fprintf(stderr, "[ft_strlcpy] Return mismatch in case '%s': expected %zu, got %zu\n", label, expected_ret, actual_ret);
        assert(0);
    }
    if (memcmp(actual, expected, sizeof(actual)) != 0)
    {
        fprintf(stderr, "[ft_strlcpy] Buffer mismatch in case '%s'\n", label);
        assert(0);
    }
    if (dsize > 0 && strlen(actual) != ft_strlen(actual))
    {
        fprintf(stderr, "[ft_strlcpy] Length mismatch between strlen and ft_strlen in case '%s'\n", label);
        assert(0);
    }
    check_sentinels(actual, dsize, label);
}

void    run_ft_strlcpy_tests(void)
{
    run_case("basic copy", "hello", 16);
    run_case("exact fit", "world", 6);
    run_case("truncated", "abcdefghijklmnopqrstuvwxyz", 10);
    run_case("zero size", "ignored", 0);
    run_case("empty source", "", 10);
    printf("ft_strlcpy: all %s tests passed\n", "5");
}
