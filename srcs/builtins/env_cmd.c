/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:24:49 by mravily           #+#    #+#             */
/*   Updated: 2022/03/04 22:39:38 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_cmd(t_shell *shell, t_cmd *cmd)
{
	int	i;

	i = -1;
	g_exit_status = 0;
	while (shell->env && shell->env[++i])
	{
		ft_putstr(shell->env[i]);
		ft_putchar('\n');
	}
	(void)cmd;
}
