/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:14:24 by rorousse          #+#    #+#             */
/*   Updated: 2018/04/16 23:14:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *ft_realloc(void *ptr, size_t size)
{
	t_info_ptr mllc_ptr;
	char *new_ptr;
	size_t	min_size;

	mllc_ptr = search_in_all_zones(ptr);
	if ((mllc_ptr.type == TINY && size < TINY) || 
	(mllc_ptr.type == SMALL && size > TINY && size < SMALL))
	{
		mllc_ptr.data->size_tab[mllc_ptr.pos] = size;
	}
	else
	{
		new_ptr = ft_malloc(size);
		min_size = (mllc_ptr.data->size_tab[mllc_ptr.pos] < size) ? mllc_ptr.data->size_tab[mllc_ptr.pos] : size;
		memcmp(ptr, new_ptr, min_size);
		ft_free(ptr);
		ptr = new_ptr;
	}
	return (ptr);
	// si le ptr est dans une zone de meme type que sa zone actuelle, qui est TINY ou SMALL : on augmente juste la size, fin
	// SINON
	// on alloue un nouveau ptr;
	// on cpie le ptr actuelle dans le nouveau ptr ( delimiteur de copie ; size la plus basse )
	// on libere l'ancien ptr
}
