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
#include <string.h>
#include <sys/mman.h>
#include "headers/malloc.h"

#define TINY 256
#define SMALL 4096

void test_multiple_large()
{
  char *ptr[100];
  int i = 0;

  while (i < 100)
  {
    ptr[i] = ft_malloc(SMALL + 1);
    i++;
  }
  i = 0;
  
  while (i < 100)
  {
    ft_free(ptr[i]);
    i++;
  }
  
  show_alloc_mem();
}

void  test_one_tiny()
{
  char  *ptr;

  ptr = ft_malloc(TINY - 1);
  show_alloc_mem();
}

void test_multiple_tiny()
{
  char *ptr[999];
  int i = 0;

  dprintf(2, "doing 999 alocations of a size of %u\n", TINY - 1);
  while (i < 999)
  {
    dprintf(2, "iteration %d\n", i);
    ptr[i] = ft_malloc(TINY - 1);
    i++;
  }
  dprintf(2, "allocations succeed\n");
  i = 0;
  while (i < 999)
  {
    strcpy(ptr[i], "Hello world!\n");
    i++;
  }
  show_alloc_mem();
 // print_memory((unsigned int *)ptr[0], (unsigned int *)ptr[99]);
  i = 0;
  while (i < 999)
  {
    ft_free(ptr[i]);
    i++;
  }
  show_alloc_mem();
}

void  test_one_large()
{
  char *ptr;

  ptr = ft_malloc(SMALL + 1);
  show_alloc_mem();
  ft_free(ptr);
  show_alloc_mem();
}

void test_two_large()
{
  char *ptr;
  char *ptr2;

  ptr = ft_malloc(TINY - 1);
  ptr2 = ft_malloc(TINY / 2);
  show_alloc_mem();
  ft_free(ptr);
  ft_free(ptr2);
  show_alloc_mem();
}
void alloc_a_large_free_another()
{
  char *test;
  char  *test2;

  test = ft_malloc(4097);
  test2 = malloc(4097);
  ft_free(test2);
  ft_free(test);
  free(test2);
}

void  test_free_alone()
{
  char *test;
  test = malloc(32);
  dprintf(2, "le pointeur est %p\n", test);
  ft_free(test);
}

void test_double_free_large()
{
  char *test;

  test = ft_malloc(42);
  dprintf(2, "Le pointeur LARGE obtenu est a l'addresse %p\n", test);
  ft_free(test);
  dprintf(2, "first free ok\n");
  ft_free(test);
  dprintf(2, "second free ok\n");
  show_alloc_mem();
}

void  test_unmap()
{
  unsigned int *lol;

  lol = (unsigned int *)0xFFFFFFFF;
  if (munmap(lol, getpagesize()) < 0)
    dprintf(2, "ERROR\n");
}

void testalloc()
{
  char *lol;
  unsigned int i;

  i = 0;
  while (i < 7000)
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
  test_multiple_tiny();
	return (0);
}

/*
** une page = 4096 octets
** ZONE TINY = 128 * 32 octets pour un total d'une page == une page divisee en 128 zones d'alloc 
** ZONE SMALL = 128 * 256 octets pour un total de 32768 == 8 pages divisees en 128 zones memoires
*/
