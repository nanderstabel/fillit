/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 16:13:32 by bwaarle       #+#    #+#                 */
/*   Updated: 2020/05/28 16:27:40 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_wrdlen(char const *s, char c)
{
	int		wrdlen;
	int		i;

	i = 0;
	wrdlen = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			wrdlen++;
		}
		i++;
	}
	return (wrdlen);
}

static char	*ft_words(char const *s, char c, int *i)
{
	int		len;
	char	*str;

	len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		*i = *i + 1;
	}
	*i = *i - len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		str[len] = s[*i];
		len++;
		*i = *i + 1;
	}
	str[len] = '\0';
	len = 0;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		wrdlen;
	char	**arr;

	if (s == NULL)
		return (NULL);
	wrdlen = ft_wrdlen(s, c);
	arr = (char **)malloc(sizeof(char *) * (wrdlen + 1));
	if (arr == NULL)
		return (NULL);
	arr[wrdlen] = NULL;
	wrdlen = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			arr[wrdlen] = ft_words(s, c, &i);
			wrdlen++;
		}
	}
	return (arr);
}
