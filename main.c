#include "./includes/lem-in.h"
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


long long			ft_atoll(const char *str)
{
	long long	n;
	int			sign;

	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
		   *str == '\f' || *str == '\v')
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48) % 10;
		++str;
	}
	return (n * sign);
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

void	parcer(t_m *m)
{
	char	*line;
	int		room;

	room = ant_num(m);
	while (get_next_line(m->fd, &line) > 0 && *line)
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

void	get_ant_num(t_m *m)
{
	t_list *at;
	long long tmp;

	at = m->in_lst;
	m->in_lst = m->in_lst->next;
	if (!ft_isdigitstr(at->content))
		lemin_error(m, "string with ants amount must consist only of digits");
	tmp = ft_atoll(at->content);
	if (tmp < 0 || tmp > INT_MAX)
		lemin_error(m , "The amount should be within 0 and INT_MAX");
	m->ant = (int)tmp;
	free(at->content);
	at->content = NULL;
	free(at);
}

void	map_in(t_m *m)
{
	char *line;

	while (get_next_line(m->fd, &line) > 0 && *line)
	{
		if (!(ft_lstaddend(&(m->in_lst), ft_lstnew(line, ft_strlen(line) + 1))))
			lemin_error(m, "File's malloc failure");
		free(line);
	}
	t_list *plist;

	plist = m->in_lst;
	while (plist)
	{
		ft_putstr(plist->content);
		ft_putstr("\n");
		plist = plist->next;
	}
	plist = m->in_lst;
	get_ant_num(m);
}

int		main(void)
{
	t_m		m;

	m.fd = open ("map.txt", O_RDONLY);
	if(m.fd < 0)
	{
		ft_putstr("can not open");
		return (0);
	}
	m.list = NULL;
	m.in_lst = NULL;
//	parcer(&m);
	map_in(&m);
}

