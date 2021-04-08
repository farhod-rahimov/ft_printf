/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 10:00:18 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			only_width(t_struct **element, va_list ap, char *tmp)
{
	if ((*element)->width[0] == '*')
	{
		tmp = (*element)->width;
		if (!((*element)->width = ft_itoa(va_arg(ap, int))))
			return (-1);
		free(tmp);
		if ((*element)->width[0] == '-')
		{
			tmp = (*element)->flag;
			if (!((*element)->flag = ft_strdup("-")))
				return (-1);
			free(tmp);
			tmp = (*element)->width;
			if (!((*element)->width = ft_substr(tmp, 1, ft_strlen(tmp))))
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int			ggget_width_and_precision_x(t_struct **element,
		va_list ap, char *tmp)
{
	if ((*element)->width != NULL)
		if (only_width(element, ap, tmp) == -1)
			return (-1);
	if ((*element)->precision != NULL)
		if ((*element)->precision[0] == '*')
		{
			tmp = (*element)->precision;
			if (!((*element)->precision = ft_itoa(va_arg(ap, int))))
				return (-1);
			free(tmp);
			if ((*element)->precision[0] == '-')
			{
				free((*element)->precision);
				(*element)->precision = NULL;
			}
		}
	return (0);
}

int			wwork_with_type_and_precision(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->precision != NULL)
	{
		if ((kolvo_simvolov = ft_atoi((*element)->precision) -
					(int)ft_strlen((*element)->arg)) > 0)
		{
			tmp = (*element)->arg;
			tmp1 = crt_symbls_s(kolvo_simvolov, '0');
			if (!((*element)->arg = ft_strjoin(tmp1, (*element)->arg)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
		if ((*element)->precision[0] == '0' && (*element)->arg[0] == '0')
		{
			tmp = (*element)->arg;
			if (!((*element)->arg = ft_strdup("")))
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int			work_with_type_x(t_struct **element, va_list ap)
{
	char	*tmp;
	int		kolvo_simvolov;

	tmp = NULL;
	kolvo_simvolov = 0;
	if (ggget_width_and_precision_x(element, ap, tmp) == -1)
		return (0);
	if (!((*element)->arg = ft_16xtoa(va_arg(ap, int))))
		return (0);
	if ((*element)->type_of_arg[0] == 'X')
	{
		tmp = (*element)->arg;
		if (!((*element)->arg = ft_toupper_str((*element)->arg)))
			return (-1);
		free(tmp);
	}
	if (wwork_with_type_and_precision(element, tmp, kolvo_simvolov) == -1)
		return (0);
	if ((*element)->flag != NULL)
		return (wwork0_with_flag_x(element, tmp, kolvo_simvolov));
	return (wwork3_with_width_x(element, tmp, kolvo_simvolov, NULL));
}
