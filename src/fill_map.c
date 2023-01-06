/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:03:53 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 12:02:39 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy(t_point *p)
{
	mlx_destroy_display(p->init);
	free (p->init);
	exit(0);
}

void	ft_fill_img(t_point *p)
{
	int			w;
	int			i;
	static char	*ta[22] = {ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT,
		HUIT, NEUF, P, E, O, C, WALL, ANIME, AA, M_1, M_2};

	w = 1;
	i = 0;
	p->win = mlx_new_window(p->init, (p->col * 32), (p->row * 32), "So_long");
	if (!p->win)
		ft_destroy(p);
	while (i < 19)
	{
		p->img[i] = mlx_xpm_file_to_image(p->init, ta[i], &w, &w);
		if (!p->img[i])
		{	
			mlx_destroy_window(p->init, p->win);
			ft_free (p, i);
			ft_destroy(p);
		}
		i++;
	}
}

void	*ft_img(char c, t_point *p)
{
	if (c == '1')
		return (p->img[14]);
	if (c == '0')
		return (p->img[12]);
	if (c == 'C')
		return (p->img[13]);
	if (c == 'E')
		return (p->img[11]);
	if (c == 'P')
		return (p->img[10]);
	if (c == 'A')
		return (p->img[15]);
	if (c == 'B')
		return (p->img[16]);
	if (c == 'M')
		return (p->img[17]);
	return (NULL);
}

void	*ft_compteur(int *col, t_point *p)
{
	int	i;
	int	len_col;
	int	value;

	i = p->pas;
	len_col = ((p->col - 1) / 2);
	value = 14;
	if (*col == len_col)
		value = i % 10;
	i /= 10;
	if (*col == len_col - 1)
		value = i % 10;
	i /= 10;
	if (*col == len_col - 2)
		value = i % 10;
	i /= 10;
	if (*col == len_col - 3)
		value = i % 10;
	return (p->img[value]);
}

void	fill_map_init(void *mlx, char **str, t_point *p)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		k = 0;
		while (str[i][k])
		{
			if ((i == (rand() % p->row + 3) || k == (rand() % p->col))
				&& str[i][k] == '0' && ft_count_c('A', p) < 4)
				str[i][k] = 'A';
			if (i != (p->row - 1))
				mlx_put_image_to_window(mlx, p->win, ft_img(str[i][k], p),
					(k * 32), (i * 32));
			else
				mlx_put_image_to_window(mlx, p->win, ft_compteur(&k, p),
					(k * 32), (i * 32));
			if (str[i][k] == 'A' && p->pas % 2 == 1)
				mlx_put_image_to_window(mlx, p->win, p->img[16],
					(k * 32), (i * 32));
			k++;
		}
		i++;
	}
}
