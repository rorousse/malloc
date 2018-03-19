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

unsigned int		*create_field(int type, int ptr_size, int field_size)
{
	unsigned int *field;
	unsigned int size;

	size = 0;
	if (type == DATA)
		size = sizeof(unsigned int) * field_size + 2 * sizeof(void*);
	else if (type == PTR)
		size = ptr_size * field_size;
	field = mmap(NULL, size,
	PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (field);
}
