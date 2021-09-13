#include "../includes/minitalk.h"

void error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(1);
}
