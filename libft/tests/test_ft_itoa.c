#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_itoa(int n);

static void run_case(const char *label, int value)
{
    char    expected[64];
    char    *actual;

    if (snprintf(expected, sizeof(expected), "%d", value) < 0)
    {
        fprintf(stderr, "[ft_itoa] Failed to format expected result for case '%s'\n", label);
        assert(0);
    }
    actual = ft_itoa(value);
    if (!actual)
    {
        fprintf(stderr, "[ft_itoa] Returned NULL for case '%s' (input %d)\n", label, value);
        assert(0);
    }
    if (strcmp(actual, expected) != 0)
    {
        fprintf(stderr, "[ft_itoa] Mismatch in case '%s': expected '%s', got '%s'\n", label, expected, actual);
        free(actual);
        assert(0);
    }
    free(actual);
}

void    run_ft_itoa_tests(void)
{
    run_case("zero", 0);
    run_case("positive single digit", 7);
    run_case("negative single digit", -3);
    run_case("positive multi digit", 12345);
    run_case("negative multi digit", -98765);
    run_case("int max", INT_MAX);
    run_case("int min", INT_MIN);
    printf("ft_itoa: all 7 tests passed\n");
}
