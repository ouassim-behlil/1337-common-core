#include <assert.h>
#include <stdio.h>
#include <string.h>

char    *ft_strchr(const char *s, int c);

static void run_case(const char *label, const char *haystack, int needle)
{
    char    *expected;
    char    *actual;

    expected = strchr(haystack, needle);
    actual = ft_strchr(haystack, needle);
    if (expected != actual)
    {
        fprintf(stderr, "[ft_strchr] Pointer mismatch in case '%s': expected %p, got %p\n",
            label, (void *)expected, (void *)actual);
        assert(0);
    }
}

void    run_ft_strchr_tests(void)
{
    static const char sample[] = "Hello, wor\xF1" "d\0 hidden";

    run_case("find first letter", sample, 'H');
    run_case("find comma", sample, ',');
    run_case("find repeated letter", sample, 'o');
    run_case("find multibyte", sample, '\xF1');
    run_case("find terminator", sample, '\0');
    run_case("not found", sample, 'z');
    run_case("negative needle", sample, -15);
    printf("ft_strchr: all %s tests passed\n", "7");
}
