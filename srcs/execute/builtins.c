/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:31:25 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 15:22:38 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_builtin(t_cmd *cmd, char **blt_str)
{
	int		i;

	i = -1;
	while (blt_str[++i])
	{
		if (cmd && cmd->args && !ft_strcmp(cmd->args->str, blt_str[i]))
			return (i);
	}
	return (-1);
}

int	is_builtin(t_cmd *cmd)
{
	char	*blt_str[CMD_NBR + 1];

	blt_str[ECHO] = "echo";
	blt_str[CD] = "cd";
	blt_str[PWD] = "pwd";
	blt_str[EXPORT] = "null";
	blt_str[F_EXPORT] = "null";
	if (cmd && cmd->args && !ft_strcmp(cmd->args->str, "export"))
	{
		if (cmd->args->next)
			blt_str[EXPORT] = "export";
		else
			blt_str[F_EXPORT] = "export";
	}
	blt_str[UNSET] = "unset";
	blt_str[ENV] = "env";
	blt_str[EXIT] = "exit";
	blt_str[8] = NULL;
	return (find_builtin(cmd, blt_str));
}

void	execute_forked_builtin(t_shell *shell, t_cmd *cmd)
{
	void	(*blt_func[CMD_NBR])(t_shell *shell, t_cmd *cmd);

	blt_func[ECHO] = echo_cmd;
	blt_func[CD] = cd_cmd;
	blt_func[PWD] = pwd_cmd;
	blt_func[EXPORT] = export_cmd;
	blt_func[F_EXPORT] = forked_export_cmd;
	blt_func[UNSET] = unset_cmd;
	blt_func[ENV] = env_cmd;
	blt_func[EXIT] = exit_cmd;
	if (cmd->blt != CD && cmd->blt != EXIT
		&& cmd->blt != EXPORT && cmd->blt != UNSET)
		(*blt_func[cmd->blt])(shell, cmd);
	exit_custom(shell, g_exit_status);
}

void	execute_builtin(t_shell *shell, t_cmd *cmd)
{
	void	(*blt_func[CMD_NBR])(t_shell *shell, t_cmd *cmd);

	blt_func[ECHO] = echo_cmd;
	blt_func[CD] = cd_cmd;
	blt_func[PWD] = pwd_cmd;
	blt_func[EXPORT] = export_cmd;
	blt_func[F_EXPORT] = forked_export_cmd;
	blt_func[UNSET] = unset_cmd;
	blt_func[ENV] = env_cmd;
	blt_func[EXIT] = exit_cmd;
	if (cmd->blt == CD || cmd->blt == EXIT
		|| cmd->blt == EXPORT || cmd->blt == UNSET)
		(*blt_func[cmd->blt])(shell, cmd);
}
