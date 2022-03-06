/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:00:55 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 02:06:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		result_len;
	int		index;
	int		str1_len;
	char	*result;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	result_len = (ft_strlen(str1) + ft_strlen(str2));
	index = 0;
	str1_len = ft_strlen(str1);
	result = ft_strnew(result_len);
	if (result == NULL)
		return (NULL);
	while (index < str1_len)
	{
		result[index] = str1[index];
		index++;
	}
	index = 0;
	while (str2 != NULL && str2[index] != '\0')
	{
		result[index + str1_len] = str2[index];
		index++;
	}
	return (result);
}
