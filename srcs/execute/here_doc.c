/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 02:08:42 by adeburea          #+#    #+#             */
/*   Updated: 2022/03/06 12:32:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_here_doc(t_shell *shell, int fd)
{
	int	i;

	i = -1;
	while (++i < 2 * shell->cmd_nbr)
		close(shell->fd[i]);
	ft_putendl("exit");
	close(fd);
	close(shell->tmp_stdin);
	close(shell->tmp_stdout);
	free(shell->fd);
	exit_custom(shell, g_exit_status);
}

void	read_here_doc(t_shell *shell, t_cmd	*cmd)
{
	cmd->fd_in = open("/tmp/.heredoc", O_RDONLY);
	if (access("/tmp/.heredoc", R_OK))
		cmd->fd_in = open(".heredoc", O_RDONLY);
	if (cmd->fd_in == -1)
	{
		free(shell->fd);
		print_error_exit(shell, NULL, 1, -1);
	}
}

char	*write_here_doc(t_shell *shell, t_token *redir, int fd)
{
	char	*alias;
	char	*cmd_line;

	while (true)
	{
		cmd_line = readline("> ");
		if (!cmd_line)
			exit_here_doc(shell, fd);
		if (!ft_strcmp(cmd_line, redir->next->str))
			break ;
		alias = process_aliases(shell->env, cmd_line);
		if (!alias)
			ft_putstr_fd(cmd_line, fd);
		else
			ft_putstr_fd(alias, fd);
		ft_putchar_fd('\n', fd);
		free(alias);
		free(cmd_line);
	}
	return (cmd_line);
}

int	here_doc(t_shell *shell, t_cmd	*cmd, t_token *redir)
{
	int		fd;

	fd = open("/tmp/.heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (access("/tmp/.heredoc", F_OK | W_OK))
		fd = open(".heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error_exit(shell, NULL, 1, -1);
	free(write_here_doc(shell, redir, fd));
	close(fd);
	read_here_doc(shell, cmd);
	return (0);
}
