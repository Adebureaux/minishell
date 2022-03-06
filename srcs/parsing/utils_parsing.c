/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:44:08 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 18:09:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Allow to trim spaces and get rid of add spaces in tab
** The return value to 0 is just a way to save one line
*/
int	add_token(char ***tab, char *line, int start, int end)
{
	char	*tmp;

	tmp = ft_strsub(line, start, end);
	if (tmp && !tmp[0])
	{
		free(tmp);
		tmp = NULL;
	}
	else
		ft_add_to_tab(tmp, (void ***)tab);
	return (0);
}
/*
** Remplace dans str de l'index start jusqu'à l'index end,
** par la variable env correspondante à to_find
** Si aucune var env ne corresponds return str
** Sinon return la str modifier
** Ne pas oublier de free result
*/

char	*find_var(char **envp, char *to_find)
{
	size_t	i;
	size_t	len;
	size_t	len_tab;

	len = ft_strlen(to_find);
	len_tab = ft_tab_len((void **)envp);
	i = 0;
	while (i < len_tab)
	{
		if (envp && envp[0] && envp[0][0] && envp[i][0] == to_find[0])
		{
			if (!ft_strncmp((char *)envp[i], to_find, len)
				&& envp[i][len] == '=')
				return (envp[i]);
		}
		i++;
	}
	return (NULL);
}

static char	*join_free(char **tab)
{
	size_t	i;
	char	*tmp;
	char	*result;

	tmp = NULL;
	result = NULL;
	i = 0;
	while (tab[i])
	{
		tmp = ft_strjoin(result, tab[i]);
		free(result);
		result = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (result);
}

char	*replace_by_var_env(char *str, char *var_env, size_t start, size_t end)
{
	char	**tab;
	char	*result;

	result = NULL;
	tab = (char **)ft_tab_new(3);
	tab[0] = ft_strsub(str, 0, start);
	if (var_env == NULL)
	{
		tab[1] = ft_strsub(str, end, ft_strlen(str + end));
		tab[2] = ft_strdup("\0");
	}
	else
	{
		tab[1] = ft_strdup(var_env);
		tab[2] = ft_strsub(str, end, ft_strlen(str + end));
	}
	result = join_free(tab);
	ft_tab_free(tab);
	return (result);
}

/*
** Remplace dans str de l'index start jusqu'à l'index end,
** par to_replace
** Return la str modifier
** Ne pas oublier de free result
*/
char	*ft_str_replace(char *str, char *to_replace, size_t start, size_t end)
{
	char	**tab;
	char	*result;
	size_t	i;

	result = NULL;
	tab = (char **)ft_tab_new(3);
	if (to_replace == NULL)
	{
		tab[0] = ft_strsub(str, 0, start);
		tab[1] = ft_strsub(str, end, ft_strlen(str + end));
		tab[2] = ft_strdup("\0");
	}
	else
	{
		tab[0] = ft_strsub(str, 0, start);
		tab[1] = ft_strdup(to_replace);
		tab[2] = ft_strsub(str, end, ft_strlen(str + end));
	}
	i = -1;
	while (tab[++i])
		result = ft_strjoin(result, tab[i]);
	ft_tab_free(tab);
	return (result);
}
