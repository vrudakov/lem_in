/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:36:07 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/24 18:16:07 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../includes/lem_in.h"

void	room_err(char **split, t_log *log, int i)
{
	if (i != 3 || !ft_isdigitstr(split[1]) || !ft_isdigitstr(split[2]))
	{
		ft_putstr("ERROR: wrong rooms naming\n");
		free_split(split);
		exit(EXIT_FAILURE);
	}
	if (log->room == 1)
	{
		ft_putstr("ERROR: usage:  number_of_ants -> the_rooms -> the_links\n");
		free_split(split);
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(split[0], '#') || ft_strchr(split[0], '-'))
	{
		ft_putstr("ERROR: name of room cant contain '-' and '#' characters\n");
		free_split(split);
		exit(EXIT_FAILURE);
	}
	if (split[0][0] == 'L' || split[0][0] == '#')
	{
		ft_putstr("room will never start with the char L or the character #\n");
		free_split(split);
		exit(EXIT_FAILURE);
	}
}

int		check_room(char *line, int action, t_log *log, int i)
{
	char	**split;
	t_room	room;

	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i == 1 && ft_strchr(split[0], '-'))
	{
		check_connection(split[0]);
		log->room = 1;
		log->link = 1;
		free_split(split);
		return (1);
	}
	room_err(split, log, i);
	check_room_list(split[0]);
	room.name = ft_strdup(split[0]);
	room.n = NULL;
	if (action == START && log->start != 2)
		g_m.start = ft_strdup(split[0]);
	if (action == END && log->end != 2)
		g_m.end = ft_strdup(split[0]);
	free_split(split);
	ft_lstaddend(&(g_m.rooms), ft_lstnew(&room, sizeof(room)));
	return (0);
}

void	map_in(void)
{
	char	*ln;
	t_log	log;

	init_struct(&log);
	while (get_next_line(g_m.fd, &ln) > 0)
	{
		if (!ft_strcmp(ln, ""))
			lemin_error("ln can't be empty\n");
		if (ln[0] == '#')
			check_comment(ln, &log);
		if (ln[0] != '#' && ln[0] != 'L' && g_m.ant != 0)
			check_room(ln, NONE, &log, 0);
		if (log.ac == 0)
			g_m.ant = get_ant_num(ln, &log);
		if (ft_strcmp(ln, "##start") && ft_strcmp(ln, "##end") &&
			!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(ln, ft_strlen(ln) + 1))))
			lemin_error("File's malloc failure\n");
		free(ln);
	}
	if (log.start == 0 || log.end == 0 || log.link == 0)
	{
		ft_putstr("ERROR: mandatory must be start, end and links\n");
		exit(EXIT_FAILURE);
	}
	free(ln);
}

void	init_gm(void)
{
	g_m.fd = 0;
	g_m.in_lst = NULL;
	g_m.ant = 0;
	g_m.pos_way = 0;
	g_m.n_ways = 0;
}

int		main(void)
{
	t_list	*plist;

	if (read(0, NULL, 0) < 0)
		lemin_error("reading\n");
	init_gm();
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
	if (g_m.pos_way == 0)
	{
		ft_putstr("ERROR: No possible solution\n");
		exit(EXIT_FAILURE);
	}
	bubble_sort(g_m.apath);
	get_pack(0);
}
