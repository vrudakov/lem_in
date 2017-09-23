#include <printf.h>
#include "./includes/lem-in.h"
t_m		g_m;

void	free_all(t_list *list)
{
	while(list)
	{
		free(list->content);
		list = list->next;
	}
}

int		lemin_error(t_m *m, char *s)
{
	ft_putstr("ERROR: ");
	ft_putendl(s);
//	free_all(m->list);
	exit(-1);
	return (-1);
}

void	free_split(char **split, int i)
{
	int	c;

	c = 0;
	if (i > 0)
	{
		while (c < i)
		{
			free(split[c]);
			c++;
		}
	}
}

int		get_ant_num(char *ant_num, t_log *log)
{
	long long tmp;

	if (!ft_isdigitstr(ant_num))
	{
		ft_putstr("ERROR: string with ants amount must consist only of digits");
		free(ant_num);
		exit(EXIT_FAILURE);
	}
	tmp = ft_atoll(ant_num);
	if (tmp < 1 || tmp > INT_MAX)
	{
		ft_putstr("ERROR: The amount should be within 1 and INT_MAX");
		free(ant_num);
		exit(EXIT_FAILURE);
	}
	log->ac = 1;
	return (int)(tmp);
}

int		find_room(char *room, char *neighbor, int s)
{
	t_list	*tmp;
	t_room	*test;

	tmp = g_m.rooms;
	while (tmp)
	{
		test = tmp->content;
		if (!ft_strcmp(test->name, room))
		{
			if (!(ft_lstaddend(&(test->n) , ft_lstnew(neighbor, ft_strlen(neighbor) + 1))))
				lemin_error(&g_m, "File's malloc failure");
			if (s != 0)
				find_room(neighbor, room, 0);
			return (1);
		}
		tmp = tmp->next;
	}
	lemin_error(&g_m, "ERROR: wrong room name in links list");
	exit(EXIT_FAILURE);
}

void	check_connection(char	*conn)
{
	char **split;
	int i;

	i = 0;
	split = ft_strsplit(conn, '-');
	while (split[i] != NULL)
		i++;
	if (i != 2) {
		ft_putstr("ERROR: wrong rooms linkage\n");
		free_split(split, i);
		exit(EXIT_FAILURE);
	}
	find_room(split[0], split[1], 1);
}

int 	check_room_list(char *in_room)
{
	t_room *room;
	t_list	*r_check;

	r_check = g_m.rooms;
	while (r_check)
	{
		room = r_check->content;
		if (!ft_strcmp(room->name,in_room))
		{
			ft_putstr("ERROR: rooms must have unique name");
			exit(EXIT_FAILURE);
		}
		r_check = r_check->next;
	}
	return (0);
}

int		check_room(char *line, int action)
{
	char	**split;
	int i;
	t_room room;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i == 1 && ft_strchr(split[0], '-'))
	{
		check_connection(split[0]);
		return (1);
	}
	if (i != 3 || !ft_isdigitstr(split[1]) || !ft_isdigitstr(split[2]))
	{
		ft_putstr("ERROR: wrong rooms naming\n");
		free_split(split, i);
		exit(EXIT_FAILURE);
	}
	check_room_list(split[0]);
	room.name = ft_strdup(split[0]);
	room.n = NULL;
	if (action == START)
		g_m.start = ft_strdup(split[0]);
	if (action == END)
		g_m.end = ft_strdup(split[0]);
	free_split(split, i);
	if (!(ft_lstaddend(&(g_m.rooms), ft_lstnew( &room , sizeof(room)))))
		lemin_error(&g_m, "File's malloc failure");
	return (0);
}

void		check_comment(char *line, t_log *log)
{
	if (__builtin_strcmp(line, "##start") == 0)
	{
		log->start += 1;
		if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		if (get_next_line(g_m.fd, &line) > 0 && *line) {
			check_room(line, START);
			if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
				lemin_error(&g_m, "File's malloc failure");
			free(line);
		}
		if (log->start > 1)
		{
			write(1, "ERROR: must be only one start\n", 30);
			exit(EXIT_FAILURE);
		}
	}
	if (__builtin_strcmp(line, "##end") == 0)
	{
		log->end += 1;
		if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		if (get_next_line(g_m.fd, &line) > 0 && *line) {
			check_room(line, END);
			if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
				lemin_error(&g_m, "File's malloc failure");
			free(line);
		}
		if (log->end > 1)
		{
			write(1, "ERROR: must be only one end\n", 28);
			exit(EXIT_FAILURE);
		}
	}
}

void	map_in()
{
	char	*line;
	t_log	log;


	log.ac = 0;
	log.end = 0;
	log.start = 0;
	log.lin = 0;
	log.room = 0;
	while (get_next_line(g_m.fd, &line) > 0 && *line)
	{
		if (!ft_strcmp(line, ""))
			lemin_error(&g_m, "line can't be empty");
		if (line[0] == '#') {
			check_comment(line, &log);
		}
		if (log.room == 0 && line[0] != '#' && line[0] != 'L' && g_m.ant != 0) {
			/*log.room = */check_room(line, NONE);
		}
		if (log.ac == 0)
			g_m.ant = get_ant_num(line, &log);
		if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end") &&
				!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		free(line);
	}
	t_list *plist;

	plist = g_m.in_lst;
	while (plist)
	{
		ft_putstr(plist->content);
		ft_putstr("\n");
		plist = plist->next;
	}
	plist = g_m.in_lst;
	t_list *tmp;
	tmp = g_m.rooms;
	t_room  *r;
	/* проверка имен комнат.
	while (tmp)
	{
		r = tmp->content;
		printf("%s\n", r->name);
		tmp = tmp->next;
	}
	 */
	while (g_m.rooms)
	{
		r = g_m.rooms->content;
		printf("%s -> ", r->name);
		while (r->n)
		{
			printf(" | %s | ", r->n->content);
			r->n = r->n->next;
		}
		printf("\n");
		g_m.rooms = g_m.rooms->next;
	}


}


int		main(void)
{


	g_m.fd = open ("map.txt", O_RDONLY);
	if(g_m.fd < 0) {
		ft_putstr("can not open");
		return (0);
	}
	g_m.in_lst = NULL;
	g_m.ant = 0;
//	parcer(&m);
	map_in();
}

проверить чтоб был start и end и чтоб не было их по 2