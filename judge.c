/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukoike <sukoike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:45:46 by sukoike           #+#    #+#             */
/*   Updated: 2022/05/01 19:45:52 by sukoike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	judge_up(int map[4][4], int col, int colarg)
{
	int	i;
	int	flg;
	int	max;

	max = map[0][col];
	i = 1;
	flg = 1;
	while (i <= 3)
	{
		if (max < map[i][col])
		{
			max = map[i][col];
			flg++;
		}
		i++;
	}
	if (flg == colarg)
	{
		return (1);
	}
	return (0);
}

int	judge_down(int map[4][4], int col, int colarg)
{
	int	i;
	int	flg;
	int	max;

	max = map[3][col];
	i = 2;
	flg = 1;
	while (i >= 0)
	{
		if (max < map[i][col])
		{
			max = map[i][col];
			flg++;
		}
		i--;
	}
	if (flg == colarg)
	{
		return (1);
	}
	return (0);
}

int	judge_left(int map[4][4], int row, int rowarg)
{
	int	j;
	int	flg;
	int	max;

	max = map[row][0];
	j = 1;
	flg = 1;
	while (j <= 3)
	{
		if (max < map[row][j])
		{
			max = map[row][j];
			flg++;
		}
		j++;
	}
	if (flg == rowarg)
	{
		return (1);
	}
	return (0);
}

int	judge_right(int map[4][4], int row, int rowarg)
{
	int	j;
	int	flg;
	int	max;

	max = map[row][3];
	j = 2;
	flg = 1;
	while (j >= 0)
	{
		if (max < map[row][j])
		{
			max = map[row][j];
			flg++;
		}
		j--;
	}
	if (flg == rowarg)
	{
		return (1);
	}
	return (0);
}

int	judge_total(int map[4][4], int arg[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (0 <= i && i <= 3)
			if (judge_up(map, i, arg[i]) != 1)
				return (0);
		if (4 <= i && i <= 7)
			if (judge_down(map, i - 4, arg[i]) != 1)
				return (0);
		if (8 <= i && i <= 11)
			if (judge_left(map, i - 8, arg[i]) != 1)
				return (0);
		if (12 <= i && i <= 15)
			if (judge_right(map, i - 12, arg[i]) != 1)
				return (0);
		i++;
	}
	return (1);
}
