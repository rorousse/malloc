/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_cmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:11:13 by rorousse          #+#    #+#             */
/*   Updated: 2016/07/09 15:45:37 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_char_cmp(char *str, char *str2, char c)
{
	int	i;

	i = 0;
	while (str[i] && str2[i] && str[i] == str2[i] &&
	str[i + 1] != c && str2[i + 1] != c)
		i++;
	if (str[i + 1] == '=' && str2[i + 1])
		return (-1);
	return (str[i] - str2[i]);
}
