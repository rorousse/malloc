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

static void	liberation(t_info_ptr ptr)
{
	if (ptr.data->size_tab[ptr.pos] == 0)
	{
		ft_putendl("Warning : zone being freed was not allocated\n");
	}
	else
	{
		if (ptr.type == LARGE)
		{
			munmap(ptr.addr, ptr.data->size_tab[ptr.pos]);
			bzero(ptr.data->alloc_zone + ptr.pos *sizeof(long unsigned int), sizeof(long unsigned int));
		}
		ptr.data->size_tab[ptr.pos] = 0;
		(ptr.data->count)--;
	}

}

void		ft_free(void *ptr)
{
	t_info_ptr	mllc_ptr;

	mllc_ptr = search_in_all_zones(ptr);
	if (mllc_ptr.addr != NULL)
	{
		liberation(mllc_ptr);
	}
	else
	{
		dprintf(2, "ERROR : NULL pointer\n");
	}
}
