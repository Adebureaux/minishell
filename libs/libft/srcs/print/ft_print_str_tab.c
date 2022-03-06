/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:43:10 by mravily           #+#    #+#             */
/*   Updated: 2020/03/03 17:43:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str_tab(char *p_name, char **p_tab)
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
		ft_putstr(p_tab[index]);
		ft_putstr("]\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
