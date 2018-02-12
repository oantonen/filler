/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_for_sizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:00:24 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/12 21:53:03 by oantonen         ###   ########.fr       */
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
	// printf("(*sizes).first=%d\n", (*sizes).first);
}

void	write_piece(t_struct *sizes, char *first)
{
	int		i;

	i = 0;
	(*sizes).piece = (char**)malloc(sizeof(char*) * ((*sizes).piece_y + 1));
	(*sizes).piece[(*sizes).piece_y] = NULL;
	while (i < (*sizes).piece_y)
	{
		get_next_line(0, &first);
		(*sizes).piece[i] = ft_strdup(first);
		i++;
		ft_strdel(&first);
	}
	// put_piece(sizes);
	i = -1;
	// while (++i < (*sizes).piece_y)
	// 	dprintf(2, "{piece=%s}\n", (*sizes).piece[i]);
}

void	piece_size(t_struct *sizes, char *first)
{
	(*sizes).piece_y = ft_atoi(&first[6]);
	(*sizes).piece_x = ft_atoi(&first[7]);
	// dprintf(2, "{piece_y=%d}\n", (*sizes).piece_y);
	// dprintf(2, "{piece_x=%d}\n", (*sizes).piece_x);
	// write_piece(sizes);
}

void	write_map(t_struct *sizes, char *first)
{
	// char	*first;
	int		i;

	i = -1;
	(*sizes).map = (char**)malloc(sizeof(char*) * ((*sizes).map_y + 1));
	(*sizes).map[(*sizes).map_y] = NULL;
	while (i++ != (*sizes).map_y - 1)
	{
		get_next_line(0, &first);
		(*sizes).map[i] = ft_strdup(first + 4);
		// dprintf(2, "{map=%s}\n", first);
		ft_strdel(&first);
	}
	i = -1;
	// while (i++ < (*sizes).map_y - 1)
	// 	dprintf(2, "{map=%s}\n", (*sizes).map[i]);
	// piece_size(sizes);
	// write_piece(sizes);
}

void	map_size(t_struct *sizes, char *first)
{
	int		i;

	i = -1;
	get_next_line(0, &first);
	(*sizes).map_y = ft_atoi(&first[8]);
	(*sizes).map_x = ft_atoi(&first[11]);
}
