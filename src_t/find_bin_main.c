#include "headers_t.h"
#include <sys/stat.h>

int	find_bin_2(t_env	**env, char	**tmp, char	**comm, char	**s)
{
	char		**path;
	struct stat	buf;
	int			i;

	path = NULL;
	i = 0;
	path = create_path(env);
	if (path == NULL)
		return (0);
	while (path[i] != NULL)
	{
		clean_ptr(s);
		clean_ptr(tmp);
		*s = ft_strjoin(path[i], "/");
		*tmp = ft_strjoin(*s, *comm);
		if (stat(*tmp, &buf) == 0)
		{
			clean_ptr(s);
			lin_clean(&path);
			return (1);
		}
		i++;
	}
	return (0);
}

int	find_bin_1(t_env	**env, char		**tmp, char	**comm, struct stat	*buf)
{
	if (*comm[0] == '.')
	{
		*tmp = ft_strjoin((*env)[find_index_equal("PWD", env)].val,
				*comm + 1);
		if (stat(*tmp, buf) == 0)
			return (1);
		clean_ptr(tmp);
	}
	if (*comm[0] == '/')
	{
		*tmp = ft_strdup(*comm);
		if (stat(*tmp, buf) == 0)
			return (1);
		clean_ptr(tmp);
	}
	if (*comm[0] == '~')
	{
		*tmp = ft_strjoin((*env)[find_index_equal("HOME", env)].val,
				*comm + 1);
		if (stat(*tmp, buf) == 0)
			return (1);
		clean_ptr(tmp);
	}
	printf ("minishell: %s: No such file or directory\n", *comm);
	return (0);
}

char	*find_bin(t_env	**env, char	**comm)
{
	char		**path;
	char		*tmp;
	char		*s;
	int			res;
	struct stat	buf;

	path = NULL;
	tmp = NULL;
	s = NULL;
	if (*comm[0] == '.' || *comm[0] == '/' || *comm[0] == '~')
	{
		if (find_bin_1(env, &tmp, comm, &buf) == 1)
			return (tmp);
		return (ft_strdup("non directory"));
	}
	res = find_bin_2(env, &tmp, comm, &s);
	if (res == 1)
		return (tmp);
	clean_ptr(&s);
	lin_clean(&path);
	return (NULL);
}
