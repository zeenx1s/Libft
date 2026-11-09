/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 16:30:34 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/09 21:45:42 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *) big);
	while (len > 0 && *big)
	{
		i = 0;
		if (*big == *little)
		{
			while (little[i] != '\0' && i < len && big[i] == little[i])
				i++;
			if (little[i] == '\0')
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
