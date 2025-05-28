/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:59:36 by nlewicki          #+#    #+#             */
/*   Updated: 2025/05/28 12:03:01 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_strtod(const char *str, char **endptr)
{
	double	value;
	char	*end;

	if (!str || !*str)
	{
		if (endptr)
			*endptr = (char *)str;
		return (0.0);
	}
	errno = 0;
	value = strtod(str, &end);
	if (errno == ERANGE)
	{
		if (endptr)
			*endptr = (char *)str;
		return (0.0);
	}
	if (endptr)
		*endptr = end;
	return (value);
}
