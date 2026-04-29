/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:28 by joapedro          #+#    #+#             */
/*   Updated: 2026/04/29 14:43:54 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	*map;

	file_name = av[1];
	if (!check_args(ac, file_name))
		exit (1);
	map = malloc(sizeof(t_map)); //dar free struct e suas variaveis
	if (!map)
		return (1);
	if (!map_load(file_name, map))
		exit (1);
	parsing(map);
	return (0);
}
