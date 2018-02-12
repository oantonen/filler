/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:48:57 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/12 22:13:39 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	map_put(t_struct *sizes, t_hole *hole, int y, int x)
{
	int		i;
	int		k;

	i = -1;
	hole->map_put = (char**)malloc(sizeof(char*) * (sizes->map_y + 1));
	hole->map_put[sizes->map_y] = NULL;
	while (i++ != sizes->map_y - 1)
		hole->map_put[i] = ft_strdup(sizes->map[i]);
	i = -1;
	while (sizes->piece[++i])
	{
		k = -1;
		while (sizes->piece[i][++k])
			if (sizes->piece[i][k] == '*')
				hole->map_put[y + i][x + k] = sizes->me; //sizes->me
	}
	i = -1;
	// dprintf(2, "y=%d x=%d\n", y, x);
	// while (hole->map_put[++i])
	// 	dprintf(2, "{%s}\n", hole->map_put[i]);
}

void	map_cpy(t_struct *sizes, t_hole *hole, int y, int x)
{
	int		i;
	int		k;

	i = -1;
	hole->map2 = (char**)malloc(sizeof(char*) * (sizes->map_y + 1));
	hole->map2[sizes->map_y] = NULL;
	while (i++ != sizes->map_y - 1)
		hole->map2[i] = ft_strdup(sizes->map[i]);
}

int		check_equality2(t_hole *hole, int i)
{
	int		p1;
	int		p2;
	int		count2;

	p1 = 0;
	count2 = 0;
	while (p1 != 20)
	{
		p2 = 0;
		while (p2 != 20)
		{
			if (hole->pos[p1] == 0 && (p1 != 0 || p2 != 0))
				break ;
			if (hole->pos[p1] == hole->pos2[p2])
				count2 += 1;
			p2++;
		}

		p1++;
	}
	return (count2);
}

int		find_hole2(char **map, t_hole *hole, int y)
{
	int		x;
	int		i;

	ft_memset(hole->pos, 0, 80);
	ft_memset(hole->pos2, 0, 80);
	i = -1;
	x = 0;
	while (ft_strstr(&map[y][x], hole->s2))
	{
		hole->pos[++i] = ft_strstr(&map[y][x], hole->s2) - map[y];
		x = hole->pos[i] + 1;
	}
	x = 0;
	i = -1;
	while (ft_strstr(&map[y + 1][x], hole->s1))
	{
		hole->pos2[++i] = ft_strstr(&map[y + 1][x], hole->s1) - map[y + 1];
		x = hole->pos2[i] + 1;
	}
	return (check_equality2(hole, i));
}

int		check_equality1(t_hole *hole, int i)
{
	int		p1;
	int		p2;
	int		count1;

	p1 = 0;
	count1 = 0;
	while (p1 != 20)
	{
		p2 = 0;
		while (p2 != 20)
		{
			if (hole->pos[p1] == 0 && (p1 != 0 || p2 != 0))
				break ;
			if (hole->pos[p1] == hole->pos2[p2])
				count1 += 1;
			p2++;
		}
		p1++;
	}
	return (count1);
}

int		find_hole1(char **map, t_hole *hole, int y)
{
	int		x;
	int		i;

	ft_memset(hole->pos, 0, 80);
	ft_memset(hole->pos2, 0, 80);
	i = -1;
	x = 0;
	while (ft_strstr(&map[y][x], hole->s1))
	{
		hole->pos[++i] = ft_strstr(&map[y][x], hole->s1) - map[y];
		x = hole->pos[i] + 1;
	}
	x = 0;
	i = -1;
	while (ft_strstr(&map[y + 1][x], hole->s2))
	{
		hole->pos2[++i] = ft_strstr(&map[y + 1][x], hole->s2) - map[y + 1];
		x = hole->pos2[i] + 1;
	}
	return (check_equality1(hole, i));
}

int		is_hole_closed(char **map_put, t_hole *hole)
{
	int		new_count1;
	int		new_count2;
	int		sum;
	int		sum2;
	int		y;

	y = -1;
	new_count1 = 0;
	new_count2 = 0;
	while (map_put[++y] && map_put[y + 1])
	{
		if (ft_strstr(map_put[y], hole->s1) && ft_strstr(map_put[y + 1], hole->s2))
			new_count1 += find_hole1(map_put, hole, y);
		if (ft_strstr(map_put[y], hole->s2) && ft_strstr(map_put[y + 1], hole->s1))
			new_count2 += find_hole2(map_put, hole, y);
	}
	sum = new_count1 + new_count2;
	sum2 = hole->count1 + hole->count2;
	while (y-- != -1)
		ft_strdel(&(map_put[y + 1]));
	free(map_put);
	if (new_count1 < hole->count1 || new_count2 < hole->count2) //more accurate check?
		return (1);
	return (0);	
}

void	write_holes(char **map, t_hole *hole)
{
	int y;

	y = -1;
	while (map[++y] && map[y + 1])
	{
		if (ft_strstr(map[y], hole->s1) && ft_strstr(map[y + 1], hole->s2))
			hole->count1 += find_hole1(map, hole, y);
		if (ft_strstr(map[y], hole->s2) && ft_strstr(map[y + 1], hole->s1))
			hole->count2 += find_hole2(map, hole, y);
	}
}

int		scan_map_for_holes(t_struct *sizes, int y, int x)
{
	int				yy;
	static t_hole	hole;

	yy = -1;
	hole.s1 = (sizes->me == 'O') ? "O." : "X.";
	hole.s2 = (sizes->me == 'O') ? ".O" : ".X";
	if (hole.map2 == NULL)
	{
		hole.count1 = 0;
		hole.count1 = 0;
		write_holes(sizes->map, &hole);
		map_cpy(sizes, &hole, y, x);
	}
	map_put(sizes, &hole, y, x);
	// dprintf(2,"count1=%d\n", hole.count1);
	// dprintf(2,"count2=%d\n", hole.count2);
	if (is_hole_closed(hole.map_put, &hole))
	{
		while (++yy != sizes->map_y)
			ft_strdel(&(hole.map2[yy]));
		// system("leaks ./oantonen.filler");
		free(hole.map2);
		hole.map2 = NULL;
		sizes->hole_count += 1;
			dprintf(2, "freeeed!\n");
			// 
		// int i = -1;
		// while (hole.map_put[++i])
		// 	dprintf(2, "{%s}\n", hole.map_put[i]);
		return (1);
	}
	sizes->x = x;
	sizes->y = y;
	return (0);
}



