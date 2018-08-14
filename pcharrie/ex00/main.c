/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:55:44 by pcharrie          #+#    #+#             */
/*   Updated: 2018/08/12 19:47:16 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	put_grid(int grid[9][9]);
void	init_grid(int grid[9][9]);
int		set_up_grid(int grid[9][9], int argc, char **argv);
int		grid_has_minimum(int grid[9][9]);
void	reverse_grid(int dest_grid[9][9], int src_grid[9][9]);
int		match_grid(int first_grid[9][9], int second_grid[9][9]);
int		backtrack_grid(int grid[9][9], int position);

void	rush(int argc, char **argv)
{
	int grid[9][9];
	int reversed_grid[9][9];
	int reversed_reversed_grid[9][9];

	init_grid(grid);
	if (set_up_grid(grid, argc, argv) == 0 || grid_has_minimum(grid) == 0)
	{
		ft_putstr("Error\n");
		return ;
	}
	reverse_grid(reversed_grid, grid);
	if (backtrack_grid(grid, 0) == 0 || backtrack_grid(reversed_grid, 0) == 0)
	{
		ft_putstr("Error\n");
		return ;
	}
	reverse_grid(reversed_reversed_grid, reversed_grid);
	if (match_grid(grid, reversed_reversed_grid) == 0)
	{
		ft_putstr("Error \n");
		return ;
	}
	put_grid(grid);
}

int		main(int argc, char **argv)
{
	rush(argc, argv);
	return (0);
}
