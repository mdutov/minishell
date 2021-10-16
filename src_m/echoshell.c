#include "headers_m.h"

static int	ft_nnnchek(char *line)
{
	int	i;

	i = 1;
	if (line[0] != '-' || line[1] == '\0')
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] != 'n')
			return (-1);
		i++;
	}
	return (0);
}

static void	echo_utils(char **lin, int a, char flag)
{
	while (lin[a] != NULL)
	{
		if (a == 1 && ((ft_strncmp(lin[a], "-n", 3) == 0)
				|| ft_nnnchek(lin[a]) == 0 ))
		{
			a++;
			while (lin[a] != NULL && (ft_strncmp(lin[a], "-n", 3) == 0
					|| ft_nnnchek(lin[a]) == 0))
				a++;
			if (lin[a] == NULL)
				return ;
			flag = '\0';
		}
		if (lin[a + 1] == NULL)
			printf("%s%c", lin[a], flag);
		else
			printf("%s ", lin[a]);
		a++;
	}
}

void	echoshell(t_minish *minish, char **lin)
{
	char	flag;

	flag = '\n';
	minish->ex_status = 0;
	if (lin[1] == NULL)
	{
		printf("\n");
		return ;
	}
	echo_utils(lin, 1, flag);
}
