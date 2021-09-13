#include "../includes/minitalk.h"

void	reset(char *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		b[i++] = 0;
}

void	handler(int sig)
{
	static char	s[101];
	static int	i;
	static int	c;

	if (--c == -1)
	{
		c = 7;
		i++;
	}
	if (sig == SIGUSR1)
		s[i] |= (1 << c);
	else if (sig == SIGUSR2)
		s[i] &= ~(1 << c);
	if (s[i] == END || i == 100)
	{
		s[i] = '\0';
		write(1, s, i + 1);
		reset(s, 100);
		i = 0;
	}
}

int		display_pid()
{
	char *pid;

	if (!(pid = ft_itoa(getpid())))
		return (0);
	write(1, "PID=", 4);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	return (1);
}

int		main(void)
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
