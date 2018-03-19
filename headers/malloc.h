/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:25:08 by rorousse          #+#    #+#             */
/*   Updated: 2018/03/19 17:25:13 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../libft/libft.h"

/***************************************
************** FT_MALLOC ***************
** BASIC EXPLANATION
** 
***************************************/


/***************************************
** MACROS
****************************************/

/* Memory parameters */

# define TINY 256
# define SMALL 4096
# define MIN_PTR_NB 100;

/* Utility */

# define VERBOSE 1

/**************************************
** ENUMS
**************************************/

enum {DATA, PTR};

/**************************************
** STRUCTURES
**************************************/

/*
** PTR contains the allocated memory given to the user
** DATA contains the size of each ptr given to the user. Data contains n unsigned int (n is the maximum number of ptrs of the zone),
** plus two void*. The first void* contains the address of the next field of datas, if the current is full. The second void*
** contains the address of the next field of pointers (same logic)
** field_size is the max number of ptr one field of the structure can contains
** nb and count are respectively the total number of ptrs and the number available. If count==nb, we must create new fields
** type is simply the size of allocations (TINY, SMALL, ...)
*/

struct s_pr_alloc
{
	char				*ptr;
	char				*data;
	unsigned int		field_size;
	unsigned int		nb;
	unsigned int 		count;
	int					type;
};

typedef struct s_pr_alloc t_pr_alloc;

struct s_large_alloc
{
	void				**data;
};

typedef struct s_large_alloc t_large_alloc;

/* Prototypes */

/*
** ALLOCATION_C
*/

void			*alloc_large(size_t size);

/*
** FIELD_C
*/

unsigned int 	*create_field(int type, int ptr_size, int field_size);

/*
** FREE_C
*/

void		ft_free(void *ptr);

/*
** MALLOC_C
*/

void	*ft_malloc(size_t size);

/*
** PLACEMENT_C
*/

char	*find_place(t_pr_alloc *zone, size_t size);

/*
** SHOW_C
*/

void	print_log(char *str, ...);
void	show_alloc_mem(void);
void	print_memory(unsigned int *start, unsigned int *end);

/*
** ZONES_C
*/

t_pr_alloc		*get_tiny(void);
t_pr_alloc		*get_small(void);
t_large_alloc	*get_large(void);

#endif
