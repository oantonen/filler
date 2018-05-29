/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_b_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:31:22 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 23:07:33 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	go_right_b_down(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 99) + ft_abs_value(sizes->y - 65);
		new_dist = ft_abs_value(x - 99) + ft_abs_value(y - 65);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_left_b_down(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 0) + ft_abs_value(sizes->y - 60);
		new_dist = ft_abs_value(x - 0) + ft_abs_value(y - 60);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_center_b_down(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 60) + ft_abs_value(sizes->y - 65);
		new_dist = ft_abs_value(x - 60) + ft_abs_value(y - 65);
		if (prev_dist > new_dist && y == 65)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		algo_for_b_down(t_struct *sizes, int x, int y, int i)
{
	if (sizes->me_up == 1)
		return (algo_for_b_up(sizes, x, y, i));
	if (left_is_touched(sizes) == 0)
		go_left_b_down(sizes, x, y, i);
	else if (right_is_touched(sizes) == 0)
		go_right_b_down(sizes, x, y, i);
	else if (center_is_touched(sizes) == 0)
		go_center_b_down(sizes, x, y, i);
	else if (center_is_touched(sizes))
	{
		if (sizes->me_up == 0)
			return (1);
		else
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
	return (0);
}
