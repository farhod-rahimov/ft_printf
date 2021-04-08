/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_3_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 10:54:18 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*get_type_of_arg_from_formatted_str(char *format,
		int i, t_struct **element)
{
	char		*set;
	int			i_for_set;

	if (format[i] == '\0')
		return (NULL);
	set = "cspdiuxX%";
	i_for_set = 0;
	while (format[i] != set[i_for_set] &&
			format[i] != '\0' && set[i_for_set] != '\0')
		i_for_set++;
	return (get2_type_of_arg_from_formatted_str(format, i, element, i_for_set));
}

char		*get2_type_of_arg_from_formatted_str(char *format,
		int i, t_struct **element, int i_for_set)
{
	char		*set;
	t_struct	*new_element;

	set = "cspdiuxX%";
	new_element = NULL;
	if (format[i] == set[i_for_set])
	{
		if (((*element)->type_of_arg =
					ft_strdup_char_like_str(set[i_for_set])) == NULL)
			return (NULL);
		if (format[++i] == '\0')
			return ("end");
		else
		{
			if ((new_element = create_new_el()) == NULL)
				return (NULL);
			(*element)->next = new_element;
			return (get_str_from_formatted_str(format, i, &new_element));
		}
	}
	return (NULL);
}
