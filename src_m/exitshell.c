#include "headers_m.h"

long long int	atoi_shell(char *b)
{
	int				k;
	long long int	cc;

	k = 0;
	cc = 0;
	while (b[k] != '\0')
	{
		if (k == 0 && b[k] == '-')
		{
			k++;
			continue ;
		}
		if (b[k] < '0' || b[k] > '9')
			return (-1);
		cc += b[k++] - '0';
		if (b[k] != '\0')
			cc *= 10;
	}
	return (0);
}

void	ft_exit(t_minish *minish, char **lin)
{
	int	j;

	if (lin == NULL || lin[1] == NULL)
	{
		printf("exit\n");
		exit(minish->ex_status);
	}
	j = atoi_shell(lin[1]);
	if (j < 0)
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", lin[1]);
		exit(255);
	}
	else if (lin[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		minish->ex_status = 1;
	}
	else
	{
		printf("exit\n");
		exit(ft_atoi(lin[1]));
	}
}
