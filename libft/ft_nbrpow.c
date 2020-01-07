/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:26:54 by toberon           #+#    #+#             */
/*   Updated: 2019/09/23 17:26:54 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrpow(int n, int power)
{
	int nb;

	nb = n;
	if (n == 0 && power == 0)
		return (1);
	if (power == 1)
		return (n);
	while (power > 1)
	{
		n = n * nb;
		power--;
	}
	return (n);
}
