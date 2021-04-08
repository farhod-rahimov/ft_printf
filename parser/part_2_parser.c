/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 10:54:24 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			workkk_with_flag(char *format, int i, t_struct **element)
{
	if (((*element)->flag = ft_strdup("0")) == NULL)
		return (-1);
	while (format[i] == '0')
		i++;
	if (format[i] == '-')
	{
		while (format[i] == '-')
			i++;
		if (((*element)->flag2 = ft_strdup("-")) == NULL)
			return (-1);
	}
	return (i);
}

char		*get_width_from_formatted_str(char *format,
		int i, t_struct **element)
{
	int kolvo_znakov_shirini;
	int temp_i;

	kolvo_znakov_shirini = 0;
	temp_i = i;
	if (format[i] != '*' && (format[i] < '0' || format[i] > '9'))
		return (get_precision_from_formatted_str(format, i, element));
	if (format[i] == '*')
	{
		if (((*element)->width = ft_strdup("*")) == NULL)
			return (NULL);
		return (get_precision_from_formatted_str(format, ++i, element));
	}
	if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			kolvo_znakov_shirini++;
			i++;
		}
		if (((*element)->width = ft_substr(format, temp_i, i - temp_i)) == NULL)
			return (NULL);
	}
	return (get_precision_from_formatted_str(format, i, element));
}

char		*get_precision_from_formatted_str(char *format,
		int i, t_struct **element)
{
	if (format[i] != '.')
		return (get_type_of_arg_from_formatted_str(format, i, element));
	i++;
	if (format[i] == '*')
	{
		if (((*element)->precision = ft_strdup("*")) == NULL)
			return (NULL);
		return (get_type_of_arg_from_formatted_str(format, ++i, element));
	}
	else if ((i = work_with_precision(format, i, element)) == -1)
		return (NULL);
	return (get_type_of_arg_from_formatted_str(format, i, element));
}

int			work_with_precision(char *format, int i, t_struct **element)
{
	int kolvo_znakov_tochnosti;
	int temp_i;

	kolvo_znakov_tochnosti = 0;
	temp_i = i;
	if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			kolvo_znakov_tochnosti++;
			i++;
		}
		if (((*element)->precision =
					ft_substr(format, temp_i, i - temp_i)) == NULL)
			return (-1);
	}
	else if (((*element)->precision = ft_strdup("0")) == NULL)
		return (-1);
	return (i);
}
