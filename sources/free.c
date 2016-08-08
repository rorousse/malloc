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

static void	liberation(char *ptr, t_pr_alloc *zone)
{
	int		espace;
	char	*data_cpy;
	unsigned int *nb;

	espace = 0;
	if (zone->nb != 0)
		espace = (ptr - zone->ptr) / zone->nb;
	data_cpy = zone->data + (espace * sizeof(unsigned int));
	nb = (unsigned int*)data_cpy;
	if (*nb == 0)
		ft_putendl("Warning : zone being freed was not allocated");
	*nb = 0;
}

void	ft_free(void *ptr)
{
	t_pr_alloc	*tiny;
	t_pr_alloc	*small;
	char		*ptr_cpy;
	
	ptr_cpy = (char*)ptr;
	tiny = get_tiny();
	small = get_small();
	if (ptr_cpy >= tiny->ptr && ptr_cpy <= (tiny->ptr + (tiny->nb * TINY)))
	{
		ft_putendl("tiny");
		liberation(ptr_cpy, tiny);
	}
	else if (ptr_cpy >= small->ptr && ptr_cpy <= (small->ptr + (small->nb * SMALL)))
	{
		ft_putendl("small");
		liberation(ptr_cpy, small);
	}
	printf("%p contre %p et %p\n", ptr_cpy, tiny->ptr, small->ptr);
}
