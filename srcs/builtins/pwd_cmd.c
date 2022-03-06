/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:18:09 by mravily           #+#    #+#             */
/*   Updated: 2022/03/04 22:39:49 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_cmd(t_shell *shell, t_cmd *cmd)
{
	char	pwd[MAXPATHLEN];

	if (getcwd(pwd, MAXPATHLEN))
	{
		ft_putstr(pwd);
		ft_putchar('\n');
		g_exit_status = 0;
	}
	else
		print_error(NULL, NULL, 1, -1);
	(void)shell;
	(void)cmd;
}
