/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:23:15 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:51:16 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	void	get_place_split(size_t *i, size_t *start,
	char ***tab, char *tmp)
{
	if ((*i) != 0)
		(*start) = add_token(tab, tmp, (*start), (*i) - (*start)) + (*i) + 1;
	if ((tmp[(*i)] == '<' && tmp[(*i) + 1] == '<')
		|| (tmp[(*i)] == '>' && tmp[(*i) + 1] == '>'))
	{
		(*start) = add_token(tab, tmp, (*i), 2) + (*i) + 2;
		(*i)++;
	}
	else if (tmp[(*i)] == '|' || (tmp[(*i)] == '<' && tmp[(*i) + 1] != '<')
		|| (tmp[(*i)] == '>' && tmp[(*i) + 1] != '>'))
		(*start) = add_token(tab, tmp, (*i), 1) + (*i) + 1;
	else if (tmp[(*i)] == ' ')
		(*start) = add_token(tab, tmp, (*i), 1) + (*i) + 1;
}

char	**split_token(char *line)
{
	size_t		i;
	size_t		start;
	char		**tab;
	t_status	state;
	char		*tmp;

	state = NONE;
	tab = (char **)ft_tab_new(1);
	tmp = ft_strtrim(line);
	start = 0;
	i = 0;
	while (tmp && tmp[i])
	{
		state = set_status(tmp, i, state);
		if (is_delim(" |<>", tmp[i]) && state == NONE)
			get_place_split(&i, &start, &tab, tmp);
		i++;
	}
	add_token(&tab, tmp, start, i - start);
	free(tmp);
	return (tab);
}

void	process_quotes(t_token *actual, char ***tab, char **env)
{
	char	**tmp_tab;
	size_t	i;

	tmp_tab = (*tab);
	i = 0;
	while (tmp_tab[i])
	{
		if (tmp_tab[i][0] == '\'')
			simple_quote_process(tab, i);
		else if (tmp_tab[i][0] == '\"')
			double_quote_process(actual, tab, i, env);
		else
			no_quote_process(actual, env, tab, i);
		i++;
	}
}

int	expansion_token(t_token *lst, char **env)
{
	t_token	*actual;

	actual = lst;
	while (actual)
	{
		if (actual->id == WORD || actual->id == FD || actual->id == LIMITER)
		{
			if (check_quote(actual, env) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		actual = actual->next;
	}
	return (EXIT_SUCCESS);
}

/* Parse la cmd line */
int	token_parser(t_shell *data, char *line)
{
	char	**tab;
	t_cmd	*actual;

	tab = split_token(line);
	if (recognize_token(data, tab))
	{
		ft_tab_free(tab);
		return (EXIT_FAILURE);
	}
	actual = data->first_cmd;
	while (actual)
	{
		if (expansion_token(actual->args, data->env)
			|| expansion_token(actual->redir, data->env))
		{
			ft_tab_free(tab);
			return (EXIT_FAILURE);
		}
		actual = actual->next;
	}
	ft_tab_free(tab);
	return (EXIT_SUCCESS);
}
