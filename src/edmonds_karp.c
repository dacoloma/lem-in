#include "lem_in.h"

void	print_path(t_graph *graph)
{
	int	tmp;
	int	*path;
	int	i;
	int	len;

	tmp = graph->dest;
	len = 0;
	while (tmp != graph->start)
	{
	ft_printf("parent[%d] = %d\n", tmp, graph->parent[tmp]);
		len++;
		tmp = graph->parent[tmp];
	}
	if (len == 0)
		return ;
	path = (int *)malloc(sizeof(int) * len);
	if (path == NULL)
		return ;
	i = 0;
	tmp = graph->dest;
	while (tmp != graph->start)
	{
		path[i] = tmp;
		i++;
		tmp = graph->parent[tmp];
	}
	path[i] = tmp;
	i = len;
	ft_printf("\nPATH : ");
	while (i >= 0)
	{
		ft_printf("%d ", path[i]);
		i--;
	}
	
	ft_printf("\n");
	free(path);
}

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
		// ft_printf("end = %d\n", end);
		// ft_printf("start = %d\n", start);
		// ft_printf("flow = %d\n", flow);
		while (current != start)
		{
			prev = graph->parent[current];
			graph->flow_passed[prev][current] += flow;
			graph->flow_passed[current][prev] -= flow;
		// ft_printf("flow_passed[%d][%d] += %d == %d\n", prev, current, flow, graph->flow_passed[prev][current]);
		// ft_printf("flow_passed[%d][%d] += %d == %d\n", current, prev, flow, graph->flow_passed[current][prev]);
			current = prev;
		}
		print_path(graph);
	}
	return (max_flow);
}
