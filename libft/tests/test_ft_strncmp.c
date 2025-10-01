#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

static void run_case(const char *label, const char *s1, const char *s2, size_t n)
{
    int expected = strncmp(s1, s2, n);
    int actual = ft_strncmp(s1, s2, n);

    if ((expected == 0) != (actual == 0))
    {
        fprintf(stderr, "[ft_strncmp] Equality mismatch in case '%s'\n", label);
        assert(0);
    }
    if ((expected < 0) != (actual < 0) || (expected > 0) != (actual > 0))
    {
        fprintf(stderr, "[ft_strncmp] Sign mismatch in case '%s': expected %d, got %d\n", label, expected, actual);
        assert(0);
    }
}

void    run_ft_strncmp_tests(void)
{
    run_case("identical full", "abcdef", "abcdef", 6);
    run_case("identical prefix shorter", "abcdef", "abcdef", 3);
    run_case("first diff", "xbcdef", "abcdef", 6);
    run_case("second longer", "abc", "abcdef", 6);
    run_case("zero length", "abc", "xyz", 0);
    run_case("unsigned compare", "\200", "\177", 2);
    printf("ft_strncmp: all %s tests passed\n", "6");
}
