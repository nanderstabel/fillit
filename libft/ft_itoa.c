/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 16:25:16 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/25 16:25:17 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int		len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	ft_convert(int nbr, int *len)
{
	char	c;
	int		l;

	l = *len;
	while (l > 1)
	{
		nbr /= 10;
		l--;
	}
	c = '0' + (nbr % 10);
	*len = *len - 1;
	return (c);
}

char		*ft_itoa(int nbr)
{
	int		i;
	int		len;
	char	*array;

	i = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	len = ft_nbrlen(nbr);
	array = (char *)malloc(sizeof(char) * (len + i + 1));
	if (array == NULL)
		return (NULL);
	if (i == 1)
		array[0] = '-';
	while (len >= 1)
	{
		array[i] = ft_convert(nbr, &len);
		i++;
	}
	array[i] = '\0';
	return (array);
}
