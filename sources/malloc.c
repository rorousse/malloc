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

#include "malloc_utils.h"

void	*ft_malloc(size_t size)
{
	t_pr_alloc	*zone;
	char		*addr;

	zone = NULL;
	addr = NULL;
	if (size <= 0)
		return (NULL);
	zone = get_zone(INIT, size);
	addr = find_place(zone, size);
	return ((void*)addr);
}
