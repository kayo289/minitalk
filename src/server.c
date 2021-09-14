/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:31:03 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/14 17:00:33 by kkikuchi         ###   ########.fr       */
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
	static char	s[101];
	static int	i;
	static int	c;

	s[i] &= ~0;
	if (c < 8)
	{
		if (sig == SIGUSR1)
			s[i] |= (1 << c);
		else if (sig == SIGUSR2)
			s[i] &= ~(1 << c);
		c++;
	}
	if (s[i] == END || i == 100)
	{
		s[i] = '\0';
		write(1, s, i);
		reset(s, 100);
		i = 0;
	}
	if (c == 8)
	{
		c = 0;
		i++;
	}
}

void	display_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		error("Pid Error\n");
	write(1, "PID=", 4);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
}

int	main(void)
{
	display_pid();
	if (signal(SIGUSR1, handler) == SIG_ERR)
		error("Signal Error\n");
	if (signal(SIGUSR2, handler) == SIG_ERR)
		error("Signal Error\n");
	while (1)
	{
	}
	return (0);
}
