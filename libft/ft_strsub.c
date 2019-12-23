/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:58:06 by toberon           #+#    #+#             */
/*   Updated: 2019/09/11 18:58:07 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	int		i;
	char	*sstr;

	i = 0;
	if (s == NULL)
		return (NULL);
	sstr = malloc(sizeof(char) * n + 1);
	if (sstr == NULL)
		return (0);
	while (s[start] != '\0' && n > 0)
	{
		sstr[i] = s[start];
		i++;
		start++;
		n--;
	}
	sstr[i] = '\0';
	return (sstr);
}
