/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:42:12 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:43:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_place(char **sort, int i, int k)
{
	while (sort[i][k] == sort[i + 1][k])
	{
		if (sort[i][k + 1] > sort[i + 1][k + 1])
		{
			ft_swap_tab((void **)sort, i);
			break ;
		}
		k++;
	}
}

/*
** Trie le tableau envoyer en params par ordre alphabétique
*/

void	ft_sort_tab(void **tab, int size)
{
	int		i;
	int		j;
	int		k;
	char	**sort;

	sort = (char **)tab;
	k = 0;
	i = 0;
	j = size;
	while (j > 0)
	{
		while (i < size - 1)
		{
			if (sort[i][k] > sort[i + 1][k])
				ft_swap_tab((void **)sort, i);
			if (sort[i][k] == sort[i + 1][k])
				get_place(sort, i, k);
			k = 0;
			i++;
		}
		i = 0;
		j--;
	}
}
