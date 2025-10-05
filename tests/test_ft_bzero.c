#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    ft_bzero(void *s, size_t n);

static void run_case(const char *label, size_t offset, size_t len)
{
    unsigned char buffer[16];
    unsigned char expected[16];

    for (size_t i = 0; i < sizeof(buffer); ++i)
    {
        buffer[i] = (unsigned char)(i + 1);
        expected[i] = (unsigned char)(i + 1);
    }
    ft_bzero(buffer + offset, len);
    memset(expected + offset, 0, len);
    if (memcmp(buffer, expected, sizeof(buffer)) != 0)
    {
        fprintf(stderr, "[ft_bzero] Buffer mismatch in case '%s'\n", label);
        assert(0);
    }
}

void    run_ft_bzero_tests(void)
{
    run_case("zero length", 3, 0);
    run_case("start of buffer", 0, 5);
    run_case("middle segment", 4, 6);
    run_case("end segment", 10, 6);
    run_case("entire buffer", 0, 16);
    printf("ft_bzero: all %s tests passed\n", "5");
}
