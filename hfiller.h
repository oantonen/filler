/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiller.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:33:48 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/12 22:02:55 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILLER_H
# define HFILLER_H

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct	s_hole
{
	char		**map2;
	char		**map_put;
	int			pos[20];
	int			pos2[20];
	int			count1;
	int			count2;
	char		*s1;
	char		*s2;
}				t_hole;

typedef struct	s_struct
{
	int			map_y;
	int			map_x;
	int			piece_y;
	int			piece_x;
	char		**map;
	char		**piece;
	char 		me;
	char		him;
	int			y;
	int			x;
	int			hole_count;
}				t_struct;

#define SMALL_MAP 255

void	map_size(t_struct *sizes, char *first);
void	detect_who_is_who(t_struct *sizes);
void	write_map(t_struct *sizes, char *first);
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
int		scan_map_for_holes(t_struct *sizes, int y, int x);

#endif