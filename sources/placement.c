/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 16:57:23 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/03 17:52:53 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "malloc.h"

static int	check_place(t_pr_alloc zone)
{
	unsigned int	i;

	i = 0;
	while (i < zone.nb)
	{
		if (zone.ptr[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*find_place(t_pr_alloc zone)
{
	int 	place;
	char	*addr;

	addr = NULL;
	place = check_place(zone);
	if (place  != -1)
		addr = zone.ptr + zone.nb + (place * zone.type);
	return (addr);
}
