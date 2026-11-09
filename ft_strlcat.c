/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/05 08:26:08 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:33:56 by yaattaou        ###   ########.fr        */
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
	return (src_l + dst_l);
}

// int	main(void)
// {
// 	char	u[] = "00000";
// 	char	p[] = "12345";

// 	ft_strlcat(p, u, 0);
// 	printf("%s\n%s", u, p);
// }
