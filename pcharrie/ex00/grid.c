/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:10:27 by pcharrie          #+#    #+#             */
/*   Updated: 2018/08/12 21:01:40 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	put_grid(int grid[9][9])
{
	int x;
	int y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			ft_putchar(grid[y][x] + '0');
			x++;
			if (y < 9)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		y++;
	}
}

void	init_grid(int grid[9][9])
{
	int x;
	int y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
}

int		set_up_grid(int grid[9][9], int argc, char **argv)
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j >= 9)
				return (0);
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				grid[i - 1][j] = argv[i][j] - '0';
			else if (argv[i][j] == '.')
				grid[i - 1][j] = 0;
			else
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
	}
	return (1);
}

void	reverse_grid(int dest_grid[9][9], int src_grid[9][9])
{
	int x;
	int y;
	int x2;
	int y2;

	y = 0;
	y2 = 8;
	while (y < 9)
	{
		x = 0;
		x2 = 8;
		while (x < 9)
		{
			dest_grid[y][x] = src_grid[y2][x2];
			x++;
			x2--;
		}
		y++;
		y2--;
	}
}

int		match_grid(int first_grid[9][9], int second_grid[9][9])
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (first_grid[y][x] != second_grid[y][x])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
