/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:54:53 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 17:55:21 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_list(void *mem, size_t size)
{
	(void)size;
	if (mem)
		free(mem);
}

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
			{
				ft_lstdel(&start, free_list);
				return (0);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	ft_lstdel(&start, free_list);
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
			i++;
			continue ;
		}
		if (!(ft_lstaddend(&(temp), ft_lstnew(s[i], ft_strlen(s[i]) + 1))))
			lemin_error("File's malloc failure");
		i++;
	}
	free_split(s);
	free(all);
	return (unique(temp));
}
