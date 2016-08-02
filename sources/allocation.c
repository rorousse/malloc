/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 18:52:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/02 23:29:34 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

static unsigned int		det_size_zone(unsigned int mode)
{
	unsigned int	page;
	unsigned int	count;

	count = mode;
	page = getpagesize();
	while ((count/mode < 100) || (count % mode != 0) || (count % page != 0))
		   count = count + mode;
	printf("%u\n", count);
	return (count);
}

void	*get_tiny()
{
	static int		init = 0;
	static int		etat[128];
	static void		*ptr_tiny;
	unsigned int	zone;
	int				i;

	i = 0;
	if (init == 0)
	{
		while (i < 128)
		{
			etat[i] = 0;
			i++;
		}
		zone = det_size_zone(TINY);
		ptr_tiny = mmap(NULL, zone + TINY, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		init = 1;
	}
	return (ptr_tiny);
}

void   *get_small()
{
    static int  	init = 0;
	static int		etat[128];
    static void 	*ptr_small;
	unsigned int 	zone; 
	int				i;

	i = 0;
    if (init == 0)
    {
		while (i < 128)
		{
			etat[i] = 0;
			i++;
		}
		zone = det_size_zone(SMALL);
		ptr_small = mmap(NULL, zone + SMALL, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		init = 1;
    }
    return (ptr_small);
}
