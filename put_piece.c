/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:15:59 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/10 21:37:15 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

int		*find_last_symb(t_struct *sizes)
{
	int		i;
	int		*coord;
	char	him;

	him = sizes->him;
	i = sizes->map_y;
	coord = (int*)malloc(sizeof(int) * 2);
	while (--i != -1)
	{
		if (ft_strchr(sizes->map[i], him))
		{
			coord[0] = i;
			coord[1] = ft_strchr(sizes->map[i], him) - sizes->map[i];
			// dprintf(2, "%d %d\n", coord[0], coord[1]);
			break ;
		}
	}
	return (coord);
}

void	check_dist2(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 39) + ft_abs_value(sizes->y - 6);
		new_dist = ft_abs_value(x - 39) + ft_abs_value(y - 6);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	maximize_field(t_struct *sizes, int x, int y)
{
	sizes->x = x;
	sizes->y = y;
}

void	check_dist(t_struct *sizes, int x, int y, int i)
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
		y_o = find_last_symb(sizes)[0];
		x_o = 0;
		prev_dist = ft_abs_value(sizes->x - x_o) + ft_abs_value(sizes->y - y_o - 2);
		new_dist = ft_abs_value(x - x_o) + ft_abs_value(y - y_o - 2);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		algorithm_switcher(t_struct *sizes, int x, int y, int i)
{
	if (sizes->map_x * sizes->map_y == SMALL_MAP)
		return (small_algorithm(sizes, x, y, i));
	if (center_is_touched(sizes) == 0)
		return (1);
	else if (left_is_touched(sizes) == 0)
		check_dist(sizes, x, y, i);
	else if (right_is_touched(sizes) == 0)
		check_dist2(sizes, x, y, i);
	else if (left_is_touched(sizes) && right_is_touched(sizes))
		return (1);
	return (0);
}

int		is_possible_to_put(int y1, int x1, t_struct *sizes)
{
	int mark;
	int x;
	int y;

	mark = 0;
	y = 0;
	x = 0;
	while ((*sizes).piece[y] != NULL)
	{
		x = 0;
		while ((*sizes).piece[y][x])
		{
			if (y + y1 >= (*sizes).map_y || x + x1 >= (*sizes).map_x)
				return (0);
			if (sizes->map[y + y1][x + x1] == sizes->me && sizes->piece[y][x] == '*')
				mark++;
			if (sizes->map[y + y1][x + x1] == sizes->him && sizes->piece[y][x] == '*')
				return (0);
			else
				x++;
		}
		y++;
	}
	if (mark != 1)
		return (0);
	return (1);
}

int		put_piece(t_struct *sizes)
{
	int		y;
	int		x;
	int		i;

	i = -1;
	x = 0;
	y = 0;
	while (y != sizes->map_y)
	{
		if (is_possible_to_put(y, x, sizes) == 1)
		{
			i++;
			if (algorithm_switcher(sizes, x, y, i))
			{
				// dprintf(2, "Entered\n");
				// dprintf(2, "first=%d %d\n", y, x);
				maximize_field(sizes, x, y);
				break ;
			}
		}
		x++;
		(x == sizes->map_x) ? (y = y + 1) : y;
		(x == sizes->map_x) ? (x = 0) : x;
	}
	if (is_possible_to_put(sizes->y, sizes->x, sizes))
		ft_printf("%d %d\n", sizes->y, sizes->x);
	else
		return (0);
	return (1);
}