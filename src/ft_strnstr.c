/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:05:27 by obehlil           #+#    #+#             */
/*   Updated: 2025/10/13 14:05:27 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		nlength;

	i = 0;
	nlength = ft_strlen(needle);
	if (!nlength)
		return ((char *)haystack);
	while (i + nlength <= len && haystack[i])
	{
		j = 0;
		while (j < nlength && haystack[i + j] == needle[j])
			j ++;
		if (j == nlength)
			return ((char *)&haystack[i]);
		i ++;
	}
	return (NULL);
}
