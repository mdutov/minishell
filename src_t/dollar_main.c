#include "headers_t.h"

/*

1) Если пробел после доллара - оставить доллар
2) Если нашли - замена
3) Если не нашли - склейка

*/

void	dollar_3(t_doll	*doll, t_env	**env, t_minish	*minish)
{
	dollar_4(doll, env);
	if (ft_strncmp((*doll).tmp_2, "?", 2) == 0)
		dollar_5(doll, minish);
	else if ((*doll).index >= 0
		&& (*env)[(*doll).index].val != NULL)
		dollar_6(doll, env);
	else
		dollar_7(doll);
}

void	dollar_1(t_doll	*doll, t_env	**env, t_minish	*minish)
{
	while ((*doll).k < (*doll).n_dol)
	{
		(*doll).old_dest = ft_strdup((*doll).dest);
		(*doll).i = (*doll).old_i;
		dollar_2(doll);
		if ((*doll).dest[(*doll).i] == '$' && (*doll).q2 > 0)
		{
			if (true_doll(doll))
				dollar_3(doll, env, minish);
			else if ((*doll).dest[(*doll).i + 1] == ' ')
			{
				(*doll).flag = 1;
				(*doll).k++;
				(*doll).old_i = (*doll).i + 1;
				clean_ptr(&(*doll).old_dest);
				continue ;
			}
			clean_ptr(&(*doll).old_dest);
			if ((*doll).flag != 1)
				(*doll).old_i = 0;
			(*doll).k++;
		}
		else
			return ;
	}
}

void	dollar_nbr(t_doll	*doll)
{
	doll->i = 0;
	doll->n_dol = 0;
	while (doll->dest[doll->i])
	{
		if (doll->dest[doll->i] == '$')
		{
			while (doll->dest[doll->i] == '$')
				doll->i++;
			doll->n_dol++;
		}
		else
			doll->i++;
	}
	doll->i = 0;
	doll->j = 0;
	doll->k = 0;
	doll->q = 1;
	doll->q2 = 1;
	doll->flag = 0;
	doll->old_i = 0;
}

char	*dollar(char	*src, t_env	**env, t_minish	*minish)
{
	t_doll	*doll;

	doll = (t_doll *)malloc(sizeof(t_doll));
	doll->dest = ft_strdup(src);
	dollar_nbr(doll);
	dollar_1(doll, env, minish);
	free(doll);
	return (doll->dest);
}

char	*doll(char	*line, t_env	**env, t_minish	*minish)
{
	char	*new;

	new = NULL;
	new = dollar(line, env, minish);
	return (new);
}
