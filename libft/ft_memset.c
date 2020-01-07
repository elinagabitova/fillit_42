/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:02:46 by toberon           #+#    #+#             */
/*   Updated: 2019/09/07 20:03:01 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*st;
	size_t			i;

	i = 0;
	st = (unsigned char*)s;
	while (n > 0)
	{
		st[i] = (char)c;
		i++;
		n--;
	}
	return (st);
}
