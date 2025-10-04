#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    ft_putendl_fd(char *s, int fd);

static char *capture_output(char *input)
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
    ft_putendl_fd(input, pipefd[1]);
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

static void run_case(const char *label, char *input, const char *expected)
{
    char *actual = capture_output(input);

    if (strcmp(actual, expected) != 0)
    {
        fprintf(stderr, "[ft_putendl_fd] Mismatch in case '%s': expected '%s', got '%s'\n", label, expected, actual);
        free(actual);
        assert(0);
    }
    free(actual);
}

void    run_ft_putendl_fd_tests(void)
{
    run_case("basic", "hello", "hello\n");
    run_case("empty", "", "\n");
    run_case("null", NULL, "");
    printf("ft_putendl_fd: all 3 tests passed\n");
}
