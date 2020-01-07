/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:44:10 by toberon           #+#    #+#             */
/*   Updated: 2019/09/18 19:44:11 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	int		i;
	char	*buf;

	buf = dest;
	i = 0;
	if (!dest && !src)
		return (0);
	while (len > 0 && *src != '\0')
	{
		*dest = *src;
		len--;
		src++;
		dest++;
	}
	while (len > 0)
	{
		*dest = '\0';
		dest++;
		len--;
	}
	return (buf);
}
