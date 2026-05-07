/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:28 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/07 12:39:15 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	*map;

	file_name = av[1];
	check_args(ac, file_name);
	map = malloc(sizeof(t_map)); //dar free struct e suas variaveis
	if (!map)
		return (1);
	ft_memset(map, 0, sizeof(t_map));
	if (!map_load(file_name, map))
		exit (1);
	parsing(map);
	return (0);
}
