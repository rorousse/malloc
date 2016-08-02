/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_double_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:25:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/06 11:34:53 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_double_str(char **str, int pos)
{
	if (pos < 0)
		return ;
	free(str[pos]);
	while (str[pos] != NULL)
	{
		str[pos] = str[pos + 1];
		pos++;
	}
}
