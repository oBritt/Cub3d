/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 18:50:40 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//non_map contains 8 meaningfull lines with meaning full value, check only before
//line ft_is_part_of_map
//un_non_map - else
t_map	*ft_map(int ac, char **av)
{
	char		**file_content;
	t_map		*ret;
	int			i;

	file_content = ft_file_create(ac, av, av[1]);
	if (file_content == 0)
		return (NULL);
	i = 0;
	ret = break_non_map(file_content, &i);
	if (ret == 0)
		return (NULL);
	ret = map_gen(ret, i);
	return (ret);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = ft_map(ac, av);
	if (map == 0)
		return (1);
}

int	player_cnt(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (line[i])
		if (line[i] == 'N' || line[i] == 'W'
			|| line[i] == 'S' || line[i] == 'E')
			ret++;
	return (ret);
}

int	inside_map_good(char **file_content, int *i)
{
	int	player;

	player = 0;
	while (file_content[*i] && ft_is_part_of_map(file_content[*i]))
	{
		player += player_cnt(file_content[*i]);
		if (player > 1)
			return (print_fd(2, "Too many players"), 0);
		(*i)++;
	}
	if (player != 1)
		return (print_fd(2, "No player"), 0);
	return (1);
}