/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:22:21 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/10 22:04:58 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"
#include <string.h>
#include <errno.h>

int		detect_up_or_down(t_struct *sizes)
{
	int		y;
	int		o_pos;
	int		x_pos;

	y = -1;
	while (sizes->map[++y])
		if (ft_strchr(sizes->map[y], 'O'))
			break ;
	o_pos = y;
	y = -1;
	while (sizes->map[++y])
		if (ft_strchr(sizes->map[y], 'X'))
			break ;
	x_pos = y;
	if (o_pos < x_pos && sizes->me == 'O')
		return (1);
	sizes->up = '\0';
	return (0);
}

int		main(void)
{
	t_struct	sizes;
	char		*first;

	// int fd = open("project/pr.txt", O_RDONLY);
	int fd = 0;
	first = NULL;
	detect_x_or_y(&sizes);
	while (get_next_line(fd, &first) > 0)
	{
		
		if (ft_strstr(first, "Plateau"))
			map_size(&sizes, first);
		if (ft_strstr(first, "0123456789"))
			write_map_and_piece(&sizes, first);
		if (sizes.up == '\0')
			detect_up_or_down(&sizes); //finished here
		if (ft_strstr(first, "Piece"))
		{
			piece_size(&sizes, first);
			write_piece(&sizes, first);
			if (put_piece(&sizes) == 0)
				break ;
		}
		// ft_printf("0 0\n");
		// usleep(50000);
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}
