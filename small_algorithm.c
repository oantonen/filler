/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:41:14 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/12 21:50:17 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

int		*find_first_symb(t_struct *sizes)
{
	int i;
	int *coord;

	i = -1;
	coord = (int*)malloc(sizeof(int) * 2);
	// coord[1] = 0;
	while (++i != sizes->map_y)
	{
		if (ft_strchr(sizes->map[i], sizes->him))
		{
			coord[0] = i;
			coord[1] = ft_strchr(sizes->map[i], sizes->him) - sizes->map[i];
			// dprintf(2, "%d %d\n", coord[0], coord[1]);
			break ;
		}
	}
	return (coord);
}

void	heading_to_left(t_struct *sizes, int x, int y, int i)
{
	int		x_o;
	int		y_o;
	int		prev_dist;
	int		new_dist;
	
	x_o = 0;
	y_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		x_o = 0;
		y_o = find_first_symb(sizes)[0];
		prev_dist = ft_abs_value(sizes->x - x_o) + ft_abs_value(sizes->y - y_o + 3);
		new_dist = ft_abs_value(x - x_o) + ft_abs_value(y - y_o + 3);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_right(t_struct *sizes, int x, int y, int i)
{
	int		x2;
	int		y2;
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
int		actual_position(t_struct *sizes)
{
	int		sdvig;
	int		y;

	sdvig = 0;
	y = 0;
	while (sizes->piece[y])
	{
		if (ft_strchr(sizes->piece[y], '*'))
			sdvig = ft_strchr(sizes->piece[y], '*') - sizes->piece[y];
		y++;
	}
	return (sdvig);
}

void	heading_to_up(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;
	int		x_o;
	int		y_o;
	int		p;

	x_o = 0;
	y_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		// y_o = find_last_symb(sizes)[0];
		// x_o = 0;
		p = actual_position(sizes);
		prev_dist = ft_abs_value(sizes->x - 14 + p) + ft_abs_value(sizes->y - 0);
		new_dist = ft_abs_value(x - 14 + p) + ft_abs_value(y - 0);
		// dprintf(2, "y=%d x=%d\n", y, x);
		// dprintf(2, "prev_dist=%d\n", prev_dist);
		// dprintf(2, "new_dist=%d\n", new_dist);
		if (prev_dist > new_dist && sizes->y >= y)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		small_algorithm(t_struct *sizes, int x, int y, int i)
{
	if (up_is_touched(sizes) == 0)
	{
		// dprintf(2, "0\n");
		heading_to_up(sizes, x, y, i);
	}
	else if (right_is_touched(sizes) == 0)
	{
		// dprintf(2, "1\n");
		heading_to_right(sizes, x, y, i);
	}
	else if (left_is_touched(sizes) == 0)
	{
		// dprintf(2, "2\n");
		heading_to_left(sizes, x, y, i);
	}
	else if (up_is_touched(sizes) && right_is_touched(sizes))
	{
		// dprintf(2, "3\n");
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