/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:09:46 by toberon           #+#    #+#             */
/*   Updated: 2019/09/22 15:09:47 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;
	unsigned char ch;

	src = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*src == ch)
		{
			return (src);
		}
		src++;
		n--;
	}
	return (0);
}
