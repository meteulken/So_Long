/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:48:54 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/06 01:57:03 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(int **solution, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(solution[i]);
		i++;
	}
	free(solution);
}

void	free_map_c(char **solution, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(solution[i]);
		i++;
	}
	free(solution);
}

void	set_solution_map_to_int(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->solution = (int **)malloc(game->map_height * sizeof(int *));
	while (i < game->map_height)
	{
		j = 0;
		game->solution[i] = (int *)malloc(game->map_width * sizeof(int));
		while (j < game->map_width)
		{
			game->solution[i][j] = 0;
			j++;
		}
		i++;
	}
}
