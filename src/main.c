#include "lem_in.h"
/*
static char	*get_name(t_graph *graph, int to_find)
{
	int i;

	i = 0;
	while (graph->adjList[i] != NULL)
	{
		if (graph->adjList[i]->index == to_find)
			return (graph->adjList[i]->name);
		i++;
	}
	return (NULL);
}

static void	print_graph(t_graph *graph, int vertices)
{
	int	i;
	t_room	*room;
	char	*room_name;

	i = 0;
	while (i < vertices)
	{
		room_name = get_name(graph, i);
		ft_printf("Room %s linked to : ", room_name);
		room = graph->adjList[i];
		while (room != NULL)
		{
			ft_printf("%s", room->name);
			if (room->next != NULL)
				ft_putchar('-');
			room = room->next;
		}
		ft_putchar('\n');
		i++;
	}
}
*/

static void	print_graph(t_graph *graph, int vertices)
{
	int	i;
	t_room	*room;

	i = 0;
	while (i < vertices)
	{
		ft_printf("Room %d linked to : ", i);
		room = graph->adjList[i];
		while (room != NULL)
		{
			ft_printf("%d", room->index);
			if (room->next != NULL)
				ft_putchar('-');
			room = room->next;
		}
		ft_putchar('\n');
		i++;
	}
}

// static void	print_cost(t_graph *graph)
// {
// 	int	vertices;
// 	int	**cost;
// 	int	i;
// 	int	j;

// 	vertices = graph->num_vertices;
// 	cost = graph->cost;
// 	i = 0;
// 	while (i < vertices)
// 		ft_printf("\t% d", i++);
// 	ft_putchar('\n');
// 	i = 0;
// 	while (i < vertices)
// 	{
// 		ft_printf("% d\t", i);
// 		j = 0;
// 		while (j < vertices)
// 			ft_printf("%d\t", graph->cost[i][j++]);
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

void	ft_exit_sdl(t_graph *graph)
{
	if (graph->visu.renderer != NULL)
		SDL_DestroyRenderer(graph->visu.renderer);
	if (graph->visu.window != NULL)
		SDL_DestroyWindow(graph->visu.window);
	if (graph->visu.window != NULL)
		SDL_DestroyWindow(graph->visu.window);
	if(graph->table != NULL)
		free(graph->table);
	// while (1);
	exit(0);
}

int		ft_error(t_graph *graph)
{
	if (graph->stage != 5)
		return 1;
	return 0;
}

void	ft_exit(t_graph *graph, int error)
{
	if (error == 1)
		ft_putstr("ERROR\n");
	// ft_memdel((void **)&graph->rooms);
	// ft_memdel((void **)&l);
	ft_exit_sdl(graph);
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
	int		max_flow;

	vertices = 8;
	graph = create_graph(vertices);

	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
	add_edge(graph, 2, 5);
	add_edge(graph, 2, 6);
	add_edge(graph, 4, 7);
	add_edge(graph, 7, 3);

	/*
	add_edge(graph, "AA", "BB");
	add_edge(graph, "AA", "CC");
	add_edge(graph, "BB", "CC");
    add_edge(graph, "BB", "EE");
    add_edge(graph, "BB", "DD");
    add_edge(graph, "CC", "EE");
    add_edge(graph, "DD", "EE");
	*/
	// print_cost(graph);
	print_graph(graph, vertices);
	int start, end;

	start = 0;
	end = 3;
	// bfs(graph, start, end);
	// print_path(graph);
	max_flow = edmonds_karp(graph, start, end);
	ft_printf("max flow = %d\n", max_flow);
	return (0);

}
