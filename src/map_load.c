#include "cub3d.h"

int	ft_count_line(char *file_name)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)))
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**alloc_map_array(int size)
{	
	char **map_array;

	map_array = malloc(sizeof(char *) * (size + 1));
	if (!map_array)
		return (NULL);
	return (map_array);
}

int	fill_map_array(char *file_name, t_map *map)
{
	char	*line;
	int		fd;
	int		i;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map->map_array[i] = ft_strdup(line);
		if (!map->map_array[i])
			return (0);
		printf("%s", map->map_array[i]);
		free(line);
		i++;
	}
	map->map_array[i] = NULL;
	close(fd);
	return (1);
}

int map_load(char *file_name, t_map *map)
{
	int size;

	size = ft_count_line(file_name);
	if (size == 0)
	{
		printf("Empty file!\n");
		return (0);
	}
	map->map_array = alloc_map_array(size);
	if (!map->map_array)
		return (0);
	if (!fill_map_array(file_name, map))
		return(0);
	return (1);
}

