/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 18:52:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 20:09:49 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*alloc_large(size_t size)
{
	t_large_alloc	*zone;
	int				i;
	int				page;

	i = 0;
	page = getpagesize();
	zone = get_large(INIT);
	while ((size % page) != 0)
		size++;
	while (i < 100 && (zone->data)[i] == NULL)
		i++;
	(zone->data)[i] = mmap(NULL, size,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ((zone->data)[i]);
}
