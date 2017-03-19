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

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

static unsigned int		det_size_zone(unsigned int mode)
{
	int	page;
	unsigned int	count;

	count = mode * 100;
	page = getpagesize();
	while (count % page != 0)
		   count = count + mode;
	return (count/mode);
}

t_pr_alloc	*get_tiny()
{
	static int			init = 0;
	static t_pr_alloc	zone;
	unsigned int		i;

	if (init == 0)
	{
		zone.nb = det_size_zone(TINY);
		zone.ptr = mmap(NULL, zone.nb * TINY, 
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		zone.type = TINY;
		zone.data = mmap(NULL, zone.nb * sizeof(unsigned int),
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		init = 1;
		i = 0;
		while (i < (zone.nb * sizeof(unsigned int)))
		{
			zone.ptr[i] = 0;
			i++;
		}
	}
	return (&zone);
}

t_pr_alloc  *get_small()
{
    static int  		init = 0;
    static t_pr_alloc	zone;
	unsigned int		i;

    if (init == 0)
    {
		zone.nb = det_size_zone(SMALL);
		zone.ptr = mmap(NULL, zone.nb * SMALL, 
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		zone.data = mmap(NULL, zone.nb *sizeof(unsigned int),
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,0);
		init = 1;
		i = 0;
		zone.type = SMALL;
		while (i < (zone.nb * sizeof(unsigned int)))
		{
			zone.ptr[i] = 0;
			i++;
		}
    }
    return (&zone);
}

t_large_alloc	*get_large()
{
	static int 	init = 0;
	static t_large_alloc zone;
	int		i;

	if (init == 0)
	{
		init = 1;
		i = 0;
		zone.data = mmap(NULL, 100 * sizeof(void*), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		while (i < 100)
		{
			(zone.data)[i] = NULL;
			i++;
		}
	}
	return (&zone);
}

void		*alloc_large(size_t size)
{
	t_large_alloc *zone;
	int				i;
	int page;

	i = 0;
	page = getpagesize();
	zone = get_large();
	while ((size % page) != 0)
		size++;
	while (i < 100 && (zone->data)[i] == NULL)
		i++;
	(zone->data)[i] = mmap(NULL, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ((zone->data)[i]);
}