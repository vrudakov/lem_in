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
	printf("set->\n");

	while (ways)
	{
		printf(" %s|\n", ways->content );
		ways = ways->next;

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

void	print_path()
void	get_pack()
{
	t_list *ways;
	t_list *ways_n;
	t_pack *pack;

	ways = g_m.apath;
	pack = (t_pack *) malloc(sizeof(t_pack) * ft_lstsize(ways));
	int i;
	int size;

	i = 0;

	size = ft_lstsize(ways);
	while (i < size)
	{
		ways_n = g_m.apath;
		pack[i].parll = ft_lstnew(ways->content, ft_strlen(ways->content) + 1);
		pathfinder(pack[i].parll, ways_n);
		calc_throughput(&pack[i]);
		printf("cap -> %d\n", pack[i].cap);
		i++;
		ways = ways->next;
	}
	print_path();
}


