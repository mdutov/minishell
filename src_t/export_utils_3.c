#include "headers_t.h"

void	print_export_0(t_env	**env, t_minish	*minish, t_env	**export)
{
	dublicate_env(env, export);
	bubbleSort(export, ft_strlen_env(env));
	print_export(export);
	minish->ex_status = 0;
}

void	clean_ptr_1(char	**s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

int	rename_export(char	*lin, t_env	**export, int	flag)
{
	int	i;

	i = find_index_equal(lin, export);
	if (flag == 1)
	{
		clean_ptr(&(*export)[i].val);
		(*export)[i].val = ft_strdup(ft_strchr(lin, '=') + 1);
	}
	if (flag == 2)
		clean_ptr_1(&(*export)[i].val);
	if (flag == 1 || flag == 2)
		addition_equal(export, i);
	return (0);
}

int	name_check_export(char	*lin, t_env	**export)
{
	int		i;
	int		len;
	char	*n;

	i = 0;
	len = ft_strlen_env(export);
	while (i < len)
	{
		if (find_index_equal(lin, export) >= 0)
		{
			n = ft_strchr(lin, '=');
			if (n == NULL)
				return (3);
			if (n && *(n + 1) != '\0')
				return (1);
			if (n && *(n + 1) == '\0')
				return (2);
			return (-1);
		}
		i++;
	}
	return (0);
}
