#include "../includes/minitalk.h"

void	post(int pid, int idx)
{
	if (idx == 1)
		kill(pid, SIGUSR1);
	else if (idx == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	sent_str(int pid, int c, int n)
{
	if (!c)
	{
		while (n < 8)
		{
			post(pid, 0);
			n++;
		}
		return ;
	}
	sent_str(pid, c / 2, ++n);
	post(pid, c % 2);
}

void	ft_client(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		sent_str(pid, (int)str[i++],0);
	sent_str(pid, 127, 0);
}

int		main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	write(1, "\nMassage : ", 11);
	write(1, argv[2], ft_strlen(argv[2]));
	write(1, "\n", 1);
	ft_client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
