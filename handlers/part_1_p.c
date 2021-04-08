/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 14:00:33 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			wwork0_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	if ((*element)->flag2 != NULL)
	{
		tmp = (*element)->flag;
		(*element)->flag = ft_strdup((*element)->flag2);
		free(tmp);
	}
	if ((*element)->flag[0] == '-')
		if (wwork1_with_flag_p(element, tmp, kolvo_simvolov) == -1)
			return (0);
	if ((*element)->flag[0] == '0')
		if (wwork2_with_flag_p(element, tmp, kolvo_simvolov) == -1)
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

int			wwork1_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (-1);
	tmp = (*element)->result;
	if (!((*element)->result = ft_strjoin("0x", (*element)->result)))
		return (-1);
	free(tmp);
	if ((*element)->width != NULL)
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->result))) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp, tmp1)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
	return (0);
}

int			wwork2_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (-1);
	tmp = (*element)->result;
	if (!((*element)->result = ft_strjoin("0x", (*element)->result)))
		return (-1);
	free(tmp);
	if ((*element)->width != NULL && (*element)->precision == NULL)
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->arg))) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, '0');
			if (!((*element)->result = ft_strjoin(tmp1, tmp)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
	if (wwork22_with_flag_p(element, tmp, kolvo_simvolov) == -1)
		return (0);
	return (0);
}

int			wwork22_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->width != NULL && (*element)->precision != NULL)
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen(((*element)->arg))) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp1, tmp)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
	return (0);
}
