#include <assert.h>
#include <stdio.h>

int ft_tolower(int c);
int ft_toupper(int c);

static int expected_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

static int expected_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}

static void run_case(const char *label, int (*fn)(int), int (*expected)(int))
{
    for (int value = -1; value <= 255; ++value)
    {
        int actual = fn(value);
        int want = expected(value);

        if (actual != want)
        {
            fprintf(stderr, "[%s] Mismatch for input %d: expected %d, got %d\n",
                label, value, want, actual);
            assert(0);
        }
    }
}

void    run_ft_case_conversion_tests(void)
{
    run_case("ft_tolower", ft_tolower, expected_tolower);
    run_case("ft_toupper", ft_toupper, expected_toupper);
    printf("ft_case: all %s tests passed\n", "2");
}
