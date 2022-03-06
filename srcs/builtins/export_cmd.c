/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:26:15 by mravily           #+#    #+#             */
/*   Updated: 2022/03/04 22:48:09 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_add_and_free(char ***envp, char *to_find,
	char *to_add, bool find)
{
	if (find == false)
		ft_add_to_tab((void **)to_add, (void ***)envp);
	else
	{
		free(to_add);
		to_add = NULL;
	}
	free(to_find);
}

void	export_var_env(char ***envp, char *to_find, char *to_add)
{
	size_t	i;
	size_t	len;
	bool	find;

	find = false;
	len = ft_strlen(to_find);
	i = -1;
	while ((*envp)[++i])
	{
		if (to_find && (*envp)[i][0] == to_find[0])
		{
			if (!ft_strncmp((char *)(*envp)[i], to_find, len)
				&& ((*envp)[i][len] == '=' || (*envp)[i][len] == '\0'))
			{
				find = true;
				free((*envp)[i]);
				(*envp)[i] = NULL;
				(*envp)[i] = ft_strdup(to_add);
			}
		}
	}
	export_add_and_free(envp, to_find, to_add, find);
}

void	check_var_env(char ***envp, char *to_find, char *to_add)
{
	int		i;
	size_t	len;
	bool	find;

	find = false;
	if (!envp[0])
		return ;
	len = ft_strlen(to_find);
	i = -1;
	while ((*envp)[++i])
	{
		if ((*envp)[i][0] == to_find[0])
			if (!ft_strncmp((char *)(*envp)[i], to_find, len)
				&& ((*envp)[i][len] == '=' || (*envp)[i][len] == '\0'))
				find = true;
	}
	if (find == false)
		ft_add_to_tab((void **)to_add, (void ***)envp);
	else
	{
		free(to_add);
		to_add = NULL;
	}
	free(to_find);
}

void	forked_export_cmd(t_shell *shell, t_cmd *cmd)
{
	t_token	*args;
	char	**export;

	export = shell->export;
	args = cmd->args->next;
	g_exit_status = 0;
	ft_sort_tab((void **)export, ft_tab_len((void **)export));
	print_export(export);
}

void	export_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**export;

	export = shell->export;
	cmd->tmp_status = 0;
	check_var(shell, cmd);
}
