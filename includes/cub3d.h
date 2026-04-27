#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map_array;
	int		height;
}	t_map;


int	check_args(int ac, char *file_name);
int	parsing(char *file_name, t_map *map);
#endif