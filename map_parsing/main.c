#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

//abrir o fd do mapa;
//verificar extensao do ficheiro: ".cub";
//mapa so pode conter 6 carateres: 1,0,N,S,E,W
//tem de estar rodeado por paredes (1);

int	check_fd(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1 )
	{
		perror("Error");
		exit(1);
	}
	return (0);
}
int	check_file_extension(char *str)
{
	char *file_extension;

	file_extension = strchr(str, '.');
	if (!file_extension)
	{
		printf("File must end with: '.cub' extension\n");
		exit(1);
	}
	if (strcmp(file_extension, ".cub") == 0)
	{
		printf("map found!\n");
		return (1);
	}
	printf("Wrong file extension!\n");
	return (0);
}

int	check_map()
{
	
}

int	map_parsing(char *str)
{
	if (check_fd(str))
		return (0);
	if (check_file_extension(str))
		return(0);
	/* if (check_map(str))
		return (0); */
	exit (1);
}

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
		return (1);
	return (0);
}