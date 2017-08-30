/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:56:42 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/30 18:57:52 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strprefix(const char *str, const char *prefix)
{
	if (!str)
		return (0);
	if (!prefix)
		return (1);
	while (*str && *prefix && *str == *prefix)
	{
		str++;
		prefix++;
	}
	return (!(*prefix));
}
