/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_m_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:01:37 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 23:07:25 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	go_right_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 39) + ft_abs_value(sizes->y - 9);
		new_dist = ft_abs_value(x - 39) + ft_abs_value(y - 9);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	go_left_up(t_struct *sizes, int x, int y, int i)
{
	int		prev_dist;
	int		new_dist;
	int		x_o;

	x_o = 0;
	if (i == 0)
	{
		sizes->x = x;
		sizes->y = y;
	}
	else
	{
		prev_dist = ft_abs_value(sizes->x - x_o) + ft_abs_value(sizes->y - 2);
		new_dist = ft_abs_value(x - x_o) + ft_abs_value(y - 2);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_up_m_up(t_struct *sizes, int x, int y, int i)
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

int		algo_for_m_up(t_struct *sizes, int x, int y, int i)
{
	if (right_is_touched(sizes) == 0)
		go_right_up(sizes, x, y, i);
	else if (left_is_touched(sizes) == 0)
		go_left_up(sizes, x, y, i);
	else if (left_is_touched(sizes) && right_is_touched(sizes))
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
