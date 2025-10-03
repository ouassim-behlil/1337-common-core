#include <assert.h>
#include <limits.h>
#include <stdio.h>

int ft_atoi(const char *str);

static void run_case(const char *label, const char *input, int expected)
{
    int actual = ft_atoi(input);

    if (actual != expected)
    {
        fprintf(stderr, "[ft_atoi] Value mismatch in case '%s': expected %d, got %d\n",
            label, expected, actual);
        assert(0);
    }
}

void    run_ft_atoi_tests(void)
{
    run_case("simple positive", "42", 42);
    run_case("simple negative", "-42", -42);
    run_case("leading whitespace", "\t\n  123", 123);
    run_case("leading plus", "+99", 99);
    run_case("mixed whitespace and sign", " \f\v-256", -256);
    run_case("leading zeros", "000123", 123);
    run_case("stops at first non digit", "123abc", 123);
    run_case("only whitespace", "   ", 0);
    run_case("only plus", "+", 0);
    run_case("only minus", "-", 0);
    run_case("int max", "2147483647", INT_MAX);
    run_case("near int min", "-2147483647", -2147483647);
    run_case("embedded spaces after sign", "- 12", 0);
    printf("ft_atoi: all %s tests passed\n", "13");
}
