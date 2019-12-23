/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:00:05 by toberon           #+#    #+#             */
/*   Updated: 2019/09/12 18:00:06 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nstr = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (nstr == NULL)
		return (0);
	while (*s1 != '\0')
	{
		nstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		nstr[i] = *s2;
		i++;
		s2++;
	}
	nstr[i] = '\0';
	return (nstr);
}
