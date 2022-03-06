/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 00:15:52 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:01:08 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(char ***tab)
{
	char	pwd[MAXPATHLEN];
	char	*eq;
	char	*full;

	getcwd(pwd, MAXPATHLEN);
	(*tab) = (char **)ft_tab_new(1);
	eq = ft_strjoin("PWD", "=");
	full = ft_strjoin(eq, pwd);
	ft_add_to_tab(full, (void ***)tab);
	free(eq);
	eq = ft_strdup("SHLVL=1");
	ft_add_to_tab(eq, (void ***)tab);
}

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		ft_putendl("Echec Malloc");
	shell->env = NULL;
	shell->export = NULL;
	shell->fd = NULL;
	shell->line = NULL;
	shell->cmd_nbr = 0;
	shell->first_cmd = init_t_cmd();
	return (shell);
}

t_token	*init_t_token(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		ft_putendl("Echec Malloc t_token");
	new->id = NEIN;
	new->str = NULL;
	new->expand = new->str;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_cmd	*init_t_cmd(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		ft_putendl("Error malloc t_cmd");
	new->pid = -42;
	new->run = 1;
	new->tmp_status = 0;
	new->args = NULL;
	new->redir = NULL;
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->next = NULL;
	return (new);
}

void	init_tab(char ***tab_dest, char **tab_src)
{
	(*tab_dest) = (char **)ft_tab_new(ft_tab_len((void **)tab_src));
	ft_tab_dup((void **)(*tab_dest), (void **)tab_src);
}
