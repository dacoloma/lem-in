#include "lem_in.h"

void	bfs(t_graph *graph, int start)
{
	t_queue	*queue;
	int		currentVertex;
	t_room	*tmp;
	int		adjVertex;

	queue = create_queue();
	graph->visited[start] = 1;
	enqueue(queue, start);
	while (is_empty(queue) == NOT_EMPTY)
	{
		print_queue(queue);
		currentVertex = dequeue(queue);
        ft_printf("\nVisited %d\n", currentVertex);
		tmp = graph->adjList[currentVertex];
    
       while (tmp != NULL) {
            adjVertex = tmp->vertex;
            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            tmp = tmp->next;
       }
    }
}
