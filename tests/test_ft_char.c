#include <assert.h>
#include <stdio.h>

int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);

static int expected_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static int expected_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

static int expected_isalnum(int c)
{
    return (expected_isdigit(c) || expected_isalpha(c));
}

static int expected_isascii(int c)
{
    return (c >= 0 && c <= 127);
}

static int expected_isprint(int c)
{
    return (c >= 32 && c < 127);
}

static void check_match(const char *label, int (*fn)(int), int (*expected)(int))
{
    for (int c = -1; c <= 255; ++c)
    {
        int actual = fn(c);
        int want = expected(c);
        if ((actual != 0) != (want != 0))
        {
            fprintf(stderr, "[%s] Boolean mismatch for input %d: expected %d, got %d\n", label, c, want, actual);
            assert(0);
        }
    }
}

void    run_ft_char_class_tests(void)
{
    check_match("ft_isalpha", ft_isalpha, expected_isalpha);
    check_match("ft_isdigit", ft_isdigit, expected_isdigit);
    check_match("ft_isalnum", ft_isalnum, expected_isalnum);
    check_match("ft_isascii", ft_isascii, expected_isascii);
    check_match("ft_isprint", ft_isprint, expected_isprint);
    printf("char classification: all %s tests passed\n", "5");
}
