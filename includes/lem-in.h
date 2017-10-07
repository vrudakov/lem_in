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
	t_list	*apath;
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

t_m		g_m;

typedef struct	s_pack
{
	t_list	*parll; // list of all parallel path
	int 	cap;
	int 	*iarr;
}				t_pack;


void	check_comment(char *line, t_log *log);
void 	check_end(char *line, t_log *log);
void	check_start(char *line, t_log *log);
void	check_connection(char	*conn);
int		find_room(char *room, char *neighbor, int s);
void	free_split(char **split, int i);
int		lemin_error(t_m *m, char *s);
int		check_room(char *line, int action, t_log *log);
int 	check_room_list(char *in_room);
int		get_ant_num(char *ant_num, t_log *log);

t_list			*get_node_by_name(char *name);
int	  	find_apath(t_room *room, char *c_path);
void	find_all_path();
void	get_pack();
int 	calc_room(char *path);
void	swap(t_list *a, t_list *b);

int		parallels(t_list	*ways, t_list	*ways_n);
#endif //LEM_IN_LEM_IN_H
