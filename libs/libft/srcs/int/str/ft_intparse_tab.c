/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intparse_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:30:06 by mravily           #+#    #+#             */
/*   Updated: 2021/12/13 10:45:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intparse_tab(char **tab)
{
	int	i;
	int	*result;
	int	len;

	len = ft_tab_len((void **)tab);
	result = ft_int_str_new(len);
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strisnum(tab[i]) == false)
			ft_putendl("Error in ft_intparse_tab");
		result[i] = ft_atoi(tab[i]);
		i++;
	}
	return (result);
}
