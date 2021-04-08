/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 10:35:47 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

t_struct	*create_new_el(void)
{
	t_struct	*new_element;

	if (!(new_element = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	new_element->str_do_p = NULL;
	new_element->flag = NULL;
	new_element->flag2 = NULL;
	new_element->width = NULL;
	new_element->precision = NULL;
	new_element->type_of_arg = NULL;
	new_element->arg = NULL;
	new_element->result = NULL;
	new_element->next = NULL;
	return (new_element);
}

char		*ft_parse(char *format, t_struct **element)
{
	if (get_str_from_formatted_str(format, 0, element) == NULL)
		return (NULL);
	return ("end");
}
