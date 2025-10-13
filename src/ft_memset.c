/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:04:08 by obehlil           #+#    #+#             */
/*   Updated: 2025/10/13 14:04:09 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	char			*p;

	uc = (unsigned char)c;
	p = (char *)ptr;
	i = 0;
	while (i < n)
		p[i++] = uc;
	return (ptr);
}
