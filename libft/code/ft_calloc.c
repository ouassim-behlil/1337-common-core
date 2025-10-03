#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	i = 0;
	cs = (char *)s;
	while (i < n)
		cs[i++] = '\0';
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (size != 0 && nitems > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
