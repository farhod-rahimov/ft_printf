/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 07:36:08 by btammara          #+#    #+#             */
/*   Updated: 2020/12/04 10:44:15 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_toupper_str(char *src)
{
	char	*str;
	int		i;

	if (src == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] >= 'a' && src[i] <= 'z')
			str[i] = src[i] - 32;
		else
			str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
