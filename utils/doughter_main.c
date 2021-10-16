#include "../src_t/headers_t.h"

void	doughter_3(t_minish	*minish, int	*status)
{
	wait(status);
	minish->ex_status = WEXITSTATUS(*status);
	signal(SIGINT, ft_ignor);
	if (WTERMSIG(*status) == SIGINT)
	{
		minish->ex_status = 130;
		printf("\n");
	}
	if (WTERMSIG(*status) == SIGQUIT)
	{
		printf("Quit: 3\n");
		minish->ex_status = 131;
	}
	minish->signal = 1;
}

void	doughter_2(t_comm	*comm_data)
{
	if (opendir(comm_data->argum[0]) != NULL)
	{
		printf("minishell: %s: is a directory\n",
			comm_data->argum[0]);
		exit (126);
	}
}

void	doughter_1(t_env	**env,
		t_comm	*comm_data, char	***new_env)
{
	char	*bin;

	bin = NULL;
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	bin = find_bin(env, &(comm_data->argum[0]));
	if (bin == NULL)
	{
		printf("minishell: %s: command not found\n",
			comm_data->argum[0]);
		exit (127);
	}
	else if (comm_data->argum[0][0] == '\0')
	{
		printf("minishell: : command not found\n");
		exit (127);
	}
	if (bin != NULL && ft_strncmp(bin, "non directory", 14) != 0)
		execve(bin, comm_data->argum, *new_env);
	clean_ptr (&bin);
}

int	doughter(t_minish	*minish, t_env	**env, t_comm	*comm_data)
{
	char	**new_env;
	int		status;
	pid_t	t;

	new_env = NULL;
	new_env = struct_to_string(env);
	if (find_build_index(comm_data->argum, minish, env))
	{
		lin_clean(&new_env);
		return (minish->ex_status);
	}
	minish->signal = 0;
	t = fork();
	signal(SIGINT, SIG_IGN);
	if (t == 0)
		doughter_1(env, comm_data, &new_env);
	else
		doughter_3(minish, &status);
	lin_clean(&new_env);
	return (0);
}
