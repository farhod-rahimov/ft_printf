/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 12:04:23 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			wwork1_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov, char *tmp)
{
	char	*tmp1;

	if (tmp_d < 0)
	{
		tmp = (*element)->arg;
		if (!((*element)->arg = ft_strjoin("-", (*element)->arg)))
			return (-1);
		free(tmp);
	}
	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (-1);
	if ((*element)->width != NULL)
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->arg))) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp, tmp1)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
	if (wwork2_with_flag_diu(element, tmp) == -1)
		return (-1);
	return (1);
}

int			wwork2_with_flag_diu(t_struct **element, char *tmp)
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

int			wwork3_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov, char *tmp)
{
	char	*tmp1;

	if ((*element)->width != NULL)
		kolvo_simvolov = ft_atoi((*element)->width) -
			(int)ft_strlen(((*element)->arg));
	if (tmp_d < 0)
		kolvo_simvolov = kolvo_simvolov - 1;
	if ((*element)->width != NULL && (*element)->precision == NULL)
		if (kolvo_simvolov > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, '0');
			(*element)->result = ft_strjoin(tmp1, tmp);
			free(tmp);
			free(tmp1);
		}
	if (tmp_d < 0)
	{
		tmp = (*element)->result;
		(*element)->result = ft_strjoin("-", (*element)->result);
		free(tmp);
	}
	return (wwork4_with_flag_diu(element, kolvo_simvolov, tmp));
}

int			wwork4_with_flag_diu(t_struct **element,
		int kolvo_simvolov, char *tmp)
{
	char	*tmp1;

	if ((*element)->width != NULL && (*element)->precision != NULL)
		if (kolvo_simvolov > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			(*element)->result = ft_strjoin(tmp1, tmp);
			free(tmp);
			free(tmp1);
		}
	if ((*element)->str_do_p != NULL)
	{
		tmp = (*element)->result;
		(*element)->result = ft_strjoin((*element)->str_do_p,
				(*element)->result);
		free(tmp);
	}
	return (1);
}

int			wwork0_with_width_diu(t_struct **element,
		long int tmp_d, char *tmp, int kolvo_simvolov)
{
	if ((*element)->width != NULL)
	{
		if (!(wwork1_with_width_diu(element, tmp_d, tmp, kolvo_simvolov)))
			return (0);
	}
	else
	{
		if (tmp_d < 0)
		{
			if (!((*element)->result = ft_strjoin("-", (*element)->arg)))
				return (0);
		}
		else if (!((*element)->result = ft_strdup((*element)->arg)))
			return (0);
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
