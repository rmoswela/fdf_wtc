/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:48:43 by rmoswela          #+#    #+#             */
/*   Updated: 2016/10/29 16:56:47 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

//function to read from file and return map points
t_map		read_map(char **line, int fd, t_env *env)
{
	t_env	tmp;

	tmp.y = 0;
	tmp->map = NULL;
	while (getNextLine(fd, line) == 1 && tmp.x != -1)
	{
	}
}
