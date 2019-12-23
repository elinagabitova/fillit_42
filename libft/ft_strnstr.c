/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:42:36 by toberon           #+#    #+#             */
/*   Updated: 2019/09/13 18:42:36 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;
	char		*res;

	res = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (res);
	while (haystack[i] != '\0' && n > 0)
	{
		j = 0;
		while ((needle[j] == haystack[i + j]) && (n > 0))
		{
			if (needle[j + 1] == '\0')
			{
				return (res + i);
			}
			j++;
			n--;
		}
		n = n + j;
		i++;
		n--;
	}
	return (0);
}
