#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_calloc(size_t count, size_t size);

static void check_zeroed(const char *label, void *ptr, size_t total)
{
    unsigned char   *bytes;

    if (ptr == NULL && total != 0)
    {
        fprintf(stderr, "[ft_calloc] Null pointer for case '%s' with %zu bytes\n",
            label, total);
        assert(0);
    }
    bytes = (unsigned char *)ptr;
    for (size_t i = 0; i < total; ++i)
    {
        if (bytes[i] != 0)
        {
            fprintf(stderr, "[ft_calloc] Non-zero byte at index %zu in case '%s'\n",
                i, label);
            assert(0);
        }
    }
}

static void run_basic_case(const char *label, size_t count, size_t size)
{
    size_t  total;
    void    *actual;
    void    *control;

    total = count * size;
    control = calloc(count, size);
    actual = ft_calloc(count, size);
    if (total != 0 && (!!actual != !!control))
    {
        fprintf(stderr, "[ft_calloc] Nullness mismatch in case '%s'\n", label);
        assert(0);
    }
    if (control != NULL)
    {
        if (total != 0 && memcmp(control, actual, total) != 0)
        {
            fprintf(stderr, "[ft_calloc] Zero initialization mismatch in case '%s'\n",
                label);
            assert(0);
        }
    }
    else
        check_zeroed(label, actual, total);
    free(control);
    free(actual);
}

static void run_overflow_case(const char *label, size_t count, size_t size)
{
    void    *actual;

    actual = ft_calloc(count, size);
    if (actual != NULL)
    {
        fprintf(stderr, "[ft_calloc] Expected NULL for overflow case '%s'\n",
            label);
        free(actual);
        assert(0);
    }
}

void    run_ft_calloc_tests(void)
{
    run_basic_case("small integers", 10, sizeof(int));
    run_basic_case("struct sized", 5, 24);
    run_basic_case("single byte", 32, 1);
    run_basic_case("zero sized operands", 0, 0);
    run_basic_case("zero count", 0, sizeof(long));
    run_basic_case("zero size", 7, 0);
    run_overflow_case("overflow detection", SIZE_MAX, 2);
    run_overflow_case("overflow near limit", SIZE_MAX / 2 + 1, 3);
    printf("ft_calloc: all %s tests passed\n", "8");
}
