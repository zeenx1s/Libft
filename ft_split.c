/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 18:08:47 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:45:16 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_free(char **str, size_t words)
{
	while (words > 0)
	{
		words--;
		free(str[words]);
		str[words] = NULL;
	}
	free(str);
	str = NULL;
	return (0);
}

static int	ft_splitter(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (s[j] && s[j] != c)
			j++;
		len = j;
		str[i] = malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (ft_free(str, i));
		ft_memcpy(str[i], s, len);
		str[i][len] = '\0';
		i++;
		s = s + len;
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_counter(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	if (!ft_splitter(str, s, c))
		return (NULL);
	return (str);
}
