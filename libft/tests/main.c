#include <stdio.h>

void    run_ft_bzero_tests(void);
void    run_ft_atoi_tests(void);
void    run_ft_calloc_tests(void);
void    run_ft_case_conversion_tests(void);
void    run_ft_char_class_tests(void);
void    run_ft_memchr_tests(void);
void    run_ft_memcmp_tests(void);
void    run_ft_memcpy_tests(void);
void    run_ft_memmove_tests(void);
void    run_ft_memset_tests(void);
void    run_ft_strchr_tests(void);
void    run_ft_strlcat_tests(void);
void    run_ft_strlcpy_tests(void);
void    run_ft_strlen_tests(void);
void    run_ft_strncmp_tests(void);
void    run_ft_strnstr_tests(void);
void    run_ft_strrchr_tests(void);
void    run_ft_split_tests(void);
void    run_ft_itoa_tests(void);
void    run_ft_putstr_fd_tests(void);
void    run_ft_putendl_fd_tests(void);
void    run_ft_putnbr_fd_tests(void);

int main(void)
{
    run_ft_bzero_tests();
    run_ft_atoi_tests();
    run_ft_calloc_tests();
    run_ft_case_conversion_tests();
    run_ft_char_class_tests();
    run_ft_memchr_tests();
    run_ft_memcmp_tests();
    run_ft_memcpy_tests();
    run_ft_memmove_tests();
    run_ft_memset_tests();
    run_ft_strchr_tests();
    run_ft_strlcat_tests();
    run_ft_strlcpy_tests();
    run_ft_strlen_tests();
    run_ft_strncmp_tests();
    run_ft_strnstr_tests();
    run_ft_strrchr_tests();
    run_ft_split_tests();
    run_ft_itoa_tests();
    run_ft_putstr_fd_tests();
    run_ft_putendl_fd_tests();
    run_ft_putnbr_fd_tests();
    puts("All tests completed successfully.");
    return (0);
}
