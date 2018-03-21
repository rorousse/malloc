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

static void	liberation(long unsigned int *data, unsigned int pos)
{
	unsigned int		*nb;

	nb = (unsigned int *)(data + 3 * sizeof(long unsigned int) + (pos * sizeof(unsigned int)));
	if (*nb == 0)
		ft_putendl("Warning : zone being freed was not allocated");
	*nb = 0;
}

static int	search_in_zone(t_pr_alloc *zone, long unsigned int *addr)
{
	long unsigned int *data;
	long unsigned int *ptr;

	if (zone == NULL)
		return (0);
	data = zone->data;
	while (data != 0)
	{
		ptr = (long unsigned int *)(*(data + 2 * sizeof(long unsigned int)));
		if (addr > ptr && addr < ptr + zone->type * zone->field_size)
		{
			liberation(data, (addr - ptr) / zone->type);
			return (1);
		}
		data = (long unsigned int *)(*(zone->data + sizeof(long unsigned int)));
	}
	return (0);
}


void		ft_free(void *ptr)
{
	t_pr_alloc	*tiny;
	t_pr_alloc	*small;
	long unsigned int *u_ptr;

	tiny = get_tiny(GET);
	small = get_small(GET);
	u_ptr = (long unsigned int*)ptr;
	if (ptr != NULL)
	{
		if (search_in_zone(tiny, u_ptr) || search_in_zone(small, u_ptr))
			return;
	}
	print_log("error : address was in a zone not pre-allocated");
}
