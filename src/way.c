/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:12:55 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 17:55:42 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../includes/lem_in.h"

void	allocation_ants(t_pack *pack_in)
{
	int		minlist;
	int		i;
	t_list	*ways;
	int		ant_t;

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
}

void	calc_throughput(t_pack *pack_in)
{
	int		i;

	i = 0;
	pack_in->iarr = malloc(sizeof(int) * ft_lstsize(pack_in->parll));
	while (i < ft_lstsize(pack_in->parll))
		pack_in->iarr[i++] = 0;
	allocation_ants(pack_in);
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
	free(pack);
}
