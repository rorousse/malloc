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

#include "malloc.h"
#include <stdio.h>

static void	show_field(t_data *data, t_pr_alloc *zone)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	print_log("Dans ce field, il y a %lu pointeurs alloues\n", data->count);
	ptr = data->alloc_zone;
	while (i < zone->nb)
	{
		if (data->size_tab[i] != 0)
		{
			printf("%p - %p:\n%u\n", ptr + (i * zone->type),
			ptr + (i * zone->type) + data->size_tab[i], data->size_tab[i]);
		}
		i++;
	}
}

static void show_zone(t_pr_alloc *zone)
{
	t_data *data;

	if (zone == NULL)
		return;
	data = zone->data;
	while (data != 0)
	{
		show_field(data, zone);
		data = data->next;
	}
}

void		print_log(char *str, ...)
{
	va_list			ap;

	if (VERBOSE)
	{
		va_start(ap, str);
		vdprintf(2, str, ap);
		va_end(ap);
	}
}

void		show_alloc_mem(void)
{
	t_pr_alloc		*tiny;
	t_pr_alloc		*small;

	tiny = get_tiny(GET);
	small = get_small(GET);
	print_log("zone TINY:\n");
	show_zone(tiny);
	print_log("zone SMALL:\n");
	show_zone(small);
}

void		print_memory(unsigned int *start, unsigned int *end)
{
	unsigned int i;

	i = 0;
	while (start + i != end)
	{
		print_log("%x  ", *start);
		if ((i % 7) == 0)
			print_log("\n");
	}
}
