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

#include "malloc_utils.h"

static void	liberation(t_info_ptr ptr)
{
	if (ptr.data->size_tab[ptr.pos] == 0)
	{
		ft_putendl("Warning : zone being freed was not allocated\n");
	}
	else
	{
		if (ptr.size_ptr == LARGE_SIZE)
		{
			munmap(ptr.addr, ptr.data->size_tab[ptr.pos]);
			bzero(ptr.data->alloc_zone + ptr.pos * sizeof(void*),
			sizeof(void*));
		}
		ptr.data->size_tab[ptr.pos] = 0;
		(ptr.data->count)--;
	}
}

void		ft_free(void *ptr)
{
	t_info_ptr	mllc_ptr;

	if (ptr == NULL)
		print_log("ERROR : NULL pointer\n");
	mllc_ptr = search_in_all_zones(ptr);
	if (mllc_ptr.addr != NULL)
	{
		liberation(mllc_ptr);
		if (mllc_ptr.data->count == 0 && mllc_ptr.data->prec != NULL)
		{
			destroy_data_field(mllc_ptr.data,
			*get_zone(mllc_ptr.data->size_tab[mllc_ptr.pos], GET));
		}
	}
	else
	{
		dprintf(2, "ERROR : pointer was already free or not allocated\n");
	}
}
