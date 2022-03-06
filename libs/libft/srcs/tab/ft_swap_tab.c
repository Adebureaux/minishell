/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:31:39 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:35:13 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Inverse la str et la str + 1 dún tableau
*/

void	ft_swap_tab(void **sort, int i)
{
	void	*tmp;

	if (sort == NULL || i < 0)
		return ;
	tmp = sort[i];
	sort[i] = sort[i + 1];
	sort[i + 1] = tmp;
}
