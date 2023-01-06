/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:11:56 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 12:58:07 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_row(char **str, t_point *p)
{
	int		i;
	int		k;
	int		t;

	p->col = 0;
	p->row = 0;
	i = 0;
	k = 0;
	t = 1;
	p->col = (int)ft_strlen(str[i]);
	if (p->col > 60)
	{
		mlx_destroy_display(p->init);
		free (p->init);
		ft_putstr_fd("Map size error ! Map too big\n", 2);
		exit (0);
	}
	while (str[i])
	{
		p->row = p->row + 1;
		if (p->col != (int)ft_strlen(str[i]))
			t = 0;
		i++;
	}
	return (p->row);
}

int	ft_return_row(char	*filename, t_point *p)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_supp(p, 1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		ft_check_string(str, p, fd);
		free (str);
		str = get_next_line(fd);
	}
	p->row = i;
	if (!i || i > 30)
	{
		ft_putstr_fd("Map error\n", 2);
		ft_destroy(p);
	}
	close (fd);
	return (i);
}

char	**ft_split_map(char	*filename, t_point *p)
{
	char	**strs;
	int		i;
	int		k;
	char	*str;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	strs = malloc(sizeof(char *) * (ft_return_row(filename, p) + 1));
	if (!strs || fd == -1)
		return (NULL);
	str = get_next_line(fd);
	while (str != NULL)
	{
		k = 0;
		while (str[k] != '\n' && str[k])
			k++;
		str[k] = '\0';
		strs[i++] = str;
		str = get_next_line(fd);
	}
	strs[i] = 0;
	close (fd);
	return (strs);
}

int	ft_check_wall_aux(char **str, int *k, int len_row)
{
	int	i;

	i = 0;
	if (*k == 0 || *k == (len_row - 1))
	{
		while (str[*k][i])
		{
			if (str[*k][i] != '1')
				return (0);
			i++;
		}
	}
	if (str[*k][0] != '1' || str[*k][ft_strlen(str[*k]) - 1] != '1')
		return (0);
	return (1);
}

int	ft_check_wall(char **str, t_point *p)
{
	int		i;
	int		k;
	int		t;

	i = 0;
	k = 1;
	ft_check_row(str, p);
	while (str[i] != NULL)
	{
		t = 0;
		while (str[i][t])
		{
			if (str[i][t] != '1' && str[i][t] != '0' && str[i][t] != 'C'
				&& str[i][t] != 'E' && str [i][t] != 'P' && str [i][t] != 'M')
				k = 0;
			t++;
		}
		if (!ft_check_wall_aux(str, &i, p->row))
			k = 0;
		i++;
	}
	if (!k)
		return (0);
	return (1);
}
