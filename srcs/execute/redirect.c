/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:07:23 by adeburea          #+#    #+#             */
/*   Updated: 2022/03/06 15:06:01 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_out(t_cmd	*cmd, t_token *redir)
{
	if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
		close(cmd->fd_out);
	if (redir->next->str)
		cmd->fd_out = open(redir->next->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		cmd->fd_out = -1;
	if (cmd->fd_out == -1)
	{
		cmd->run = 0;
		if (redir->next->str)
			return (print_error(NULL, redir->next->str, 1, 3));
		else if (redir->next->expand)
			return (print_error(NULL, redir->next->expand, 1, 4));
	}
	if (redir->next->str)
	{		
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	return (0);
}

int	append_out(t_cmd *cmd, t_token *redir)
{
	if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
		close(cmd->fd_out);
	if (redir->next->str)
		cmd->fd_out = open(redir->next->str, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		cmd->fd_out = -1;
	if (cmd->fd_out == -1)
	{
		cmd->run = 0;
		if (redir->next->str)
			return (print_error(NULL, redir->next->str, 1, 3));
		else if (redir->next->expand)
			return (print_error(NULL, redir->next->expand, 1, 4));
	}
	if (redir->next->str)
	{		
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	return (0);
}

int	redir_in(t_cmd	*cmd, t_token *redir)
{
	if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
		close(cmd->fd_in);
	if (redir->next->str)
		cmd->fd_in = open(redir->next->str, O_RDONLY);
	else
		cmd->fd_out = -1;
	if (cmd->fd_in == -1)
	{
		cmd->run = 0;
		if (redir->next->str)
			return (print_error(NULL, redir->next->str, 1, 3));
		else if (redir->next->expand)
			return (print_error(NULL, redir->next->expand, 1, 4));
	}
	return (0);
}

int	execute_redir(t_shell *shell, t_cmd	*cmd, t_token *redir)
{
	while (redir)
	{
		if (redir->id == REDIR_OUT && redir_out(cmd, redir))
			return (0);
		else if (redir->id == APPEND_OUT && append_out(cmd, redir))
			return (0);
		else if (redir->id == REDIR_IN && redir_in(cmd, redir))
			return (0);
		else if (redir->id == HERE_DOC && here_doc(shell, cmd, redir))
			return (0);
		redir = redir->next;
	}
	if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	return (1);
}
