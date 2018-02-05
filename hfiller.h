/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiller.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:33:48 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/05 20:36:31 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILLER_H
# define HFILLER_H

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct	s_struct
{
	int			map_y;
	int			map_x;
	int			piece_y;
	int			piece_x;
	char		**map;
	char		**piece;
	char		*enemy;
	int 		first;
	int			y;
	int			x;
}				t_struct;

void	map_size(t_struct *sizes, char *first);
void	detect_me_and_enemy(t_struct *sizes);
void	write_map_and_piece(t_struct *sizes, char *first);
int		put_piece(t_struct *sizes);
void	piece_size(t_struct *sizes, char *first);
void	write_piece(t_struct *sizes, char *first);
int		ft_printf(const char *arg, ...);


#endif