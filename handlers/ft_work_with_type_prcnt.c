/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_prcnt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 16:37:26 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ggget_width_and_precision(t_struct **element, va_list ap, char *tmp)
{
	if ((*element)->width != NULL)
		if ((*element)->width[0] == '*')
		{
			tmp = (*element)->width;
			if (!((*element)->width = ft_itoa(va_arg(ap, int))))
				return (-1);
			free(tmp);
		}
	if ((*element)->precision != NULL)
		if ((*element)->precision[0] == '*')
		{
			tmp = (*element)->precision;
			if (!((*element)->precision = ft_itoa(va_arg(ap, int))))
				return (-1);
			free(tmp);
		}
	return (0);
}

int			wwork0_with_flag_prcnt(t_struct **element,
		char *tmp, int kolvo_simvolov, char *tmp1)
{
	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	if ((*element)->width != NULL)
	{
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->arg))) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp, tmp1)))
				return (0);
			free(tmp);
			free(tmp1);
		}
	}
	if ((*element)->str_do_p != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result =
					ft_strjoin((*element)->str_do_p, (*element)->result)))
			return (0);
		free(tmp);
	}
	return (1);
}

int			wwork0_with_width_prcnt(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->flag != NULL)
	{
		if ((*element)->flag[0] == '0')
			if ((kolvo_simvolov = ft_atoi((*element)->width) -
						(int)ft_strlen(((*element)->arg))) > 0)
			{
				tmp1 = crt_symbls_s(kolvo_simvolov, '0');
				if (!((*element)->result = ft_strjoin(tmp1, (*element)->arg)))
					return (0);
				free(tmp1);
			}
	}
	else if ((kolvo_simvolov = ft_atoi((*element)->width) -
				(int)ft_strlen(((*element)->arg))) > 0)
	{
		tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
		if (!((*element)->result = ft_strjoin(tmp1, (*element)->arg)))
			return (0);
		free(tmp1);
	}
	else if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	return (wwork1_with_width_prcnt(element, tmp));
}

int			wwork1_with_width_prcnt(t_struct **element,
		char *tmp)
{
	if ((*element)->str_do_p != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result =
					ft_strjoin((*element)->str_do_p, (*element)->result)))
			return (0);
		free(tmp);
	}
	return (1);
}

int			work_with_type_prcnt(t_struct **element, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if (ggget_width_and_precision(element, ap, tmp) == -1)
		return (0);
	if (!((*element)->arg = ft_strdup("%")))
		return (0);
	if ((*element)->flag != NULL)
		if ((*element)->flag[0] == '-')
			return (wwork0_with_flag_prcnt(element, tmp, 0, NULL));
	if ((*element)->width != NULL)
		return (wwork0_with_width_prcnt(element, tmp, 0));
	else if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	if ((*element)->str_do_p != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result =
					ft_strjoin((*element)->str_do_p, (*element)->result)))
			return (0);
		free(tmp);
	}
	return (1);
}
