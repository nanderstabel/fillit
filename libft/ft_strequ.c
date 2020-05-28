/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 16:13:20 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/26 16:13:22 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		l1;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	if (l1 != l2)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
