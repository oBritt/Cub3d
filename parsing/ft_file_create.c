/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:08 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 19:48:42 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		invalid_input();
		return (0);
	}
	len = ft_strlen(av[1]);
	if (len <= 3 || av[1][len - 1] != 'b' || av[1][len -2] != 'u'
		|| av[1][len - 3] != 'b' || av[1][len - 4] != '.')
	{
		print_fd(2, "Error\nToo little arguments\n");
		return (0);
	}
	return (1);
}

char	**ft_file_create3(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		i++;
	if (i < 9)
		return (print_fd(2, "Error\nToo little lines\n"),
			free_split(ret), NULL);
}

char	**ft_file_create2(char **ret, int fd)
{
	int		j;
	char	*temp;

	temp = get_next_line(fd);
	while (temp != NULL && is_empty_line(temp) == 1)
		free(temp);
	while (temp != NULL)
	{
		j = 0;
		while (ret[j])
			j++;
		if (j != 0 && ret[j - 1] == '\n')
			ret[fd - 1] = 0;
		ret = smerge(ret, temp);
		free(temp);
		if (ret == 0)
			return (close(fd), NULL);
		temp = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror("close"), free_split(ret), NULL);
	return (ft_file_create3(ret));
}

char	**ft_file_create(int ac, char **av, char *file_name)
{
	char			*temp;
	char			**ret;
	int				fd;

	if (ft_check_args(ac, av) == 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nOpen"), 0);
	ret = smerge(0, 0);
	if (ret == 0)
		return (NULL);
	ret = ft_file_create2(ret, fd);
	get_next_line(-1);
	return (ret);
}
