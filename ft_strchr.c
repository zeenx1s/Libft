/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/05 18:50:41 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:34:02 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (((char) c) == '\0')
	{
		return ((char *)(s + s_len));
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
