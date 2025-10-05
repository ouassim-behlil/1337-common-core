#include <assert.h>
#include <stddef.h>
#include <stdio.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t len);

static char *reference_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  needle_len;

    if (*needle == '\0')
        return (char *)haystack;
    needle_len = 0;
    while (needle[needle_len] != '\0')
        ++needle_len;
    for (size_t i = 0; haystack[i] != '\0' && i + needle_len <= len; ++i)
    {
        size_t  j = 0;

        while (j < needle_len && haystack[i + j] == needle[j])
            ++j;
        if (j == needle_len)
            return (char *)(haystack + i);
    }
    return NULL;
}

static void run_case(const char *label, const char *haystack, const char *needle, size_t len)
{
    char    *expected;
    char    *actual;

    expected = reference_strnstr(haystack, needle, len);
    actual = ft_strnstr(haystack, needle, len);
    if (expected != actual)
    {
        fprintf(stderr, "[ft_strnstr] Pointer mismatch in case '%s': expected %p, got %p\n",
            label, (void *)expected, (void *)actual);
        assert(0);
    }
}

void    run_ft_strnstr_tests(void)
{
    static const char hay[] = "Find the needle in this haystack";

    run_case("empty needle", hay, "", 0);
    run_case("match at start", hay, "Find", sizeof(hay));
    run_case("match in middle", hay, "needle", sizeof(hay));
    run_case("match at boundary", hay, "hay", 31);
    run_case("insufficient length", hay, "needle", 8);
    run_case("no match", hay, "absent", sizeof(hay));
    run_case("partial overlap", hay, "stack", 33);
    run_case("len shorter than needle", hay, "needle", 5);
    run_case("zero len non empty needle", hay, "Find", 0);
    printf("ft_strnstr: all %s tests passed\n", "9");
}
