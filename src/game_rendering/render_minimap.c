#include "cub3d.h"

void	*draw_square(t_map *map, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, x + size, y + i, color);
		i++;
	}
	i = 0;
	while (i < size + 1)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, x + i, y + size, color);
		i++;
	}
	return (0);
}

void	*draw_minimap(t_map *map, int y, int x)
{
	char *valid_chars;

	valid_chars = "NSEW";
	/* if (map->grid[y][x] == '1') */
	/* 	mlx_pixel_put(map->mlx, map->mlx_win, (x * 20), (y * 20), 255); */
	/* if (ft_strchr(valid_chars, map->grid[y][x])) */
	/* 	mlx_pixel_put(map->mlx, map->mlx_win, (x * 20), (y * 20), 255255255); */
	if (map->grid[y][x] == '1')
		draw_square(map, x * RATIO, y * RATIO, RATIO, 255);
//	if (ft_strchr(valid_chars, map->grid[y][x]))
	return (0);
}

void	render_minimap(t_map *map)
{
	int	y;
	int	x;

	y = 0;
//	draw_square(map, map->player_x, map->player_y, 10, 255255255);
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
	draw_square(map, map->player_x * RATIO, map->player_y * RATIO, RATIO, 255255255);
}
