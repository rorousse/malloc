/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:18:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 22:20:04 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	liberation(t_data *data, unsigned int pos)
{
	if (data->size_tab[pos] == 0)
	{
		ft_putendl("Warning : zone being freed was not allocated");
	}
	else
	{
		data->size_tab[pos] = 0;
		(data->count)--;
	}
}

static int	search_in_zone(t_pr_alloc *zone, char *addr)
{
	t_data *data;

	if (zone == NULL)
		return (0);
	data = zone->data;
	while (data != 0)
	{
		dprintf(2, "recherche de %p dans %p - %p\n", addr, data->alloc_zone, data->alloc_zone + zone->type * zone->nb);
		if (addr >= data->alloc_zone && addr < data->alloc_zone + zone->type * zone->nb)
		{
			liberation(data, (addr - data->alloc_zone) / zone->type);
			return (1);
		}
		data = data->next;
	}
	return (0);
}


void		ft_free(void *ptr)
{
	t_pr_alloc	*tiny;
	t_pr_alloc	*small;
	t_pr_alloc	*large;
	char		*addr;

	tiny = get_tiny(GET);
	small = get_small(GET);
	large = get_large(GET);
	addr = (char*)ptr;
	if (ptr != NULL)
	{
		if (search_in_zone(tiny, addr) || search_in_zone(small, addr))
			return;
	}
	print_log("error : address was in a zone not pre-allocated");
}
