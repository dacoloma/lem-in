#include "lem_in.h"
/*
static void	print_graph(t_graph *graph, int vertices)
{
	int	i;
	t_room	*room;
	
	i = 0;
	while (i < vertices)
	{
		room = graph->adjList[i];
		ft_printf("Room %d linked to : ", i);
		while (room != NULL)
		{
			ft_putnbr(room->vertex);
			if (room->next != NULL)
				ft_putchar('-');
			room = room->next;
		}
		ft_putchar('\n');
		i++;
	}
}
*/
static void	print_cost(t_graph *graph)
{
	int	vertices;
	int	**cost;
	int	i;
	int	j;

	vertices = graph->num_vertices;
	cost = graph->cost;
	i = 0;
	while (i < vertices)
		ft_printf("\t% d", i++);
	ft_putchar('\n');
	i = 0;
	while (i < vertices)
	{
		ft_printf("% d\t", i);
		j = 0;
		while (j < vertices)
			ft_printf("%d\t", graph->cost[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

/*
              3
            / |
           /  |
	0 -- 1 -- 4
	  \  |  /
	   \ | / 
		 2    
*/

int		main(void)
{
	t_graph	*graph;
	int		vertices;

	vertices = 5;
	graph = create_graph(vertices);
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

	print_cost(graph);
	// print_graph(graph, vertices);
	// bfs(graph, 0);

	return (0);
}
