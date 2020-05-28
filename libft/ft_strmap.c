/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 15:38:41 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/25 15:38:42 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	fs = (char *)malloc(sizeof(char) * (i + 1));
	if (fs == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		fs[i] = f(s[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
