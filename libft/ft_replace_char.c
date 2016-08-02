/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:06:25 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/30 11:46:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_char(char *str, char c, char new)
{
	if (str != NULL)
	{
		while (*str)
		{
			if (*str == c)
				*str = new;
			str++;
		}
	}
}
