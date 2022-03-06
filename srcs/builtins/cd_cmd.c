/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:26:42 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:34:08 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_env(t_shell *shell)
{
	char	pwd[MAXPATHLEN];

	getcwd(pwd, MAXPATHLEN);
	replace_env(shell, "OLDPWD", find_var_env(shell->env, "PWD"));
	replace_env(shell, "PWD", pwd);
}

int	switch_directory(t_shell *shell, t_cmd *cmd, char *path)
{
	char	*buf;

	if (path && !ft_strncmp(path, "~", 1))
	{
		buf = find_var_env(shell->env, "HOME");
		if (!buf)
			return (print_error(cmd, "HOME not set", 1, 2));
	}
	else if (path && !ft_strncmp(path, "-", 1))
	{
		buf = find_var_env(shell->env, "OLDPWD");
		if (!buf)
			return (print_error(cmd, "OLDPWD not set", 1, 2));
	}
	else
		buf = path;
	if (buf && access(buf, F_OK) == -1)
		return (print_error(cmd, path, 1, 1));
	if (!cmd->next && cmd == shell->first_cmd && buf)
	{
		chdir(buf);
		update_env(shell);
	}
	return (1);
}

void	cd_cmd(t_shell *shell, t_cmd *cmd)
{
	t_token	*args;

	args = cmd->args->next;
	cmd->tmp_status = 0;
	if (args && args->next && args->next->str)
		print_error(shell->first_cmd, "too many argument", 1, 2);
	else if (!args)
		switch_directory(shell, cmd, "~");
	else
		switch_directory(shell, cmd, args->str);
}
