#include <assert.h>
#include <stdio.h>
#include <string.h>

char    *ft_strrchr(const char *s, int c);

static void run_case(const char *label, const char *haystack, int needle)
{
    char    *expected;
    char    *actual;

    expected = strrchr(haystack, needle);
    actual = ft_strrchr(haystack, needle);
    if (expected != actual)
    {
        fprintf(stderr, "[ft_strrchr] Pointer mismatch in case '%s': expected %p, got %p\n",
            label, (void *)expected, (void *)actual);
        assert(0);
    }
}

void    run_ft_strrchr_tests(void)
{
    static const char sample[] = "abra\xDA" "cadabra\0tail";

    run_case("last occurrence", sample, 'a');
    run_case("single occurrence", sample, 'c');
    run_case("not present", sample, 'z');
    run_case("find terminator", sample, '\0');
    run_case("high bit value", sample, '\xDA');
    run_case("negative needle", sample, -38);
    printf("ft_strrchr: all %s tests passed\n", "6");
}
