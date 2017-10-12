/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:44:10 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 14:56:25 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant	*create_ant(char *path, int l)
{
	t_ant	*ret;

	ret = malloc(sizeof(t_ant));
	ret->r_split = ft_strsplit(path, '#');
	ret->room = 0;
	ret->name = ft_strjoin("L", ft_itoa(l));
	return (ret);
}

void	ant_guide(t_list *list)
{
	t_ant	*ant;

	while (list)
	{
		ant = list->content;
		if (ft_strcmp(ant->r_split[ant->room], g_m.end))
		{
			ant->room++;
			ft_putstr(ant->name);
			ft_putchar('-');
			ft_putstr(ant->r_split[ant->room]);
			ft_putchar(' ');
			if (!ft_strcmp(ant->r_split[ant->room], g_m.end))
				g_m.ant--;
		}
		list = list->next;
	}
	ft_putchar('\n');
}

void	print_path(t_pack pack)
{
	t_list	*temp;
	t_list	*ants;
	int		i;
	int		na;

	na = 1;
	ants = NULL;
	while (g_m.ant)
	{
		temp = pack.parll;
		i = 0;
		while (temp)
		{
			if (pack.iarr[i] > 0)
			{
				ft_lstaddend(&(ants),
					ft_lstnew(create_ant(temp->content, na), sizeof(t_ant)));
				pack.iarr[i]--;
				na++;
			}
			i++;
			temp = temp->next;
		}
		ant_guide(ants);
	}
}
