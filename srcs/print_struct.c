/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:47:34 by mravily           #+#    #+#             */
/*   Updated: 2022/03/04 20:12:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Displays the content of each link of the chained list */
void	print_t_shell(t_shell *data)
{
	if (data == NULL)
		printf("error print_t_shell\n");
	ft_putendl("~~~~~> T_SHELL <~~~~~");
	ft_putendl("----=========----");
	ft_print_str_tab("ENV", data->env);
	print_list_cmd(data->first_cmd);
	print_list_token("TOKEN", data->first_token);
	ft_putendl("----=========----");
}

/* Displays the content of each link of the chained list */
void	print_list_token(char *name, t_token *list)
{
	t_token	*actual;
	size_t	i;

	if (list == NULL)
		printf("error print_list_token\n");
	actual = list;
	ft_putendl(name);
	ft_putendl("----=========----");
	i = 0;
	while (actual != NULL)
	{
		ft_printf("~~~~~> %d <~~~~~\n", i);
		print_token(actual);
		actual = actual->next;
		i++;
	}
	ft_putendl("----=========----");
}

/* Display the link of chained list given in paramas */
void	print_token(t_token *element)
{
	ft_putendl("----=========----");
	printf("ID = %d\n", element->id);
	printf("str = %s\n", element->str);
	ft_putendl("----=========----");
}

void	print_cmd(t_cmd *element)
{
	ft_putendl("----=========----");
	print_list_token("ARGS", element->args);
	print_list_token("REDIR", element->redir);
	ft_printf("fd_in = %d\n", element->fd_in);
	ft_printf("fd_out = %d\n", element->fd_out);
	ft_putendl("----=========----");
}

/* Display the link of chained list given in paramas */
void	print_list_cmd(t_cmd *list)
{
	size_t	i;
	t_cmd	*actual;

	actual = list;
	ft_putendl("~~~~~> T_CMD <~~~~~");
	ft_putendl("----=========----");
	i = 0;
	while (actual != NULL)
	{
		ft_printf("~~~~~> CMD %d <~~~~~\n", i);
		print_cmd(actual);
		actual = actual->next;
		i++;
	}
	ft_putendl("----=========----");
}
