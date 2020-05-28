/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 19:36:48 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/15 19:36:49 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				diff;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	diff = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (s1[i] != '\0')
	{
		diff = cs1[i] - cs2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	if (s2[i] != '\0')
		diff = cs1[i] - cs2[i];
	return (diff);
}
