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

#include "malloc_utils.h"

/*
** Alloue la memoire destinee a un champ de type DATA ou PTR,
** puis renvoie celui-ci.
*/

t_data		*create_data_field(t_pr_alloc *zone, t_data *prec)
{
	t_data *data;
	size_t size;

	size = zone->size_ptr;
	if (size == LARGE_SIZE)
	{
		size = sizeof(void*);
	}
	data = mmap(NULL, zone->size_data,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bzero(data, zone->size_data);
	data->prec = prec;
	data->size_tab = (unsigned int *)(&(data->size_tab) + sizeof(void*));
	data->alloc_zone = mmap(NULL, size * zone->nb,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bzero(data->alloc_zone, size * zone->nb);
	if (data == MAP_FAILED || data->alloc_zone == MAP_FAILED)
	{
		print_log("MAP FAILED\n");
		exit(0);
	}
	return (data);
}

void		destroy_data_field(t_data *data, t_pr_alloc zone)
{
	t_data	*prec;
	t_data	*next;
	size_t	size;

	prec = data->prec;
	next = data->next;
	size = zone.size_ptr;
	if (size == LARGE_SIZE)
		size = sizeof(void*);
	print_log("DESTRUCTION\n");
	munmap(data->alloc_zone, size * zone.nb);
	munmap(data, zone.size_data);
	if (prec != NULL)
		prec->next = next;
	if (next != NULL)
		next->prec = prec;
}
