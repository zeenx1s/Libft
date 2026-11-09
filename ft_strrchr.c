/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/05 20:09:30 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:33:45 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	while (s_len > 0)
	{
		s_len--;
		if (s[s_len] == (char) c)
			return (((char *) & s[s_len]));
	}
	return (NULL);
}
