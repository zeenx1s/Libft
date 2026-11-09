/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcmp.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 03:08:47 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:34:13 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2)
		return (0);
	while (n > i && ((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
