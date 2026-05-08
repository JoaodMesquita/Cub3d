#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "error_messages.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include <sys/stat.h>


typedef struct s_map
{
	char	**map_array;
	//char	**grid;
	int		is_map;
	int		NO_identifier;
	int		SO_identifier;
	int		WE_identifier;
	int		EA_identifier;
	int		F_identifier;
	int		C_identifier;
	int		type_identifiers;
}	t_map;


// input validation
int		check_args(char *file_name);

// map loading
void	map_load(char *file_name, t_map *map);
void	fill_map_array(char *file_name, t_map *map);
int		check_fd(char *str);

// parsing
void	parsing(t_map *map);

// parsing utils
int		is_space(char c);
int		is_empty_line(char *str);
int		is_map(char *line);
int		check_file_extension_xpm(char *str);

//free memory

void	free_struct(t_map *map);
void	free_array(char **array);

// error
void	error_exit(const char *message);
#endif