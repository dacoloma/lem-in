#include "lem_in.h"

int is_empty(t_queue *queue) {
    if(queue->rear == -1) 
        return EMPTY;
    else 
        return NOT_EMPTY;
}
