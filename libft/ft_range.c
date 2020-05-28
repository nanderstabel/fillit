/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:08:39 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/09 15:08:40 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		div;
	int		*array;

	div = max - min;
	if (div <= 0)
		return (NULL);
	i = 0;
	array = (int *)malloc(sizeof(*array) * (div + 1));
	while (i < div)
	{
		array[i] = min;
		i++;
		min++;
	}
	array[i] = '\0';
	return (array);
}
