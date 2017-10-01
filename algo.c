# include "includes/lem-in.h"

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
	char **split;
	int i;
	int c;

	split = ft_strsplit(path, '#');
	i = 0;
	c = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], n) == 0)
		{
			c = 1;
		}
		free(split[i]);
		i++;
	}
	return (c);
}

t_list			*get_node_by_name(char *name)
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

int	  	find_apath(t_room *room, char *c_path)
{
	t_list	*neighbours;
	t_room	*neighbour;

	neighbours = room->n;
	c_path = ft_append(c_path, room->name,
					 ft_strlen(c_path), ft_strlen(room->name) + 1);
	c_path = ft_append(c_path, "#", ft_strlen(c_path), 1);
	if (room->status == END)
	{
		if (!(ft_lstaddend(&(g_m.apath), ft_lstnew(c_path, ft_strlen(c_path) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		return (1);
	}
	while (neighbours)
	{
		neighbour = get_node_by_name(neighbours->content)->content;
		if (n_in_str(c_path, neighbour->name))
		{
			neighbours = neighbours->next;
			continue ;
		}
		neighbours = neighbours->next;
		find_apath(neighbour, ft_strdup(c_path));
	}
	return (0);
}