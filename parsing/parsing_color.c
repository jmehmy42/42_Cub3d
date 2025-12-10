/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:10:31 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:10:31 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_number(const char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_convert_rgb(char **rgb_parts, t_color *color)
{
	int	red;
	int	green;
	int	blue;

	if (!is_valid_number(rgb_parts[0]) || !is_valid_number(rgb_parts[1])
		|| !is_valid_number(rgb_parts[2]))
		return (ft_error("Error: RGB values must be numeric (0-255)"));
	red = ft_atoi(rgb_parts[0]);
	green = ft_atoi(rgb_parts[1]);
	blue = ft_atoi(rgb_parts[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		return (ft_error("RGB values must be in range 0-255"));
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (0);
}

static int	parse_rgb_values(char *rgb_str, t_color *color)
{
	char	**rgb_parts;
	int		count;
	int		result;

	rgb_parts = ft_split(rgb_str, ',');
	if (!rgb_parts)
		return (ft_error("Error: Memory allocation faild for RGB parsing"));
	count = 0;
	while (rgb_parts[count])
		count++;
	if (count != 3)
	{
		free_string(rgb_parts);
		return (ft_error("Error: RGB format must be R,G,B only 3 values"));
	}
	result = validate_convert_rgb(rgb_parts, color);
	free_string(rgb_parts);
	return (result);
}

static char	*extract_rgb_string(char *line)
{
	char	*rgb_str;
	int		i;
	int		j;
	int		start;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	rgb_str = malloc(i - start + 1);
	if (!rgb_str)
		return (NULL);
	j = 0;
	while (start < i)
		rgb_str[j++] = line[start++];
	rgb_str[j] = '\0';
	return (rgb_str);
}

int	parse_color_line(t_game *game, char *line)
{
	char	*rgb_str;
	t_color	color;

	rgb_str = extract_rgb_string(line);
	if (!rgb_str)
	{
		destroy_textures(game);
		return (ft_error("Memory alocation failed for color parsing"));
	}
	if (parse_rgb_values(rgb_str, &color) != 0)
	{
		free_rgb_textures(game, rgb_str);
		return (-1);
	}
	if (ft_strncmp(line, "F ", 2) == 0)
		game->floor_color = color;
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->ceiling_color = color;
	else
	{
		free_rgb_textures(game, rgb_str);
		return (ft_error("Error: Invalid color line must start with F or C"));
	}
	free(rgb_str);
	return (0);
}
