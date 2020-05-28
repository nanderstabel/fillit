/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 12:19:20 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/17 12:19:22 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *restrict s2, size_t n)
{
	size_t		in1;
	size_t		in2;

	in1 = 0;
	in2 = 0;
	while (s1[in1] != '\0')
		in1++;
	while (in2 < n && s2[in2] != '\0')
	{
		s1[in1] = s2[in2];
		in1++;
		in2++;
	}
	s1[in1] = '\0';
	return (s1);
}
