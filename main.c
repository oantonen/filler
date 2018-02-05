/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:22:21 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/05 21:00:16 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfiller.h"


int		main(void)
{
	t_struct	sizes;
	char	*first;

	// fd = open("project/fight1.txt", O_RDONLY);
	first = NULL;
	detect_me_and_enemy(&sizes);
	while (get_next_line(0, &first) > 0)
	{
		if (ft_strstr(first, "Plateau"))
			map_size(&sizes, first);
		if (ft_strstr(first, "0123456789"))
			write_map_and_piece(&sizes, first);
		if ((ft_strstr(first, "Piece")))
		{
			piece_size(&sizes, first);
			write_piece(&sizes, first);
			if (put_piece(&sizes) == 0)
				break ;
		}
		// ft_printf("0 0\n");
		// usleep(50000);
	}
	return (0);
}
