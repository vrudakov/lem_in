/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:44:41 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 18:02:37 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long			ft_atoll(const char *str)
{
	long long	n;
	int			sign;

	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
		*str == '\f' || *str == '\v')
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48) % 10;
		++str;
	}
	return (n * sign);
}
