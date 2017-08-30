#include "./includes/lem-in.h"
void	free_all()
{

}
int		ft_error(t_m *m, char *s)
{
	ft_putstr("ERROR: ");
	ft_putendl(s);
//	free_all(m->r, m->t, m->f, NULL);
	exit(-1);
	return (-1);
}

int 	ant_num(t_m *m)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (!(ft_lstaddend(&(m->list), ft_lstnew(line, ft_strlen(line) + 1))))
//				ft_error(e, "File's malloc failure");
			write(1, "ERROR\n", 6);
		m->ant = (ft_isdigitstr(line) ? ft_atoi(line) : 0);
		free(line);
		if (m->ant < 1)
//				ft_error(m, "Invalid ants number");
			write(1, "ERROR\n", 6);
	}
	return (1);
}

void	parcer(t_m *m)
{
	char	*line;
	int		room;

	room = ant_num(m);
	while (get_next_line(0, &line) > 0 && *line)
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


int		main(void)
{
	t_m		m;
	m.list = NULL;
	parcer(&m);
}