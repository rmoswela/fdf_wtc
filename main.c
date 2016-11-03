/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:17:50 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/03 11:33:52 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_env	env;
	t_map	*point;

	/*ensure that there is only one argument read*/
	if (ac == 2)
	{
		/*validation of the file read*/
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
		{
			/*read the map and use the points to draw your 3D object*/
			point = ft_read_map(&line, env.map, fd, &env);
			if (line && env.x != -1)
			{
				/*initialize mlx*/
				env.mlx = mlx_init();
				/*make a new window*/
				env.win = mlx_new_window(env.mlx, 1000, 1000, "FDF - av[1]");
				/*function to draw 3D object*/
				ft_draw_object(point, env);
				/*mlx function to close the window*/
				mlx_key_hook(env.win, ft_exit, 0);
				/*mlx function to receive events and call the associated 
				 * function to handle the received event*/
				mlx_loop(env.mlx);
			}
		}
		else
			perror("Error: ");
	}
	else
		perror("Error: ");
}
