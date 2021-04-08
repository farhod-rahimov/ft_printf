/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_if_tmp_arg_null_term.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:08:28 by btammara          #+#    #+#             */
/*   Updated: 2020/12/04 10:43:10 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	part2(char *arg, char *s, char *flag, int ret)
{
	if (arg[0] == '\0')
	{
		if (flag != NULL)
		{
			if (flag[0] != '-')
				write(1, &s[ft_strlen(s)], 1);
		}
		else
			write(1, &s[ft_strlen(s)], 1);
		ret = ret + 1;
	}
	return (ret);
}

int			ft_putstr_if_tmp_arg_null_term(char *arg, char *s, char *flag)
{
	size_t	i;
	int		ret;

	if (s == NULL)
		return (0);
	i = 0;
	ret = 0;
	if (arg[0] == '\0')
	{
		if (flag != NULL)
			if (flag[0] == '-')
				write(1, &s[ft_strlen(s)], 1);
		ret = 1;
	}
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (part2(arg, s, flag, ret));
}
