/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:40:51 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 14:21:39 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_place_proc_alias(char *token, char **env, int i)
{
	char	*alias;
	char	*result;
	char	*var_env;

	var_env = NULL;
	result = NULL;
	if (token[i] == '$' && token[i + 1] != '\0' && token[i + 1] == '?')
	{
		var_env = ft_itoa(g_exit_status);
		result = replace_by_var_env(token, var_env, i, (i + 2));
		free(var_env);
		return (result);
	}
	if (token[i] == '$')
	{
		alias = ft_strsub(token, i + 1, (ft_strlen_delim(token + i + 1,
						"!\"#$%&\'()*+,./:;<=>?@[\\]^`{|}~ ")));
		var_env = ft_strdup(find_var_env(env, alias));
		result = replace_by_var_env(token, var_env, i,
				ft_strlen(alias) + i + 1);
		free(alias);
		free(var_env);
		return (result);
	}
	return (result);
}

char	*process_aliases(char **env, char *token)
{
	int		i;
	char	*result;
	char	*tmp;

	result = NULL;
	if (ft_strcmp_c(token, '$') == true)
	{
		if (token[0] == '$' && token[1] == '\0')
			return (ft_strdup("$"));
		i = -1;
		while (token[++i])
		{
			result = get_place_proc_alias(token, env, i);
			if (result != NULL)
				break ;
		}
	}
	if (ft_strcmp_c(result, '$') == true)
	{
		tmp = process_aliases(env, result);
		free(result);
		result = tmp;
	}
	return (result);
}
