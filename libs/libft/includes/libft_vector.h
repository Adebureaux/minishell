/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:41:56 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 21:09:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTOR_H
# define LIBFT_VECTOR_H

typedef struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

t_vector2		create_vector2(int p_x, int p_y);
t_vector2		*malloc_vector2(int p_x, int p_y);
void			swap_t_vector2(t_vector2 *a, t_vector2 *b);
bool			is_t_vector2_equal(t_vector2 a, t_vector2 b);
float			distance_vector2(t_vector2 a, t_vector2 b);

#endif
