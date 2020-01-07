/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:43:26 by toberon           #+#    #+#             */
/*   Updated: 2019/09/13 18:43:27 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*str;

	n = ft_strlen(s);
	str = (char *)s;
	while (n + 1 > 0)
	{
		if (str[n] == c)
			return (&str[n]);
		n--;
	}
	return (0);
}
