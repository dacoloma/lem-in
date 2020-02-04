#include "lem_in.h"

t_room *create_room(int index)//char *name)
{
    t_room *newRoom = (t_room *)malloc(sizeof(t_room));
	if (newRoom == NULL)
		return (NULL);
    // newRoom->name = name;
	newRoom->index = index;//-1;
    newRoom->next = NULL;
    return newRoom;
}
