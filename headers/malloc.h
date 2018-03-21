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
#include <string.h>
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
enum {GET, INIT};

/**************************************
** STRUCTURES
**************************************/

/*
** CONTENU D'UNE ZONE DATA
** premier long unsigned int : nombre total de places occupées dans la zone
** second long unsigned int : addresse de la zone data suivante
** troisieme long unsigned int : addresse de la zone PTR associé
** unsigned ints suivants : place occupée par chaque ptr
*/

struct s_pr_alloc
{
	long unsigned int	*data;
	unsigned int		field_size;
	unsigned int		nb;
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

unsigned long int	*create_data_field(int ptr_size, int field_size);
void	destroy_data_field(long unsigned int *data_field, int ptr_size, int field_size);

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

t_pr_alloc		*get_tiny(int mode);
t_pr_alloc		*get_small(int mode);
t_large_alloc	*get_large(int mode);

#endif
