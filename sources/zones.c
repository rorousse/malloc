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

static unsigned int		det_nb_alloc(unsigned int mode)
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
	int page;

	page = getpagesize();
	zone->nb = det_nb_alloc(mode);
	zone->size_data = sizeof(t_data) + sizeof(unsigned int) * zone->nb;
	while (zone->size_data % page != 0)
		zone->size_data++;
	zone->type = mode;
	zone->data = create_data_field(zone);
}

t_pr_alloc				*get_tiny(int mode)
{
	static int			init = 0;
	static t_pr_alloc	zone;

	if (init == 0)
	{
		if (mode == GET)
			return (NULL);
		init_zone(&zone, TINY);
		init = 1;
	}
	return (&zone);
}

t_pr_alloc				*get_small(int mode)
{
	static int			init = 0;
	static t_pr_alloc	zone;

	if (init == 0)
	{
		if (mode == GET)
			return (NULL);
		init_zone(&zone, SMALL);
		init = 1;
	}
	return (&zone);
}

t_large_alloc			*get_large(int mode)
{
	static int				init = 0;
	static t_large_alloc	zone;
	int						i;

	if (init == 0)
	{
		if (mode == GET)
			return (NULL);
		init = 1;
		i = 0;
		zone.data = mmap(NULL, 100 * sizeof(void*),
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		while (i < 100)
		{
			(zone.data)[i] = 0;
			i++;
		}
	}
	return (&zone);
}
