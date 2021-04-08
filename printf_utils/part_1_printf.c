/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:37 by btammara          #+#    #+#             */
/*   Updated: 2020/12/07 16:21:53 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_is_it_correct_element(t_struct **element)
{
	int i;

	i = 0;
	if ((*element)->str_do_p == NULL && (*element)->type_of_arg == NULL)
		return (0);
	if ((*element)->str_do_p != NULL)
	{
		if ((*element)->type_of_arg == NULL)
			if ((*element)->flag != NULL || (*element)->width != NULL
					|| (*element)->precision != NULL)
				return (0);
		if ((*element)->type_of_arg != NULL)
			if ((*element)->flag == NULL || (*element)->width == NULL
					|| (*element)->precision == NULL)
				return (0);
	}
	if ((*element)->str_do_p != NULL)
		(*element)->result = ft_strdup((*element)->str_do_p);
	return (1);
}

int		is_there_something_to_print(t_struct **element, va_list ap)
{
	t_struct	*tmp;
	char		*set;
	int			i;

	tmp = *element;
	set = "cspdiuxX%";
	while (tmp)
	{
		i = 0;
		if (tmp->type_of_arg != NULL)
		{
			while (tmp->type_of_arg[0] != set[i] && set[i] != '\0')
				i++;
			if (tmp->type_of_arg[0] == set[i] && set[i] != '\0')
				if (!(redirect_to_appropriate_type(set[i], &tmp, ap)))
					return (-1);
		}
		else if ((check_is_it_correct_element(&tmp) == 0))
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int		print_result(t_struct **element)
{
	t_struct	*tmp;
	int			len_of_printed;

	tmp = *element;
	len_of_printed = 0;
	while (tmp)
	{
		len_of_printed = len_of_printed + ft_strlen(tmp->result);
		if (tmp->type_of_arg != NULL)
		{
			if (tmp->type_of_arg[0] == 'c')
			{
				if (ft_putstr_if_tmp_arg_null_term(tmp->arg,
							tmp->result, tmp->flag))
					len_of_printed += 1;
			}
			else
				ft_putstr_fd(tmp->result, 1);
		}
		else
			ft_putstr_fd(tmp->result, 1);
		tmp = tmp->next;
	}
	return (len_of_printed);
}

int		redirect_to_appropriate_type(char type_of_arg,
		t_struct **element, va_list ap)
{
	if (type_of_arg == 'c')
		return (work_with_type_c(element, ap));
	if (type_of_arg == 's')
		return (work_with_type_s(element, ap));
	if (type_of_arg == 'd' || type_of_arg == 'i' || type_of_arg == 'u')
		return (work_with_type_diu(element, ap));
	if (type_of_arg == 'x' || type_of_arg == 'X')
		return (work_with_type_x(element, ap));
	if (type_of_arg == 'p')
		return (work_with_type_p(element, ap));
	if (type_of_arg == '%')
		return (work_with_type_prcnt(element, ap));
	return (0);
}

void	free_struct(t_struct **element, t_struct *tmp_s1)
{
	t_struct	*tmp_s;

	tmp_s = *element;
	while (tmp_s)
	{
		if (tmp_s->str_do_p != NULL)
			free(tmp_s->str_do_p);
		if (tmp_s->flag != NULL)
			free(tmp_s->flag);
		if (tmp_s->flag2 != NULL)
			free(tmp_s->flag2);
		if (tmp_s->width != NULL)
			free(tmp_s->width);
		if (tmp_s->precision != NULL)
			free(tmp_s->precision);
		if (tmp_s->type_of_arg != NULL)
			free(tmp_s->type_of_arg);
		if (tmp_s->arg != NULL)
			free(tmp_s->arg);
		if (tmp_s->result != NULL)
			free(tmp_s->result);
		tmp_s1 = tmp_s;
		tmp_s = tmp_s->next;
		free(tmp_s1);
	}
}
