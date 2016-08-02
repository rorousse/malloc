/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_double_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:32:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 15:45:16 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_double_str(char ***str, char *new)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char**)malloc((ft_get_size_double_str(*str) + 2) * sizeof(char*));
	while (str[0][i] != NULL)
	{
		copy[i] = ft_strdup(str[0][i]);
		i++;
	}
	copy[i] = ft_strdup(new);
	copy[i + 1] = NULL;
	i = 0;
	ft_free_double_str(*str);
	*str = copy;
}
