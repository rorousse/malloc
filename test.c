/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:03:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/03 21:13:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *ptr;
	int  *bouh;
	int	 *lol;

	ptr = malloc(4);
	bouh = (int*)ptr;
	*bouh = 4096;
	lol = (int*)ptr;
	printf("%d\n", *lol);
}
