#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    ft_putnbr_fd(int n, int fd);

static char *capture_output(int value)
{
    int     pipefd[2];
    char    buffer[32];
    char    *result;
    size_t  size;
    ssize_t read_bytes;

    if (pipe(pipefd) != 0)
    {
        perror("pipe");
        assert(0);
    }
    ft_putnbr_fd(value, pipefd[1]);
    close(pipefd[1]);
    result = NULL;
    size = 0;
    while ((read_bytes = read(pipefd[0], buffer, sizeof(buffer))) > 0)
    {
        char *newbuf = realloc(result, size + read_bytes + 1);
        if (!newbuf)
        {
            free(result);
            close(pipefd[0]);
            assert(0);
        }
        result = newbuf;
        memcpy(result + size, buffer, read_bytes);
        size += read_bytes;
    }
    if (read_bytes < 0)
    {
        perror("read");
        free(result);
        close(pipefd[0]);
        assert(0);
    }
    close(pipefd[0]);
    if (!result)
    {
        result = malloc(1);
        if (!result)
            assert(0);
    }
    result[size] = '\0';
    return (result);
}

static void run_case(const char *label, int value, const char *expected)
{
    char *actual = capture_output(value);

    if (strcmp(actual, expected) != 0)
    {
        fprintf(stderr, "[ft_putnbr_fd] Mismatch in case '%s': expected '%s', got '%s'\n", label, expected, actual);
        free(actual);
        assert(0);
    }
    free(actual);
}

void    run_ft_putnbr_fd_tests(void)
{
    run_case("zero", 0, "0");
    run_case("positive", 42, "42");
    run_case("negative", -42, "-42");
    run_case("int max", INT_MAX, "2147483647");
    run_case("int min", INT_MIN, "-2147483648");
    printf("ft_putnbr_fd: all 5 tests passed\n");
}
