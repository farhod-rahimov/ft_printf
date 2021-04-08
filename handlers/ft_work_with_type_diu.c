/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_diu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 12:12:33 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			work_with_type_diu(t_struct **element, va_list ap)
{
	long int	d;
	long int	tmp_d;
	char		*tmp;

	tmp = NULL;
	tmp_d = 1;
	if ((*element)->width != NULL)
		if (gget_width(element, ap) == -1)
			return (0);
	if ((*element)->precision != NULL)
		if (gget_precision(element, ap) == -1)
			return (0);
	if ((*element)->type_of_arg[0] == 'u')
		d = (va_arg(ap, unsigned int));
	else if ((d = (va_arg(ap, int))) < 0)
	{
		tmp_d = d;
		d = d * (-1);
	}
	(*element)->arg = ft_itoa(d);
	if (wwork_with_precision_diu(element, tmp, 0, NULL) == -1)
		return (0);
	if ((*element)->flag != NULL)
		return (wwork0_with_flag_diu(element, tmp_d, 0));
	return (wwork0_with_width_diu(element, tmp_d, tmp, 0));
}
