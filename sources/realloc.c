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

#include "malloc_utils.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_info_ptr	mllc_ptr;
	char		*new_ptr;
	size_t		min_size;

	mllc_ptr = search_in_all_zones(ptr);
	if (size < mllc_ptr.size_ptr && mllc_ptr.size_ptr != LARGE)
		mllc_ptr.data->size_tab[mllc_ptr.pos] = size;
	else
	{
		new_ptr = ft_malloc(size);
		min_size = (mllc_ptr.data->size_tab[mllc_ptr.pos] < size) ?
		mllc_ptr.data->size_tab[mllc_ptr.pos] : size;
		memcmp(ptr, new_ptr, min_size);
		ft_free(ptr);
		ptr = new_ptr;
	}
	return (ptr);
}
