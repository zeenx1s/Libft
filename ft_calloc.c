/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/07 07:09:00 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:34:30 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*mem;
	size_t	total;

	if (size != 00 && n > SIZE_MAX / size)
		return (NULL);
	total = n * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
