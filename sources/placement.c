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

#include <stdio.h>
# include "malloc.h"

static int	check_place(t_pr_alloc zone)
{
	unsigned int	i;
	unsigned int	*nb;

	i = 0;
	while (i < zone.nb)
	{
		nb = (unsigned int*)(zone.data + (i * sizeof(unsigned int)));
		if (*nb == 0)
		{
			return (i);
		}
		i++;
	}
	ft_putendl("Error placement");
	return (-1);
}

char	*find_place(t_pr_alloc *zone, size_t size)
{
	unsigned int	*nb;	
	int 			place;
	char			*addr;

	addr = NULL;
	place = check_place(*zone);
	if (place  != -1)
	{
		addr = zone->ptr + (place * zone->type);
		nb = (unsigned int*)(zone->data + (place * sizeof(unsigned int)));
		*nb = size;
	}
	return (addr);
}
