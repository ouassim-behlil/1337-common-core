#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    *ft_memmove(void *dest, const void *src, size_t n);

static void run_case(const char *label, size_t dest_offset, size_t src_offset, size_t len)
{
    unsigned char actual[32];
    unsigned char expected[32];
    unsigned char original[32];

    for (size_t i = 0; i < sizeof(actual); ++i)
    {
        unsigned char value = (unsigned char)(i + 1);
        actual[i] = value;
        expected[i] = value;
        original[i] = value;
    }
    void *actual_ptr = ft_memmove(actual + dest_offset, actual + src_offset, len);
    memmove(expected + dest_offset, expected + src_offset, len);
    if (actual_ptr != actual + dest_offset)
    {
        fprintf(stderr, "[ft_memmove] Return pointer mismatch in case '%s'\n", label);
        assert(0);
    }
    if (memcmp(actual, expected, sizeof(actual)) != 0)
    {
        fprintf(stderr, "[ft_memmove] Buffer mismatch in case '%s'\n", label);
        fprintf(stderr, "  Before: ");
        for (size_t i = 0; i < sizeof(original); ++i)
            fprintf(stderr, "%u ", (unsigned)original[i]);
        fprintf(stderr, "\n  Expected: ");
        for (size_t i = 0; i < sizeof(expected); ++i)
            fprintf(stderr, "%u ", (unsigned)expected[i]);
        fprintf(stderr, "\n  Actual: ");
        for (size_t i = 0; i < sizeof(actual); ++i)
            fprintf(stderr, "%u ", (unsigned)actual[i]);
        fprintf(stderr, "\n");
        assert(0);
    }
}

void    run_ft_memmove_tests(void)
{
    run_case("no overlap forward", 0, 8, 8);
    run_case("no overlap backward", 8, 0, 8);
    run_case("overlap forward", 4, 0, 16);
    run_case("overlap backward", 0, 4, 16);
    run_case("self move", 0, 0, 32);
    run_case("zero length", 10, 2, 0);
    printf("ft_memmove: all %s tests passed\n", "6");
}
