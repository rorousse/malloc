/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:30:12 by rorousse          #+#    #+#             */
/*   Updated: 2018/03/19 16:30:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Alloue la memoire destinee a un champ de type DATA ou PTR,
** puis renvoie celui-ci.
*/

char		*create_data_field(int ptr_size, int field_size)
{
	char			*data_field;
	char			*ptr_field;
	unsigned int	size;

	size = sizeof(unsigned int) * field_size + 3 * sizeof(void*);
	data_field = mmap(NULL, size,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	bzero(data_field, size);
	size = ptr_size * field_size;
	ptr_field = mmap(NULL, size,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	*(data_field + 2 * sizeof(long unsigned int)) = (long unsigned int)ptr_field;
	return (data_field);
}
