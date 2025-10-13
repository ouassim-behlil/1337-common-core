/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:03:40 by obehlil           #+#    #+#             */
/*   Updated: 2025/10/13 14:03:41 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*m;

	i = 0;
	s = (const unsigned char *)str;
	m = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (&m[i]);
		i++;
	}
	return (NULL);
}
