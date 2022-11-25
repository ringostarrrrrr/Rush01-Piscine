/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukoike <sukoike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:40:09 by sukoike           #+#    #+#             */
/*   Updated: 2022/05/01 20:49:08 by sukoike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		solve(int map[4][4], int *arg);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

int	check_arg(int arc, char *arg)
{
	int	i;

	if (arc != 2)
		return (1);
	if (ft_strlen(arg) != 31)
		return (1);
	i = 0;
	while (arg[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (arg[i] > '4' || arg[i] < '1')
				return (1);
		}
		else
		{
			if (arg[i] != 32)
				return (1);
		}
		i++;
	}
	return (0);
}

void	str_to_int_array(char *argv_char, int *argv_int)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv_char[i] != '\0')
	{
		if (i % 2 == 0)
		{
			argv_int[j] = argv_char[i] - '0';
			j++;
		}
		i++;
	}
}

void	map_init(int map[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_result(int map[4][4])
{
	int		i;
	int		j;
	char	c;
	char	space;
	char	change_line;

	i = 0;
	space = ' ';
	change_line = '\n';
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, &space, 1);
			j++;
		}
		write(1, &change_line, 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	argv_int[16];
	int	map[4][4];

	if (check_arg(argc, argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	str_to_int_array(argv[1], argv_int);
	map_init(map);
	if (solve(map, argv_int))
	{
		print_result(map);
	}
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
