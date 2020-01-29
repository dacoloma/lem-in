#include "lem_in.h"

void add_edge(t_graph *graph, int src, int dest)
{
    // Add edge from src to dest
    t_room *newRoom = create_room(dest);
    newRoom->next = graph->adjList[src];
    graph->adjList[src] = newRoom;
 
    // Add edge from dest to src
    newRoom = create_room(src);
    newRoom->next = graph->adjList[dest];
    graph->adjList[dest] = newRoom;
}
