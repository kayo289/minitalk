/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:07:48 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:26:59 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	ans;

	ans = 0;
	minus = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		ans = ans * 10 + (str[i++] - '0');
		if (ans * minus > 2147483647)
			return (-1);
		else if (ans * minus < -2147483648)
			return (0);
	}
	return ((int)ans * minus);
}
