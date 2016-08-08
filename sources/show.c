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

static void	show_zone(t_pr_alloc zone)
{
	unsigned int	i;
	unsigned int	*nb;

	i = 0;
	while ( i < zone.nb)
    {
        nb = (unsigned int*)(zone.data + (i * sizeof(unsigned int)));
		if (*nb != 0)
        {
            printf("%p - %p:\n %u\n", zone.ptr + (i * zone.type), zone.ptr + (i * zone.type) + *nb, *nb);
		}
        i++;
    }
}

void	show_alloc_mem()
{
	t_pr_alloc 		*tiny;
	t_pr_alloc		*small;

	tiny = get_tiny();
	small = get_small();
	show_zone(*tiny);
	show_zone(*small);
}
