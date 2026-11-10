/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yaattaou <yaattaou@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 21:47:00 by yaattaou         #+#    #+#              */
/*   Updated: 2026/11/10 03:27:29 by yaattaou        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	ft_helper(size_t len, size_t i, long n, char *str)
{
	while (len > i)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	long	c;
	char	*str;

	c = n;
	i = 0;
	len = ft_counter(c);
	if (c < 0)
	{
		c = -c;
		i++;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (i == 1)
		str[0] = '-';
	str[len] = '\0';
	ft_helper(len, i, c, str);
	return (str);
}
