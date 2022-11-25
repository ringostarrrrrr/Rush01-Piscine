/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukoike <sukoike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:07:07 by sitagaki          #+#    #+#             */
/*   Updated: 2022/05/01 19:44:47 by sukoike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	judge_total(int matrix[4][4], int arg[16]);
int	check_total(int matrix[4][4], int row, int col, int n);

int	find_zero(int map[4][4], int *i, int *j)
{
	*i = 0;
	while (*i <= 3)
	{
		*j = 0;
		while (*j <= 3)
		{
			if (map[*i][*j] == 0)
			{
				return (0);
			}
			*j += 1;
		}
		*i += 1;
	}
	return (1);
}

int	solve(int map[4][4], int arg[16])
{
	int	i;
	int	j;
	int	n;

	if ((find_zero(map, &i, &j)) && (judge_total(map, arg)))
	{
		return (1);
	}
	n = 1;
	while (n <= 4)
	{
		if (check_total(map, i, j, n))
		{
			map[i][j] = n;
			if (solve(map, arg))
			{
				return (1);
			}
			map[i][j] = 0;
		}
		n++;
	}
	return (0);
}
