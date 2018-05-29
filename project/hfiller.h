/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiller.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:33:48 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/15 20:58:50 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILLER_H
# define HFILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_struct
{
	int			map_y;
	int			map_x;
	int			piece_y;
	int			piece_x;
	int			sh_x;
	int			sh_y;
	char		**map;
	char		**piece;
	char		me;
	char		him;
	char		y;
	char		x;
	char		me_up;
}				t_struct;

void			map_size(t_struct *sizes, char *first);
void			detect_who_is_who(t_struct *sizes);
void			write_map(t_struct *sizes, char *first);
int				put_piece(t_struct *sizes, int y, int x);
void			write_piece(t_struct *sizes, char *first);
int				ft_printf(const char *arg, ...);
int				right_is_touched(t_struct *sizes);
int				left_is_touched(t_struct *sizes);
int				up_is_touched(t_struct *sizes);
int				center_is_touched(t_struct *sizes);
int				is_enemy_above(t_struct *sizes);
int				small_algorithm(t_struct *sizes, int x, int y, int i);
int				small_algorithm_up(t_struct *sizes, int x, int y, int i);
int				algo_for_m_up(t_struct *sizes, int x, int y, int i);
int				algo_for_b_down(t_struct *sizes, int x, int y, int i);
int				algo_for_b_up(t_struct *sizes, int x, int y, int i);
int				algorithm_switcher(t_struct *sizes, int x, int y, int i);
void			detect_up_or_down(t_struct *sizes);

#endif
