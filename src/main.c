/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:28 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/13 13:29:25 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	/* int i = 0;
	while (map->grid[i])
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
	free_struct(map); */
	return (0);
}
