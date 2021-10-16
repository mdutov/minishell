#include "../src_t/headers_t.h"
#include "../src_m/headers_m.h"

int	tabandspace(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] == ' ' || line[i] == '\t'))
			break ;
		i++;
	}
	if (line[i] != '\0')
		return (1);
	return (0);
}

void	shell_lvl(t_env **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*env)[i].name != NULL)
	{
		if (ft_strncmp("SHLVL=", (*env)[i].name, 7) == 0)
		{
			tmp = ft_itoa((int)ft_atoi((*env)[i].val) + 1);
			free ((*env)[i].val);
			(*env)[i].val = ft_strdup(tmp);
			free (tmp);
		}
		i++;
	}
}

t_minish	*ret_minish(void)
{
	static t_minish	minish;

	return (&minish);
}

void	ft_ignor(int sig)
{
	t_minish	*minish_1;

	minish_1 = ret_minish();
	(void)sig;
	if (minish_1->signal == 1)
	{
		minish_1->ex_status = 1;
		printf("minishell>%s  \n", rl_line_buffer);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	minish_init(t_minish *minish, t_env **env)
{
	int	i;

	i = 0;
	minish->signal = 1;
	while ((*env)[i].name != NULL)
	{
		if (ft_strncmp((*env)[i].name, "HOME", 4) == 0)
			break ;
		i++;
	}
	if ((*env)[i].name == NULL)
		exit (1);
	minish->temp1 = ft_strjoin((*env)[i].val, "/temp1");
	minish->temp2 = ft_strjoin((*env)[i].val, "/temp2");
	minish->tempredl = ft_strjoin((*env)[i].val, "/tempredl");
}
