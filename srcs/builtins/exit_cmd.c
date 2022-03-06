/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:24:18 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 13:41:01 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_error(t_cmd *cmd, t_token *args)
{
	if (args)
	{
		if (!ft_strisdigit(args->str))
			print_error(cmd, args->str, 255, 255);
		else if (args->next)
			print_error(cmd, "too many arguments", 1, 2);
		else
		{
			g_exit_status = ft_atoi(args->str) % 256;
			cmd->tmp_status = ft_atoi(args->str) % 256;
		}
	}
}

void	close_exit(t_shell *shell, t_cmd *cmd, int status)
{
	int	i;

	close(shell->tmp_stdin);
	close(shell->tmp_stdout);
	while (cmd)
	{
		if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
			close(cmd->fd_out);
		if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
			close(cmd->fd_in);
		cmd = cmd->next;
	}
	i = -1;
	while (++i < 2 * shell->cmd_nbr)
		close(shell->fd[i]);
	free(shell->fd);
	exit_custom(shell, status);
}

void	exit_cmd(t_shell *shell, t_cmd *cmd)
{
	t_token	*args;

	args = cmd->args->next;
	if (!cmd->next && cmd == shell->first_cmd)
		printf("exit\n");
	handle_error(cmd, args);
	if (!cmd->next && cmd == shell->first_cmd)
	{
		if (args)
		{
			if (!ft_strisdigit(args->str))
				close_exit(shell, cmd, 2);
			else
				close_exit(shell, cmd, g_exit_status);
		}
		else
			close_exit(shell, cmd, 0);
	}
}
