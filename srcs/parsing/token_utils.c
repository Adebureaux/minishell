/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 01:19:10 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:47:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_redir_two(t_cmd *actual, char **tab, int i, t_type *previous)
{
	if (ft_strcmp_c(tab[i], '<'))
	{
		if (check_redir(tab, i, REDIR_IN, (*previous)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		token_push_back(&actual->redir, set_t_token(REDIR_IN,
				ft_strdup(tab[i])));
		(*previous) = REDIR_IN;
	}
	else if (ft_strcmp_c(tab[i], '>'))
	{
		if (check_redir(tab, i, REDIR_OUT, (*previous)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		token_push_back(&actual->redir, set_t_token(REDIR_OUT,
				ft_strdup(tab[i])));
		(*previous) = REDIR_OUT;
	}
	return (EXIT_SUCCESS);
}

static int	set_redir_one(t_cmd *actual, char **tab, int i, t_type *previous)
{
	if (ft_strstr(tab[i], "<<") != NULL)
	{
		if (check_redir(tab, i, HERE_DOC, (*previous)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		token_push_back(&actual->redir, set_t_token(HERE_DOC,
				ft_strdup(tab[i])));
		(*previous) = HERE_DOC;
	}
	else if (ft_strstr(tab[i], ">>") != NULL)
	{
		if (check_redir(tab, i, APPEND_OUT, (*previous)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		token_push_back(&actual->redir, set_t_token(APPEND_OUT,
				ft_strdup(tab[i])));
		(*previous) = APPEND_OUT;
	}
	return (EXIT_SUCCESS);
}

static int	set_redir(t_cmd *actual, char **tab, int i, t_type *previous)
{
	if (ft_strstr(tab[i], "<<") != NULL || ft_strstr(tab[i], ">>") != NULL)
	{
		if (set_redir_one(actual, tab, i, previous) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (ft_strcmp_c(tab[i], '<') || ft_strcmp_c(tab[i], '>'))
	{
		if (set_redir_two(actual, tab, i, previous) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	set_other(t_cmd *actual, char **tab, int i, t_type *previous)
{
	if ((*previous) != NEIN && tab[i][0] != ' ' && (*previous) == HERE_DOC)
	{
		token_push_back(&actual->redir, set_t_token(LIMITER,
				ft_strdup(tab[i])));
		(*previous) = LIMITER;
	}
	else if ((*previous) != NEIN && tab[i][0] != ' '
		&& ((*previous) == REDIR_IN || (*previous) == REDIR_OUT
			|| (*previous) == APPEND_OUT))
	{
		token_push_back(&actual->redir, set_t_token(FD, ft_strdup(tab[i])));
		(*previous) = FD;
	}
	else
	{
		if (tab[i][0] != ' ')
		{
			token_push_back(&actual->args, set_t_token(WORD,
					ft_strdup(tab[i])));
			(*previous) = WORD;
		}
	}
}

int	manage_token(t_norm *norm, size_t i)
{
	if ((norm->quotes == false && ft_strcmp_c(norm->tab[i], '|'))
		|| (norm->quotes == false && ft_strstr(norm->tab[i], "<<") != NULL)
		|| (norm->quotes == false && ft_strstr(norm->tab[i], ">>") != NULL)
		|| (norm->quotes == false && ft_strcmp_c(norm->tab[i], '<'))
		|| (norm->quotes == false && ft_strcmp_c(norm->tab[i], '>')))
	{
		if (norm->tab[i] && ft_strcmp_c(norm->tab[i], '|')
			&& ft_strlen(norm->tab[i]) == 1)
		{
			if (check_pipe(norm->tab, i, norm->previous) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			norm->cmd->next = init_t_cmd();
			norm->cmd = norm->cmd->next;
			norm->previous = PIPE;
		}
		if (set_redir(norm->cmd, norm->tab, i, &norm->previous) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		set_other(norm->cmd, norm->tab, i, &norm->previous);
	return (EXIT_SUCCESS);
}
