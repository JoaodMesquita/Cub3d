#include <stdio.h>

//abrir o fd do mapa;
//verificar extensao do ficheiro: ".cub";
//mapa so pode conter 6 carateres: 1,0,N,S,E,W
//tem de estar rodeado por paredes (1);
int	check_file_extension(char *str)
{
	
}

int	map_parsing(char *str)
{
	check_file_extension(str);
}

int	main(int ac, char **av)
{
	char	*map;

	(void)av;
	if (ac != 2)
	{
		printf("Invalid arguments\n");
		return(1);
	}
	printf("ok!\n");
	map = av[1];
	if (!map_parsing(map))
		return (1);
	return (0);
}