/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:36:07 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 15:37:54 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../includes/lem_in.h"

void	room_err(char **split, t_log *log, int i)
{
	if (i != 3 || !ft_isdigitstr(split[1]) || !ft_isdigitstr(split[2]))
	{
		ft_putstr("ERROR: wrong rooms naming\n");
		free_split(split, i);
		exit(EXIT_FAILURE);
	}
	if (log->room == 1)
	{
		ft_putstr("ERROR: usage:  number_of_ants -> the_rooms -> the_links\n");
		free_split(split, i);
		exit(EXIT_FAILURE);
	}
}

int		check_room(char *line, int action, t_log *log)
{
	char	**split;
	int		i;
	t_room	room;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i == 1 && ft_strchr(split[0], '-'))
	{
		check_connection(split[0]);
		log->room = 1;
		log->link = 1;
		return (1);
	}
	room_err(split, log, i);
	check_room_list(split[0]);
	room.name = ft_strdup(split[0]);
	room.n = NULL;
	if (action == START)
		g_m.start = ft_strdup(split[0]);
	if (action == END)
		g_m.end = ft_strdup(split[0]);
	free_split(split, i);
	ft_lstaddend(&(g_m.rooms), ft_lstnew(&room, sizeof(room)));
	return (0);
}

void	map_in(void)
{
	char	*line;
	t_log	log;

	init_struct(&log);
	while (get_next_line(g_m.fd, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			lemin_error("line can't be empty");
		if (line[0] == '#')
			check_comment(line, &log);
		if (line[0] != '#' && line[0] != 'L' && g_m.ant != 0)
			check_room(line, NONE, &log);
		if (log.ac == 0)
			g_m.ant = get_ant_num(line, &log);
		if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end") &&
				!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line,
					ft_strlen(line) + 1))))
			lemin_error("File's malloc failure");
		free(line);
	}
	if (log.start == 0 || log.end == 0 || log.link == 0)
	{
		ft_putstr("ERROR: mandatory must be start, end and links");
		exit(EXIT_FAILURE);
	}
}

int		calc_room(char *path)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(path, '#');
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	return (i);
}

int		main(void)
{
	t_list	*plist;

	g_m.fd = open("map.txt", O_RDONLY);
	g_m.in_lst = NULL;
	g_m.ant = 0;
	map_in();
	plist = g_m.in_lst;
	while (plist)
	{
		ft_putstr(plist->content);
		write(1, "\n", 1);
		plist = plist->next;
	}
	write(1, "\n", 1);
	find_apath(get_node_by_name(g_m.start)->content, ft_strnew(1));
	bubble_sort(g_m.apath);
	get_pack();
}
