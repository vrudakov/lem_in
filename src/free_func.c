/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:11:07 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/24 18:16:35 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_pack(t_pack *pack, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_lstdel(&pack[i].parll, free_list);
		free(pack[i].iarr);
		i++;
	}
}

void	free_split(char **split)
{
	int	c;
	int i;

	c = 0;
	i = 0;
	while (split[i] != NULL)
		i++;
	if (i > 0)
	{
		while (c < i)
		{
			free(split[c]);
			c++;
		}
	}
	free(split);
}

void	free_list(void *mem, size_t size)
{
	(void)size;
	if (mem)
		free(mem);
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
