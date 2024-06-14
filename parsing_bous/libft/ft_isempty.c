/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:16:00 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 17:08:18 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(int const c)
{
	if ((9 <= (char) c && (char) c <= 13) || ((char)c == ' '))
		return (1);
	return (0);
}
