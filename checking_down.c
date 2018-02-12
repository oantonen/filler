/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:25:06 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/11 21:35:13 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

/*
** left side touched or blocked to touch
*/

int		left_is_touched(t_struct *sizes)
{
	int		y;
	int 	i;

	y = 0;
	i = sizes->map_y - 1;
	while (y != sizes->map_y)
	{
		if (ft_strchr((*sizes).map[y], sizes->me) - (*sizes).map[y] == 0)
		{
			// dprintf(2, "left_is_touched\n");
			return (1);
		}
		y++;
	}
	if (ft_strchr(sizes->map[i], sizes->him) && ft_strchr(sizes->map[i], sizes->me))
		return (1);
	return (0);
}

int		right_is_touched(t_struct *sizes)
{
	int		y;
	int		map_x;

	y = 0;
	map_x = sizes->map_x;
	while (y != sizes->map_y)
	{
		if (ft_strrchr(sizes->map[y], sizes->me) - sizes->map[y] == map_x - 1)
			return (1);
		y++;
	}
	return (0);
}

int		up_is_touched(t_struct *sizes)
{
	int		y;

	y = 0;
	if (ft_strrchr(sizes->map[y], sizes->me))
	{
		// dprintf(2, "touched1\n");
		return (1);
	}
	if (ft_strrchr(sizes->map[y], sizes->him))
		return (1);
	return (0);
}

int		down_is_touched(t_struct *sizes)
{
	int		y;

	y = sizes->map_y - 1;
	if (ft_strrchr(sizes->map[y], sizes->me))
		if (ft_strrchr(sizes->map[y], sizes->me) - sizes->map[y] < 3)
			return (1);
	return (0);
}

int		center_is_touched(t_struct *sizes)
{
	int		y;

	y = 14;
	if (ft_strrchr(sizes->map[y], sizes->me) - sizes->map[y])
		return (1);
	return (0);
}

int		is_enemy_above(t_struct *sizes)
{
	int		y;
	int		i;
	int		middle;
	int		first_half;
	int		sec_half;

	y = -1;
	i = -1;
	first_half = 0;
	sec_half = 0;
	middle = sizes->map_y / 2;
	while (++y != sizes->map_y)
	{
		i = -1;
		while (sizes->map[y][++i] && y <= sizes->map_y / 2)
			if (sizes->map[y][i] == sizes->him)
				first_half++;
		while (sizes->map[y][++i] && y > sizes->map_y / 2)
			if (sizes->map[y][i] == sizes->him)
				sec_half++;
	}
	// dprintf(2, "first_half=%d\n", first_half);
	// dprintf(2, "sec_half=%d\n", sec_half);
	return (first_half > sec_half ? 1 : 0);
}