/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:34:04 by mravily           #+#    #+#             */
/*   Updated: 2022/03/04 21:49:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	find_some_chars(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	while (str && str[i])
	{
		y = 0;
		while (to_find && to_find[y])
		{
			if (str[i] == to_find[y])
				return (true);
			y++;
		}
		i++;
	}
	return (false);
}

void	check_var(t_shell *shell, t_cmd *cmd)
{
	t_token	*actual;

	actual = cmd->args->next;
	while (actual)
	{
		if ((actual->str && actual->str[0] == '=')
			|| (actual->str && ft_isdigit(actual->str[0]))
			|| (actual->str && actual->str[0] == '\0'))
			print_error(cmd, actual->str, 1, 5);
		if (!cmd->next && cmd == shell->first_cmd
			&& ft_strcchr(actual->str, '=') == true)
		{
			export_var_env(&shell->env,
				ft_strsub(actual->str, 0, ft_strlen_delim(actual->str, "=")),
				ft_strdup(actual->str));
			export_var_env(&shell->export,
				ft_strsub(actual->str, 0, ft_strlen_delim(actual->str, "=")),
				ft_strdup(actual->str));
		}
		else if (!cmd->next && cmd == shell->first_cmd)
			check_var_env(&shell->export,
				ft_strsub(actual->str, 0, ft_strlen(actual->str)),
				ft_strdup(actual->str));
		actual = actual->next;
	}
}

void	print_export(char **export)
{
	int		i;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	i = -1;
	while (export[++i])
	{
		if (ft_strcchr(export[i], '=') == true)
		{
			key = ft_strsub(export[i], 0, ft_strlen_delim(export[i], "=") + 1);
			value = ft_strdup(export[i] + ft_strlen_delim(export[i], "=") + 1);
			printf("declare -x %s\"%s\"\n", key, value);
			free(key);
			free(value);
		}
		else
			printf("declare -x %s\n", export[i]);
	}
}
