/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:57:10 by nlafarge          #+#    #+#             */
/*   Updated: 2021/09/15 23:04:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);

#endif
