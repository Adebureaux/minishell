/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:40:49 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 11:54:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd_path(char *cmd, char **path)
{
	char	*full_path;
	char	*command;
	int		i;

	i = -1;
	while (path && path[++i])
	{
		command = ft_strappend("/", cmd);
		full_path = ft_strappend(path[i], command);
		if (!access(full_path, X_OK))
		{
			free(command);
			return (full_path);
		}
		free(command);
		free(full_path);
	}
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	return (NULL);
}

char	*set_path_exec(char **env, char *cmd)
{
	char	*new_str;
	char	**path;

	if (env && env[0])
	{
		path = ft_split(find_var_env(env, "PATH"), ':');
		new_str = get_cmd_path(cmd, path);
		ft_tab_free(path);
		return (new_str);
	}
	return (NULL);
}

int	token_len(t_token *token)
{
	int	len;

	len = 0;
	while (token)
	{
		len++;
		token = token->next;
	}
	return (len);
}

char	**set_args(t_token *token)
{
	int		i;
	char	**args;

	i = 0;
	args = malloc(sizeof(char *) * (token_len(token) + 1));
	while (token && token->id == WORD)
	{
		if (token->str)
			args[i++] = token->str;
		else
			g_exit_status = 0;
		token = token->next;
	}
	args[i] = NULL;
	return (args);
}
