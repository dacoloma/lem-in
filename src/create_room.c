#include "lem_in.h"

t_room *create_room(int v)
{
    t_room *newRoom = (t_room *)malloc(sizeof(t_room));
	if (newRoom == NULL)
		return (NULL);
    newRoom->vertex = v;
    newRoom->next = NULL;
    return newRoom;
}
