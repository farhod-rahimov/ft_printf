/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16xtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 08:44:54 by btammara          #+#    #+#             */
/*   Updated: 2020/12/08 09:45:49 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		ccounter(long long int n1)
{
	long long int counter;

	if (n1 == 0)
		return (1);
	counter = 0;
	while (n1 != 0)
	{
		n1 = n1 / 16;
		counter++;
	}
	return (counter);
}

static void		fill_str(long long int n, int i, char *str)
{
	int	mod;

	mod = 0;
	while (n != 0)
	{
		mod = n % 16;
		if (mod == 10)
			str[i] = 'a';
		else if (mod == 11)
			str[i] = 'b';
		else if (mod == 12)
			str[i] = 'c';
		else if (mod == 13)
			str[i] = 'd';
		else if (mod == 14)
			str[i] = 'e';
		else if (mod == 15)
			str[i] = 'f';
		else
			str[i] = n % 16 + 48;
		n = n / 16;
		i--;
	}
}

static	char	*positive(long long int n, int counter, char *str)
{
	int	i;

	i = counter - 1;
	if (!(str = (char *)malloc((sizeof(char) * counter) + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	fill_str(n, i, str);
	str[counter] = '\0';
	return (str);
}

char			*ft_16xtoa(long long int n)
{
	long long int		n1;
	unsigned long int	negative;
	char				*str;

	n1 = n;
	negative = 4294967295;
	str = NULL;
	if (n >= 0)
		return (positive(n, ccounter(n1), str));
	else
		return (positive((negative + n + 1), ccounter(negative + n + 1), str));
	return (str);
}
