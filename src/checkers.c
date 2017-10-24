/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:14:47 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 17:37:07 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_room_list(char *in_room)
{
	t_room	*room;
	t_list	*r_check;

	r_check = g_m.rooms;
	while (r_check)
	{
		room = r_check->content;
		if (!ft_strcmp(room->name, in_room))
		{
			ft_putstr("ERROR: rooms must have unique name");
			exit(EXIT_FAILURE);
		}
		r_check = r_check->next;
	}
	return (0);
}

void	check_start(char *line, t_log *log)
{
	log->start += 1;
	if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
		lemin_error("File's malloc failure");
	if (get_next_line(g_m.fd, &line) > 0 && *line)
	{
		check_room(line, START, log, 0);
		if (!(ft_lstaddend(&(g_m.in_lst),
			ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error("File's malloc failure");
		free(line);
	}
	if (log->start > 1)
	{
		write(1, "ERROR: must be only one start\n", 30);
		exit(EXIT_FAILURE);
	}
}

void	check_end(char *line, t_log *log)
{
	log->end += 1;
	if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
		lemin_error("File's malloc failure");
	if (get_next_line(g_m.fd, &line) > 0 && *line)
	{
		check_room(line, END, log, 0);
		if (!(ft_lstaddend(&(g_m.in_lst),
			ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error("File's malloc failure");
		free(line);
	}
	if (log->end > 1)
	{
		write(1, "ERROR: must be only one end\n", 28);
		exit(EXIT_FAILURE);
	}
}

void	check_comment(char *line, t_log *log)
{
	if (__builtin_strcmp(line, "##start") == 0)
		check_start(line, log);
	else if (__builtin_strcmp(line, "##end") == 0)
		check_end(line, log);
}

void	check_connection(char *conn)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(conn, '-');
	while (split[i] != NULL)
		i++;
	if (i != 2)
	{
		ft_putstr("ERROR: wrong rooms linkage\n");
		free_split(split);
		exit(EXIT_FAILURE);
	}
	find_room(split[0], split[1], 1);
	free_split(split);
}
