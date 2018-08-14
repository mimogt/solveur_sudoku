/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:09:36 by pcharrie          #+#    #+#             */
/*   Updated: 2018/08/12 19:47:37 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_in_line(int grid[9][9], int y, int n)
{
	int x;

	x = 0;
	while (x < 9)
	{
		if (grid[y][x] == n)
			return (1);
		x++;
	}
	return (0);
}

int		is_in_column(int grid[9][9], int x, int n)
{
	int y;

	y = 0;
	while (y < 9)
	{
		if (grid[y][x] == n)
			return (1);
		y++;
	}
	return (0);
}

int		is_in_block(int grid[9][9], int x, int y, int n)
{
	int start_of_block_x;
	int start_of_block_y;

	start_of_block_x = x - (x % 3);
	start_of_block_y = y - (y % 3);
	y = start_of_block_y;
	while (y < start_of_block_y + 3)
	{
		x = start_of_block_x;
		while (x < start_of_block_x + 3)
		{
			if (grid[y][x] == n)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		can_be_placed(int grid[9][9], int x, int y, int n)
{
	if (is_in_line(grid, y, n) == 0
			&& is_in_column(grid, x, n) == 0
			&& is_in_block(grid, x, y, n) == 0)
		return (1);
	return (0);
}

int		backtrack_grid(int grid[9][9], int current_position)
{
	int x;
	int y;
	int n;

	if (current_position == 81)
		return (1);
	y = current_position / 9;
	x = current_position % 9;
	if (grid[y][x] != 0)
		return (backtrack_grid(grid, current_position + 1));
	n = 1;
	while (n < 10)
	{
		if (can_be_placed(grid, x, y, n))
		{
			grid[y][x] = n;
			if (backtrack_grid(grid, current_position + 1) == 1)
				return (1);
		}
		n++;
	}
	grid[y][x] = 0;
	return (0);
}
