#include "lem_in.h"

int dequeue(t_queue *queue)
{
	int item;
    
	if(is_empty(queue) == EMPTY){
        ft_printf("Queue is empty");
        item = -1;
    }
    else{
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear){
            ft_printf("\nResetting queue\n");
            queue->front = queue->rear = -1;
        }
    }
    return item;
}