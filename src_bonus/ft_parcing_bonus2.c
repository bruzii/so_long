/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:11:56 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 16:20:57 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_check_string(char *str, t_point *p, int fd)
{
	int	i;

	i = 0;
	(void) p;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'M'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
		{
			ft_putstr_fd("Map error\n", 2);
			free (str);
			close (fd);
			ft_destroy(p);
		}
		i++;
	}
}

void	ft_fill_position(char c, t_point *p, int i, int row)
{
	if (c == 'P')
	{
		p->col_p = i;
		p->row_p = row;
	}
	if (c == 'E')
	{
		p->col_e = i;
		p->row_e = row;
	}
}

int	ft_search_count(char c, char **str, t_point *p)
{
	int		i;
	int		count;
	int		row;

	count = 0;
	row = 0;
	while (str[row] != NULL)
	{
		i = 0;
		while (str[row][i])
		{
			if (str[row][i] == c)
			{
				ft_fill_position(c, p, i, row);
				count++;
			}
			i++;
		}
		row++;
	}
	return (count);
}

void	ft_delete(t_point *p)
{
	mlx_destroy_display(p->init);
	free (p->init);
	ft_putstr_fd("Map error\n", 2);
	ft_free(p, 0);
}

int	ft_parcing(char **str, t_point *p)
{
	if (!ft_check_wall(str, p) || !ft_check_row(str, p))
	{
		ft_delete(p);
		return (0);
	}
	if (ft_search_count('E', str, p) != 1
		|| ft_search_count('P', str, p) != 1)
	{
		ft_delete(p);
		return (0);
	}
	if (!ft_search_count('C', str, p))
	{
		ft_delete(p);
		return (0);
	}
	return (1);
}
