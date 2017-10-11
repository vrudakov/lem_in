#include "./includes/lem-in.h"

const void swap(t_list *a, t_list *b)
{
	void *temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void bubble_sort(t_list *start)
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
			if (calc_room(ptr1->content) > calc_room(ptr1->next->content))
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}
