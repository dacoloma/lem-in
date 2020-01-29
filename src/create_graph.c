#include "lem_in.h"

t_graph	*create_graph(int vertices)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (graph == NULL)
		return (NULL);
	graph->num_vertices = vertices;
	graph->adjList = (t_room **)malloc(sizeof(t_room *) * vertices);
	if (graph->adjList == NULL)
		return (NULL);
	graph->visited = (int *)malloc(sizeof(int) * vertices);
	if (graph->visited == NULL)
		return (NULL);
	i = 0;
	while (i < vertices)
	{
		graph->adjList[i] = NULL;
		graph->visited[i] = 0;
		i++;
	}
	return (graph);
}