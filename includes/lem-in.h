#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H
# include "../libft/includes/libft.h"
#define START 1
#define END 2
#define NONE 0

# define FILE "./map.txt"

typedef	struct	s_m
{
	t_list	*in_lst;
	t_list	*rooms;
	char 	*start;
	char 	*end;

	int 	ant;
	int 	fd;

}				t_m;

typedef struct	s_room
{
	char	*name;
	t_list	*n;
	int 	status;
}				t_room;

typedef	struct	s_log
{
	int		ac;
	int		start;
	int		end;
	int 	lin;
	int 	room;

}				t_log;

#endif //LEM_IN_LEM_IN_H
