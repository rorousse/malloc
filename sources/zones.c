/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:43:16 by rorousse          #+#    #+#             */
/*   Updated: 2018/03/19 16:43:21 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static unsigned int		det_size_zone(unsigned int mode)
{
	int				page;
	unsigned int	count;

	count = mode * MIN_PTR_NB;
	page = getpagesize();
	while (count % page != 0)
		count = count + mode;
	return (count / mode);
}

static void				init_zone(t_pr_alloc *zone, unsigned int mode)
{
	unsigned int i;

	zone->count = 0;
	zone->field_size = det_size_zone(mode);
	zone->nb = zone->field_size;
	zone->ptr = mmap(NULL, zone->nb * mode,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	zone->data = mmap(NULL, zone->nb * sizeof(unsigned int) + sizeof(void*),
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	zone->type = mode;
	while (i < (zone->nb * sizeof(unsigned int)))
	{
		zone->ptr[i] = 0;
		i++;
	}
}

t_pr_alloc				*get_tiny(void)
{
	static int			init = 0;
	static t_pr_alloc	zone;

	if (init == 0)
	{
		init_zone(&zone, TINY);
		init = 1;
	}
	return (&zone);
}

t_pr_alloc				*get_small(void)
{
	static int			init = 0;
	static t_pr_alloc	zone;

	if (init == 0)
	{
		init_zone(&zone, SMALL);
		init = 1;
	}
	return (&zone);
}

t_large_alloc			*get_large(void)
{
	static int				init = 0;
	static t_large_alloc	zone;
	int						i;

	if (init == 0)
	{
		init = 1;
		i = 0;
		zone.data = mmap(NULL, 100 * sizeof(void*),
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		while (i < 100)
		{
			(zone.data)[i] = NULL;
			i++;
		}
	}
	return (&zone);
}
