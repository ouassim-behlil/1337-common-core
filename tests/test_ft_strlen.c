#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *s);

static void run_case(const char *label, const char *input)
{
    size_t expected = strlen(input);
    size_t actual = ft_strlen(input);

    if (expected != actual)
    {
        fprintf(stderr, "[ft_strlen] Length mismatch in case '%s': expected %zu, got %zu\n", label, expected, actual);
        assert(0);
    }
}

void    run_ft_strlen_tests(void)
{
    run_case("empty", "");
    run_case("short", "abc");
    run_case("long", "this is a much longer string for testing purposes");
    run_case("with spaces", "leading and trailing ");
    run_case("single", "x");
    printf("ft_strlen: all %s tests passed\n", "5");
}
