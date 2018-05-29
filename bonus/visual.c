/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:55:07 by oantonen          #+#    #+#             */
/*   Updated: 2018/02/15 20:02:11 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"

int		main(int ac, char **av)
{
	char	*first;
	int		speed;

	if (ac != 2)
		speed = 100;
	else
		speed = ft_atoi(av[1]);
	while (get_next_line(0, &first) > 0)
	{
		usleep(speed);
		if (first[0] == '0')
			ft_putendl(&first[4]);
		else if (first[0] == ' ')
			ft_putendl("");
		if (first[0] == '=')
			ft_putendl(first);
		if (first[0] == '<' && !ft_strstr(first, "[0, 0]"))
			system("clear");
		if (first != NULL)
			free(first);
	}
}
