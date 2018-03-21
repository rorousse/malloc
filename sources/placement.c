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

static long unsigned int *get_data_field(t_pr_alloc *zone)
{
	long unsigned int	*data;
	long unsigned int	next_addr;
	long unsigned int	nb;
	char				*tmp;

	data = (long unsigned int*)zone->data;
	nb = *data;
	while (nb == zone->nb)
	{
		next_addr = *(data + sizeof(long unsigned int));
		if (next_addr == 0)
		{
			tmp = create_field(zone->type, zone->nb);
			*(data + sizeof(long unsigned int)) = (long unsigned int)tmp;
		}
		data = (long unsigned int *)next_addr;
		nb = *data;
	}
	return (data);
}

char		*find_place(t_pr_alloc *zone, size_t size)
{
	long unsigned int	*nb;
	unsigned int		place;
	long unsigned int	*data;
	char				*addr;

	data = get_data_field(zone);
	place = get_place(data, zone->nb, size);
	nb = data;
	(*nb)++;
	nb = (long unsigned int *)(*(data + 2 * sizeof(long unsigned int)));
	addr = (char*)(nb + place * zone->type);
	return (addr);
}
