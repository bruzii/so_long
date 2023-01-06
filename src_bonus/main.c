/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:59:58 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 16:42:29 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free(t_point *p, int t)
{
	int	i;

	i = 0;
	if (t)
	{
		t--;
		while (t >= 0)
		{
			mlx_destroy_image(p->init, p->img[t]);
			t--;
		}
	}
	while (p->str[i])
	{
		free (p->str[i]);
		i++;
	}
	free (p->str);
}

void	ft_supp(t_point *p, int t)
{
	mlx_destroy_display(p->init);
	free (p->init);
	ft_putstr_fd("Map Error\n", 2);
	if (t == 0)
		ft_free(p, 0);
	exit (0);
}

int	ft_check_ber(char *str)
{
	int		i;
	char	*s;
	int		t;
	int		q;

	s = ".ber";
	t = 3;
	i = (int)ft_strlen(str) - 1;
	q = i - 4;
	while (q < i)
	{
		if (str[i] != s[t])
			return (0);
		t--;
		i--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_point	p;

	p.pas = 0;
	if (argc != 2 || !ft_check_ber(argv[1]))
		return (0);
	p.init = mlx_init();
	if (!p.init)
		return (0);
	p.str = ft_split_map(argv[1], &p);
	if (!p.init || !ft_parcing(p.str, &p))
		return (0);
	ft_next(&p);
	if (ft_map_valid(&p))
		ft_supp(&p, 0);
	ft_free(&p, 0);
	p.str = ft_split_map(argv[1], &p);
	p.str[p.row_e][p.col_e] = '0';
	ft_fill_img(&p);
	fill_map_init(p.init, p.str, &p);
	ft_press(&p);
	mlx_loop(p.init);
	return (0);
}
