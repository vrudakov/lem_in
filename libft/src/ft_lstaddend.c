/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:11:50 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/29 18:16:30 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst || !new)
		return (0);
	list = *alst;
	if (!list)
	{
		*alst = new;
		return (1);
	}
	while (list->next)
		list = list->next;
	list->next = new;
	return (1);
}
