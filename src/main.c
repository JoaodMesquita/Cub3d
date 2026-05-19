/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:28 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/19 12:21:37 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	*map;
	//void	*mlx;
	//void	*mlx_win;
	
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
	set_player_direction(map);
	printf("posY: %f\n", map->player.posY);
	printf("posX: %f\n", map->player.posX);
	printf("dirY: %f\n", map->player.dirY);
	printf("dirX:%f\n", map->player.dirX);
	//mlx = mlx_init(); // criar funcao para iniciar janela/jogo
	//mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	//mlx_loop(mlx);
	free_struct(map);
	return (0);
}
