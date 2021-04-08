/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 08:44:54 by btammara          #+#    #+#             */
/*   Updated: 2020/12/04 16:15:41 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*simple(long long int n)
{
	char *str;

	if (n < 0)
	{
		if (!(str = (char *)malloc(sizeof(char) + 2)))
			return (NULL);
		str[0] = '-';
		str[1] = (n * (-1)) + 48;
		str[2] = '\0';
		return (str);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) + 1)))
			return (NULL);
		str[0] = n + 48;
		str[1] = '\0';
		return (str);
	}
	return (NULL);
}

static	int		ccounter(long long int n1)
{
	long long int counter;

	counter = 0;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		counter++;
	}
	return (counter);
}

static	char	*positive(long long int n, long long int counter, char *str)
{
	long long int i;

	i = counter - 1;
	if (!(str = (char *)malloc((sizeof(char) * counter) + 1)))
		return (NULL);
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	str[counter] = '\0';
	return (str);
}

static	char	*negative(long long int nn, long long int counter, char *str)
{
	long long int i;

	i = 1;
	nn = nn * -1;
	if (!(str = (char *)malloc((sizeof(char) * counter) + 2)))
		return (NULL);
	i = counter;
	str[0] = '-';
	while (nn != 0 && i > 0)
	{
		str[i] = nn % 10 + 48;
		nn = nn / 10;
		i--;
	}
	str[counter + 1] = '\0';
	return (str);
}

char			*ft_itoa(long long int n)
{
	long long int	n1;
	char			*str;

	n1 = n;
	str = NULL;
	if (n >= -9 && n <= 9)
		return (simple(n));
	if (n > 0)
		return (positive(n, ccounter(n1), str));
	else if (n < 0)
		return (negative(n, ccounter(n1), str));
	return (str);
}
