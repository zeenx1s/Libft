/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcpy.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 04:49:46 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:45:35 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = ft_strlen(src);
	if (size == 0)
		return (src_l);
	while (size - 1 > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}

// int	main(void)
// {
// 	char	s[20] = "helloooooo";
// 	char	d[20];

// 	ft_strlcpy(d, s, 16);
// 	printf("%s", d);
// 	return (0);
// }
