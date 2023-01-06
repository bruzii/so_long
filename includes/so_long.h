/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:09:54 by bgervais          #+#    #+#             */
/*   Updated: 2023/01/06 16:19:40 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define ZERO "./src_xpm/b-0.xpm"
# define UN "./src_xpm/b-1.xpm"
# define DEUX "./src_xpm/b-2.xpm"
# define TROIS "./src_xpm/b-3.xpm"
# define QUATRE "./src_xpm/b-4.xpm"
# define CINQ "./src_xpm/b-5.xpm"
# define SIX "./src_xpm/b-6.xpm"
# define SEPT "./src_xpm/b-7.xpm"
# define HUIT "./src_xpm/b-8.xpm"
# define NEUF "./src_xpm/b-9.xpm"
# define P "./src_xpm/MARIOO.xpm"
# define E "./src_xpm/EXIT.xpm"
# define O "./src_xpm/grass.xpm"
# define C "./src_xpm/stars.xpm"
# define WALL "./src_xpm/wall.xpm"
# define ANIME "./src_xpm/a_1.xpm"
# define AA "./src_xpm/a_2.xpm"
# define M_1 "./src_xpm/mechant_1.xpm"
# define M_2 "./src_xpm/mechant_2.xpm"

typedef struct s_point
{
	int		col;
	int		row;
	int		col_p;
	int		row_p;
	int		col_e;
	int		row_e;
	int		pas;
	char	touch;
	char	**str;
	void	*init;
	void	*win;
	void	*img[19];
}	t_point;

int		ft_check_row(char **str, t_point *p);
int		ft_check_wall(char **str, t_point *p);
int		ft_search_count(char c, char **str, t_point *p);
int		ft_parcing(char **filename, t_point *p);
char	**ft_split_map(char *filename, t_point *p);
void	ft_check_string(char *str, t_point *p, int fd);
char	*ft_itoa(int nb);
void	ft_supp(t_point *p, int t);
void	ft_destroy(t_point *p);
void	ft_free(t_point *p, int t);
void	ft_fill_img(t_point *p);
void	*ft_img(char c, t_point *p);
void	fill_map_init(void *mlx, char **str, t_point *p);
void	ft_press(t_point *p);
int		key_press(int keycode, t_point *p);
void	ft_moove(char **str, t_point *p);
int		ft_next(t_point *p);
int		ft_map_valid(t_point *p);
int		ft_count_c(char c, t_point *p);

#endif
