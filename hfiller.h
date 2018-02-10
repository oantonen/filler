/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiller.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:33:48 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/10 21:06:23 by oantonen         ###   ########.fr       */
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
	char 		me;
	char		him;
	int			y;
	int			x;
	char		up;
}				t_struct;

#define SMALL_MAP 255

void	map_size(t_struct *sizes, char *first);
void	detect_x_or_y(t_struct *sizes);
void	write_map_and_piece(t_struct *sizes, char *first);
int		put_piece(t_struct *sizes);
void	piece_size(t_struct *sizes, char *first);
void	write_piece(t_struct *sizes, char *first);
int		ft_printf(const char *arg, ...);
int		right_is_touched(t_struct *sizes);
int		left_is_touched(t_struct *sizes);
int		up_is_touched(t_struct *sizes);
int		center_is_touched(t_struct *sizes);
int		*find_last_symb(t_struct *sizes);
int		small_algorithm(t_struct *sizes, int x, int y, int i);
int		is_enemy_above(t_struct *sizes);

#endif