/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:48:58 by rorousse          #+#    #+#             */
/*   Updated: 2018/06/03 17:49:14 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_utils.h"

void		print_log(char *str, ...)
{
	va_list			ap;

	if (VERBOSE)
	{
		va_start(ap, str);
		vdprintf(2, str, ap);
		va_end(ap);
	}
}