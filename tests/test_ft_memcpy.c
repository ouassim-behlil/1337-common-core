#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dest, const void *src, size_t n);

static void run_case(const char *label, size_t len, size_t dest_offset)
{
    unsigned char   src[32];
    unsigned char   actual[64];
    unsigned char   expected[64];
    void            *ret_actual;
    void            *ret_expected;

    for (size_t i = 0; i < sizeof(src); ++i)
        src[i] = (unsigned char)(i * 3 + 1);
    memset(actual, 0xAA, sizeof(actual));
    memset(expected, 0xAA, sizeof(expected));
    ret_actual = ft_memcpy(actual + dest_offset, src, len);
    ret_expected = memcpy(expected + dest_offset, src, len);
    if (ret_actual != actual + dest_offset)
    {
        fprintf(stderr, "[ft_memcpy] Return pointer mismatch in case '%s'\n", label);
        assert(0);
    }
    if (memcmp(actual, expected, sizeof(actual)) != 0)
    {
        fprintf(stderr, "[ft_memcpy] Buffer mismatch in case '%s'\n", label);
        assert(0);
    }
    if (ret_expected != expected + dest_offset)
    {
        fprintf(stderr, "[ft_memcpy] Reference return pointer mismatch in case '%s'\n",
            label);
        assert(0);
    }
}

static void run_self_copy_case(const char *label, size_t len)
{
    unsigned char actual[64];
    unsigned char original[64];

    for (size_t i = 0; i < sizeof(actual); ++i)
    {
        unsigned char value = (unsigned char)(i + 5);
        actual[i] = value;
        original[i] = value;
    }
    ft_memcpy(actual, actual, len);
    if (memcmp(actual, original, sizeof(actual)) != 0)
    {
        fprintf(stderr, "[ft_memcpy] Self copy mismatch in case '%s'\n", label);
        assert(0);
    }
}

void    run_ft_memcpy_tests(void)
{
    run_case("basic copy", 16, 0);
    run_case("offset destination", 16, 8);
    run_case("copy zero bytes", 0, 4);
    run_case("binary data", 23, 5);
    run_self_copy_case("self copy", 32);
    printf("ft_memcpy: all %s tests passed\n", "5");
}
