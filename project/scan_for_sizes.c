/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_for_sizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:00:24 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/15 18:20:40 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"

void	detect_who_is_who(t_struct *sizes)
{
	char	*first;

	while (get_next_line(0, &first) > 0 && !(ft_strstr(first, "$$$ exec")))
		;
	if (ft_strstr(first, "$$$ exec p1"))
	{
		sizes->me = 'O';
		sizes->him = 'X';
	}
	else
	{
		sizes->me = 'X';
		sizes->him = 'O';
	}
	ft_strdel(&first);
}

void	write_piece(t_struct *sizes, char *first)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	(*sizes).piece_y = ft_atoi(&first[6]);
	(*sizes).piece_x = ft_atoi(&first[7]);
	(*sizes).piece = (char**)malloc(sizeof(char*) * ((*sizes).piece_y + 1));
	(*sizes).piece[(*sizes).piece_y] = NULL;
	while (i < (*sizes).piece_y)
	{
		get_next_line(0, &first);
		(*sizes).piece[i] = ft_strdup(first);
		i++;
		ft_strdel(&first);
	}
}

void	detect_up_or_down(t_struct *sizes)
{
	if (sizes->map_y == 100 && sizes->me == 'X')
	{
		sizes->me_up = 1;
	}
	else if ((sizes->map_y == 15 || sizes->map_y == 24) && sizes->me == 'O')
		sizes->me_up = 1;
	else
		sizes->me_up = 0;
}

void	write_map(t_struct *sizes, char *first)
{
	int		i;
	int		y;

	y = 0;
	i = -1;
	(*sizes).map = (char**)malloc(sizeof(char*) * ((*sizes).map_y + 1));
	(*sizes).map[(*sizes).map_y] = NULL;
	while (i++ != (*sizes).map_y - 1)
	{
		get_next_line(0, &first);
		(*sizes).map[i] = ft_strdup(first + 4);
		ft_strdel(&first);
	}
}

void	map_size(t_struct *sizes, char *first)
{
	get_next_line(0, &first);
	(*sizes).map_y = ft_atoi(&first[8]);
	(*sizes).map_x = ft_atoi(&first[11]);
	ft_strdel(&first);
}
