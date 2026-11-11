/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 06:23:56 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/11 15:29:27 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	m;
	size_t	i;

	i = 0;
	m = (unsigned char) c;
	while (n > i)
	{
		((char *) s)[i] = m;
		i++;
	}
	return (s);
}
