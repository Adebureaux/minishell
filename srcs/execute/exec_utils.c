/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:16:48 by adeburea          #+#    #+#             */
/*   Updated: 2022/03/06 14:36:11 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_pipe(t_shell *shell)
{
	int		i;
	t_cmd	*cmd;

	i = -1;
	cmd = shell->first_cmd;
	shell->fd = malloc(sizeof(int) * shell->cmd_nbr * 2);
	while (++i < shell->cmd_nbr)
	{
		if (pipe(shell->fd + i * 2) < 0)
			print_error_exit(shell, NULL, 1, -1);
	}
}

void	close_fd(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < 2 * shell->cmd_nbr)
		close(shell->fd[i]);
	free(shell->fd);
}

void	wait_process(t_shell *shell, t_cmd *cmd)
{
	int	ret;

	close_fd(shell);
	ret = -1;
	while (cmd)
	{
		waitpid(cmd->pid, &ret, 0);
		if (cmd->blt == EXIT)
			g_exit_status = cmd->tmp_status;
		else if (WIFEXITED(ret))
			g_exit_status = WEXITSTATUS(ret);
		else if (WIFSIGNALED(ret))
			g_exit_status = WTERMSIG(ret) + 128;
		else if (cmd->blt != CD && cmd->blt != EXIT
			&& cmd->blt != EXPORT && cmd->blt != UNSET)
			g_exit_status = ret % 255;
		else
			g_exit_status = cmd->tmp_status;
		if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
			close(cmd->fd_out);
		if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
			close(cmd->fd_in);
		cmd = cmd->next;
	}
}

void	manage_fd(t_shell *shell, t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->next && dup2(shell->fd[shell->i + 1], cmd->fd_out) == -1)
		print_error_exit(shell, NULL, 1, -1);
	if (shell->i && dup2(shell->fd[shell->i - 2], cmd->fd_in) == -1)
		print_error_exit(shell, NULL, 1, -1);
	while (++i < 2 * shell->cmd_nbr)
		close(shell->fd[i]);
	free(shell->fd);
	close(shell->tmp_stdin);
	close(shell->tmp_stdout);
	if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
		close(cmd->fd_out);
	if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
		close(cmd->fd_in);
}
