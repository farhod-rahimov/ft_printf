/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 16:21:03 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*element;
	int			ret_len;

	if (!(element = create_new_el()) || format == NULL)
		return (-1);
	if (ft_parse((char *)format, &element) == NULL)
	{
		free_struct(&element, NULL);
		return (-1);
	}
	va_start(ap, format);
	if (is_there_something_to_print(&element, ap) == -1)
	{
		free_struct(&element, NULL);
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	ret_len = print_result(&element);
	free_struct(&element, NULL);
	return (ret_len);
}
