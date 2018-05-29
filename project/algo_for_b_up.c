/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_b_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:46:39 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 23:07:40 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	go_right_b_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 99) + ft_abs_value(sizes->y - 20);
		new_dist = ft_abs_value(x - 99) + ft_abs_value(y - 20);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_left_b_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 0) + ft_abs_value(sizes->y - 25);
		new_dist = ft_abs_value(x - 0) + ft_abs_value(y - 25);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_center_b_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 45) + ft_abs_value(sizes->y - 23);
		new_dist = ft_abs_value(x - 45) + ft_abs_value(y - 23);
		if (prev_dist > new_dist && y == 23)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		algo_for_b_up(t_struct *sizes, int x, int y, int i)
{
	if (right_is_touched(sizes) == 0)
		go_right_b_up(sizes, x, y, i);
	else if (left_is_touched(sizes) == 0)
		go_left_b_up(sizes, x, y, i);
	else if (center_is_touched(sizes) == 0)
		go_center_b_up(sizes, x, y, i);
	else
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
