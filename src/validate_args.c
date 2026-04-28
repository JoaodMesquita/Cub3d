#include "cub3d.h"

//abrir o fd do mapa;
//verificar extensao do ficheiro: ".cub";
//mapa so pode conter 6 carateres: 1,0,N,S,E,W
//tem de estar rodeado por paredes (1);
//separar config do mapa

// verificar se o ficheiro tem permissoe

int	is_directory(char *file_name)
{
	struct stat sb;

	if (stat(file_name, &sb) == -1)
		return (0);
	if (S_ISDIR(sb.st_mode))
	{
		printf("Its's a directory\n");
		return (1);
	}
	return (0);
}

int	check_fd(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1 )
	{
		perror("Error");
		return(1);
	}
	close(fd);
	return (0);
}

int	check_file_extension(char *str)
{
	char	*file_extension;
	int		len;

	file_extension = ft_strrchr(str, '/');
		file_extension++;
	file_extension = ft_strchr(file_extension, '.');
	if (!file_extension)
	{
		printf("File must end with: '.cub' extension\n");
		return (1);
	}
	len = ft_strlen(file_extension);
	if ((ft_strncmp(file_extension, ".cub", 4) == 0) && len == 4)
			return (0);
	printf("Wrong file extension!\n");
	return (1);
}

int	check_args(int ac, char *file_name)
{
	if (ac != 2)
	{
		printf("Invalid arguments\n");
		return(0);
	}
	else if (is_directory(file_name))
		return (0);
	else if (check_fd(file_name))
		return (0);
	else if (check_file_extension(file_name))
		return(0);
	else
		return (1);
}
