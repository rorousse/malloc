#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h> 
# include <sys/mman.h>
# include "../libft/libft.h"

# define TINY 256
# define SMALL 4096

/* structures de donnes */

struct s_pr_alloc
{
	char				*ptr;
	char				*data;
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

t_pr_alloc	*get_tiny(void);
t_pr_alloc	*get_small(void);
t_large_alloc	*get_large(void);
void		*alloc_large(size_t size);


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

void	show_alloc_mem(void);

#endif
