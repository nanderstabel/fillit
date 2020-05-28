/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:31:33 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/16 17:31:34 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		t;

	i = 0;
	t = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		t++;
	}
	while (i < len && dst[i] != '\0' && src[t] == '\0')
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
