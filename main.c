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

void testalloc()
{
  char *lol;
  char *mdr;

  lol = ft_malloc(2);
  mdr = ft_malloc(3);
  ft_free(lol);
  ft_free(mdr);
  show_alloc_mem();
}

int main()
{
 	testalloc();
	return (0);
}

/*
** une page = 4096 octets
** ZONE TINY = 128 * 32 octets pour un total d'une page == une page divisee en 128 zones d'alloc 
** ZONE SMALL = 128 * 256 octets pour un total de 32768 == 8 pages divisees en 128 zones memoires
*/
