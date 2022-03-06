/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:28:12 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 04:33:34 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_cmd(t_shell *shell, t_cmd *cmd)
{
	t_token	*args;

	g_exit_status = 0;
	args = cmd->args->next;
	if (args && !ft_strcmp(args->str, "-n"))
		args = args->next;
	while (args)
	{
		ft_putstr(args->str);
		if (args->next)
			ft_putchar(' ');
		args = args->next;
	}
	if (!cmd->args->next
		|| (cmd->args->next && ft_strcmp(cmd->args->next->str, "-n")))
		ft_putchar('\n');
	(void)shell;
}
