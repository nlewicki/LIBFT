/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:48:55 by nlewicki          #+#    #+#             */
/*   Updated: 2025/05/27 14:36:06 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	old_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	old_size = new_size / 2;  // Copy size for N elements when adding N+1
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
