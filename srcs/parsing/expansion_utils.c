/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:11:38 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 21:21:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_delim(char *delim, char c)
{
	size_t	i;

	i = 0;
	while (delim[i])
	{
		if (delim[i] == c)
			return (true);
		i++;
	}
	return (false);
}

t_status	set_status(char *line, int i, t_status state)
{
	if (line[i] == '\"' && state == NONE)
		state = OPEN_D;
	else if (line[i] == '\'' && state == NONE)
		state = OPEN_S;
	else if (line[i] == '\"' && state == OPEN_D)
		state = NONE;
	else if (line[i] == '\'' && state == OPEN_S)
		state = NONE;
	return (state);
}

static void	sub_to_add(t_quotes *data, int i, char *line, char ***tab)
{
	char	*tmp;

	data->i_last_quote = i + 1;
	tmp = ft_strsub(line, data->i_first_quote,
			(data->i_last_quote - data->i_first_quote));
	ft_add_to_tab(tmp, (void ***)tab);
	data->i_first_quote = i + 1;
}

void	extract_quote(char *line, char ***tab, int i, t_quotes *data)
{
	if (line[i] == '\'' && (data->state == NONE || data->state == CLOSE_S
			|| data->state == CLOSE_D))
	{
		data->state = OPEN_S;
		data->i_first_quote = i;
	}
	else if (line[i] == '\'' && data->state == OPEN_S)
	{
		data->state = CLOSE_S;
		sub_to_add(data, i, line, tab);
	}
	if (line[i] == '\"' && (data->state == NONE || data->state == CLOSE_S
			|| data->state == CLOSE_D))
	{
		data->state = OPEN_D;
		data->i_first_quote = i;
	}
	else if (line[i] == '\"' && data->state == OPEN_D)
	{
		data->state = CLOSE_D;
		sub_to_add(data, i, line, tab);
	}
}
