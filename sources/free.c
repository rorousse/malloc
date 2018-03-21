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

/*
static void	liberation(char *ptr, t_pr_alloc *zone)
{
	unsigned int		espace;
	char				*data_cpy;
	unsigned int		*nb;

	espace = 0;
	if (zone->type != 0)
		espace = (ptr - zone->ptr) / zone->type;
	data_cpy = zone->data + (espace * sizeof(unsigned int));
	nb = (unsigned int*)data_cpy;
	if (*nb == 0)
		ft_putendl("Warning : zone being freed was not allocated");
	*nb = 0;
}

void		ft_free(void *ptr)
{
	t_pr_alloc	*tiny;
	t_pr_alloc	*small;
	char		*ptr_cpy;

	if (ptr != NULL)
	{
		ptr_cpy = (char*)ptr;
		tiny = get_tiny();
		small = get_small();
		if (ptr_cpy >= tiny->ptr && ptr_cpy <= (tiny->ptr + (tiny->nb * TINY)))
		{
			liberation(ptr_cpy, tiny);
		}
		else if (ptr_cpy >= small->ptr &&
		ptr_cpy <= (small->ptr + (small->nb * SMALL)))
		{
			liberation(ptr_cpy, small);
		}
	}
}
*/