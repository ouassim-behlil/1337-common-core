#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlcat(char *dest, const char *src, size_t dsize);
size_t  ft_strlen(const char *s);

#define MAX_BUFFER 64
#define SENTINEL '\xAA'

static size_t	reference_strlcat(char *dest, const char *src, size_t dsize)
{
    size_t  d_len;
    size_t  s_len;
    size_t  i;
    size_t  j;

    d_len = strlen(dest);
    s_len = strlen(src);
    if (dsize == 0 || dsize <= d_len)
        return (dsize + s_len);
    i = 0;
    j = d_len;
    while (j < dsize - 1 && src[i] != '\0')
        dest[j++] = src[i++];
    dest[j] = '\0';
    return (d_len + s_len);
}

static void	check_sentinels(const char *buffer, size_t dsize, size_t initial_len, const char *label)
{
    size_t  idx;
    size_t  boundary;

    boundary = initial_len + 1;
    if (dsize > boundary)
        boundary = dsize;
    if (boundary >= MAX_BUFFER)
        return ;
    idx = boundary;
    while (idx < MAX_BUFFER)
    {
        if ((unsigned char)buffer[idx] != (unsigned char)SENTINEL)
        {
            fprintf(stderr, "[ft_strlcat] Sentinel overwritten in case '%s' at index %zu\n", label, idx);
            assert(0);
        }
        idx++;
    }
}

static void	run_case(const char *label, const char *initial, const char *src, size_t dsize)
{
    char    actual[MAX_BUFFER];
    char    expected[MAX_BUFFER];
    size_t  expected_ret;
    size_t  actual_ret;
    size_t  initial_len;

    memset(actual, SENTINEL, sizeof(actual));
    memset(expected, SENTINEL, sizeof(expected));
    initial_len = strlen(initial);
    assert(initial_len < MAX_BUFFER);
    strcpy(actual, initial);
    strcpy(expected, initial);
    expected_ret = reference_strlcat(expected, src, dsize);
    actual_ret = ft_strlcat(actual, src, dsize);
    if (actual_ret != expected_ret)
    {
        fprintf(stderr, "[ft_strlcat] Return mismatch in case '%s': expected %zu, got %zu\n", label, expected_ret, actual_ret);
        assert(0);
    }
    if (strcmp(actual, expected) != 0)
    {
        fprintf(stderr, "[ft_strlcat] Buffer mismatch in case '%s':\n  expected '%s'\n  got      '%s'\n", label, expected, actual);
        assert(0);
    }
    if (strlen(actual) != ft_strlen(actual))
    {
        fprintf(stderr, "[ft_strlcat] Length mismatch between strlen and ft_strlen in case '%s'\n", label);
        assert(0);
    }
    check_sentinels(actual, dsize, initial_len, label);
}

void    run_ft_strlcat_tests(void)
{
    run_case("basic append fits", "abc", "def", 16);
    run_case("exact fit with nul", "abc", "def", 7);
    run_case("partial append", "abc", "def", 5);
    run_case("no space to append", "abcdef", "XYZ", 3);
    run_case("zero size", "hello", "world", 0);
    run_case("empty source", "prefix", "", 10);
    run_case("empty dest", "", "suffix", 10);
    run_case("single byte room", "abcd", "efgh", 5);
    run_case("large source clipped", "start", "abcdefghijklmnopqrstuvwxyz", 12);
    run_case("dest already long", "longdestination", "short", 32);
    printf("ft_strlcat: all %s tests passed\n", "10");
}
