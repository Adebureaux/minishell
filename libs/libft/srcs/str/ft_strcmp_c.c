/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:11 by mravily           #+#    #+#             */
/*   Updated: 2021/11/25 09:14:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if in the p_src p_target is present
** return true if p_target is find
** else return false
*/
bool	ft_strcmp_c(char *p_src, char p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == '\0')
		return (0);
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_target)
			return (true);
		i++;
	}
	return (false);
}
