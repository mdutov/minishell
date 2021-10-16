#include "headers_t.h"

int	find_index_path(t_env	**env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_env(env);
	while (i < len)
	{
		if (ft_strncmp((*env)[i].name, "PATH=", 6) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**create_path(t_env **env)
{
	int		i;
	char	**path;

	path = NULL;
	i = find_index_path(env);
	if (i >= 0)
		path = ft_split((*env)[i].val, ':');
	return (path);
}

char	**struct_to_string(t_env	**env)
{
	int		len;
	int		i;
	char	**newenviron1;

	len = ft_strlen_env(env);
	newenviron1 = (char **)malloc(sizeof(char *) * (len + 1));
	newenviron1[len] = NULL;
	i = 0;
	while (i < len)
	{
		newenviron1[i] = ft_strjoin((*env)[i].name, (*env)[i].val);
		i++;
	}
	return (newenviron1);
}
