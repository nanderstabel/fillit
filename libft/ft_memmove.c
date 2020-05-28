/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 14:28:25 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/19 14:28:29 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
