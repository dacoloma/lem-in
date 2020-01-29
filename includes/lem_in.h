#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define WIDTH 1000
# define HEIGHT 1000
# define SIZE 40
# define EMPTY 1
# define NOT_EMPTY 0

typedef struct		s_room
{
	int				vertex;
	struct s_room	*next;
}					t_room;

typedef struct		s_queue
{
	int		items[SIZE];
	int		front;
	int		rear;
}					t_queue;

typedef struct		s_graph
{
	int		*visited;
	t_room	**adjList;
	int		num_vertices;
}					t_graph;

t_graph				*create_graph(int vertices);
t_room				*create_room(int v);
void				add_edge(t_graph *graph, int src, int dest);
t_queue				*create_queue(void);
void				enqueue(t_queue *queue, int value);
int					dequeue(t_queue *queue);
int					is_empty(t_queue *queue);
void				print_queue(t_queue *queue);
void				bfs(t_graph *graph, int start);
#endif
