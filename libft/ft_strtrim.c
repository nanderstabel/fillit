/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 19:26:56 by bwaarle       #+#    #+#                 */
/*   Updated: 2019/01/25 19:26:58 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_blank(void)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 1);
	str[i] = '\0';
	return (str);
}

static char	ft_increase(const char *s, char *str, int *i, int *j)
{
	str[*j] = s[*i];
	*i += 1;
	*j += 1;
	return (str[*i]);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_blank());
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	str = (char *)malloc(sizeof(char) * ((len - i) + 2));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[j] = ft_increase(s, str, &i, &j);
	}
	str[j] = '\0';
	return (str);
}
