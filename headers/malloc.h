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

# define LARGE sizeof(char*)
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

typedef struct s_data t_data;
typedef struct s_pr_alloc t_pr_alloc;

/*
** CONTENU D'UNE ZONE DATA
** premier long unsigned int : nombre total de places occupées dans la zone
** second long unsigned int : addresse de la zone data suivante
** troisieme long unsigned int : addresse de la zone PTR associé
** unsigned ints suivants : place occupée par chaque ptr
*/

struct s_data
{
	long unsigned int	count;
	t_data 				*next;
	char				*alloc_zone;
	unsigned int 		*size_tab;
};


struct s_pr_alloc
{
	int 				type;
	unsigned int 		nb;
	unsigned int		size_data;
	t_data				*data;
};

/* Prototypes */

/*
** FIELD_C
*/

t_data	*create_data_field(t_pr_alloc *zone);
void	destroy_data_field(t_data *data, t_pr_alloc zone);

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
t_pr_alloc	*get_large(int mode);

#endif
