/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:37:32 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 01:58:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Return the last link of the chain list */
t_token	*ft_lstlast(t_token *lst)
{
	t_token	*actual;

	actual = lst;
	if (lst == NULL)
		return (NULL);
	if (lst == NULL)
		ft_putendl("List not initialized with element");
	while (actual && actual->next)
		actual = actual->next;
	return (actual);
}

/* Add the link new at the last of the chain list */
void	ft_lstadd_back(t_token *lst, t_token *new)
{
	t_token	*tmp;

	if (!lst)
	{
		lst = new;
		return ;
	}
	tmp = ft_lstlast(lst);
	tmp->next = new;
}

void	token_push_back(t_token **lst, t_token *new)
{
	t_token	*actual;
	t_token	*tmp;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		actual = (*lst);
		tmp = actual;
		while (actual->next != NULL)
			actual = actual->next;
		actual->next = new;
		actual->next->previous = tmp;
	}
}
