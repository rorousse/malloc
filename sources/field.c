/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:30:12 by rorousse          #+#    #+#             */
/*   Updated: 2018/03/19 16:30:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Alloue la memoire destinee a un champ de type DATA ou PTR,
** puis renvoie celui-ci.
*/

t_data *create_data_field(t_pr_alloc *zone)
{
	t_data *data;

	data = mmap(NULL, zone->size_data,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bzero(data, zone->size_data);
	data->size_tab = (unsigned int *)(&(data->size_tab) + sizeof(void*));
	data->alloc_zone = mmap(NULL, zone->type * zone->nb,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bzero(data->alloc_zone, zone->type * zone->nb);
		print_log("Alloc Zone est %p\n", data->alloc_zone);
	if (data == MAP_FAILED || data->alloc_zone == MAP_FAILED)
	{
		print_log("MAP FAILED\n");
		exit(0);
	}
	return (data);
}

void		destroy_data_field(t_data *data, t_pr_alloc zone)
{
	print_log("DESTRUCTION\n");
	munmap(data->alloc_zone, zone.type * zone.nb);
	munmap(data, zone.size_data);
}
