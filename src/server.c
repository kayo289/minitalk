/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:31:03 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/13 22:41:21 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	reset(char *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		b[i++] &= 0;
}

void	handler(int sig)
{
	static char	s[100];
	static int	i;
	static int	c;

	if (--c == -1)
	{
		c = 7;
		i++;
	}
	s[i] &= ~0;
	if (sig == SIGUSR1)
		s[i] |= (1 << c);
	else if (sig == SIGUSR2)
		s[i] &= ~(1 << c);
	if (s[i] == END || i == 99)
	{
		write(1, s, i);
		reset(s, 100);
		i = 0;
	}
}

int	display_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		return (0);
	write(1, "PID=", 4);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	return (1);
}

int	main(void)
{
	if (!(display_pid()))
		error("Pid Error\n");
	if (signal(SIGUSR1, handler) == SIG_ERR)
		error("Signal Error\n");
	if (signal(SIGUSR2, handler) == SIG_ERR)
		error("Signal Error\n");
	while (1)
	{
	}
	return (0);
}
