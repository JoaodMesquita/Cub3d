#include "cub3d.h"

void	check_identifier(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		printf("OK!\n");
	}
	if (ft_strncmp(str, "SO ", 3) == 0)
	{
		printf("OK!\n");
	}
	if (ft_strncmp(str, "WE ", 3) == 0)
	{
		printf("OK!\n");
	}
	if (ft_strncmp(str, "EA ", 3) == 0)
	{
		printf("OK!\n");
	}
}

int	map_file_config(int fd)
{
	char	*line;
	int		i;

	while ((line = get_next_line(fd)))
	{
		i = 0;
		while (line[i])
		{
			while (line[i] == ' ')
				i++;
			check_identifier(line);
			i++;
		}
		line++;
	}
	return (0);
}

/* int	map_parsing(char *file_name, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	map->grid = malloc(sizeof(char *) * (i + 1));
	if (!map->grid)
	{
		printf("Error: Malloc\n");
		return (1);
	}
	i = 0;
	fd = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map->grid[i] = ft_strdup(line);
		printf("%s", map->grid[i]);
		free(line);
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	return (0);
} */

int	parsing(char *file_name, t_map *map)
{
	int	fd;

	(void)map;
	fd = open(file_name, O_RDONLY);
	if (!map_file_config(fd))
		return (1);
/* 	if (!map_parsing(file_name, map))
		return (1); */
	close(fd);
	return (0);
}
