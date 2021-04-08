/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 09:35:25 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ggget_width_s(t_struct **element, va_list ap, char *tmp)
{
	if ((*element)->width[0] == '*')
	{
		tmp = (*element)->width;
		if (!((*element)->width = ft_itoa(va_arg(ap, int))))
			return (-1);
		free(tmp);
		if ((*element)->width[0] == '-')
		{
			tmp = (*element)->width;
			if (!((*element)->width = ft_substr((*element)->width,
							1, ft_strlen((*element)->width))))
				return (-1);
			free(tmp);
			tmp = (*element)->flag;
			if (!((*element)->flag = ft_strdup("-")))
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int			ggget_precision_s(t_struct **element, va_list ap, char *tmp)
{
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

int			wwork0_with_flag_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	if ((*element)->precision != NULL)
		if ((int)ft_strlen((*element)->arg) > ft_atoi((*element)->precision))
		{
			tmp = (*element)->arg;
			if (!((*element)->arg = ft_substr((*element)->arg,
							0, ft_atoi((*element)->precision))))
				return (0);
			free(tmp);
		}
	if ((*element)->result != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result =
					ft_strjoin((*element)->result, (*element)->arg)))
			return (0);
		free(tmp);
	}
	else if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	return (wwork1_with_flag_s(element, tmp, kolvo_simvolov));
}

int			wwork1_with_flag_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->width != NULL &&
			(kolvo_simvolov = ft_atoi((*element)->width) -
			(int)ft_strlen((*element)->arg)) > 0)
	{
		tmp = (*element)->result;
		if ((*element)->flag[0] == '-')
		{
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin((*element)->result, tmp1)))
				return (0);
			free(tmp1);
		}
		else if ((tmp1 = crt_symbls_s(kolvo_simvolov, '0')))
		{
			if (!((*element)->result = ft_strjoin(tmp1, (*element)->result)))
				return (0);
			free(tmp1);
		}
		free(tmp);
	}
	return (1);
}

int			wwork2_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	if ((*element)->result != NULL)
	{
		if ((int)ft_strlen((*element)->arg) > ft_atoi((*element)->precision))
		{
			tmp = (*element)->arg;
			if (!((*element)->arg = ft_substr((*element)->arg,
							0, ft_atoi((*element)->precision))))
				return (0);
			free(tmp);
		}
		if ((wwork3_with_precision_s(element, tmp, kolvo_simvolov) == -1))
			return (0);
	}
	else
		return (wwork4_with_precision_s(element, tmp, kolvo_simvolov));
	return (1);
}
