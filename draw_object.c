/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:37:19 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/02 15:01:52 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*function*/
t_map			*ft_point_to_place(t_map *new, t_env env)
{
	int			i;
	t_map		*tmp;

	i = 0;
	tmp = new;
	while (i < env.x && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

/*function to draw lines on the window usint the straight line equation*/
void			ft_draw_line(t_points p1, t_points p2, t_env env)
{
	double		grad;
	double		y_intercept;
	double		x_coord;
	int			x_end;
	int			y_end;

	x = p1.x;
	x_end = p2.x;
	y_end = p2.y;
	if (p1.x == p2.x)
		grad = 0;
	else
		grad = (p2.y - p1.y) / (p2.x - p1.x);
	y_intercept = p1.y - grad * p1.x;
	if (p2.x < p1.x (x_coord = p2.x))
		x_end = p2.x;
	while (x <= x_end && grad != 0 && (x = x + 0.1))
		mlx_put_pixel(env.mlx, env.win, x + 350, \ 
				grad * (x - 0.1) + y_intercept - 200, 0XFFFFFF);
	while (p1.y <= y_end && grad == 0 && (p1.y = p1.y + 0.1))
		mlx_put_pixel(env.mlx, env.win, \ 
				x_coord + 350, p1.y - 0.1 - 200, 0XFFFFFF)
}

/*function to draw columns*/
void			ft_draw_columns(t_map *new, t_env env)
{
	t_map		*tmp;
	t_map		*tmp1;
	t_points	p1;
	t_points	p2;

	tmp = new;
	tmp1 = ft_point_to_place(new, env);
	while (tmp1 != NULL)
	{
		p1.x = tmp->x + (800 - (8 * 20)) / 20;
		p1.y = tmp->y + (800 / 2);
		p2.x = tmp->x + (800 - (8 * 20)) / 20;
		p2.y = tmp->y + (800 / 2);
		ft_draw_line(p1, p2, env);
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
}

/*function to draw rows*/
void			ft_draw_rows(t_map *new, t_env env)
{
	int			loop;
	t_map		*tmp;
	t_map		*tmp1;
	t_points	p1;
	t_points	p2;

	loop = 0;
	tmp = new;
	tmp1 = tmp1->next;
	while (tmp1)
	{
		p1.x = tmp->x + (800 - (8 * 20)) / 20;
		p1.y = tmp->y + (800 /2);
		p2.x = tmp->x + (800 - (8 * 20)) / 20;
		p2.y = tmp->y + (800 /2);
		if (loop < env.x)
			ft_draw_line(p1, p2, env);
		else
			loop = 0;
		tmp = tmp->next;
		loop++;
		tmp1 = tmp1->next;
	}
}

void			ft_draw(t_map new, t_env env)
{
	ft_draw_columsn(new, env);
	ft_draw_rows(new, env);
}
