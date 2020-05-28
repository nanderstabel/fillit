/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:48:03 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/12 17:48:04 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;
	int				i;

	i = 0;
	uc = b;
	while (len > 0)
	{
		uc[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (uc);
}
