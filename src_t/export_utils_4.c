#include "headers_t.h"

int	check_valid_2(char	**lin, int *i)
{
	if (((*lin)[*i] >= 48 && (*lin)[*i] <= 57)
		|| (*lin)[*i] == ' ')
		return (1);
	while ((*lin)[*i])
	{
		if (((*lin)[*i] >= 65 && (*lin)[*i] <= 90)
			|| ((*lin)[*i] >= 97 && (*lin)[*i] <= 122)
			|| ((*lin)[*i] >= 48 && (*lin)[*i] <= 57)
			|| (*lin)[*i] == '_')
			(*i)++;
		else
			return (1);
	}
	return (0);
}

int	check_valid_1(char	**lin, int *i, char *n)
{
	if (((*lin)[0] >= 48 && (*lin)[0] <= 57)
		|| (*lin)[0] == ' ')
		return (1);
	while ((*lin) + *i < n)
	{
		if (((*lin)[*i] >= 65 && (*lin)[*i] <= 90)
			|| ((*lin)[*i] >= 97 && (*lin)[*i] <= 122)
			|| ((*lin)[*i] >= 48 && (*lin)[*i] <= 57)
			|| (*lin)[*i] == '_')
			(*i)++;
		else
			return (1);
	}
	(*i)++;
	while ((*lin)[*i])
	{
		if (((*lin)[*i] >= 65 && (*lin)[*i] <= 90)
			|| ((*lin)[*i] >= 97 && (*lin)[*i] <= 122)
			|| ((*lin)[*i] >= 48 && (*lin)[*i] <= 57)
			|| (*lin)[*i] == '_' || (*lin)[*i] == ' ')
			(*i)++;
		else
			return (1);
	}
	return (0);
}

char	*check_valid(char *lin)
{
	char	*n;
	int		i;
	int		ret;

	i = 0;
	n = ft_strchr(lin, '=');
	if (n != NULL)
	{
		if (n == lin)
			return (lin);
		else
		{
			ret = check_valid_1(&lin, &i, n);
			if (ret == 1)
				return (lin);
		}
	}
	else if (check_valid_2(&lin, &i) == 1)
		return (lin);
	return (NULL);
}

int	lin_null(t_env	**export, char	**lin, int *i, t_env	**env)
{
	t_minish	*minish;

	minish = ret_minish();
	if (lin[*i] == NULL)
	{
		print_export_0(env, minish, export);
		env_clean(export);
		return (minish->ex_status);
	}
	return (-500);
}
