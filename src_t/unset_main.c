#include "headers_t.h"

void	delete_unset(t_env	**unset, int	i)
{
	int	len;

	len = ft_strlen_env(unset);
	free((*unset)[i].name);
	(*unset)[i].name = NULL;
	free((*unset)[i].val);
	(*unset)[i].val = NULL;
	if (i < len - 1)
	{
		(*unset)[i].name = ft_strdup((*unset)[len - 1].name);
		(*unset)[i].val = ft_strdup((*unset)[len - 1].val);
		free((*unset)[len - 1].name);
		(*unset)[len - 1].name = NULL;
		free((*unset)[len - 1].val);
		(*unset)[len - 1].val = NULL;
	}
}

int	find_index_unset(char	*lin, t_env	**unset)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = ft_strlen_env(unset);
	flag = 0;
	while (i < len)
	{
		if (ft_strncmp((*unset)[i].name,
			lin, without_equal((*unset)[i].name)) == 0
			&& ft_strncmp((*unset)[i].name, lin, ft_strlen(lin)) == 0)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag)
		return (i);
	return (-1);
}

void	unset_main_1(char	**lin, t_env	**unset, t_env	**env, int	*index)
{
	int	i;

	i = 1;
	dublicate_env(env, unset);
	while (lin[i])
	{
		*index = find_index_unset(lin[i], unset);
		if (*index >= 0)
			delete_unset(unset, *index);
		i++;
	}
	env_clean(env);
	dublicate_env(unset, env);
	env_clean(unset);
}

int	unset_main(t_env	**env, t_minish	*minish, char	**lin)
{
	char	*n;
	int		index;
	t_env	*unset;

	if (lin[1] == NULL)
		return (minish->ex_status = 0);
	n = check_valid(lin[1]);
	if (n != NULL)
	{
		printf("minishell: export: `%s': not a valid identifier\n", n);
		minish->ex_status = 1;
		return (1);
	}
	unset_main_1(lin, &unset, env, &index);
	minish->ex_status = 0;
	return (minish->ex_status);
}
