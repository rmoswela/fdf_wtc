/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:48:43 by rmoswela          #+#    #+#             */
/*   Updated: 2016/10/31 16:05:18 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*function*/
t_map		*list_rev(t_map *start)
{
	t_map	*prev;
	t_map	*current;
	t_map	*next;

	prev = NULL;
	current = start;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	start = prev;
	return (start);
}

/*function to determine size*/
void		ft_findSize(t_env *env, int length)
{
	if (length < 25)
		env->size = 20;
	else if (length < 50 && length > 25)
		env->size = 15;
	else if (length < 100 && length > 50)
		env->size = 10;
	else if (lenght > 100 && length < 300)
		env->size = 5;
	else if (length > 300)
		env->size = 1;
}

/*function to get size*/
void		ft_getSize(char **line, t_env *env)
{
	int		length;

	/*iterate to get number of points in a line*/
	length = 0;
	while (line[length] != '\0')
		length++;
	if (length == env->x || length)
	{
		findSize(env, length);
		env->x = 0;
	}
	else
		env->size = -1;
}

/*function to read from file and return map points*/
t_map		ft_read_map(char **line, t_env *new, int fd, t_env *env)
{
	/*temporary record*/
	t_env	tmp;

	tmp.y = 0;
	tmp.map = NULL;
	/*iterate */
	while (getNextLine(fd, line) == 1 && tmp.x != -1)
	{
		line = ft_strsplit(*line, ' ');
		ft_getSize(&line, tmp);
		while (line[tmp.x] != '\0' && tmp.x != -1)
		{
			/*allocate memory for new map record*/
			new = (t_map *)malloc(sizeof(t_map));
			new->z = tmp.y;
			/*use of isometric equation to determine point in space so to make a 3D view*/
			new->x = (1 / sqrt(6)) * ((sqrt(3) * tmp.x) + (0 * tmp.y) \
				   	+ (-(sqrt(3) * new->z))) * tmp.size;
			new->y = (1 / sqrt(6)) * ((1 * tmp.x) + (2 * ft_atoi(line[tmp.x])) \
					+ (1 * new->z));
			new->next = tmp.map;
			tmp.map = new;
			tmp.x++;
		}
		tmp.y++;
	}
	new = tmp.map;
	env->x = tmp.x;
	env->y = tmp.y;
	env->area = tmp.x * tmp.y;
	return(list_rev(new));
}
