/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:25:06 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/14 18:41:26 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

/*
** left side touched or blocked to touch
*/

int		left_is_touched(t_struct *sizes)
{
	int		y;
	int		i;

	y = 0;
	i = sizes->map_y - 1;
	while (y != sizes->map_y)
	{
		if (ft_strchr((*sizes).map[y], sizes->me) - (*sizes).map[y] == 0)
			return (1);
		y++;
	}
	if (ft_strchr(sizes->map[i], sizes->him))
		if (ft_strchr(sizes->map[i], sizes->me))
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
		return (1);
	if (ft_strrchr(sizes->map[y], sizes->him) ||\
	ft_strrchr(sizes->map[y + 1], sizes->him))
		return (1);
	return (0);
}

int		center_is_touched(t_struct *sizes)
{
	int				y;
	int				i;
	int				count;
	static int		lines;

	y = 21;
	if (lines <= 5)
		while (++y <= 29)
		{
			i = -1;
			count = 0;
			while (sizes->map[y][++i])
				if (sizes->map[y][i] != '.')
					count++;
			if (count >= 92)
				lines++;
		}
	if (lines >= 5)
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
		while (sizes->map[y][++i] && y <= middle)
			if (sizes->map[y][i] == sizes->him)
				first_half++;
		while (sizes->map[y][++i] && y > middle)
			if (sizes->map[y][i] == sizes->him)
				sec_half++;
	}
	return (first_half > sec_half ? 1 : 0);
}
