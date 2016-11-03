/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:22:47 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/03 10:30:29 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define EXIT 53

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "includes/libft.h"

typedef struct		s_map
{
	double			x;
	double			y;
	double			z;
	struct s_map	*next;
}					t_map;

typedef struct		s_points
{
	double			x;
	double			y;
}					t_points;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				area;
	int				size;
	t_map			*map;
}					t_env;

t_map				*ft_read_map(char **line, t_map *new, int fd, t_env *env);
void				ft_draw_object(t_map *new, t_env env);
int					ft_exit(int keycode);

#endif
