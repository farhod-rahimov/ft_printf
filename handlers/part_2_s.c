/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 10:09:35 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			create_result(t_struct **element, char *tmp)
{
	tmp = (*element)->result;
	if (!((*element)->result =
			ft_strjoin((*element)->result, (*element)->arg)))
		return (-1);
	free(tmp);
	return (0);
}

int			wwork3_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->width != NULL)
	{
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen((*element)->arg)) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin((*element)->result, tmp1)))
				return (-1);
			free(tmp);
			free(tmp1);
		}
		tmp = (*element)->result;
		if (!((*element)->result =
					ft_strjoin((*element)->result, (*element)->arg)))
			return (-1);
		free(tmp);
	}
	else if (create_result(element, tmp) == -1)
		return (-1);
	return (0);
}

int			wwork4_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((int)ft_strlen((*element)->arg) > ft_atoi((*element)->precision))
	{
		tmp = (*element)->arg;
		if (!((*element)->arg = ft_substr((*element)->arg,
						0, ft_atoi((*element)->precision))))
			return (0);
		free(tmp);
	}
	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	if ((*element)->width != NULL)
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen((*element)->arg)) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin(tmp1, (*element)->result)))
				return (0);
			free(tmp);
			free(tmp1);
		}
	return (1);
}

int			wwork5_with_width_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if ((*element)->result != NULL)
	{
		if ((kolvo_simvolov = ft_atoi((*element)->width) -
					(int)ft_strlen((*element)->arg)) > 0)
		{
			tmp = (*element)->result;
			tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
			if (!((*element)->result = ft_strjoin((*element)->result, tmp1)))
				return (0);
			free(tmp);
			free(tmp1);
		}
		tmp = (*element)->result;
		if (!((*element)->result = ft_strjoin((*element)->result,
						(*element)->arg)))
			return (0);
		free(tmp);
	}
	else
		return (wwork6_with_width_s(element, tmp, kolvo_simvolov));
	return (1);
}

int			wwork6_with_width_s(t_struct **element,
		char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if (!((*element)->result = ft_strdup((*element)->arg)))
		return (0);
	if ((kolvo_simvolov = ft_atoi((*element)->width) -
				(int)ft_strlen((*element)->arg)) > 0)
	{
		tmp = (*element)->result;
		tmp1 = crt_symbls_s(kolvo_simvolov, ' ');
		if (!((*element)->result = ft_strjoin(tmp1, (*element)->result)))
			return (0);
		free(tmp);
		free(tmp1);
	}
	return (1);
}
