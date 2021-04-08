/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/08 17:32:32 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			gget_width_and_precision(t_struct **element, va_list ap, char *tmp)
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
			if ((*element)->precision[0] == '-')
			{
				free((*element)->precision);
				(*element)->precision = NULL;
			}
		}
	return (0);
}

int			work_with_type_p(t_struct **element, va_list ap)
{
	char	*tmp;
	int		kolvo_simvolov;

	tmp = NULL;
	kolvo_simvolov = 0;
	if (gget_width_and_precision(element, ap, tmp) == -1)
		return (0);
	if (!((*element)->arg = ft_16xtoa((va_arg(ap, long long int)))))
		return (0);
	if ((*element)->precision != NULL)
		if (wworkk_with_type_p(element, tmp, kolvo_simvolov) == -1)
			return (0);
	if ((*element)->flag != NULL)
		return (wwork0_with_flag_p(element, tmp, kolvo_simvolov));
	return (wwork3_p(element, (*element)->arg, kolvo_simvolov));
}

int			wworkk_with_type_p(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

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
		if (!((*element)->arg = ft_strdup("")))
			return (-1);
	return (0);
}

int			wwork3_p(t_struct **element, char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if (!((*element)->arg = ft_strjoin("0x", (*element)->arg)))
		return (0);
	free(tmp);
	if ((*element)->width != NULL)
	{
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->arg))) > 0)
		{
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp1, (*element)->arg)))
				return (0);
			free(tmp1);
		}
		else if (!((*element)->result = ft_strdup((*element)->arg)))
			return (0);
	}
	else if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	if (wwork33_p(element, tmp) == -1)
		return (0);
	return (1);
}

int			wwork33_p(t_struct **element, char *tmp)
{
	if ((*element)->str_do_p != NULL)
	{
		tmp = (*element)->result;
		if (!((*element)->result = ft_strjoin((*element)->str_do_p,
						(*element)->result)))
			return (-1);
		free(tmp);
	}
	return (0);
}
