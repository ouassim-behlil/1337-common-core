# libft

Simple reimplementation of a core set of C standard library routines used at 1337/42 projects. The code lives in `src/` and builds into the static library `libft.a`.

## Getting Started
- `cd src`
- `make` builds the mandatory library
- `make bonus` adds the linked-list helpers to the archive
- `make clean`, `make fclean`, `make re` keep the workspace tidy

To use the library, include `libft.h` and link the archive, e.g.:

```sh
gcc -Wall -Wextra -Werror main.c src/libft.a -I src
```

## Function Overview
| Category | Functions | Description |
| --- | --- | --- |
| Character helpers | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_tolower`, `ft_toupper` | Character classification and ASCII case conversion wrappers. |
| Memory & allocation | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` | Low-level memory fill, copy, search, comparison, and zero-initialized allocation utilities. |
| String length & copy | `ft_strlen`, `ft_strlcpy`, `ft_strlcat` | Measure string length and perform bounded copies/concatenations. |
| String search & iteration | `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strmapi`, `ft_striteri` | Locate substrings or characters and apply callbacks across string contents. |
| String creation | `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` | Allocate new strings through duplication, slicing, trimming, joining, or tokenizing. |
| Conversion & output | `ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Convert between text and integers, write characters and numbers to file descriptors. |
| Bonus linked list | `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` | Singly linked list node creation, traversal, mutation, and cleanup helpers. |

