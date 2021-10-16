#include "../headers_m.h"

void	freetmpfd(int i, t_minish *minish)
{
	int	tempfd;

	if (i % 2 == 0)
		tempfd = open(minish->temp2, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		tempfd = open(minish->temp1, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	close(tempfd);
}

int	rightreddir(int i, t_comm **comm_data, t_minish *minish, int comm_nbr)
{
	int	tempfd;

	if (comm_data[i]->redrflag == 1)
		tempfd = open(comm_data[i]->redr, \
			O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		tempfd = open(comm_data[i]->redr, \
			O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (tempfd < 0)
	{
		printf("minish: %s: No such file or directory\n", \
		comm_data[i]->redl);
		if (i == comm_nbr - 1)
		{
			minish->ex_status = 1;
			return (1);
		}
	}
	dup2(tempfd, STDOUT_FILENO);
	close(tempfd);
	freetmpfd(i, minish);
	return (0);
}

void	writefdchange(int i, t_minish *minish)
{
	int	tempfd;

	if (i % 2 == 0)
		tempfd = open(minish->temp2, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		tempfd = open(minish->temp1, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (tempfd < 0)
		exit(1);
	dup2(tempfd, STDOUT_FILENO);
	close(tempfd);
}

void	pipecicle(t_minish *minish, t_env **env, \
		t_comm **comm_data, int comm_nbr)
{
	int	i;

	i = -1;
	while (++i < comm_nbr)
	{
		if (comm_data[i]->redlflag == 1 && \
		leftreddir(comm_data, i, minish) > 0 && (++i > 0))
			continue ;
		if (comm_data[i]->redlflag == 2 && \
		(doublleft(minish, comm_data, env, i) != 0 ) && (++i > 0))
			continue ;
		else if (i != 0)
			readfdchange(i, minish);
		if ((comm_data[i]->redrflag == 1 || comm_data[i]->redrflag == 2) && \
		(rightreddir(i, comm_data, minish, comm_nbr) != 0 && (++i > 0)))
			continue ;
		else if (i != comm_nbr - 1)
			writefdchange(i, minish);
		else if (!(comm_data[i]->redrflag > 0))
			dup2(minish->oldstdout, STDOUT_FILENO);
		doughter(minish, env, comm_data[i]);
	}
}

int	ourmultipipe(t_minish *minish, t_env **env, \
		t_comm **comm_data, int comm_nbr)
{
	int	tempfd;
	int	oldstdin;

	oldstdin = dup(STDIN_FILENO);
	minish->oldstdout = dup(STDOUT_FILENO);
	pipecicle(minish, env, comm_data, comm_nbr);
	tempfd = open(minish->temp2, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	close (tempfd);
	tempfd = open(minish->temp1, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	close (tempfd);
	dup2(minish->oldstdout, STDOUT_FILENO);
	dup2(oldstdin, STDIN_FILENO);
	close(oldstdin);
	close(minish->oldstdout);
	return (0);
}
