#include "cub3d.h"

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
	int	len;

	file_extension = ft_strchr(str, '.');
	if (!file_extension)
	{
		printf("File must end with: '.cub' extension\n");
		return (1);
	}
	len = ft_strlen(file_extension);
	while (*file_extension && len == 4)
	{
		if (ft_strncmp(file_extension, ".cub", 4) == 0)
		{
			printf("map found!\n");
			return (0);
		}
		file_extension++;
	}
	printf("Wrong file extension!\n");
	return (1);
}

/* int	check_map(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	
	
} */

int	map_parsing(char *str)
{
	if (check_fd(str))
		return (0);
	if (check_file_extension(str))
		return(0);
	/* if (check_map(str))
		return (0); */
	else
		return (1);
}