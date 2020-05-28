/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/09/29 21:57:35 by bwaarle       #+#    #+#                 */
/*   Updated: 2018/09/29 21:57:38 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int val;

	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	val = nb * ft_power(nb, power - 1);
	return (val);
}
