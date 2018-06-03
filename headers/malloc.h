/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:54:10 by rorousse          #+#    #+#             */
/*   Updated: 2018/04/18 11:54:13 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

/***************************************
** SIZE_RANGE
** Put the different sizes of the pre-allocated zones your malloc should use.
** The sizes are supposed to be from the smallest to the greatest. 
****************************************/

#define SIZE_RANGE 7
static unsigned int size_range[SIZE_RANGE] = {12, 32, 64, 128, 256, 4096, UINT_MAX};
#define LARGE_SIZE size_range[SIZE_RANGE - 1]

/***************************************
** FUNCTIONS
****************************************/

void	ft_free(void *ptr);
void	ft_free_all(void);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	show_alloc_mem(void);
