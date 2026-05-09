#include "cub3d.h"

void	error_exit(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}


void	error_free_exit(char *message, t_map* map)
{
	free_struct(map);
	error_exit(message);
}