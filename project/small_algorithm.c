/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:41:14 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 18:43:27 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

int		find_first_symb(t_struct *sizes)
{
	int i;
	int coord;

	i = -1;
	coord = 0;
	while (++i != sizes->map_y)
	{
		if (ft_strchr(sizes->map[i], sizes->him))
		{
			coord = i;
			break ;
		}
	}
	return (coord);
}

void	heading_to_left(t_struct *sizes, int x, int y, int i)
{
	int		y_o;
	int		prev_dist;
	int		new_dist;

	y_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		y_o = find_first_symb(sizes);
		prev_dist = sizes->x + ft_abs_value(sizes->y - y_o + 3);
		new_dist = x + ft_abs_value(y - y_o + 3);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_right(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 16) + ft_abs_value(sizes->y - 11);
		new_dist = ft_abs_value(x - 16) + ft_abs_value(y - 11);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_up(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;
	int		x_o;
	int		y_o;

	x_o = 0;
	y_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		prev_dist = ft_abs_value(sizes->x - 14) + ft_abs_value(sizes->y - 0);
		new_dist = ft_abs_value(x - 14) + ft_abs_value(y - 0);
		if (prev_dist > new_dist && sizes->y >= y)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		small_algorithm(t_struct *sizes, int x, int y, int i)
{
	if (sizes->me_up == 1)
		return (small_algorithm_up(sizes, x, y, i));
	if (up_is_touched(sizes) == 0)
		heading_to_up(sizes, x, y, i);
	else if (right_is_touched(sizes) == 0)
		heading_to_right(sizes, x, y, i);
	else if (left_is_touched(sizes) == 0)
		heading_to_left(sizes, x, y, i);
	else if (up_is_touched(sizes) && right_is_touched(sizes))
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
