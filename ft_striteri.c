/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:27:51 by nlewicki          #+#    #+#             */
/*   Updated: 2024/04/02 15:38:34 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putchar(unsigned int i, char *c)
// {
// 	ft_putchar_fd(i + '0', 1);
// 	ft_putchar_fd(*c, 1);
// 	ft_putchar_fd('\n', 1);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main()
// {
// 	char	str[] = "Hello";
// 	ft_striteri(str, &ft_putchar);
// 	return (0);
// }
