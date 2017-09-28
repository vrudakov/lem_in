#include <printf.h>
#include "./includes/lem-in.h"


void unique(char **start)
{
	int swapped;
	char *ptr1;
	char *ptr2;
	int 	i;
	int 	j;


	ptr1 = start[0];
	ptr2 = start[1];
	swapped = 1;
	i = 0;
	/*while(ptr1)
	{

		ways_n = ways->next;
		while(ways_n)
		{
			pathfinder(ways, ways_n);
			ways_n = ways_n->next;
		}
		ways = ways->next;
	 }*/
}

проверить на паралельность пути , методом пузырьковой сортировки. Удалить начало и старт;

void	parallels(t_list	*ways, t_list	*ways_n)
{
	char *all;
	char **split;
	char *first;
	char *second;

	first = ways->content;
	first = __DARWIN_NULL;
	all = ft_strjoin(ways->content,ways_n->content);
	split = ft_strsplit(all, '#');


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