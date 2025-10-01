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
	size_t	dLen;
	size_t	sLen;
	size_t	i;
	size_t	j;

	dLen = ft_strlen(dest);
	sLen = ft_strlen(src);
	if (dsize == 0 || dsize <= dLen)
		return (dsize + sLen);
	i = 0;
	j = dLen;
	while ((j < dsize - 1) && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dLen + sLen);
}