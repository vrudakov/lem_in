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
			ft_lstaddend(&(ways), ft_lstnew( ways_n->content , ft_strlen(ways_n->content) + 1 ));
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


int get_counter(t_list *pack_ways, int counter, int iteration)
{
	t_list *temp;

	temp = pack_ways;

	while (temp != NULL)
	{
//		printf("len of path %s is %i\n", (char *) temp->content, get_path_len(temp->content));
		if (iteration == get_path_len(temp->content))
			counter++;
		temp = temp->next;
	}
	return counter;
}

int get_path_len(char* path)
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

void	calc_throughput_t(t_pack *pack)
{
	t_list	*ways;
	int		cap;
	char 	*str;
	int 	sh;
	int 	w;
	int 	i;

	w = 0;
//	ways = pack->parll;
	cap = 0;
	/*while (ways)
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
	printf("cap -->>> %d \n", cap);
	*/
	int ant_number = g_m.ant;
	int flow_cap = 0;
	int counter = 0;

/*

	while (ant_number >= 0)
	{
		flow_cap++;
		counter = get_counter(pack->parll, counter, flow_cap);
		ant_number = ant_number - counter;

	}
	printf("cap -->>> %d \n", flow_cap);
 */
}

int		minpath(t_list *list)
{
	int 	check;
	t_list	*temp;
	int		ret;

	ret = 0;
	check = 0;
	temp = list;
	ret = get_path_len(temp->content);
	while(temp)
	{
		check = get_path_len(temp->content);
		if (check < ret)
			ret = check;
		temp = temp->next;
	}
	return (ret);
}




void	calc_throughput(t_pack *pack_in)
{
    int     ant_t;
	t_list	*ways;
	int 	minlist;


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
//		pack[i].parll->ant_t = 0;
		pathfinder(pack[i].parll, ways_n);
		calc_throughput(&pack[i]);
		i++;
		ways = ways->next;
	}

}


