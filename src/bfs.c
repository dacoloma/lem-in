#include "lem_in.h"

static int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
static void	ft_set_par_dist(t_graph *graph)
{
	int	i;
	
	i = 0;
	while (i < graph->num_vertices)
	{
		graph->distance[i] = 0;
		graph->parent[i] = -1;
		i++;
	}
}

int	bfs(t_graph *graph, int start, int dest)
{
	t_queue	*queue;
	int		current;
	t_room	*tmp;
	int		adjVertex;

	ft_set_par_dist(graph);
	queue = create_queue();
	graph->start = start;
	graph->dest = dest;
	enqueue(queue, start);
	graph->parent[start] = -1;
	graph->distance[start] = INT_MAX;
	// graph->visited[start] = 1;
	// graph->distance[start] = 0;
	while (is_empty(queue) == NOT_EMPTY)
	{
		print_queue(queue);
		// Get first element in queue 
		current = dequeue(queue);
		ft_printf("\nVisited %d\n", current);

		// Get list of adjacent of current node
		tmp = graph->adjList[current];
		while (tmp != NULL)
		{
			// Get node of adjacent list
			adjVertex = tmp->index;

			// if(graph->visited[adjVertex] == 0)
			// If node not visited and doesn't have a parent yet
			if(graph->parent[adjVertex] == -1)
			{
				ft_printf("cost[%d][%d] = %d\n", current, tmp->index, graph->cost[current][tmp->index]);
				ft_printf("flow[%d][%d] = %d\n", current, tmp->index, graph->flow_passed[current][tmp->index]);
				if (graph->cost[current][tmp->index] - graph->flow_passed[current][tmp->index] > 0)
				{
			ft_printf("\nparent[%d] = %d\n", adjVertex, graph->parent[adjVertex]);
					// Set node as visited by setting a parent
					graph->parent[adjVertex] = current;
					// graph->visited[adjVertex] = 1;
					// graph->distance[adjVertex] = graph->distance[current] + 1;
					graph->distance[adjVertex] = get_min(graph->distance[current],
						graph->cost[current][adjVertex] - graph->flow_passed[current][tmp->index]);
					graph->parent[adjVertex] = current;
					if (adjVertex == dest)
						return (graph->distance[dest]);
					enqueue(queue, adjVertex);
				}
			}
			tmp = tmp->next;
		}
    }
	ft_printf("\nDEBUG\n");
	return (0);
}
