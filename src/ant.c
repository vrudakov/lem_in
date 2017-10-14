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
	char 	*num;

	num = ft_itoa(l);
	ret = malloc(sizeof(t_ant));
	ret->r_split = ft_strsplit(path, '#');
	ret->room = 0;
	ret->name = ft_strjoin("L", num);
	free(num);
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

void	free_ant(t_list **ant)
{
	t_list	*list;
	t_list	*temp;
	t_ant	*tf;

	list = (*ant)->next;
	while (list)
	{
		temp = list->next;
		tf = list->content;
		free(tf->name);
		free_split(tf->r_split);
		free(tf);
		free(list);
		list = temp;
	}
	tf = (*ant)->content;
	free(tf->name);
	free_split(tf->r_split);
	free(tf);
	free(list);
	free(*ant);
	*ant = NULL;
}


void	print_path(t_pack pack)
{
	t_list	*temp;
	t_list	*ants;
	int		i;
	int		na;
	t_ant	*ant;
	t_list	*tofree;

	na = 1;
	ants = NULL;
	tofree = NULL;
	while (g_m.ant)
	{
		temp = pack.parll;
		i = 0;
		while (temp)
		{
			if (pack.iarr[i] > 0)
			{
				ant = create_ant(temp->content, na);
				ft_lstaddend(&(ants), ft_lstnew(ant, sizeof(t_ant)));
				pack.iarr[i]--;
				na++;
				free(ant);
			}
			i++;
			temp = temp->next;
		}
		ant_guide(ants);
	}
	free_ant(&ants);
	free(ants);
}
