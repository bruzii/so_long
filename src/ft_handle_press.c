/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:35:32 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 12:03:08 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_point *p)
{
	(void)p;
	return (0);
}

int	handle_destroy(t_point *p)
{
	mlx_destroy_window(p->init, p->win);
	ft_free(p, 19);
	mlx_destroy_display(p->init);
	free (p->init);
	exit (0);
}

char	ft_return_touch(int keycode)
{
	if (keycode == W)
		return ('W');
	if (keycode == A)
		return ('A');
	if (keycode == S)
		return ('S');
	if (keycode == D)
		return ('D');
	return ('\0');
}

int	key_press(int keycode, t_point *p)
{
	p->touch = '\0';
	if (keycode == ESC)
	{
		mlx_destroy_window(p->init, p->win);
		ft_free(p, 19);
		mlx_destroy_display(p->init);
		free (p->init);
		exit (0);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		p->touch = ft_return_touch(keycode);
		if ((p->touch == 'W' && p->str[p->row_p - 1][p->col_p] != '1')
			|| (p->touch == 'A' && p->str[p->row_p][p->col_p - 1] != '1')
			|| (p->touch == 'S' && p->str[p->row_p + 1][p->col_p] != '1')
			|| (p->touch == 'D' && p->str[p->row_p][p->col_p + 1] != '1'))
		{
			p->pas = p->pas + 1;
		}
		ft_moove(p->str, p);
	}
	p->touch = '\0';
	return (0);
}

void	ft_press(t_point *p)
{
	mlx_loop_hook(p->init, handle_no_event, p);
	mlx_hook(p->win, 2, 1L << 0, &key_press, p);
	mlx_hook(p->win, 17, 1L << 17, handle_destroy, p);
}
