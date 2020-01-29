#include "lem_in.h"

void enqueue(t_queue *q, int value)
{
    if(q->rear == SIZE-1)
        ft_printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
