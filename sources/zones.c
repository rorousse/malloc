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

#include "malloc_utils.h"

static unsigned int		det_nb_alloc(size_t size)
{
	int				page;
	unsigned int	count;

	if (size == LARGE_SIZE)
	{
		dprintf(2, "det nb alloc : LARGE detected\n");
		size = sizeof(void*);
	}
	count = size * MIN_PTR_NB;
	page = getpagesize();
	while (count % page != 0)
		count = count + size;
	return (count / size);
}

static void				init_zone(t_pr_alloc *zone, size_t size)
{
	int page;

	dprintf(2, "Starting init zone with a size of %zu\n", size);
	page = getpagesize();
	zone->nb = det_nb_alloc(size);
	dprintf(2, "det_nb_alloc ok\n");
	zone->size_data = sizeof(t_data) + sizeof(size_t) * zone->nb;
	while (zone->size_data % page != 0)
		zone->size_data++;
	zone->size_ptr = size;
	dprintf(2, "zone->size_ptr vaut %zu\n", zone->size_ptr);
	dprintf(2, "launching create data field\n");
	zone->data = create_data_field(zone, NULL);
	dprintf(2, "create data field ok\n");
	dprintf(2, "fin init zone\n");
}

t_pr_alloc				*get_zone(int mode, size_t size)
{
	static t_mllc_zones mllc_zones;
	int					i;

	i = 0;
	if (mode == INDEX)
		return (&(mllc_zones.zones[size]));
	while (i < SIZE_RANGE)
	{
		dprintf(2, "test %d\n", i);
		if (size < size_range[i])
		{
			dprintf(2, "trigger\n");
			if (mode == INIT && mllc_zones.zones[i].data == NULL)
			{
				init_zone(&(mllc_zones.zones[i]), size_range[i]);
			}
			return (&(mllc_zones.zones[i]));
		}
		i++;
	}
	dprintf(2, "Echec get zone\n");
	return (NULL);
}
