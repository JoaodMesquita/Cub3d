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
}	t_map;


int		check_args(int ac, char *file_name);
int		map_load(char *file_name, t_map *map);
int		fill_map_array(char *file_name, t_map *map);
void	parsing(t_map *map);

#endif