/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:58:00 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/07 12:55:28 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_empty_line(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		return (0);
		str++;
	}
	return (1);
}

int	is_map(char *line)
{
	while(*line)
	{
		if (*line != ' ' 
		|| *line != '0'
		|| *line != '1'
		|| *line != 'N'
		|| *line != 'S'
		|| *line != 'W'
		|| *line != 'E')
			return (0);
		line++;
	}
	return (1);
}

int	check_file_extension_xpm(char *str)
{
	char	*file_extension;
	int		len;

	file_extension = ft_strrchr(str, '/');
	file_extension++;
	file_extension = ft_strchr(file_extension, '.');
	if (!file_extension)
	{
		printf("Error\nTextures: File must end with: '.xpm' extension\n");
		exit (1);
	}
	len = ft_strlen(file_extension);
	if ((ft_strncmp(file_extension, ".xpm", 4) == 0) && len == 4)
		return (0);
	printf("Error\nWrong file extension!\n");
	exit (1);
}