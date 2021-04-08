/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_3_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 10:05:31 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			wwork1_with_width_diu(t_struct **element,
		long int tmp_d, char *tmp, int kolvo_simvolov)
{
	char	*tmp1;

	if (tmp_d < 0)
	{
		tmp = (*element)->arg;
		if (!((*element)->arg = ft_strjoin("-", (*element)->arg)))
			return (0);
		free(tmp);
	}
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
	return (1);
}
