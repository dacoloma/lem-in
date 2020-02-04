#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <SDL.h>
# include <math.h>
# include <limits.h>

# define WIDTH 1000
# define HEIGHT 1000
# define SIZE 40
# define EMPTY 1
# define NOT_EMPTY 0

typedef struct		s_room
{
	char			*name;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_texture
{
	Uint32			*content;
	SDL_Texture		*texture;
	Uint32			color_tmp;
}					t_texture;

typedef struct		s_queue
{
	int		items[SIZE];
	int		front;
	int		rear;
}					t_queue;

typedef struct s_visu // visu
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Surface		*ant;
	SDL_Surface		*room;
	SDL_Surface		*wallpaper;
	SDL_Texture		*room_t;
	SDL_Texture		*wallpaper_t;
	t_vec2			min;
	t_vec2			max;
	int				active;
}	t_visu;

/*
typedef struct		s_l
{
	t_visu			visu;
	t_room			*rooms;//list chaine de rooms
	int				nb_ants;//nombres de fourmis
	int				nb_rooms;//nombre salles
	int				nb_rooms_check;
	int				stage;
	int				nb_paths;
	char			*start;
	char			*end;
	t_room			**table;//tableau de hach de rooms
	t_room			**pile;
	t_path			*allpaths;
	t_path			*paths;
}						t_l;
*/

typedef struct		s_graph
{
	int				*visited;
	t_room			**adjList;
	int				num_vertices;
	int				**cost;
	int				**flow_passed;
	int				start;
	int				dest;

	t_visu			visu;
	t_room			**table;//tableau de hach de rooms
	int				stage;
	int				*distance;
	int				*parent;
}					t_graph;

t_graph				*create_graph(int vertices);
t_room				*create_room(int index);//char *name);
void				add_edge(t_graph *graph, int src, int dest);//char *src, char *dest);
t_queue				*create_queue(void);
void				enqueue(t_queue *queue, int value);
int					dequeue(t_queue *queue);
int					is_empty(t_queue *queue);
void				print_queue(t_queue *queue);
// void				bfs(t_graph *graph, int start);
int					bfs(t_graph *graph, int start, int dest);
t_graph				read_stdin(t_graph *graph);
t_graph				init(t_graph *graph);
void				ft_exit(t_graph *graph, int error);
void				ft_exit_sdl(t_graph *graph);
void				initialize_sdl(t_graph *graph);
void				update_image(t_graph *graph, t_texture *tex);
void				set_pixel(t_texture *text, Uint32 color, t_vec2 coord);
t_texture			black(t_texture tex);
t_graph				render(t_graph *graph);
int					check_fill_links(t_graph *graph, char *line);
int					check_fill_rooms(t_graph *graph, char **split, int mode, int start);
void				free_split(char **split);
void   				hach_table(t_graph *graph);
void  				find_paths(t_graph *graph, int i);
void 				max_paths(t_graph *graph, int start, int end);
int 			    search_table(t_room **table, char *name, int size);//trouve l'index dans le tableau **table de la room "name"
// t_path				do_you_know_the_way(t_graph *graph, int i);
void 				apply_sdl(t_graph *graph);
int					edmonds_karp(t_graph *graph, int start, int end);
#endif
