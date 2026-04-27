#include "cub3d.h"

void	read_map_file(char *file_name, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		free(line);
		i++;
	}
	map->map_array = malloc(sizeof(char *) * (i + 1));
	if (!map->map_array)
	{
		printf("Error: Malloc\n");
		return ;
	}
	close(fd);
	i = 0;
	fd = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map->map_array[i] = ft_strdup(line);
		printf("%s", map->map_array[i]);
		free(line);
		i++;
	}
	map->map_array[i] = NULL;
	close(fd);
}

int	parsing(char *file_name, t_map *map)
{
	int i = 0;
	read_map_file(file_name, map);
}
