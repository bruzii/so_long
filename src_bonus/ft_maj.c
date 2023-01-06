/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:39:22 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 15:11:32 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(t_point *p, int row, int col)
{
	char	temp;

	temp = p->str[p->row_p][p->col_p];
	p->str[p->row_p][p->col_p] = p->str[row][col];
	p->str[row][col] = temp;
	p->row_p = row;
	p->col_p = col;
}

char	ft_e_c(char c, t_point *p)
{
	if (c == 'M' || (c == 'E' && ft_count_c('C', p) == 0))
	{
		mlx_loop_end(p->init);
		ft_free(p, 19);
		mlx_clear_window(p->init, p->win);
		mlx_destroy_window(p->init, p->win);
		mlx_destroy_display(p->init);
		free (p->init);
		exit (0);
	}
	if (c == 'C')
		c = '0';
	return (c);
}

void	ft_put_exit(t_point *p)
{
	if (ft_count_c('C', p) == 0)
	{
		p->str[p->row_e][p->col_e] = 'E';
		mlx_put_image_to_window(p->init, p->win, p->img[13],
			(p->row_e * 32), (p->col_e * 32));
	}
}

void	ft_swap_player(char c, t_point *p, char **str)
{
	if (c == 'W' && str[p->row_p - 1][p->col_p] != '1')
	{
		str[p->row_p - 1][p->col_p] = ft_e_c(str[p->row_p - 1][p->col_p], p);
		ft_swap(p, (p->row_p - 1), p->col_p);
	}
	if (c == 'D' && str[p->row_p][p->col_p + 1] != '1')
	{
		str[p->row_p][p->col_p + 1] = ft_e_c(str[p->row_p][p->col_p + 1], p);
		ft_swap(p, (p->row_p), (p->col_p + 1));
	}
	if (c == 'A' && str[p->row_p][p->col_p - 1] != '1')
	{
		str[p->row_p][p->col_p - 1] = ft_e_c(str[p->row_p][p->col_p - 1], p);
		ft_swap(p, (p->row_p), (p->col_p - 1));
	}
	if (c == 'S' && str[p->row_p + 1][p->col_p] != '1')
	{
		str[p->row_p + 1][p->col_p] = ft_e_c(str[p->row_p + 1][p->col_p], p);
		ft_swap(p, (p->row_p + 1), p->col_p);
	}
	ft_put_exit(p);
}

void	ft_moove(char **str, t_point *p)
{
	int		i;
	int		k;

	if (ft_count_c('C', p) == 0)
		p->str[p->row_e][p->col_e] = 'E';
	i = p->row_p;
	k = p->col_p;
	if (p->touch != '\0')
	{
		ft_swap_player(p->touch, p, str);
		fill_map_init(p->init, str, p);
	}
}
