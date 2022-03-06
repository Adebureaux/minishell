/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:34:37 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:42:51 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_to_tab(void *to_add, void ***tab)
{
	void	**tmp;

	tmp = *tab;
	*tab = ft_tab_new(ft_tab_len(tmp) + 1);
	if (tmp != NULL)
	{
		ft_tab_cpy(*tab, tmp);
		free(tmp);
	}
	(*tab)[ft_tab_len(*tab)] = to_add;
}

void	ft_add_to_front_tab(void *to_add, void ***tab)
{
	void	**tmp;
	size_t	i;

	if ((*tab) == NULL)
	{
		(*tab) = ft_tab_new(1);
		ft_add_to_tab(to_add, tab);
		return ;
	}
	tmp = (*tab);
	(*tab) = ft_tab_new(ft_tab_len(tmp) + 1);
	(*tab)[0] = (void *)ft_strdup((char *)to_add);
	i = 0;
	while (tmp[i] != NULL)
	{
		ft_add_to_tab(tmp[i], tab);
		i++;
	}
}
