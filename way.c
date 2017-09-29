#include <printf.h>
#include "./includes/lem-in.h"


int		unique(t_list  *start)
{
	int swapped;
	t_list *ptr1;
	t_list *lptr;

	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ft_strcmp(ptr1->content, ptr1->next->content) == 0)
				return (0);
//			if (calc_room(ptr1->content) > calc_room(ptr1->next->content))
//			{
//				swap(ptr1, ptr1->next);
//				swapped = 1;
//			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	return (1);
}

//проверить на паралельность пути , методом пузырьковой сортировки. Удалить начало и старт;

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

int		pathfinder(t_list	*ways, t_list	*ways_n)
{
	int	step;
	int c;
	int ant_c;

	c = 0;
	step = 0;
	ant_c = g_m.ant;
	while (1)
	{

		step++;

		ant_c - c;
		if (ant_c == 0)
			return step;
	}
}

typedef struct s_pack
{
	char	*c_way;
	t_list	*parll;
	int 	cap;
}		t_pack;

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (ft_lstsize(lst->next) + 1);
	return (0);
}

void	get_pack()
{
	t_list	*ways;
	t_list	*ways_n;
	t_pack	*pack;

	ways = g_m.apath;
	pack = (t_pack*)malloc(sizeof(t_pack) * ft_lstsize(ways));
	pack->cap = g_m.ant + calc_room(ways->content) - 1;
	printf("cap -> %d\n", pack->cap);
	printf("cap -> %d\n", ft_lstsize(ways));
	while(ways)
	{

		ways_n = ways->next;
		while(ways_n)
		{
			pathfinder(ways, ways_n);
			ways_n = ways_n->next;
		}
		ways = ways->next;
	}

}