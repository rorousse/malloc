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

	count = size * MIN_PTR_NB;
	page = getpagesize();
	while (count % page != 0)
		count = count + size;
	return (count / size);
}

static void				init_zone(t_pr_alloc *zone, size_t size)
{
	int page;

	page = getpagesize();
	zone->nb = det_nb_alloc(size);
	zone->size_data = sizeof(t_data) + sizeof(size_t) * zone->nb;
	while (zone->size_data % page != 0)
		zone->size_data++;
	zone->size_ptr = size;
	zone->data = create_data_field(zone, NULL);
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
		if (size < size_range[i])
		{
			if (mode == INIT)
			{
				init_zone(&(mllc_zones.zones[i]), size_range[i]);
			}
			return (&(mllc_zones.zones[i]));
		}
		i++;
	}
	return (NULL);
}

