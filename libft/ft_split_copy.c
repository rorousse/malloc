/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:43:31 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 14:38:34 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_origin_size(char **origin)
{
	int	i;

	i = 0;
	while (origin[i] != NULL)
		i++;
	return (i + 1);
}

char		**ft_split_copy(char **origin)
{
	char	**copy;
	int		i;
	int		taille;

	i = 0;
	taille = get_origin_size(origin);
	copy = (char**)malloc(taille * sizeof(char*));
	while (origin[i] != NULL)
	{
		copy[i] = ft_strdup(origin[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
