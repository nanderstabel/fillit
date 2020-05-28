/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 17:49:22 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/13 17:49:24 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static void	ft_neg(int neg, long long *convert)
{
	if (neg == 1)
		*convert *= -1;
}

static void	ft_min(const char *str, int *i, int *neg)
{
	if (str[*i] == '-')
	{
		*i = *i + 1;
		*neg = *neg + 1;
	}
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	convert;
	int			neg;

	neg = 0;
	i = 0;
	convert = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r' || (str[i] == '+' && str[i + 1] != '+'))
	{
		if (str[i] == '+' && str[i + 1] == '-')
			return (0);
		i++;
	}
	ft_min(str, &i, &neg);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		convert = convert + str[i] - '0';
		if (str[i + 1] != '\0' && str[i + 1] >= '0' && str[i + 1] <= '9')
			convert *= 10;
		i++;
	}
	ft_neg(neg, &convert);
	return (convert);
}
