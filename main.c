/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 19:19:36 by rorousse          #+#    #+#             */
/*   Updated: 2017/03/18 22:30:47 by rorousse         ###   ########.fr       */
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
  unsigned int i;

  while (i < 500)
  {
    dprintf(2, "ESSAI NUMERO %u\n", i);
    i++;
    lol = ft_malloc(i+1);
    ft_free(lol);
  }
  dprintf(2, "END OF ALLOCATION\n");
  show_alloc_mem();
}

int main()
{
  char *lol;
  
  dprintf(2, "page size vaut %d\n", getpagesize()); 
  lol = ft_malloc(30000);
  //ft_free(lol);
  show_alloc_mem();
	//testalloc();
	return (0);
}

/*
** une page = 4096 octets
** ZONE TINY = 128 * 32 octets pour un total d'une page == une page divisee en 128 zones d'alloc 
** ZONE SMALL = 128 * 256 octets pour un total de 32768 == 8 pages divisees en 128 zones memoires
*/
