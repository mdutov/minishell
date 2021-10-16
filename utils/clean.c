#include "../src_t/headers_t.h"

void	env_clean(t_env	**env)
{
	int	i;

	i = 0;
	if ((*env) == NULL)
		return ;
	while ((*env)[i].name)
	{
		free((*env)[i].name);
		(*env)[i].name = NULL;
		if ((*env)[i].val)
		{
			free((*env)[i].val);
			(*env)[i].val = NULL;
		}
		i++;
	}
	free(*env);
	*env = NULL;
}

void	lin_clean(char	***lin)
{
	int	i;

	i = 0;
	if (*lin == NULL)
		return ;
	while ((*lin)[i])
	{
		free((*lin)[i]);
		(*lin)[i] = NULL;
		i++;
	}
	free((*lin));
	(*lin) = NULL;
}

void	clean_ptr(char	**s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

void	clean_data(t_comm	***comm_data)
{
	int	i;

	i = 0;
	if (**comm_data != NULL)
	{
		while ((*comm_data)[i] != NULL)
		{
			lin_clean(&(*comm_data)[i]->argum);
			clean_ptr(&(*comm_data)[i]->redr);
			clean_ptr(&(*comm_data)[i]->redl);
			free((*comm_data)[i]);
			(*comm_data)[i] = NULL;
			i++;
		}
	}
	else
		return ;
	free(*comm_data);
	*comm_data = NULL;
}
