#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

static void run_memcmp_case(const char *label, const void *a, const void *b, size_t len)
{
    int expected;
    int actual;

    expected = memcmp(a, b, len);
    actual = ft_memcmp(a, b, len);
    if (actual != expected)
    {
        fprintf(stderr, "[ft_memcmp] Result mismatch in case '%s': expected %d, got %d\n", label, expected, actual);
        assert(0);
    }
    if ((actual == 0) != (expected == 0))
    {
        fprintf(stderr, "[ft_memcmp] Equality mismatch in case '%s'\n", label);
        assert(0);
    }
}

void    run_ft_memcmp_tests(void)
{
    static const unsigned char same_left[] = "abcdef";
    static const unsigned char same_right[] = "abcdef";
    static const unsigned char diff_first_left[] = "xbcdef";
    static const unsigned char diff_first_right[] = "abcdef";
    static const unsigned char diff_last_left[] = "abcdez";
    static const unsigned char diff_last_right[] = "abcdef";
    static const unsigned char binary_left[] = {0x00, 0x01, 0x02, 0x03};
    static const unsigned char binary_right[] = {0x00, 0x01, 0x02, 0xFF};
    static const unsigned char embedded_nul_left[] = {'a', '\0', 'c', 'd'};
    static const unsigned char embedded_nul_right[] = {'a', '\0', 'c', 'a'};
    static const unsigned char unsigned_cmp_left[] = {0x80, 0x00, 0x7F};
    static const unsigned char unsigned_cmp_right[] = {0x01, 0x00, 0x7F};

    run_memcmp_case("identical buffers", same_left, same_right, 6);
    run_memcmp_case("different first byte", diff_first_left, diff_first_right, 6);
    run_memcmp_case("different last byte", diff_last_left, diff_last_right, 6);
    run_memcmp_case("zero length", diff_last_left, diff_last_right, 0);
    run_memcmp_case("binary data", binary_left, binary_right, 4);
    run_memcmp_case("difference after nul", embedded_nul_left, embedded_nul_right, 4);
    run_memcmp_case("unsigned comparison", unsigned_cmp_left, unsigned_cmp_right, 3);
    printf("ft_memcmp: all %s tests passed\n", "7");
}
