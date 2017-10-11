/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:42:17 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 14:56:35 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

int		get_path_len(const char *path)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '#')
			len++;
		i++;
	}
	return (len - 1);
}

void	pathfinder(t_list *ways, t_list *ways_n)
{
	while (ways_n)
	{
		if (check_parall(ways, ways_n))
			ft_lstaddend(&(ways), ft_lstnew(ways_n->content,
											ft_strlen(ways_n->content) + 1));
		ways_n = ways_n->next;
	}
}

int		minpath(t_list *list, const int *iarr)
{
	int		check;
	t_list	*temp;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	check = 0;
	temp = list;
	ret = get_path_len(temp->content) + iarr[i];
	while (temp)
	{
		check = get_path_len(temp->content) + iarr[i];
		if (check < ret)
			ret = check;
		i++;
		temp = temp->next;
	}
	return (ret);
}

int		maxpath(t_list *list, const int *iarr)
{
	int		check;
	t_list	*temp;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	check = 0;
	temp = list;
	ret = 1;
	while (temp)
	{
		check = get_path_len(temp->content) + iarr[i];
		if (check > ret && iarr[i] != 0)
			ret = check;
		i++;
		temp = temp->next;
	}
	return (ret);
}
