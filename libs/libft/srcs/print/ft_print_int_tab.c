/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:49:51 by mravily           #+#    #+#             */
/*   Updated: 2021/11/02 09:56:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(char *p_name, int **p_tab)
{
	size_t		index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar('{');
		ft_putstr(p_name);
		ft_putstr("}\n");
	}
	ft_putstr("-----===-----\n");
	while (p_tab && p_tab[index])
	{
		ft_putnbr(index);
		ft_putstr("--->[");
		ft_putnbr(p_tab[index][0]);
		ft_putstr("]\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
