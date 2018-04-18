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

#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "libft.h"
#include "malloc.h"

/***************************************
************** FT_MALLOC ***************
** BASIC EXPLANATION
** 
***************************************/


/***************************************
** MACROS
****************************************/

/* Memory parameters */

# define LARGE sizeof(char*)
# define MIN_PTR_NB 100;

/* Utility */

# define VERBOSE 1

/**************************************
** ENUMS
**************************************/

enum {DATA, PTR};
enum {GET, INIT, INDEX};

/**************************************
** STRUCTURES
**************************************/

typedef struct s_data t_data;
typedef struct s_pr_alloc t_pr_alloc;
typedef struct s_info_ptr t_info_ptr;
typedef struct s_mllc_zones t_mllc_zones;

struct s_data
{
	long unsigned int	count;
	t_data 				*next;
	t_data				*prec;
	char				*alloc_zone;
	unsigned int 		*size_tab;
};


struct s_pr_alloc
{
	unsigned int 		size_ptr;
	unsigned int 		nb;
	unsigned int		size_data;
	t_data				*data;
};

struct s_info_ptr
{
	char			*addr;
	size_t			size_ptr;
	t_data			*data;
	unsigned int	pos;
};

struct s_mllc_zones
{
	unsigned int init;
	t_pr_alloc zones[SIZE_RANGE];
};

/**************************************
** GLOBALES
**************************************/


/* Prototypes */

/*
** FIELD_C
*/

t_data	*create_data_field(t_pr_alloc *zone, t_data *prec);
void	destroy_data_field(t_data *data, t_pr_alloc zone);

/*
** PLACEMENT_C
*/

char	*find_place(t_pr_alloc *zone, size_t size);

/*
** SEARCH_C
*/

t_info_ptr	search_in_zone(t_pr_alloc *zone, char *addr);
t_info_ptr search_in_all_zones(void *ptr);

/*
** SHOW_C
*/

void	print_log(char *str, ...);
void	show_alloc_mem(void);
void	print_memory(long unsigned int *start, unsigned int size);

/*
** ZONES_C
*/

t_pr_alloc		*get_zone(int mode, size_t size);

#endif
