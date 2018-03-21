/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 18:31:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 22:43:10 by rorousse         ###   ########.fr       */
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
		print_log("allocation de zone TINY\n");
		zone = get_tiny(INIT);
		addr = find_place(zone, size);
	}
	if (addr == NULL && size <= SMALL)
	{
		print_log("allocation de zone SMALL\n");
		zone = get_small(INIT);
		addr = find_place(zone, size);
	}
	if (addr == NULL)
	{
		print_log("allocation de zone LARGE\n");
		addr = alloc_large(size);
	}
	return ((void*)addr);
}
