/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:28:00 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 01:24:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_without_quote(char *str, char c)
{
	char	*tmp;
	size_t	i;
	size_t	y;

	tmp = ft_memalloc(ft_strlen(str));
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			tmp[y] = str[i];
			y++;
		}
		i++;
	}
	return (tmp);
}

void	simple_quote_process(char ***tab, int index)
{
	char	*tmp;
	char	*str;

	str = (*tab)[index];
	tmp = extract_without_quote(str, '\'');
	free((*tab)[index]);
	(*tab)[index] = ft_strdup(tmp);
	free(tmp);
}

void	double_quote_process(t_token *actual, char ***tab,
	int index, char **env)
{
	char	*tmp[4];

	tmp[0] = (*tab)[index];
	tmp[1] = extract_without_quote(tmp[0], '\"');
	if (actual->id != LIMITER)
	{
		tmp[2] = process_aliases(env, tmp[1]);
		if (tmp[2] != NULL)
		{
			free(tmp[0]);
			tmp[0] = ft_strdup(tmp[2]);
			free(tmp[2]);
		}
		else
		{
			free(tmp[0]);
			tmp[0] = ft_strdup(tmp[1]);
		}
		(*tab)[index] = ft_strdup(tmp[0]);
	}
	else
		(*tab)[index] = ft_strdup(tmp[1]);
	free(tmp[1]);
	free(tmp[0]);
}

static void	get_place_no_proc(char ***tab, int index,
	char *tmp, t_token *actual)
{
	char	**space;
	int		i;

	if (ft_strcmp_c(tmp, ' '))
	{
		space = ft_split(tmp, ' ');
		free((*tab)[index]);
		(*tab)[index] = ft_strdup(space[0]);
		i = 0;
		while (space[++i])
			token_push_back(&actual, set_t_token(actual->id,
					ft_strdup(space[i])));
		ft_tab_free(space);
	}
	else
	{
		free((*tab)[index]);
		(*tab)[index] = ft_strdup(tmp);
	}
}

void	no_quote_process(t_token *actual, char **env, char ***tab, int index)
{
	char	*str;
	char	*tmp;
	char	**space;

	space = NULL;
	str = (*tab)[index];
	tmp = process_aliases(env, str);
	if (tmp != NULL)
	{
		if (tmp[0] == '\0')
		{
			free((*tab)[index]);
			(*tab)[index] = NULL;
		}
		else
			get_place_no_proc(tab, index, tmp, actual);
	}
	free(tmp);
}
