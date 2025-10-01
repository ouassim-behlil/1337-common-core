#include <stdio.h>

void    run_ft_bzero_tests(void);
void    run_ft_char_class_tests(void);
void    run_ft_memcmp_tests(void);
void    run_ft_memmove_tests(void);
void    run_ft_memset_tests(void);
void    run_ft_strlcat_tests(void);
void    run_ft_strlcpy_tests(void);
void    run_ft_strlen_tests(void);
void    run_ft_strncmp_tests(void);

int main(void)
{
    run_ft_bzero_tests();
    run_ft_char_class_tests();
    run_ft_memcmp_tests();
    run_ft_memmove_tests();
    run_ft_memset_tests();
    run_ft_strlcat_tests();
    run_ft_strlcpy_tests();
    run_ft_strlen_tests();
    run_ft_strncmp_tests();
    puts("All tests completed successfully.");
    return (0);
}
