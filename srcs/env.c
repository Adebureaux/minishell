/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:25:29 by adeburea          #+#    #+#             */
/*   Updated: 2022/03/05 18:07:41 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	replace_env(t_shell *shell, char *key, char *value)
{
	char	*eq;
	char	*full;

	eq = ft_strjoin(key, "=");
	full = ft_strjoin(eq, value);
	export_var_env(&shell->env, ft_strdup(key), ft_strdup(full));
	export_var_env(&shell->export, ft_strdup(key), ft_strdup(full));
	free(eq);
	free(full);
}

char	*find_var_env(char **envp, char *to_find)
{
	size_t	i;
	size_t	len;
	size_t	len_tab;

	len = ft_strlen(to_find);
	len_tab = ft_tab_len((void **)envp);
	i = 0;
	while (i < len_tab)
	{
		if (envp && envp[0] && envp[0][0] && envp[i][0] == to_find[0])
		{
			if (!ft_strncmp((char *)envp[i], to_find, len)
				&& envp[i][len] == '=')
				return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

void	set_env_tab(char ***env, char *to_find, char *to_replace)
{
	size_t		len;
	size_t		len_tab;
	size_t		i;

	len = ft_strlen(to_find);
	len_tab = ft_tab_len((void **)(*env));
	i = 0;
	while (i < len_tab - 1)
	{
		if ((*env)[i][0] == to_find[0])
		{
			if (ft_strncmp((char *)(*env)[i], to_find, len) == 0
				&& (*env)[i][len] == '=')
				(*env)[i] = to_replace;
		}
		i++;
	}
}
