#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	*map;

	file_name = av[1];
	if (!check_args(ac, file_name))
		exit (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (!map_load(file_name, map))
		exit (1);
	return (0);
}