/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:30:53 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/14 16:31:23 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	post(int pid, int idx)
{
	if (idx == 1)
		kill(pid, SIGUSR1);
	else if (idx == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	sent_str(int pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		usleep(55);
		bit = (c >> i) & 1;
		if (bit == 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	return ;
}

void	ft_client(int pid, char *str)
{
	int		i;

	i = 0;
	if (!pid || kill(pid, 0) == -1)
		error("Pid Error\n");
	while (str[i])
		sent_str(pid, (int)str[i++]);
	sent_str(pid, 127);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	ft_client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
