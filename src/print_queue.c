#include "lem_in.h"

void	print_queue(t_queue *queue)
{
    int i;
	
	i = queue->front;
    if(is_empty(queue) == EMPTY) {
        ft_printf("Queue is empty");
    } else {
        ft_printf("\nQueue contains : ");
        for(i = queue->front; i < queue->rear + 1; i++) {
                ft_printf("%d ", queue->items[i]);
        }
    }    
}