#include "lem_in.h"

int	edmonds_karp(t_graph *graph, int start, int end)
{
	int	flow;
	int max_flow;
	int	current;
	int	prev;

	max_flow = 0;
	while (1)
	{
		flow = bfs(graph, start, end);
		if (flow == 0)
			break;
		max_flow += flow;
		current = end;
		while (current != start)
		{
			prev = graph->parent[current];
			graph->flow_passed[prev][current] += flow;
			graph->flow_passed[current][prev] -= flow;
			current = prev;
		}
	}
	return (max_flow);
}
