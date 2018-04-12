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

static unsigned int	get_place(t_data *data, unsigned int nb_max, unsigned int alloc_size)
{
	unsigned int	i;

	i = 0;
	while (i < nb_max && data->size_tab[i] != 0)
		i++;
	if (i == nb_max)
	{
		print_log("FATAL ERROR : get_place()\n");
		exit(1);
	}
	data->size_tab[i] = alloc_size;
	print_log("size %u stored\n", alloc_size);
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
	long unsigned int	*large_addr;
	int 				page;

	if (zone->type == LARGE)
	{
		page = getpagesize();
		while ((size % page) != 0)
			size++;
	}
	data = get_data_field(zone);
	place = get_place(data, zone->nb, size);
	data->count++;
	addr = data->alloc_zone + (place * zone->type);
	if (zone->type == LARGE)
	{
		large_addr = (long unsigned int *)addr;
		*large_addr = (long unsigned int)mmap(NULL, size,
		PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		addr = (char*)(*large_addr);
	}
	print_log("L'allocation sera de size %u\n", size);
	return (addr);
}
