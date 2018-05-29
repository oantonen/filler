/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:22:21 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/15 18:21:37 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	clean_struct(t_struct *sizes)
{
	int y;

	y = -1;
	while (sizes->map[++y] != NULL)
		ft_strdel(&(sizes->map[y]));
	free(sizes->map);
	y = -1;
	while (sizes->piece[++y] != NULL)
		ft_strdel(&(sizes->piece[y]));
	free(sizes->piece);
}

int		is_possible_to_put(int y1, int x1, t_struct *sizes)
{
	int mark;
	int x;
	int y;

	mark = 0;
	y = 0;
	while ((*sizes).piece[y] != NULL)
	{
		x = 0;
		while ((*sizes).piece[y][x])
		{
			if (y + y1 >= (*sizes).map_y || x + x1 >= (*sizes).map_x)
				return (0);
			if (sizes->map[y + y1][x + x1] == sizes->me && \
				sizes->piece[y][x] == '*')
				mark++;
			if (sizes->map[y + y1][x + x1] == sizes->him && \
				sizes->piece[y][x] == '*')
				return (0);
			else
				x++;
		}
		y++;
	}
	return ((mark == 1) ? 1 : 0);
}

int		put_piece(t_struct *sizes, int y, int x)
{
	int		i;

	i = -1;
	while (y != sizes->map_y)
	{
		if (is_possible_to_put(y, x, sizes) == 1)
		{
			i++;
			if (algorithm_switcher(sizes, x, y, i))
			{
				sizes->x = x;
				sizes->y = y;
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

int		main(void)
{
	t_struct	sizes;
	char		*first;

	first = NULL;
	detect_who_is_who(&sizes);
	map_size(&sizes, first);
	detect_up_or_down(&sizes);
	while (get_next_line(0, &first) > 0)
	{
		if (ft_strstr(first, "0123456789"))
			write_map(&sizes, first);
		if (ft_strstr(first, "Piece"))
		{
			write_piece(&sizes, first);
			if (put_piece(&sizes, 0, 0) == 0)
				break ;
			clean_struct(&sizes);
		}
		ft_strdel(&first);
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}
