/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:59:15 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 12:59:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	char	lastc;
	char	*pstr;

	lastc = (char)c;
	pstr = (char *)str;
	while (*pstr != '\0')
		pstr++;
	while (*pstr != lastc)
	{
		if (pstr == str)
			return (0);
		pstr--;
	}
	return ((char *)pstr);
}
