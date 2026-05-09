#include "cub3d.h"

void error_exit(char *message, t_map *map)
{
	printf("Error\n%s\n", message);
	free_struct(map);
	exit(1);
}

void error_free_array_exit(char *message, char **memory, t_map* map)
{
	free_array(memory);
	error_exit(message, map);
}