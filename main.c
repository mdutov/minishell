#include "./src_t/headers_t.h"
#include "./src_m/headers_m.h"

int	comm_data_cicle(t_comm **comm_data, int comm_nbr,
	t_minish *minish, char **commlines)
{
	int	i;

	i = 0;
	while (i < comm_nbr)
	{
		comm_data[i] = parser_commline(commlines[i]);
		if (comm_data[i] == NULL)
		{
			minish->ex_status = 258;
			printf("minishell: syntax error near unexpected token\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	tokenerror(t_minish *minish)
{
	printf("minishell: syntax error near unexpected token |\n");
	minish->ex_status = 258;
	return (1);
}

static int	parser(t_env **env, t_minish *minish, char *line)
{
	char	**commlines;
	t_comm	**comm_data;
	int		comm_nbr;
	char	*line_2;

	commlines = NULL;
	comm_data = NULL;
	if (line == NULL)
	{
		printf("\033[Aminishell> exit\n");
		exit (minish->ex_status);
	}
	if (tabandspace(line) == 0)
		return (0);
	line_2 = doll(line, env, minish);
	parser_pipe(line_2, &comm_nbr, &commlines);
	clean_ptr(&line_2);
	if (parser_2(&comm_data, minish, &commlines) == 0)
		return (0);
	if (parser_1(&comm_data, &comm_nbr, minish, &commlines) == 1)
		return (1);
	ourmultipipe(minish, env, comm_data, comm_nbr);
	clean_data(&comm_data);
	lin_clean(&commlines);
	return (minish->ex_status);
}

void	execute(t_env	**env, t_minish	*minish)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("minishell>");
		if (ft_strlen(line) > 0)
			add_history(line);
		parser(env, minish, line);
		clean_ptr(&line);
	}
}

int	main(int argc, char **argv, char **engv)
{
	t_minish	*minish;
	t_env		*env;

	(void)argc;
	(void)argv;
	env = (t_env *)malloc(sizeof(t_env) * (ft_strlen_engv(engv) + 1));
	env[ft_strlen_engv(engv)].name = NULL;
	env[ft_strlen_engv(engv)].val = NULL;
	minish = ret_minish();
	copy_env(&env, engv, 0);
	minish_init(minish, &env);
	shell_lvl(&env);
	signal(SIGINT, ft_ignor);
	signal(SIGQUIT, SIG_IGN);
	execute(&env, minish);
	env_clean(&env);
	return (0);
}
