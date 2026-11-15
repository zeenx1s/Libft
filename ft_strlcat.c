/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/05 08:26:08 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/11 14:39:53 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	i;
	size_t	j;

	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size == 0)
		return (src_l);
	while (i < size && dst[i])
		i++;
	if (size == i)
		return (size + src_l);
	while (size - 1 > i + j && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (src_l + dst_l);
}
