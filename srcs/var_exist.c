/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 00:24:32 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 01:54:17 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Recupère le nom de la variable et s'arrete au premier '=' renconté
*/
char	*recovery_var(char *line)
{
	size_t		i;
	char		*var;

	i = 0;
	while (line[i] != '=' && line[i])
		i++;
	var = (char *)malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			var[i] = '\0';
			return (var);
		}
		var[i] = line[i];
		i++;
	}
	return (line);
}

bool	check_if_var_exist(char *args, char **env)
{
	size_t	i;
	int		len;
	char	*var;

	var = recovery_var(args);
	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (env[i][0] == var[0])
		{
			if (ft_strncmp((char *)env[i], var, len) == 0
				&& env[i][len] == '=')
				return (true);
		}
		i++;
	}
	free(var);
	return (false);
}
