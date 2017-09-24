#include "./includes/lem-in.h"

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

int		find_room(char *room, char *neighbor, int s) {
	t_list *tmp;
	t_room *test;

	tmp = g_m.rooms;
	while (tmp) {
		test = tmp->content;
		if (!ft_strcmp(test->name, room)) {
			if (!(ft_lstaddend(&(test->n),
							   ft_lstnew(neighbor, ft_strlen(neighbor) + 1))))
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
