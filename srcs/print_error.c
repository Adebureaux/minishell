/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:35:02 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 15:17:18 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error_exit(t_shell *shell, t_cmd *cmd, int exit_status,
	int error_type)
{
	if (error_type == -1 && errno)
		ft_fprintf(STDERR_FILENO, ": %s\n", strerror(errno));
	else if (error_type == 126)
		ft_fprintf(STDERR_FILENO, "minishell: %s: permission denied\n",
			cmd->args->str);
	else if (error_type == 127)
		ft_fprintf(STDERR_FILENO, "minishell: %s: command not found\n",
			cmd->args->str);
	if (cmd)
		cmd->tmp_status = exit_status;
	g_exit_status = exit_status;
	exit_custom(shell, exit_status);
}

int	print_error_2(t_cmd *cmd, int exit_status)
{
	if (cmd)
		cmd->tmp_status = exit_status;
	g_exit_status = exit_status;
	return (exit_status);
}

int	print_error(t_cmd *cmd, char *str, int exit_status, int error_type)
{
	if (error_type == -1 && errno)
		ft_fprintf(2, "minishell: %s\n", strerror(errno));
	else if (error_type == 1 && errno && cmd->args->next)
		ft_fprintf(2, "minishell: %s: %s: %s\n",
			cmd->args->str, cmd->args->next->str, strerror(errno));
	else if (error_type == 2)
		ft_fprintf(2, "minishell: %s: %s\n", cmd->args->str, str);
	else if (error_type == 3)
		ft_fprintf(2, "minishell: %s: %s\n", str, strerror(errno));
	else if (error_type == 4)
		ft_fprintf(2, "minishell: %s: ambigous redirect\n", str);
	else if (error_type == 5)
		ft_fprintf(2, "minishell: %s: `%s': not a valid identifier\n",
			cmd->args->str, str);
	else if (error_type == 255)
		ft_fprintf(2, "minishell: %s: %s: numeric argument required\n",
			cmd->args->str, cmd->args->next->str);
	else if (error_type == 258)
		ft_fprintf(2,
			"minishell: syntax error near unexpected token `%s'\n", str);
	else if (error_type == 22)
		ft_fprintf(2, "minishell: syntax error: unexpected end of file\n");
	return (print_error_2(cmd, exit_status));
}
