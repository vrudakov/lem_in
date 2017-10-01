#include <printf.h>
#include "./includes/lem-in.h"


int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (ft_lstsize(lst->next) + 1);
	return (0);
}


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
	char *first;
	char *second;
	t_list	*temp;
	int i;

	first = ways->content;
	first = __DARWIN_NULL;
	temp = NULL;
	all = ft_strjoin(ways->content, ways_n->content);
	split = ft_strsplit(all, '#');
	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strcmp(split[i], g_m.start) == 0 || ft_strcmp(split[i], g_m.end) == 0 )
		{
//			free(split[i]);
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

t_list	*g_path;

int		pathfinder(t_list	*ways, t_list	*ways_n)
{
	int	step;
	int c;
	int ant_c;

	c = 0;
	step = 0;
	ant_c = g_m.ant;
	while(ways_n)
	{
		if (check_parall(ways, ways_n))
			ft_lstaddend(&(ways), ft_lstnew( ways_n->content , sizeof(ways_n->content) + 2));
		ways_n = ways_n->next;
	}
	printf("set->\n");

	while (ways)
	{
		printf(" %s|\n", ways->content );
		ways = ways->next;

	}
		/*
	while (1)
	{

		step++;

		ant_c - c;
		if (ant_c == 0)
			return step;
	}
	 */
}
typedef struct s_pack
{
	char	*c_way;
	t_list	*parll;
	int 	cap;
}		t_pack;

void	calc_throughput(t_pack *pack)
{
	t_list	*ways;
	int		cap;
	char 	*str;
	int 	sh;
	int 	w;
	int 	i;

	w = 0;
	ways = pack->parll;
	cap = 0;
	while (ways)
	{
		i = 0;
		sh = 0;
		w++;
		str = ways->content;
		while(str[i] != '\0')
		{
			if (str[i] == '#')
				sh++;
			i++;
		}
		cap = sh + (g_m.ant / w);
		ways = ways->next;
	}
}

void	get_pack()
{
	t_list *ways;
	t_list *ways_n;
	t_pack *pack;

	ways = g_m.apath;
	pack = (t_pack *) malloc(sizeof(t_pack) * ft_lstsize(ways));
	pack->cap = g_m.ant + calc_room(ways->content) - 1;
	int i;
	int size;

	i = 0;

	size = ft_lstsize(ways);
	while (i < size)
	{
		ways_n = g_m.apath;
		pack[i].parll = ft_lstnew(ways->content, ways->content_size);
		pathfinder(pack[i].parll, ways_n);
		calc_throughput(&pack[i]);
		i++;
		ways = ways->next;
	}
	/*
	while (pack[0].parll)
	{
		printf("%s|\n", pack[0].parll->content);
		pack[0].parll = pack[0].parll->next;
	}*/
}
//	while(ways)
//	{
//		ways_n = g_m.apath;
//		while(ways_n)
//		{
//			pathfinder(ways, ways_n);
//			ways_n = ways_n->next;
//		}
//		ways = ways->next;
//	}

