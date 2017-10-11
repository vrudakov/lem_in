/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:12:55 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 14:33:38 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "includes/lem_in.h"

int		unique(t_list *start)
{
	t_list *ptr1;
	t_list *ptr2;

	ptr1 = start;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ft_strcmp(ptr1->content, ptr2->content) == 0)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

int		parallels(t_list *ways, t_list *ways_n)
{
	char	*all;
	char	**s;
	t_list	*temp;
	int		i;

	temp = NULL;
	all = ft_strjoin(ways->content, ways_n->content);
	s = ft_strsplit(all, '#');
	i = 0;
	while (s[i] != NULL)
	{
		if (ft_strcmp(s[i], g_m.start) == 0 || ft_strcmp(s[i], g_m.end) == 0)
		{
			free(s[i]);
			i++;
			continue ;
		}
		if (!(ft_lstaddend(&(temp), ft_lstnew(s[i], ft_strlen(s[i]) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		free(s[i]);
		i++;
	}
	return (unique(temp));
}

int		check_parall(t_list *list, t_list *test)
{
	while (list)
	{
		if (!parallels(list, test))
			return (0);
		list = list->next;
	}
	return (1);
}

void	calc_throughput(t_pack *pack_in)
{
	int		ant_t;
	t_list	*ways;
	int		minlist;
	int		i;

	i = 0;
	pack_in->iarr = malloc(sizeof(int) * ft_lstsize(pack_in->parll));
	while (i < ft_lstsize(pack_in->parll))
		pack_in->iarr[i++] = 0;
	ant_t = g_m.ant;
	while (ant_t)
	{
		minlist = minpath(pack_in->parll, pack_in->iarr);
		ways = pack_in->parll;
		i = 0;
		while (ways)
		{
			if (get_path_len(ways->content) + pack_in->iarr[i] <= minlist)
			{
				pack_in->iarr[i] += 1;
				ant_t--;
				break ;
			}
			i++;
			ways = ways->next;
		}
	}
	pack_in->cap = maxpath(pack_in->parll, pack_in->iarr) - 1;
}

t_pack	minpack(t_pack *pack, int size)
{
	int	i;
	int m;
	int cap;

	m = 0;
	i = 0;
	cap = pack->cap;
	while (i < size)
	{
		if (cap > pack[i].cap)
		{
			cap = pack[i].cap;
			m = i;
		}
		i++;
	}
	return (pack[m]);
}



void	get_pack(void)
{
	t_list	*ways;
	t_list	*ways_n;
	t_pack	*pack;
	int		i;
	int		size;

	ways = g_m.apath;
	size = ft_lstsize(ways);
	pack = (t_pack *)malloc(sizeof(t_pack) * size);
	i = 0;
	while (i < size)
	{
		ways_n = g_m.apath;
		pack[i].parll = ft_lstnew(ways->content, ft_strlen(ways->content) + 1);
		pathfinder(pack[i].parll, ways_n);
		calc_throughput(&pack[i]);
		i++;
		ways = ways->next;
	}
	print_path(minpack(pack, size));
}
