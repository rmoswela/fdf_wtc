/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:37:19 by rmoswela          #+#    #+#             */
/*   Updated: 2016/10/31 18:53:20 by rmoswela         ###   ########.fr       */
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
	double		m;
	double		c;
	double		x;
	int			x_end;
	int			y_end;

	x = p1.x;
	x_end = p2.x;
	y_end = p2.y;
	if (p1.x == p2.x)
		m = 0;
	else
		m = (p2.y - p1.y) / (p2.x - p1.x);
	c = p1.y - m * p1.x;
	if (p2.x < p1.x (x = p2.x))
		x_end = p2.x;
	while (x <= x_end && m != 0 && (x = x + 0.1))
		mlx_put_pixel(env.mlx, env.win, x + 350, m * (x - 0.1) + c - 200, \
			   0XFFFFFF);
	while (p1.y <= y_end && m == 0 && (p1.y = p1.y + 0.1))
		mlx_put_pixel(env.mlx, env.win, x + 350, p1.y - 0.1 - 200, \
				0XFFFFFF)
}

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
