/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 19:19:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/08 22:17:45 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "headers/malloc.h"

int main()
{
	char *lol;
	char	*mdr;

	lol = ft_malloc(2);
	mdr = ft_malloc(3);
	printf("le pointeur est %p et %p \n", lol, mdr);
	show_alloc_mem();
	ft_free(lol);
	show_alloc_mem();
	return (0);
}

/*
** une page = 4096 octets
** ZONE TINY = 128 * 32 octets pour un total d'une page == une page divisee en 128 zones d'alloc 
** ZONE SMALL = 128 * 256 octets pour un total de 32768 == 8 pages divisees en 128 zones memoires
*/
