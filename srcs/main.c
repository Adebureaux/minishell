/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:01:28 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 11:19:15 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

int	is_str_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	minishell(t_shell *data)
{
	while (1)
	{
		data->line = readline("minishell: ");
		if (!data->line)
		{
			ft_putendl("exit");
			exit_custom(data, g_exit_status);
		}
		else if (is_str_space(data->line) && data->line[0])
		{
			add_history(data->line);
			if (token_parser(data, data->line) == EXIT_SUCCESS)
				execute_loop(data, data->first_cmd);
		}
		free_cmd(data, data->first_cmd);
		data->first_cmd = init_t_cmd();
	}
	return (g_exit_status);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	*data;

	g_exit_status = 0;
	handle_global_signals();
	data = init_shell();
	if (envp && envp[0] == NULL)
	{
		init_env(&data->env);
		init_env(&data->export);
	}
	else
	{
		init_tab(&data->env, envp);
		init_tab(&data->export, data->env);
	}
	return (minishell(data));
	(void)ac;
	(void)av;
}
