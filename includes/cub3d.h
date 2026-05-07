#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include <sys/stat.h>


typedef struct s_map
{
	char	**map_array;
	char	**grid;
	int		is_map;
	int		NO_identifier;
	int		SO_identifier;
	int		WE_identifier;
	int		EA_identifier;
	int		F_identifier;
	int		C_identifier;
	int		type_identifiers;
}	t_map;


int		check_args(int ac, char *file_name);
int		map_load(char *file_name, t_map *map);
int		fill_map_array(char *file_name, t_map *map);
int	check_fd(char *str);

// parsing
void	parsing(t_map *map);

// parsing utils
int		is_space(char c);
int		is_empty_line(char *str);
int		is_map(char *line);
int		check_file_extension_xpm(char *str);


#endif