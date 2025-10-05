#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n);

static void run_case(const char *label, const void *haystack, int needle, size_t len)
{
    const unsigned char   *expected;
    const unsigned char   *actual;

    expected = memchr(haystack, needle, len);
    actual = ft_memchr(haystack, needle, len);
    if (expected != actual)
    {
        fprintf(stderr, "[ft_memchr] Pointer mismatch in case '%s': expected %p, got %p\n",
            label, (void *)expected, (void *)actual);
        assert(0);
    }
}

void    run_ft_memchr_tests(void)
{
    static const unsigned char data[] = {
        0x10, 0x20, 0x00, 0xFF, 0x30, 0xF0, 0x50
    };

    run_case("found at start", data, 0x10, sizeof(data));
    run_case("found in middle", data, 0xFF, sizeof(data));
    run_case("found at end", data, 0x50, sizeof(data));
    run_case("search for nul", data, '\0', sizeof(data));
    run_case("not present", data, 0xAA, sizeof(data));
    run_case("zero length", data, 0x10, 0);
    run_case("unsigned compare", data, -16, sizeof(data));
    printf("ft_memchr: all %s tests passed\n", "7");
}
