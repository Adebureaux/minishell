/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:21:26 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:04:36 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*process_tab(t_token *actual, char **env,
	t_quotes data, char ***tab)
{
	size_t	i;
	char	*result;
	char	*tmp;

	tmp = NULL;
	result = NULL;
	if (data.state == CLOSE_S || data.state == CLOSE_D)
		process_quotes(actual, tab, env);
	if (actual->id != LIMITER && data.state == NONE)
		no_quote_process(actual, env, tab, 0);
	if (tab != NULL)
	{
		i = -1;
		while ((*tab)[++i])
		{
			tmp = ft_strjoin(result, (*tab)[i]);
			free(result);
			result = ft_strdup(tmp);
			free(tmp);
		}
	}
	return (result);
}

static void	get_place_check_quote(t_quotes *data, char *line,
	char ***tab, size_t i)
{
	char	*tmp_2;

	if (data->i_first_quote != 0 && data->i_last_quote == 0
		&& data->first == false)
	{
		data->first = true;
		tmp_2 = ft_strsub(line, 0, i);
		ft_add_to_tab(tmp_2, (void ***)tab);
	}
	else if (data->i_last_quote < data->i_first_quote
		&& i == data->i_first_quote
		&& (data->state == OPEN_S || data->state == OPEN_D))
	{
		tmp_2 = ft_strsub(line, data->i_last_quote,
				(data->i_first_quote - data->i_last_quote));
		ft_add_to_tab(tmp_2, (void ***)tab);
	}
}

static void	extract_to_tab(t_quotes *data, char *line, char ***tab)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			extract_quote(line, tab, i, data);
			get_place_check_quote(data, line, tab, i);
		}
		i++;
	}
	data->i_last_quote = i;
	tmp = ft_strsub(line, data->i_first_quote,
			(data->i_last_quote - data->i_first_quote));
	ft_add_to_tab(tmp, (void ***)tab);
}

int	check_quote(t_token *actual, char **env)
{
	char		**tab;
	char		*line;
	t_quotes	data;

	data = init_data_quotes();
	tab = (char **)ft_tab_new(1);
	line = actual->str;
	if (line)
		actual->expand = line;
	extract_to_tab(&data, line, &tab);
	if (data.state == OPEN_S || data.state == OPEN_D)
	{
		print_error(NULL, "newline", 258, 258);
		ft_tab_free(tab);
		return (EXIT_FAILURE);
	}
	actual->str = process_tab(actual, env, data, &tab);
	free(line);
	ft_tab_free(tab);
	return (EXIT_SUCCESS);
}
