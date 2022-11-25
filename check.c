/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukoike <sukoike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:38:39 by sukoike           #+#    #+#             */
/*   Updated: 2022/05/01 19:38:41 by sukoike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col(int map[4][4], int col, int n)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (map[row][col] == n)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_row(int map[4][4], int row, int n)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (map[row][col] == n)
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	check_total(int map[4][4], int row, int col, int n)
{
	if ((check_col(map, col, n) == 1) && (check_row(map, row, n) == 1)
		&& (map[row][col] == 0))
	{
		return (1);
	}
	return (0);
}
