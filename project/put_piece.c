/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:15:59 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/15 16:06:52 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

int		find_last_symb(t_struct *sizes)
{
	int		i;
	int		coord;
	char	him;

	him = sizes->him;
	i = sizes->map_y;
	coord = 0;
	while (--i != -1)
	{
		if (ft_strchr(sizes->map[i], him))
		{
			coord = i;
			break ;
		}
	}
	return (coord);
}

void	go_right(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;

	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		prev_dist = ft_abs_value(sizes->x - 39) + ft_abs_value(sizes->y - 12);
		new_dist = ft_abs_value(x - 39) + ft_abs_value(y - 12);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_left(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;
	int		y_o;

	y_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		y_o = find_last_symb(sizes) + 3;
		prev_dist = ft_abs_value(sizes->x - 0) + ft_abs_value(sizes->y - y_o);
		new_dist = ft_abs_value(x - 0) + ft_abs_value(y - y_o);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_up_m(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;

	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		prev_dist = ft_abs_value(sizes->y - 0);
		new_dist = ft_abs_value(y - 0);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		algorithm_switcher(t_struct *sizes, int x, int y, int i)
{
	if (sizes->map_y == 15)
		return (small_algorithm(sizes, x, y, i));
	if (sizes->map_y == 100)
		return (algo_for_b_down(sizes, x, y, i));
	if (sizes->me_up == 1 && sizes->map_y == 24)
		return (algo_for_m_up(sizes, x, y, i));
	if (left_is_touched(sizes) == 0)
		go_left(sizes, x, y, i);
	else if (right_is_touched(sizes) == 0)
		go_right(sizes, x, y, i);
	else if (up_is_touched(sizes) == 0)
		heading_to_up_m(sizes, x, y, i);
	else if (left_is_touched(sizes) && right_is_touched(sizes))
	{
		if (is_enemy_above(sizes) == 1)
			return (1);
		else
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
	return (0);
}
