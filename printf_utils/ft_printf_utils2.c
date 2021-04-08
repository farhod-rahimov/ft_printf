/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:31:13 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 16:40:41 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if ((p = (char *)malloc((len + 1) * sizeof(char))))
	{
		while (s1[i] != '\0')
		{
			p[i] = s1[i];
			i++;
		}
		len = i;
		i = 0;
		while (s2[i] != '\0')
			p[len++] = s2[i++];
		p[len] = '\0';
		return (p);
	}
	return (NULL);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned	int	i;
	char			*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		if ((p = (char *)malloc(1 * sizeof(char))))
			p[0] = '\0';
		return (p);
	}
	if ((p = (char *)malloc((len + 1) * sizeof(char))))
	{
		while (i < len && s[start] != '\0')
			p[i++] = s[start++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
