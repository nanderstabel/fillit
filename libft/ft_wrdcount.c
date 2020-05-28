/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrdcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:56:49 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/02/22 12:56:50 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_wrdcount(char const *s, char c)
{
	int		wrds;
	int		i;

	i = 0;
	wrds = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			wrds++;
		}
		i++;
	}
	return (wrds);
}
