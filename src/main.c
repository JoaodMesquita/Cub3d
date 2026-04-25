#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*map;

	if (ac != 2)
	{
		printf("Invalid arguments\n");
		return(1);
	}
	map = av[1];
	if (!map_parsing(map))
		exit (1);
	return (0);
}