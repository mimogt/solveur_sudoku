/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:34:31 by pcharrie          #+#    #+#             */
/*   Updated: 2018/08/12 19:47:25 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		grid_has_minimum(int grid[9][9])
{
	int n;
	int x;
	int	y;

	n = 0;
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (grid[y][x] != 0)
				n++;
			x++;
		}
		y++;
	}
	if (n >= 17)
		return (1);
	return (0);
}
