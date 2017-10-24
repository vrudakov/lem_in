/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:08:33 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/14 19:28:17 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_append(char *s1, char const *s2, size_t len, size_t len2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(len + len2 + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int		n_in_str(char *path, char *n)
{
	char	**split;
	int		i;
	int		c;

	split = ft_strsplit(path, '#');
	i = 0;
	c = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], n) == 0)
		{
			c = 1;
		}
		i++;
	}
	free_split(split);
	return (c);
}

t_list	*get_node_by_name(char *name)
{
	t_list *temp;
	t_room *room;

	temp = g_m.rooms;
	while (temp)
	{
		room = temp->content;
		if (!ft_strcmp(room->name, name))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	check_neighbours(t_list *neighbours, char *path)
{
	t_room	*neighbour;

	while (neighbours)
	{
		neighbour = get_node_by_name(neighbours->content)->content;
		if (n_in_str(path, neighbour->name))
		{
			neighbours = neighbours->next;
			continue ;
		}
		neighbours = neighbours->next;
		if (g_m.n_ways < 5000)
			find_apath(neighbour, ft_strdup(path));
	}
}

int		find_apath(t_room *room, char *path)
{
	t_list	*neighbours;

	neighbours = room->n;
	path = ft_append(path, room->name,
					ft_strlen(path), ft_strlen(room->name) + 1);
	path = ft_append(path, "#", ft_strlen(path), 1);
	if (ft_strcmp(room->name, g_m.end) == 0)
	{
		g_m.pos_way = 1;
		if (!(ft_lstaddend(&(g_m.apath), ft_lstnew(path, ft_strlen(path) + 1))))
			lemin_error("File's malloc failure");
		free(path);
		g_m.n_ways++;
		if (g_m.n_ways < 100000)
			return (0);
		return (1);
	}
	check_neighbours(neighbours, path);
	free(path);
	return (0);
}
