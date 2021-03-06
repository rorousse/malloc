/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 18:02:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 22:48:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_utils.h"

static void	print_content(t_data *data, t_pr_alloc *zone, unsigned int i)
{
	char				*ptr;
	long unsigned int	*ptr_large;

	ptr = data->alloc_zone;
	if (zone->size_ptr != LARGE_SIZE)
	{
		dprintf(2, "%p - %p:\n%zu\n", ptr + (i * zone->size_ptr),
		ptr + (i * zone->size_ptr) + data->size_tab[i],
		data->size_tab[i]);
	}
	else
	{
		ptr_large = (unsigned long int *)(ptr + (i * sizeof(void*)));
		dprintf(2, "%lx - %lx:\n%zu\n", *ptr_large,
		*ptr_large + data->size_tab[i], data->size_tab[i]);
	}
}

static void	show_field(t_data *data, t_pr_alloc *zone)
{
	unsigned int		i;

	i = 0;
	while (i < zone->nb)
	{
		if (data->size_tab[i] != 0)
		{
			print_content(data, zone, i);
		}
		i++;
	}
	print_log("Dans ce field, il y a %lu pointeurs alloues\n", data->count);
}

static void	show_zone(t_pr_alloc *zone)
{
	t_data *data;

	if (zone == NULL)
		return ;
	data = zone->data;
	while (data != 0)
	{
		show_field(data, zone);
		data = data->next;
	}
}

void		show_alloc_mem(void)
{
	size_t i;

	i = 0;
	while (i < SIZE_RANGE)
	{
		print_log("Pre-allocated map, type %u:\n", i);
		show_zone(get_zone(INDEX, i));
		i++;
	}
}

void		print_memory(long unsigned int *start, unsigned int size)
{
	unsigned int i;

	i = 0;
	print_log("START :\n");
	while (i < size)
	{
		print_log("%x  ", *start);
		if (((i + 1) % 8) == 0)
			print_log("\n");
		start += sizeof(long unsigned int);
		i++;
	}
	print_log("%u bytes readed\n", i);
}
