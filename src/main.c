/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:28 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/18 16:22:41 by grui-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_map *map)
{
	map->mlx = mlx_init(); // criar funcao para iniciar janela/jogo
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "cub3d");
	render_minimap(map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	*map;
	
	if (ac != 2)
	{
		printf("Invalid arguments\n");
		exit (1);
	}
	file_name = av[1];
	check_args(file_name);
	map = ft_calloc(1, sizeof(t_map)); //dar free struct e suas variaveis
	if (!map)
		return (1);
	map_load(file_name, map);
	parsing(map);
	game_init(map);
	free_struct(map);
	return (0);
}
