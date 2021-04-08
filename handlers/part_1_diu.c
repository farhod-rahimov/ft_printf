/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 10:07:12 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			gget_width(t_struct **element, va_list ap)
{
	char	*tmp;

	tmp = NULL;
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
			if (!((*element)->width = ft_substr((*element)->width,
							1, ft_strlen((*element)->width))))
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int			only_flag(t_struct **element)
{
	if ((*element)->flag[0] == '0')
		if ((*element)->width != NULL)
		{
			if ((*element)->width[0] == '0')
			{
				if (!((*element)->precision = ft_strdup("1")))
					return (-1);
			}
			else if (!((*element)->precision = ft_strdup((*element)->width)))
				return (-1);
		}
	if ((*element)->flag[0] == '-')
		if (!((*element)->precision = ft_strdup("1")))
			return (-1);
	return (0);
}

int			gget_precision(t_struct **element, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if ((*element)->precision[0] == '*')
	{
		tmp = (*element)->precision;
		if (!((*element)->precision = ft_itoa(va_arg(ap, int))))
			return (-1);
		free(tmp);
		if ((*element)->precision[0] == '-')
		{
			tmp = (*element)->precision;
			if ((*element)->flag != NULL)
			{
				if (only_flag(element) == -1)
					return (-1);
			}
			else if (!((*element)->precision = ft_strdup("1")))
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int			wwork_with_precision_diu(t_struct **element,
		char *tmp, int kolvo_nuley, char *tmp1)
{
	if (ft_strlen((*element)->arg) == 1 && (*element)->arg[0] == '0')
	{
		if ((*element)->precision != NULL)
			if ((*element)->precision[0] == '0')
			{
				free((*element)->arg);
				if (!((*element)->arg = ft_strdup("")))
					return (-1);
			}
	}
	if ((*element)->precision != NULL)
	{
		if ((kolvo_nuley = ft_atoi((*element)->precision) -
					(int)ft_strlen((*element)->arg)) > 0)
		{
			tmp = (*element)->arg;
			tmp1 = crt_symbls_s(kolvo_nuley, '0');
			if (!((*element)->arg = ft_strjoin(tmp1, tmp)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
	}
	return (0);
}

int			wwork0_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov)
{
	char	*tmp;

	tmp = NULL;
	if ((*element)->flag2 != NULL)
	{
		free((*element)->flag);
		(*element)->flag = ft_strdup((*element)->flag2);
	}
	if ((*element)->flag[0] == '-')
		return (wwork1_with_flag_diu(element, tmp_d, kolvo_simvolov, tmp));
	if ((*element)->flag[0] == '0')
	{
		if ((*element)->result != NULL)
		{
			tmp = (*element)->result;
			(*element)->result = ft_strjoin((*element)->result,
					(*element)->arg);
			free(tmp);
		}
		else
			(*element)->result = ft_strdup((*element)->arg);
		return (wwork3_with_flag_diu(element, tmp_d, kolvo_simvolov, tmp));
	}
	return (0);
}
