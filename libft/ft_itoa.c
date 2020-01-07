/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:35:05 by toberon           #+#    #+#             */
/*   Updated: 2019/09/13 18:35:06 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbneg(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static int		ft_nblen(int n)
{
	int len;

	len = 0;
	while ((n / 10) != 0)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

static char		*ft_itoacat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		buf[i + j] = s2[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

char			*ft_itoa(int n)
{
	char		*fresh;
	int			nlen;
	char		*end;
	int			neg;
	long int	nb;

	nb = n;
	neg = ft_nbneg(nb);
	end = "-";
	(neg < 0 ? nb = nb * -1 : nb);
	nlen = ft_nblen(nb);
	fresh = malloc(sizeof(char) * nlen + 1);
	if (fresh == NULL)
		return (0);
	fresh[nlen] = '\0';
	while (nlen != 0)
	{
		fresh[nlen - 1] = (nb % 10 + 48);
		nb = nb / 10;
		nlen--;
	}
	if (neg < 0)
		return (ft_itoacat(end, fresh));
	return (fresh);
}
