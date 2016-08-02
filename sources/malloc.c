/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 18:31:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/08/02 22:25:51 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"
#include "../libft/libft.h"

void	*ft_malloc(size_t size)
{
	(void)size;
	ft_putendl("launch");
	get_tiny();
	get_small();
	return (0);
}
