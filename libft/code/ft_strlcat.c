#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dlength;
	size_t	slength;
	size_t	i;
	size_t	j;

	dlength = ft_strlen(dest);
	slength = ft_strlen(src);
	if (dsize == 0 || dsize <= dlength)
		return (dsize + slength);
	i = 0;
	j = dlength;
	while ((j < dsize - 1) && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dlength + slength);
}
