/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:42:20 by toberon           #+#    #+#             */
/*   Updated: 2019/09/13 18:42:20 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * size + 1);
	i = 0;
	if (str == NULL)
		return (0);
	while (size + 1 != 0)
	{
		str[i] = '\0';
		size--;
		i++;
	}
	return (str);
}
