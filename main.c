/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:22:21 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/12 22:03:05 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"
#include <string.h>
#include <errno.h>

int		detect_up_or_down(t_struct *sizes)
{
	sizes->hole_count = 0;
	if (sizes->map_y == 100 && sizes->me == 'X')
		return (1);
	else if ((sizes->map_y == 15 || sizes->map_y == 24) && sizes->me == 'O')
		return (1);
	return (0);
}

int		main(void)
{
	t_struct	sizes;
	char		*first;

	// int fd = open("project/pr.txt", O_RDONLY);
	int fd = 0;
	first = NULL;
	detect_who_is_who(&sizes);
	map_size(&sizes, first);
	detect_up_or_down(&sizes);
	while (get_next_line(fd, &first) > 0)
	{
		// if (ft_strstr(first, "Plateau"))
		// 	map_size(&sizes, first);
		if (ft_strstr(first, "0123456789"))
			write_map(&sizes, first);
		if (ft_strstr(first, "Piece"))
		{
			piece_size(&sizes, first);
			write_piece(&sizes, first);
			if (put_piece(&sizes) == 0) //0
				break ;
		}
	// system("leaks ./oantonen.filler");
		// usleep(50000);
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}
