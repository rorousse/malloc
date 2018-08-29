/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:13:01 by rorousse          #+#    #+#             */
/*   Updated: 2018/06/04 11:13:04 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void test_simple_alloc(size_t size)
{
	char *ptr;
	size_t	i;

	i = 0;
	dprintf(2, "Testing now with a size of %zu \n", size);
	ptr = ft_malloc(size);
	dprintf(2, "Allocation seems to have worked\n");
	if (ptr == NULL)
		dprintf(2, "WARNING : PTR NULL, ECHEC ALLOC\n");
	if (ptr != NULL)
	{
		for (i=0; i < size; i++)
		{
			ptr[i] = 'a';
		}
	}
	dprintf(2, "\n liberating now\n");
	ft_free (ptr);
	dprintf(2, "\n liberation ok\n");
}

void basic_test()
{
	size_t i;

	for(i=1; i < SIZE_MAX; i*=10)
	{
		test_simple_alloc(i);
	}
}