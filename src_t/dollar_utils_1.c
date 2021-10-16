#include "headers_t.h"

void	dollar_7(t_doll	*doll)
{
	clean_ptr(&(*doll).tmp_2);
	(*doll).tmp_1 = ft_substr((*doll).dest, 0, (*doll).i);
	(*doll).tmp_2 = ft_strdup((*doll).dest + (*doll).i + (*doll).j);
	clean_ptr(&(*doll).dest);
	(*doll).dest = ft_strjoin((*doll).tmp_1, (*doll).tmp_2);
	clean_ptr(&(*doll).tmp_1);
	clean_ptr(&(*doll).tmp_2);
}

void	dollar_6(t_doll	*doll, t_env **env)
{
	clean_ptr(&(*doll).tmp_2);
	(*doll).tmp_1 = ft_substr((*doll).dest, 0, (*doll).i);
	clean_ptr(&(*doll).dest);
	(*doll).tmp_2 = ft_strdup((*env)[(*doll).index].val);
	(*doll).dest = ft_strjoin((*doll).tmp_1, (*doll).tmp_2);
	clean_ptr(&(*doll).tmp_1);
	clean_ptr(&(*doll).tmp_2);
	(*doll).tmp_1 = ft_strjoin((*doll).dest,
			(*doll).old_dest + (*doll).i + (*doll).j);
	clean_ptr(&(*doll).dest);
	clean_ptr(&(*doll).old_dest);
	(*doll).dest = (*doll).tmp_1;
}

void	dollar_5(t_doll	*doll, t_minish	*minish)
{
	clean_ptr(&(*doll).tmp_2);
	(*doll).tmp_1 = ft_substr((*doll).dest, 0, (*doll).i);
	clean_ptr(&(*doll).dest);
	(*doll).tmp_2 = ft_itoa(minish->ex_status);
	(*doll).dest = ft_strjoin((*doll).tmp_1, (*doll).tmp_2);
	clean_ptr(&(*doll).tmp_1);
	clean_ptr(&(*doll).tmp_2);
	(*doll).tmp_1 = ft_strjoin((*doll).dest,
			(*doll).old_dest + (*doll).i + (*doll).j);
	clean_ptr(&(*doll).dest);
	clean_ptr(&(*doll).old_dest);
	(*doll).dest = (*doll).tmp_1;
}

void	dollar_4(t_doll	*doll, t_env	**env)
{
	(*doll).j = 0;
	while ((*doll).dest[(*doll).i + (*doll).j] != ' '
		&& (*doll).dest[(*doll).i + (*doll).j] != '\t'
		&& (*doll).dest[(*doll).i + (*doll).j] != '\0'
		&& (*doll).dest[(*doll).i + (*doll).j] != '\''
		&& (*doll).dest[(*doll).i + (*doll).j] != '\"'
		&& (*doll).dest[(*doll).i + (*doll).j] != '>'
		&& (*doll).dest[(*doll).i + (*doll).j] != '<')
		(*doll).j++;
	(*doll).tmp_2 = ft_substr((*doll).dest, (*doll).i + 1, (*doll).j - 1);
	(*doll).index = find_index_equal((*doll).tmp_2, env);
}

void	dollar_2(t_doll	*doll)
{
	while ((*doll).dest[(*doll).i] != '$' && (*doll).dest[(*doll).i] != '\0')
	{
		if ((*doll).q2 > 0 && (*doll).dest[(*doll).i] == '\"')
			(*doll).q *= -1;
		if ((*doll).q > 0 && (*doll).dest[(*doll).i] == '\'')
			(*doll).q2 *= -1;
		(*doll).i++;
	}
}
