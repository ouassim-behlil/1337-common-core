#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;
	size_t			slength;

	i = 0;
	j = start;
	slength = ft_strlen(s);
	if (start >= slength)
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len && start + i < slength)
		sub[i++] = s[j++];
	sub[i] = '\0';
	return (sub);
}

static int	is_in_set(int c, const char *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	size_t		start;
	size_t		end;
	size_t		len;

	start = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strdup(""));
	end = len - 1;
	while (s[start] && is_in_set(s[start], set))
		start++;
	while (end >= start && is_in_set(s[end], set))
		end--;
	return (ft_substr(s, (unsigned int)start, (end - start + 1)));
}
