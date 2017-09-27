# include "includes/lem-in.h"


void	find_all_path()
{
	char *c_path;
	t_list *croom;
	t_room *room;
	t_list	*path;

	croom = g_m.rooms;
	while (croom)
	{
		room = croom->content;
		if (ft_strcmp(room->name,g_m.start))
		{
			c_path = ft_strjoin("",room->name);
			while (room->n)
			{
				if (room->status == END)
				{
					if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(c_path, ft_strlen(c_path) + 1))))
						lemin_error(&g_m, "File's malloc failure");
				}

				room->n = room->n->next;
			}
		}
		croom = croom->next;
	}

}


int	  	find_apath(t_room *room, char *c_path)
{

	if (room->status == END)
	{
		if (!(ft_lstaddend(&(g_m.in_lst), ft_lstnew(c_path, ft_strlen(c_path) + 1))))
			lemin_error(&g_m, "File's malloc failure");
		return (1);
	}

	return (0);
}