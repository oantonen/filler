/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:17:30 by oantonen          #+#    #+#             */
/*   Updated: 2017/11/23 22:25:45 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*s)
		s++;
	while (s != ptr && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char*)s);
	if (*s == *ptr && *s != (char)c)
		return (0);
	return (0);
}
