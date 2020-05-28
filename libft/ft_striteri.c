/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 15:40:46 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/25 15:40:47 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		s++;
		i++;
	}
}
