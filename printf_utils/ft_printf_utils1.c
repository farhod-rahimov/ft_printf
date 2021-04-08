/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:31:13 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 16:40:51 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long int	ft_strlen(const char *s)
{
	unsigned long int	len;

	if (s == NULL)
		return (-1);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char			*ft_strdup(const char *s1)
{
	char					*p;
	unsigned long long int	i;
	unsigned long long int	a;

	i = 0;
	a = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	if ((p = (char *)malloc((i + 1) * sizeof(char))))
	{
		while (a < i)
		{
			p[a] = s1[a];
			a++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

char			*ft_strdup_char_like_str(const char c)
{
	char	*p;

	if ((p = (char *)malloc(2 * sizeof(char))))
	{
		p[0] = c;
		p[1] = '\0';
		return (p);
	}
	return (NULL);
}

char			*crt_spcs_c(int n)
{
	char	*p;
	int		i;

	i = 0;
	if (n == 0)
		n = 1;
	if ((p = (char *)malloc(n * sizeof(char))))
	{
		if (n > 1)
		{
			while (i < (n - 1))
				p[i++] = ' ';
			p[i] = '\0';
		}
		else
		{
			p[0] = '\0';
			p[1] = '\0';
		}
		return (p);
	}
	return (NULL);
}

char			*crt_symbls_s(int n, char c)
{
	char	*p;
	int		i;

	i = 0;
	if (n == 0)
		n = 1;
	if ((p = (char *)malloc((n + 1) * sizeof(char))))
	{
		while (i < n)
			p[i++] = c;
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
