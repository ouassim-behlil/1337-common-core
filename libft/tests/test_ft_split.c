#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    **ft_split(const char *s, char c);

static void free_split(char **parts)
{
    size_t  i;

    if (!parts)
        return ;
    i = 0;
    while (parts[i])
    {
        free(parts[i]);
        i++;
    }
    free(parts);
}

static void run_case(const char *label, const char *input, char delim, const char *expected[])
{
    char    **actual;
    size_t  idx;

    actual = ft_split(input, delim);
    if (!actual)
    {
        fprintf(stderr, "[ft_split] Returned NULL for case '%s'\n", label);
        assert(0);
    }
    idx = 0;
    while (expected[idx])
    {
        if (!actual[idx])
        {
            fprintf(stderr, "[ft_split] Missing token %zu in case '%s' (expected '%s')\n", idx, label, expected[idx]);
            free_split(actual);
            assert(0);
        }
        if (strcmp(actual[idx], expected[idx]) != 0)
        {
            fprintf(stderr, "[ft_split] Mismatch in case '%s' at token %zu: expected '%s', got '%s'\n", label, idx, expected[idx], actual[idx]);
            free_split(actual);
            assert(0);
        }
        idx++;
    }
    if (actual[idx] != NULL)
    {
        fprintf(stderr, "[ft_split] Extra token '%s' in case '%s'\n", actual[idx], label);
        free_split(actual);
        assert(0);
    }
    free_split(actual);
}

void    run_ft_split_tests(void)
{
    const char  *expected_basic[] = {"lorem", "ipsum", "dolor", NULL};
    const char  *expected_trimmed[] = {"start", "middle", "end", NULL};
    const char  *expected_no_delim[] = {"solostring", NULL};
    const char  *expected_all_delim[] = {NULL};
    const char  *expected_empty[] = {NULL};
    const char  *expected_null_delim[] = {"null", NULL};

    run_case("basic words", "lorem ipsum dolor", ' ', expected_basic);
    run_case("multiple delimiters", ";;start;;middle;;;end;", ';', expected_trimmed);
    run_case("no delimiter present", "solostring", ',', expected_no_delim);
    run_case("all delimiters", ";;;;", ';', expected_all_delim);
    run_case("empty string", "", 'x', expected_empty);
    run_case("null delimiter", "null", '\0', expected_null_delim);
    printf("ft_split: all 6 tests passed\n");
}
