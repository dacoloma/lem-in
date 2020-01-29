#include "lem_in.h"

t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->front = -1;
	queue->rear = -1;
	return (queue);
}