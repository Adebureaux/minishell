/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:25:31 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 01:50:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Cherche dans le tableau env si to find est présente et le mets à zéro
** Retour true si to find à été trouver et false dans le cas contraire
*/
char	**unset(char **env, char *to_find)
{
	int		i;
	int		j;
	int		len;
	char	**new_tab;

	i = 0;
	j = 0;
	if (find_var_env(env, to_find))
		new_tab = (char **)malloc(sizeof(char *) * ft_tab_len((void *)env));
	else
		new_tab = (char **)malloc
			(sizeof(char *) * (ft_tab_len((void *)env) + 1));
	len = ft_strlen(to_find);
	while (env[i])
	{
		if (ft_strncmp(env[i], to_find, len))
		{
			new_tab[j] = ft_strdup(env[i]);
			j++;
		}
		i++;
	}
	new_tab[j] = NULL;
	ft_tab_free(env);
	return (new_tab);
}

/*
** Supprime la variable du tableau env et export si elle est trouvée
*/
void	unset_cmd(t_shell *shell, t_cmd *cmd)
{
	t_token	*actual;

	cmd->tmp_status = 0;
	actual = cmd->args->next;
	while (actual && actual->str)
	{
		if ((actual->str && actual->str[0] == '=')
			|| (actual->str && ft_isdigit(actual->str[0]))
			|| (actual->str && actual->str[0] == '\0'))
			print_error(cmd, actual->str, 1, 5);
		if (!cmd->next && cmd == shell->first_cmd)
		{
			shell->env = unset(shell->env, actual->str);
			shell->export = unset(shell->export, actual->str);
		}
		actual = actual->next;
	}
}
