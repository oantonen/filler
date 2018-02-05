/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:15:59 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/05 21:09:15 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	check_dist2(int x, int y, t_struct *sizes, int i)
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
		prev_dist = ft_abs_value(sizes->x - 8) + ft_abs_value(sizes->y - 0);
		new_dist = ft_abs_value(x - 8) + ft_abs_value(y - 0);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	check_dist(int x, int y, t_struct *sizes, int i)
{
	// int		x2;
	// int		y2;
	// int		prev_dist;
	// int		new_dist;
	// int yy = 0;
	
	// while ((*sizes).map[yy])
	// {
	// 	if (ft_strchr((*sizes).map[yy], 'X') - (*sizes).map[yy] == 0)
	// 	{
			check_dist2(x, y, sizes, i);
			return ;
	// 	}
	// 	yy++;
	// }
	
	// if (i == 0)
	// {
	// 	sizes->x = x;
	// 	sizes->y = y;
	// }
	// else
	// {
	// 	prev_dist = ft_abs_value(sizes->x - 0) + ft_abs_value(sizes->y - 10);
	// 	new_dist = ft_abs_value(x - 0) + ft_abs_value(y - 10);
	// 	if (prev_dist > new_dist)
	// 	{
	// 		sizes->x = x;
	// 		sizes->y = y;
	// 	}
	// }
}

int		is_possible_to_put(int x1, int y1, t_struct *sizes)
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
			if ((*sizes).map[y + y1][x + x1] == 'X' && (*sizes).piece[y][x] == '*')
				mark++;
			if ((*sizes).map[y + y1][x + x1] != 'O' || (*sizes).map[y + y1][x + x1] == 'X')
				x++;
			else
				return (0);
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
	while (y != (*sizes).map_y)
	{
		if (is_possible_to_put(x, y, sizes) == 1)
		{	
			i++;
			// ft_printf("%d %d\n", y, x);
			// return (1);
			check_dist(x, y, sizes, i);
		}
		x++;
		(x == (*sizes).map_x) ? (y = y + 1) : y;
		(x == (*sizes).map_x) ? (x = 0) : x;
	}
	// dprintf(2, "%d %d\n", (*sizes).y, (*sizes).x);
	ft_printf("%d %d\n", (*sizes).y, (*sizes).x);
	if ((*sizes).y == 0 && !(*sizes).x && is_possible_to_put(0, 0, sizes) == 0)
		ft_printf("%d %d\n", 0, 0);
	if ((*sizes).y == 0 && !(*sizes).x && is_possible_to_put(0, 0, sizes) == 0)
		return (0);
	return (1);
}