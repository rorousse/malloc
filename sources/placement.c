/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 16:57:23 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 21:05:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** if the functions return zone->nb, it means that no place was found in the field, so we must go to next field / create a new field
** else, the function returns the place where the ptr should be
*/

static unsigned int	get_place(long unsigned int *data, unsigned int nb_max, unsigned int alloc_size)
{
	unsigned int	i;
	unsigned int	*nb;

	i = 0;
	data += 3 * sizeof(long unsigned int);
	nb = (unsigned int*)data;
	while (i < nb_max && *nb != 0)
	{
		data += sizeof(unsigned int);
		nb = (unsigned int*)data;
		i++;
	}
	if (i == nb_max)
	{
		print_log("FATAL ERROR : get_place()\n");
		exit(1);
	}
	*nb = alloc_size;
	return (i);
}

static t_data *get_data_field(t_pr_alloc *zone)
{
	t_data	*data;

	data = zone->data;
	while (data->count == zone->nb)
	{
		if (data->next == 0)
			data->next = create_data_field(zone);
		data = data->next;
	}
	return (data);
}

char		*find_place(t_pr_alloc *zone, size_t size)
{
	unsigned int		place;
	t_data				*data;
	char				*addr;

	data = get_data_field(zone);
	place = get_place(data, zone->nb, size);
	data->count++;
	nb = (long unsigned int *)(*(data + 2 * sizeof(long unsigned int)));
	addr = (char*)(nb + place * zone->type);
	return (addr);
}
