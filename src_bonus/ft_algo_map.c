/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:18:54 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/31 18:29:55 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_x(int col, int row, t_point *p)
{
	int	temp;

	temp = row;
	while (p->str[row][col] != '1')
	{
		p->str[row][col] = '*';
		row++;
	}
	row--;
	while (p->str[row][col] != '1')
	{
		p->str[row][col] = '*';
		row = row - 1;
	}
	row = temp;
	while (p->str[row][col + 1] != '1')
	{
		p->str[row][col] = '*';
		col++;
	}
	while (p->str[row][col] != '1')
	{
		p->str[row][col] = '*';
		col = col - 1;
	}
}

int	ft_map_valid(t_point *p)
{
	int	i;
	int	k;

	i = 0;
	while (p->str[i])
	{
		k = 0;
		while (p->str[i][k])
		{
			if (p->str[i][k] == 'E' || p->str[i][k] == 'C')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	ft_count_c(char c, t_point *p)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = 0;
	while (p->str[i])
	{
		k = 0;
		while (p->str[i][k])
		{
			if (p->str[i][k] == c)
				count++;
			k++;
		}
		i++;
	}
	return (count);
}

int	ft_next(t_point *p)
{
	int			row;
	int			col;
	static int	t;

	col = p->col_p;
	row = p->row_p;
	p->str[row][col] = '*';
	while (p->str[row])
	{
		if (row == 0)
			t = ft_count_c('*', p);
		while (p->str[row][col])
		{
			if (p->str[row][col] == '*')
				ft_make_x(col, row, p);
			col++;
		}
		col = 0;
		if (row == (p->row - 1) && ft_count_c('*', p) == t)
			break ;
		if (!p->str[row + 1])
			row = -1;
		row++;
	}
	return (0);
}
