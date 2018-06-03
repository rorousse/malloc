/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:43:59 by rorousse          #+#    #+#             */
/*   Updated: 2018/04/14 11:44:02 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_utils.h"

static void	search_in_large(char *addr, t_info_ptr *mllc_ptr, unsigned int nb)
{
	unsigned int	i;
	char			*alloc_zone;

	i = 0;
	alloc_zone = (mllc_ptr->data)->alloc_zone;
	while (i < nb)
	{
		if (memcmp(alloc_zone, &addr, sizeof(long unsigned int)) == 0)
		{
			mllc_ptr->size_ptr = LARGE_SIZE;
			mllc_ptr->addr = addr;
			mllc_ptr->pos = i;
			return ;
		}
		alloc_zone += sizeof(long unsigned int);
		i++;
	}
}

static int	set_info_ptr(t_info_ptr *info_ptr, t_pr_alloc *zone, char *addr)
{
	if (zone->size_ptr != LARGE_SIZE
	&& addr >= info_ptr->data->alloc_zone
	&& addr < info_ptr->data->alloc_zone + zone->size_ptr * zone->nb)
	{
		info_ptr->addr = addr;
		info_ptr->pos = (addr - info_ptr->data->alloc_zone) /
		zone->size_ptr;
		info_ptr->size_ptr = zone->size_ptr;
		return (1);
	}
	else
	{
		search_in_large(addr, info_ptr, zone->nb);
		if (info_ptr->addr != NULL)
			return (1);
	}
	return (0);
}

t_info_ptr	search_in_zone(t_pr_alloc *zone, char *addr)
{
	t_info_ptr	info_ptr;

	info_ptr.size_ptr = 0;
	info_ptr.addr = NULL;
	if (zone == NULL)
	{
		print_log("null zone\n");
		return (info_ptr);
	}
	info_ptr.data = zone->data;
	while (info_ptr.data != NULL && !set_info_ptr(&info_ptr, zone, addr))
		info_ptr.data = info_ptr.data->next;
	return (info_ptr);
}

t_info_ptr	search_in_all_zones(void *ptr)
{
	unsigned int	i;
	t_info_ptr		mllc_ptr;

	mllc_ptr.size_ptr = 0;
	mllc_ptr.data = NULL;
	mllc_ptr.addr = NULL;
	mllc_ptr.pos = 0;
	i = 0;
	while (i < SIZE_RANGE && mllc_ptr.size_ptr == 0)
	{
		mllc_ptr = search_in_zone(get_zone(INDEX, i), ptr);
		i++;
	}
	return (mllc_ptr);
}
