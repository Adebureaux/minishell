/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:49:51 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:47:36 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redir(t_type id)
{
	if (id == HERE_DOC || id == REDIR_OUT || id == REDIR_IN || id == APPEND_OUT)
		return (true);
	return (false);
}

t_token	*set_t_token(t_type id, char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		ft_putendl("Echec Malloc t_token");
	new->id = id;
	new->str = str;
	new->expand = str;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

int	check_redir(char **tab, size_t i, t_type id, t_type previous)
{
	if (is_redir(id) && (i > 0 && tab[i - 1])
		&& (previous == HERE_DOC
			|| previous == REDIR_OUT
			|| previous == REDIR_IN
			|| previous == APPEND_OUT))
	{
		print_error(NULL, tab[i], 258, 258);
		return (EXIT_FAILURE);
	}
	if (tab[i + 1] != NULL)
		return (EXIT_SUCCESS);
	else
	{
		print_error(NULL, "newline", 258, 258);
		return (EXIT_FAILURE);
	}
}

int	check_pipe(char **tab, int i, t_type previous)
{
	if ((i > 0 && tab[i - 1])
		&& (previous == HERE_DOC
			|| previous == REDIR_OUT
			|| previous == REDIR_IN
			|| previous == APPEND_OUT))
	{
		print_error(NULL, tab[i], 258, 258);
		return (EXIT_FAILURE);
	}
	if (ft_strcmp_c(tab[i], '|') && !tab[i + 1])
	{
		print_error(NULL, tab[i], 2, 258);
		return (EXIT_FAILURE);
	}
	if ((i == 0 && ft_strcmp_c(tab[i + 1], '|') && tab[i + 2] == NULL)
		|| (ft_strcmp_c(tab[i], '|') && ft_strcmp_c(tab[i + 1], '|')))
	{
		print_error(NULL, "||", 258, 258);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	recognize_token(t_shell *data, char **tab)
{
	t_norm		norm;
	size_t		i;

	norm.quotes = false;
	norm.tab = tab;
	norm.previous = NEIN;
	norm.cmd = data->first_cmd;
	i = 0;
	while (norm.tab && norm.tab[i])
	{
		if (ft_strcmp_c(norm.tab[i], '\'') || ft_strcmp_c(norm.tab[i], '\"'))
			norm.quotes = true;
		if (manage_token(&norm, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		norm.quotes = false;
		i++;
	}
	return (EXIT_SUCCESS);
}
