/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 19:49:05 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/15 19:49:06 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				diff;
	size_t			it;

	i = 0;
	diff = 0;
	it = 0;
	while (it < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0 || (s1[i] == '\0' && s2[i] == '\0'))
		{
			return (diff);
		}
		i++;
		it++;
	}
	return (diff);
}
