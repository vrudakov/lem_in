#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H
# include "../libft/includes/libft.h"

# define FILE "./map.txt"

typedef	struct	s_m
{
	t_list	*list;
	t_list	*in_lst;

	int 	ant;
	int 	fd;

}				t_m;

typedef	struct	s_log
{
	int		ac;
	int		start;
	int		end;
	int 	lin;
	int 	room;

}				t_log;

#endif //LEM_IN_LEM_IN_H
