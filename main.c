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

int		check_room(char *line, int action)
{
	char	**split;
	int i;
	t_room	room;


	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i != 3 || !ft_isdigitstr(split[1]) || !ft_isdigitstr(split[2]))
	{
		ft_putstr("ERROR: wrong rooms naming\n");
		exit(EXIT_FAILURE);
	}
	room.name = ft_strdup(split[0]);
	if (action == START)
		g_m.start = ft_strdup(split[0]);
	if (action == END)
		g_m.end = ft_strdup(split[0]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	g_m.rooms = ft_lstnew( &room , sizeof(room));
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
		}
		free(line);
		if (log->end > 1)
		{
			write(1, "ERROR: must be only one end\n", 28);
			exit(EXIT_FAILURE);
		}
	}
//	if (log
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
		if (line[0] == '#') {
			check_comment(line, &log);
		}
		if (log.room == 0 && line[0] != '#' && line[0] != 'L' && g_m.ant != 0) {
			log.room = check_room(line, NONE);
		}
		if (log.ac == 0)
			g_m.ant = get_ant_num(line, &log);
		if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
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
}


int		main(void)
{


	g_m.fd = open ("map.txt", O_RDONLY);
	if(g_m.fd < 0)
	{
		ft_putstr("can not open");
		return (0);
	}
	g_m.list = NULL;
	g_m.in_lst = NULL;
	g_m.ant = 0;
//	parcer(&m);
	map_in();
}





void	parcer(t_m *m)
{
	char	*line;
	int		room;

//	room = ant_num(m);
	while (get_next_line(g_m.fd, &line) > 0 && *line)
	{


//		if (ft_strprefix(line, "##"))
//			type = get_room_type(e, line);
//		else if (*line == '#')
//			ft_lstaddend(&(e->f), ft_lstnew(line, ft_strlen(line) + 1));
//		else
//		{
//			if (room)
//				room = parse_room(e, line, type, room);
//			if (!room && !parse_tube(e, line))
//				break ;
//			if (!(ft_lstaddend(&(e->f), ft_lstnew(line, ft_strlen(line) + 1))))
//				ft_error(e, "File's malloc failure");
//			type = 0;
	}
	free(line);
}





int 	ant_num(t_m *m)
{
	char	*line;

	if (get_next_line(m->fd, &line) > 0)
	{
		if (!(ft_lstaddend(&(m->list), ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error(m, "File's malloc failure");
		m->ant = (ft_isdigitstr(line) ? ft_atoi(line) : 0);
		free(line);
		if (m->ant < 1)
			lemin_error(m, "Invalid ants number, first line must be number of ants");
	}
	return (1);
}