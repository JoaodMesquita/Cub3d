#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "error_messages.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include <sys/stat.h>

typedef struct	s_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

}	t_texture;

typedef struct	s_map
{
	char		**map_array;
	char		**grid;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	int			is_map;
	int			player_count;
	int			NO_identifier;
	int			SO_identifier;
	int			WE_identifier;
	int			EA_identifier;
	int			F_identifier;
	int			C_identifier;
	int			type_identifiers;
	t_texture	textures;
}	t_map;


// input validation
void	check_args(char *file_name);

// map loading
void	map_load(char *file_name, t_map *map);
void	fill_map_array(char *file_name, t_map *map);
int		check_fd(char *str);

// parsing
void	parsing(t_map *map);

// parsing utils
int		is_space(char c);
int		is_empty_line(char *str);
void	check_map_chars(char **map_grid, t_map *map);
void	check_duplicated(t_map *map, int identifier);
void	check_file_extension_xpm(char *path, t_map *map);
int		parsing_map_grid(t_map *map, int start);
int		is_player(char c);
int		get_longest_line(t_map *map);
int		get_map_height(t_map *map);

//free memory

void	free_struct(t_map *map);
void	free_array(char **array);

// error
void	error_exit(char *message);
void	error_free_exit(char *message, t_map *map);
void	error_free_array_and_struct(char *message, t_map *map, char **array);
#endif