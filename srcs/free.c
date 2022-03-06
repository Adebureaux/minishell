/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:41:14 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 11:45:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Reset the token chained list */
void	free_token(t_token **actual)
{
	t_token	*tmp;

	while (*actual)
	{
		(*actual)->id = -1;
		free((*actual)->str);
		tmp = (*actual)->next;
		free(*actual);
		(*actual) = NULL;
		(*actual) = tmp;
	}
}

void	free_cmd(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*actual;
	void	*tmp;

	actual = cmd;
	while (actual)
	{
		if (actual->args)
			free_token(&actual->args);
		if (actual->redir)
			free_token(&actual->redir);
		tmp = actual;
		actual = actual->next;
		free(tmp);
		tmp = NULL;
	}
	free(shell->line);
}

void	free_shell(t_shell *shell)
{
	free_cmd(shell, shell->first_cmd);
	ft_tab_free(shell->env);
	ft_tab_free(shell->export);
	free(shell);
}

void	exit_custom(t_shell *shell, int exit_status)
{
	free_shell(shell);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(exit_status);
}
