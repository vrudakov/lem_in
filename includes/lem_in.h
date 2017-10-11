/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:00:47 by vrudakov          #+#    #+#             */
/*   Updated: 2017/10/11 15:07:06 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# define START 1
# define END 2
# define NONE 0
# define FILE "./map.txt"

typedef	struct	s_m
{
	t_list	*in_lst;
	t_list	*rooms;
	t_list	*apath;
	char	*start;
	char	*end;
	int		ant;
	int		fd;
}				t_m;

typedef struct	s_room
{
	char	*name;
	t_list	*n;
}				t_room;

typedef	struct	s_log
{
	int		ac;
	int		start;
	int		end;
	int		room;

}				t_log;

t_m		g_m;

typedef struct	s_pack
{
	t_list	*parll;
	int		cap;
	int		*iarr;
}				t_pack;

typedef struct	s_ant
{
	int		room;
	char	**r_split;
	char	*name;
}				t_ant;

void			check_comment(char *line, t_log *log);
void			check_end(char *line, t_log *log);
void			check_start(char *line, t_log *log);
void			check_connection(char	*conn);
int				find_room(char *room, char *neighbor, int s);
void			free_split(char **split, int i);
int				lemin_error(char *s);
int				check_room(char *line, int action, t_log *log);
int				check_room_list(char *in_room);
int				get_ant_num(char *ant_num, t_log *log);

t_list			*get_node_by_name(char *name);
int				find_apath(t_room *room, char *c_path);
void			get_pack();
int				calc_room(char *path);
void			bubble_sort(t_list *start);
int				parallels(t_list	*ways, t_list	*ways_n);
void			init_struct(t_log *log);

int				minpath(t_list *list, const int *iarr);
int				maxpath(t_list *list, const int *iarr);
int				get_path_len(const char *path);
void			pathfinder(t_list *ways, t_list *ways_n);
int				check_parall(t_list *list, t_list *test);
void			print_path(t_pack pack);

#endif
