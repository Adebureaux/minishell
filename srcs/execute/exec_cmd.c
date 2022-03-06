/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:41:28 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 14:24:42 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*path;
	char	**argv;

	if (is_builtin(cmd) == -1)
	{
		if (!cmd->args->str)
			exit_custom(shell, g_exit_status);
		argv = set_args(cmd->args);
		path = set_path_exec(shell->env, cmd->args->str);
		if (!path || execve(path, argv, shell->env) == -1)
		{
			if (argv && argv[0]
				&& !access(argv[0], F_OK) && access(argv[0], X_OK))
			{
				free(path);
				free(argv);
				print_error_exit(shell, cmd, 126, 126);
			}
			free(path);
			free(argv);
			print_error_exit(shell, cmd, 127, 127);
		}
	}
	else
		execute_forked_builtin(shell, cmd);
}

void	execute_fork(t_shell *shell, t_cmd *cmd)
{
	handle_cmd_signals();
	cmd->pid = fork();
	if (cmd->pid == -1)
		print_error_exit(shell, NULL, 1, -1);
	else if (!cmd->pid)
	{
		manage_fd(shell, cmd);
		execute_cmd(shell, cmd);
	}
	ignore_all_signals();
}

int	count_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (cmd->args)
			i++;
		cmd = cmd->next;
	}
	return (i);
}

int	execute_loop(t_shell *shell, t_cmd *cmd)
{
	shell->i = 0;
	shell->cmd_nbr = count_cmd(cmd);
	execute_pipe(shell);
	while (cmd)
	{
		shell->tmp_stdout = dup(STDOUT_FILENO);
		shell->tmp_stdin = dup(STDIN_FILENO);
		cmd->blt = is_builtin(cmd);
		if (cmd->redir)
			execute_redir(shell, cmd, cmd->redir);
		if (cmd->args && cmd->run)
		{
			execute_fork(shell, cmd);
			execute_builtin(shell, cmd);
			shell->i += 2;
		}
		dup2(shell->tmp_stdin, STDIN_FILENO);
		close(shell->tmp_stdin);
		dup2(shell->tmp_stdout, STDOUT_FILENO);
		close(shell->tmp_stdout);
		cmd = cmd->next;
	}
	wait_process(shell, shell->first_cmd);
	handle_global_signals();
	return (0);
}
