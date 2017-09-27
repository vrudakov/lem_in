# include "includes/lem-in.h"


void	find_all_path()
{
	char *c_path;
	t_list *croom;
	t_room *room;

	croom = g_m.rooms;
	while (croom)
	{
		room = croom->content;
		if (ft_strcmp(room->name,g_m.start))
		{
			c_path = ft_strjoin("",room->name);
			while (room->n)
			{

				room->n = room->n->next;
			}
		}
		croom = croom->next;
	}

}