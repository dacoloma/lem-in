#include "lem_in.h"

void	print_queue(t_queue *queue)
{
    int i;
	
    if(is_empty(queue) == EMPTY)
	{
        ft_printf("Queue is empty");
    }
	else
	{
        ft_printf("\nQueue contains : ");
		i = queue->front;
		while(i < queue->rear + 1)
		{
			ft_printf("%d ", queue->items[i++]);
        }
    }    
}