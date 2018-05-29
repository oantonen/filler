/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:49:21 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 23:07:13 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	heading_to_left_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 0) + ft_abs_value(sizes->y + 8);
		new_dist = ft_abs_value(x - 0) + ft_abs_value(y + 8);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_right_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 16) + ft_abs_value(sizes->y + 5);
		new_dist = ft_abs_value(x - 16) + ft_abs_value(y + 5);
		if (prev_dist > new_dist)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

void	heading_to_up_up(t_struct *sizes, int x, int y, int i)
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
		prev_dist = ft_abs_value(sizes->x - 14) + ft_abs_value(sizes->y - 0);
		new_dist = ft_abs_value(x - 14) + ft_abs_value(y - 0);
		if (prev_dist > new_dist && sizes->y >= y)
		{
			sizes->x = x;
			sizes->y = y;
		}
	}
}

int		small_algorithm_up(t_struct *sizes, int x, int y, int i)
{
	if (right_is_touched(sizes) == 0)
		heading_to_right_up(sizes, x, y, i);
	else if (left_is_touched(sizes) == 0)
		heading_to_left_up(sizes, x, y, i);
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
