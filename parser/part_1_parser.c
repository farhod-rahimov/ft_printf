/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 10:46:06 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*get_str_from_formatted_str(char *format, int i, t_struct **element)
{
	format = format + i;
	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (i == (int)ft_strlen(format))
	{
		if (((*element)->str_do_p = ft_strdup(format)) == NULL)
			return (NULL);
		return ("end");
	}
	if (((*element)->str_do_p = ft_substr(format, 0, i)) == NULL)
		return (NULL);
	if ((i = work_with_prcnt1(format, i, element)) == -1)
		return (NULL);
	if (format[i] != '\0')
		return (get_flag_from_formatted_str(format, i, element));
	return ("end");
}

int			work_with_prcnt1(char *format, int i, t_struct **element)
{
	char	*tmp;
	int		kolvo_prcnt;

	tmp = NULL;
	kolvo_prcnt = 0;
	while (format[i] != '\0' && format[i] == '%')
	{
		kolvo_prcnt++;
		i++;
	}
	if (kolvo_prcnt % 2 == 0)
	{
		kolvo_prcnt = kolvo_prcnt / 2;
		tmp = (*element)->str_do_p;
		if (format[i] == '\0' && ((*element)->str_do_p =
					ft_strdup(format - kolvo_prcnt)) == NULL)
			return (-1);
		else if (((*element)->str_do_p =
					ft_substr(format, 0, i - kolvo_prcnt)) == NULL)
			return (-1);
		free(tmp);
	}
	else if (kolvo_prcnt % 2 != 0)
		return (work_with_prcnt2(format, i, element, kolvo_prcnt));
	return (i);
}

int			work_with_prcnt2(char *format, int i,
		t_struct **element, int kolvo_prcnt)
{
	char	*tmp;

	if (format[i] == '\0')
		return (-1);
	tmp = (*element)->str_do_p;
	if (kolvo_prcnt > 2)
	{
		kolvo_prcnt = kolvo_prcnt / 2;
		if (((*element)->str_do_p =
					ft_substr(format, 0, --i - kolvo_prcnt)) == NULL)
			return (-1);
	}
	else if (((*element)->str_do_p = ft_substr(format, 0, --i)) == NULL)
		return (-1);
	if (ft_strlen((*element)->str_do_p) == 0)
	{
		free((*element)->str_do_p);
		(*element)->str_do_p = NULL;
	}
	free(tmp);
	return (i);
}

char		*get_flag_from_formatted_str(char *format,
		int i, t_struct **element)
{
	t_struct	*new_element;

	new_element = NULL;
	if (format[i] != '%')
	{
		if ((new_element = create_new_el()) == NULL)
			return (NULL);
		(*element)->next = new_element;
		return (get_str_from_formatted_str(format, i, &new_element));
	}
	if (format[i + 1] != '-' && format[i + 1] != '0')
		return (get_width_from_formatted_str(format, ++i, element));
	if ((i = (work_with_flag(format, i, element))) == -1)
		return (NULL);
	return (get_width_from_formatted_str(format, i, element));
}

int			work_with_flag(char *format, int i, t_struct **element)
{
	if (format[++i] == '-')
	{
		if (((*element)->flag = ft_strdup("-")) == NULL)
			return (-1);
		while (format[i] == '-')
			i++;
		if (format[i] == '0')
		{
			while (format[i] == '0')
				i++;
			if (((*element)->flag2 = ft_strdup("0")) == NULL)
				return (-1);
		}
	}
	if (format[i] == '0')
		if ((i = workkk_with_flag(format, i, element)) == -1)
			return (-1);
	return (i);
}
