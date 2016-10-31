/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:22:47 by rmoswela          #+#    #+#             */
/*   Updated: 2016/10/31 16:21:04 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define EXIT 53

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
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

#endif
