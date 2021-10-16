#include	"headers_t.h"

void	print_env(t_env	**env)
{
	int	i;

	i = 0;
	while ((*env)[i].name)
	{
		if (ft_strchr((*env)[i].name, '='))
		{
			printf("%s", (*env)[i].name);
			if ((*env)[i].val)
				printf("%s\n", (*env)[i].val);
			else
				printf("\n");
		}
		i++;
	}
}

int	env_main(t_env	**env, t_minish	*minish, char	**lin)
{
	if (lin[1] == NULL)
	{
		print_env(env);
		minish->ex_status = 0;
	}
	return (0);
}
