#include "cub3d.h"

void	*draw_minimap(t_map *map, int y, int x)
{
	char *valid_chars;

	valid_chars = "NSEW";
	if (map->grid[y][x] == '1')
		mlx_pixel_put(map->mlx, map->mlx_win, (x * 20), (y * 20), 255);
	if (ft_strchr(valid_chars, map->grid[y][x]))
		mlx_pixel_put(map->mlx, map->mlx_win, (x * 20), (y * 20), 255255255);
	return (0);
}

void	*draw_square(t_map *map, int size, int color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, (map->player_x + i) * 20, map->player_y * 20, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, map->player_x * 20, (map->player_y + i) * 20, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, (map->player_x + size) * 20, (map->player_y + i) * 20, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, (map->player_x + i) * 20, (map->player_y + size) * 20, color);
		i++;
	}
	return (0);
}

void	render_minimap(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	//draw_square(map, 10, 255255255);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_minimap(map, y, x);
			x++;
		}
		y++;
	}
}
