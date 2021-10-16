#include "../headers_m.h"

int	leftreddir(t_comm **comm_data, int i, t_minish *minish)
{
	int	tempfd;

	tempfd = open(comm_data[i]->redl, O_RDONLY, S_IRWXU);
	if (tempfd < 0)
	{
		printf("minishell: %s: No such file or directory\n", \
			comm_data[i]->redl);
		minish->ex_status = 1;
		return (1);
	}
	dup2(tempfd, STDIN_FILENO);
	close(tempfd);
	return (0);
}

int	doublleft(t_minish *minish, t_comm **comm_data, t_env **env, int i)
{
	int	tempfd;

	if (doublebackreddir(minish, comm_data[i]->redl, env) == 0)
	{
		tempfd = open(minish->tempredl, O_RDONLY, S_IRWXU);
		dup2(tempfd, STDIN_FILENO);
		close(tempfd);
		return (0);
	}
	else
		return (1);
}

void	readfdchange(int i, t_minish *minish)
{
	int	tempfd;

	if (i % 2 == 0)
		tempfd = open(minish->temp1, O_RDONLY, S_IRWXU);
	else
		tempfd = open(minish->temp2, O_RDONLY, S_IRWXU);
	if (tempfd < 0)
		exit(1);
	dup2(tempfd, STDIN_FILENO);
	close(tempfd);
}
