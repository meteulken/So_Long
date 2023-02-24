/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:59:30 by mulken            #+#    #+#             */
/*   Updated: 2023/02/22 13:59:32 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_retangular(char **map)
{
	int	x;
	int i;
	
	x = 1;
	if (!map)
		return (0);
	while (map[x] != NULL)
	{
		if (ft_strlen(map[x]) != ft_strlen(map[0]))
			return (0);
		x++;
	}
	i = 0;
	while (map[0][i] != '\n' && map[0][i])
	{
		if (i == x)
			return (1);
		i++;
	}
	ft_printf ("Map Shape Error\n");
	exit (1);
}

/*
static int	is_shape(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
		j++;
	j--;
	while (map[0][i] != '\n' && map[0][i])
		i++;
	i--;
	if (i < 2 || i == j)
	{
		printf ("Map Shape Error\n");
		exit (1);
	}
	return (1);
}
*/

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_pec(t_game *game)
{
	int	i;
	int	j;

	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_collect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit == 0 || game->n_collect == 0)
		return (0);
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (is_retangular(game->map) && is_wall(game->map) && is_pec(game)
		&& is_validate(game->map))
		return (1);
	return (0);
}
