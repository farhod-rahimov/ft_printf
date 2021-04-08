/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 09:35:19 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			work_with_type_s(t_struct **element, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if ((*element)->width != NULL)
		if (ggget_width_s(element, ap, tmp) == -1)
			return (0);
	if ((*element)->precision != NULL)
		if (ggget_precision_s(element, ap, tmp) == -1)
			return (0);
	tmp = va_arg(ap, char *);
	if (tmp == NULL)
	{
		if (!((*element)->arg = ft_strdup("(null)")))
			return (0);
	}
	else if (!((*element)->arg = ft_strdup(tmp)))
		return (0);
	if (work_s(element, tmp) == -1)
		return (0);
	return (1);
}

int			work_s(t_struct **element, char *tmp)
{
	if ((*element)->str_do_p != NULL)
		if (!((*element)->result = ft_strdup((*element)->str_do_p)))
			return (-1);
	if ((*element)->flag != NULL)
		return (wwork0_with_flag_s(element, tmp, 0));
	if ((*element)->precision != NULL)
		return (wwork2_with_precision_s(element, tmp, 0));
	if ((*element)->width != NULL)
		return (wwork5_with_width_s(element, tmp, 0));
	if ((*element)->result != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result = ft_strjoin(tmp, (*element)->arg)))
			return (-1);
		free(tmp);
	}
	else if (!((*element)->result = ft_strdup((*element)->arg)))
		return (-1);
	return (0);
}
