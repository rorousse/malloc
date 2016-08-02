#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h> 
# include <sys/mman.h>
# include "../libft/libft.h"

# define TINY 256
# define SMALL 4096

/* structures de donnes */

struct s_memzone
{
	void				*ptr;
	size_t				size;
	struct s_memzone	*next;
	struct s_memzone	*prec;
};

typedef struct s_memzone t_memzone;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

/* Prototypes */

/*
** ALLOCATION_C
*/

void	*get_tiny(void);
void	*get_small(void);

/*
** MALLOC_C
*/

void	*ft_malloc(size_t size);

#endif
