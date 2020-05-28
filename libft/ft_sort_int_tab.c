/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 12:24:04 by exam          #+#    #+#                 */
/*   Updated: 2019/02/12 12:24:06 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;

	tmp = 0;
	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
