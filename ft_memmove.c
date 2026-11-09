/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 02:32:47 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:34:09 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	if (src > dest)
	{
		i = 0;
		while (n > i)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *) dest)[n - 1] = ((unsigned char *) src)[n - 1];
			n--;
		}
	}
	return (dest);
}
