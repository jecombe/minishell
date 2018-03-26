#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXCOM 1000
#define MAXLIST 100
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

void		printDir(void)
{
	char	cwd[1024];
	getcwd(cwd, sizeof(cwd));
}
void		init_shell(void)
{
	ft_putendl("---------------------------------");
	ft_putendl("|	MINISHELL		|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("---------------------------------");
}

int main()
{
	char	inputString[MAXCOM];
	char	*parseArgs[MAXLIST];
	char	*parseArgsPiped[MAXLIST];
	int execflag;

	execflag = 0;
	init_shell();
	while (1)
	{
		printDir();
		get_next_line(0, 0);
	}
}

