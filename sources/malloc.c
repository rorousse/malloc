/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 18:31:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/03 17:56:21 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"
#include "../libft/libft.h"
#include <stdio.h>

void	*ft_malloc(size_t size)
{
	t_pr_alloc	*zone;
	char		*addr;

	zone = NULL;
	addr = NULL;
	if (size <= 0)
		return (NULL);
	if (size <= TINY)
	{
		zone = get_tiny();
		addr = find_place(zone);
	}
	if (addr == NULL && size <= SMALL)
	{
		zone = get_small();
		addr = find_place(zone);
	}
	printf("la zone est %p\n", zone->ptr);
	return (0);
}
