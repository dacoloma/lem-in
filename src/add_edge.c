#include "lem_in.h"


/*
int     search_table(t_room **table, char *name, int size)
{
        long key;
        int res;
        int infinite;

        infinite = 0;
        key = hash(name, size);
        res = key;
        while (1)
        {
            if (res >= size)
                res = 0;
            if(table[res] != NULL)
                if (ft_strcmp(table[res]->name, name) == 0)
                    return(res);
            infinite++;
            if (infinite >= size)
                return (-1); // pas trouve !
            res++;
            // printf("name %s res = %d, infinite = %d, size = %d\n", name, res, infinite, size);
        }
        return(res);
}

static int		set_index(t_graph *graph, char *name)
{
	int	i;

	i = 0;
	while (graph->adjList[i] != NULL)
	{
		if (ft_strcmp(name, graph->adjList[i]->name) == 0)
			return (i);
		i++;
	}
	return (i);
}
*/

void	add_edge(t_graph *graph, int src, int dest)//char *src, char *dest)
{
	t_room *room_src;
	t_room *room_dest;
/*
	// int	index_src;
	// int	index_dest;

	index_src = set_index(graph, src);
	index_dest = set_index(graph, dest);
    // Add edge from src to dest
    room_dest = create_room(dest);
	room_dest->index = index_dest;
    room_dest->next = graph->adjList[index_src];
    graph->adjList[index_src] = room_dest;
 
    // Add edge from dest to src
    room_src = create_room(src);
	room_src->index = index_src;
    room_src->next = graph->adjList[index_dest];
    graph->adjList[index_dest] = room_src;
*/
    // Add edge from src to dest
    room_dest = create_room(dest);
    room_dest->next = graph->adjList[src];
    graph->adjList[src] = room_dest;
 
    // Add edge from dest to src
    room_src = create_room(src);
    room_src->next = graph->adjList[dest];
    graph->adjList[dest] = room_src;
}
