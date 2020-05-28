/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 20:17:07 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/20 20:17:08 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = ft_strlen(str);
	while (i > -1)
	{
		if (s[i] == c || (s[i] == '\0' && c == '\0'))
		{
			return (s + i);
		}
		i--;
	}
	return (NULL);
}
