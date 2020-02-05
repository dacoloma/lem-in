#include "lem_in.h"

t_graph	*create_graph(int vertices)
{
	t_graph	*graph;
	int		i;
	int		j;

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
	graph->distance = (int *)malloc(sizeof(int) * vertices);
	if (graph->distance == NULL)
		return (NULL);
	graph->parent = (int *)malloc(sizeof(int) * vertices);
	if (graph->parent == NULL)
		return (NULL);
	graph->cost = (int **)malloc(sizeof(int *) * vertices);
	if (graph->cost == NULL)
		return (NULL);
	graph->flow_passed = (int **)malloc(sizeof(int *) * vertices);
	if (graph->flow_passed == NULL)
		return (NULL);
	i = 0;
	while (i < vertices)
	{
		graph->adjList[i] = NULL;
		graph->visited[i] = 0;
		graph->cost[i] = (int *)malloc(sizeof(int) * vertices);
		if (graph->cost[i] == NULL)
			return (NULL);
		graph->flow_passed[i] = (int *)malloc(sizeof(int) * vertices);
		if (graph->flow_passed[i] == NULL)
			return (NULL);
		j = 0;
		while (j < vertices)
		{
			graph->cost[i][j] = 1;
			graph->flow_passed[i][j] = 0;
			j++;
		}
		graph->visited[i] = 0;
		// graph->distance[i] = INT_MAX;
		graph->distance[i] = 0;
		graph->parent[i] = -1;
		i++;
	}
	// i = 0;
	// while (i < vertices)
	// {
		
	// 	i++;
	// }
	return (graph);
}