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

static unsigned int	check_place(t_pr_alloc *zone)
{
	unsigned int	i;
	unsigned int	*nb;

	i = 0;
	while (i < zone->nb)
	{
		nb = (unsigned int*)(zone->data + (i * sizeof(unsigned int)));
		if (*nb == 0)
		{
			return (i);
		}
		i++;
	}
	ft_putendl("Error placement\n");
	return (-1);
}

static char *get_data_field(t_pr_alloc zone)
{
	unsigned int		i;
	long unsigned int	*data;
	long unsigned int	*ptr;
	unsigned int		nb;
	long unsigned int	tmp;

	data = zone->data;
	nb = *data;
	i = 0;
	while (nb == zone->nb)
	{
		i++;
		ptr = *(data + sizeof(long unsigned int));
		if (ptr == 0)
		{
			tmp = create_new_field(DATA, zone->type, zone->nb);
			*(data + sizeof(long unsigned int)) = tmp;
			tmp = create_new_field(PTR, zone->type, zone->nb);
			*(data + (2 * sizeof(long unsigned int))) = tmp;
			return (i);
		}
	}
}

char		*find_place(t_pr_alloc *zone, size_t size)
{
	unsigned int		*nb;
	unsigned int		place;
	char				*data;
	char				*addr;

	addr = zone->ptr;
	data = get_data_field(zone);
	place = check_place(*zone);
	if (place != -1)
	{
		addr = zone->ptr + (place * zone->type);
		nb = (unsigned int*)(zone->data + (place + 3 * sizeof(long unsigned int)));
		*nb = size;
	}
	return (addr);
}
