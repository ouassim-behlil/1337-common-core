#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    *ft_memset(void *ptr, int c, size_t n);

static void run_case(const char *label, unsigned char fill, size_t offset, size_t len)
{
    unsigned char actual[32];
    unsigned char expected[32];

    memset(actual, 0xAA, sizeof(actual));
    memset(expected, 0xAA, sizeof(expected));
    unsigned char buffer[32];
    for (size_t i = 0; i < sizeof(buffer); ++i)
        buffer[i] = (unsigned char)(i + 1);
    memcpy(actual, buffer, sizeof(buffer));
    memcpy(expected, buffer, sizeof(buffer));
    void *ret_actual = ft_memset(actual + offset, fill, len);
    void *ret_expected = memset(expected + offset, fill, len);
    if (ret_actual != actual + offset)
    {
        fprintf(stderr, "[ft_memset] Return pointer mismatch in case '%s'\n", label);
        assert(0);
    }
    if (memcmp(actual, expected, sizeof(actual)) != 0)
    {
        fprintf(stderr, "[ft_memset] Buffer mismatch in case '%s'\n", label);
        assert(0);
    }
    (void)ret_expected;
}

void    run_ft_memset_tests(void)
{
    run_case("zero length", 0xFF, 4, 0);
    run_case("full buffer", 0x11, 0, 32);
    run_case("partial front", 0xCC, 0, 10);
    run_case("partial middle", 0x55, 10, 5);
    run_case("partial tail", 0x00, 20, 12);
    printf("ft_memset: all %s tests passed\n", "5");
}
