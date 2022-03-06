/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:23:36 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 20:54:44 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Initialise la structure t_quotes */
t_quotes	init_data_quotes(void)
{
	t_quotes	new;

	new.i_first_quote = 0;
	new.i_last_quote = 0;
	new.first = false;
	new.state = NONE;
	return (new);
}
