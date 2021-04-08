/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 09:45:21 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	ggget_width(t_struct **element, va_list ap)
{
	char	*tmp;

	if ((*element)->width[0] == '*')
	{
		tmp = (*element)->width;
		(*element)->width = ft_itoa(va_arg(ap, int));
		free(tmp);
	}
	if ((*element)->width[0] == '-')
	{
		tmp = (*element)->flag;
		(*element)->flag = ft_strdup("-");
		free(tmp);
		tmp = (*element)->width;
		(*element)->width = ft_substr(tmp, 1, ft_strlen(tmp));
		free(tmp);
	}
}

static	int		wwork_with_flag(t_struct **element)
{
	char *tmp;
	char *tmp1;

	if ((*element)->flag[0] == '-')
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
		if ((*element)->width != NULL)
		{
			tmp = (*element)->result;
			tmp1 = crt_spcs_c(ft_atoi((*element)->width));
			(*element)->result = ft_strjoin((*element)->result, tmp1);
			free(tmp);
			free(tmp1);
		}
		return (1);
	}
	return (0);
}

static	int		wwork_with_width(t_struct **element)
{
	char	*tmp;
	char	*tmp1;
	int		width;

	width = ft_atoi((*element)->width);
	if ((*element)->result != NULL)
	{
		tmp = (*element)->result;
		tmp1 = crt_spcs_c(width);
		(*element)->result = ft_strjoin((*element)->result, tmp1);
		free(tmp);
		free(tmp1);
		tmp = (*element)->result;
		(*element)->result = ft_strjoin((*element)->result,
				(*element)->arg);
		free(tmp);
	}
	else
	{
		tmp1 = crt_spcs_c(width);
		(*element)->result = ft_strjoin(tmp1, (*element)->arg);
		free(tmp1);
	}
	return (1);
}

int				work_with_type_c(t_struct **element, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if ((*element)->width != NULL)
		ggget_width(element, ap);
	(*element)->arg = ft_strdup_char_like_str((char)va_arg(ap, int));
	if ((*element)->str_do_p != NULL)
		(*element)->result = ft_strdup((*element)->str_do_p);
	if ((*element)->flag != NULL)
		return (wwork_with_flag(element));
	if ((*element)->width != NULL)
		return (wwork_with_width(element));
	if ((*element)->result != NULL)
	{
		tmp = (*element)->result;
		(*element)->result = ft_strjoin(tmp, (*element)->arg);
		free(tmp);
	}
	else
		(*element)->result = ft_strdup((*element)->arg);
	return (1);
}
