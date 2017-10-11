#include <printf.h>
#include <zconf.h>
#include "./includes/lem-in.h"

int		unique(t_list  *start)
{
	t_list *ptr1;
	t_list *ptr2;

	ptr1 = start;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ft_strcmp(ptr1->content, ptr2->content) == 0)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

int		parallels(t_list	*ways, t_list	*ways_n)
{
	char *all;
	char **split;
	t_list	*temp;
	int i;

	temp = NULL;
	all = ft_strjoin(ways->content, ways_n->content);
	split = ft_strsplit(all, '#');
	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strcmp(split[i], g_m.start) == 0 || ft_strcmp(split[i], g_m.end) == 0 )
		{
			free(split[i]);
			i++;
			continue ;
		}
		if (!(ft_lstaddend(&(temp), ft_lstnew(split[i], ft_strlen(split[i]) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		free(split[i]);
		i++;
	}
	return (unique(temp));
}

int		check_parall(t_list *list, t_list *test)
{
	while (list)
	{
		if(!parallels(list, test))
			return (0);
		list = list->next;
	}
	return (1);
}

void	pathfinder(t_list	*ways, t_list	*ways_n)
{
	while(ways_n)
	{
		if (check_parall(ways, ways_n))
			ft_lstaddend(&(ways), ft_lstnew( ways_n->content , ft_strlen(ways_n->content) + 1));
		ways_n = ways_n->next;
	}
}


int get_path_len(const char* path)
{

	int len = 0;
	int i = 0;

	while(path[i] != '\0')
	{
		if (path[i] == '#')
			len++;
		i++;
	}
	return len - 1;
}

int		minpath(t_list *list,const int *iarr)
{
	int 	check;
	t_list	*temp;
	int		ret;
	int 	i;

	i = 0;
	ret = 0;
	check = 0;
	temp = list;
	ret = get_path_len(temp->content) + iarr[i];
	while(temp)
	{
		check = get_path_len(temp->content) + iarr[i];
		if (check < ret)
			ret = check;
		i++;
		temp = temp->next;
	}
	return (ret);
}

int 	maxpath(t_list *list,const int *iarr)
{
	int 	check;
	t_list	*temp;
	int		ret;
	int 	i;

	i = 0;
	ret = 0;
	check = 0;
	temp = list;
	ret = 1;
	while(temp)
	{
		check = get_path_len(temp->content) + iarr[i];
		if (check > ret && iarr[i] != 0)
			ret = check;
		i++;
		temp = temp->next;
	}
	return (ret);
}


void	calc_throughput(t_pack *pack_in)
{
    int     ant_t;
	t_list	*ways;
	int 	minlist;
	int 	i;

	i = 0;
	pack_in->iarr = malloc(sizeof(int) * ft_lstsize(pack_in->parll));
	while (i < ft_lstsize(pack_in->parll))
		pack_in->iarr[i++] = 0;
	ant_t = g_m.ant;
	while (ant_t)
	{
		minlist = minpath(pack_in->parll, pack_in->iarr);
		ways = pack_in->parll;
		i = 0;
		while (ways)
		{
			if (get_path_len(ways->content) + pack_in->iarr[i] <= minlist)
			{
				pack_in->iarr[i] += 1;
				ant_t--;
				break ;
			}
			i++;
			ways = ways->next;
		}
	}
	pack_in->cap = maxpath(pack_in->parll, pack_in->iarr) - 1;
}

t_pack	minpack(t_pack *pack,int size)
{
	int	i;
	int m;
	int cap;

	m = 0;
	i = 0;
	cap = pack->cap;
	while (i < size)
	{
		if (cap > pack[i].cap)
		{
			cap = pack[i].cap;
			m = i;
		}
		i++;
	}
	return (pack[m]);
}

typedef struct 	s_ant
{
	int 	room;
	char 	**r_split;
	char 	*name;
	int 	fin;
}				t_ant;

t_ant	*create_ant(char *path, int	l)
{
	t_ant	*ret;

	ret = malloc(sizeof(t_ant));
	ret->fin = 1;
	ret->r_split = ft_strsplit(path, '#');
	ret->room = 0;
	ret->name = ft_strjoin("L", ft_itoa(l));
	return (ret);
}
void	ant_guide(t_list *list)
{
	t_ant	*ant;
	while (list)
	{
		ant = list->content;
		if (ft_strcmp(ant->r_split[ant->room], g_m.end))
		{
			ant->room++;
			ft_putstr(ant->name);
			ft_putchar('-');
			ft_putstr(ant->r_split[ant->room]);
			ft_putchar(' ');
			if (!ft_strcmp(ant->r_split[ant->room], g_m.end))
				g_m.ant--;
		}
		list = list->next;
	}
	ft_putchar('\n');
}

void	print_path(t_pack pack)
{
	t_list	*temp;
	t_list	*ants;
	int 	i;
	int 	na;

	na = 1;
	ants = NULL;
	while (g_m.ant)
	{
		temp = pack.parll;
		i = 0;
		while (temp)
		{
			if (pack.iarr[i] > 0)
			{
				ft_lstaddend(&(ants), ft_lstnew(create_ant(temp->content, na), sizeof(t_ant)));
				pack.iarr[i]--;
				na++;
			}
			i++;
			temp = temp->next;
		}
		ant_guide(ants);
	}
}

void	get_pack()
{
	t_list *ways;
	t_list *ways_n;
	t_pack *pack;
	int i;
	int size;

	ways = g_m.apath;
	size = ft_lstsize(ways);
	pack = (t_pack *) malloc(sizeof(t_pack) * size);
	i = 0;
	while (i < size)
	{
		ways_n = g_m.apath;
		pack[i].parll = ft_lstnew(ways->content, ft_strlen(ways->content) + 1);
		pathfinder(pack[i].parll, ways_n);
		calc_throughput(&pack[i]);
		i++;
		ways = ways->next;
	}
	print_path(minpack(pack, size));
}


