/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 18:40:04 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/20 18:40:05 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				cmp;
	unsigned char	*ts1;
	unsigned char	*ts2;

	if (n == 0)
		return (0);
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	cmp = 0;
	while (i < (n - 1))
	{
		cmp = ts1[i] - ts2[i];
		if (cmp != 0)
			return (cmp);
		i++;
	}
	cmp = ts1[i] - ts2[i];
	return (cmp);
}
