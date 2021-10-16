#include "headers_t.h"

void	bubbleSort_1(t_env **tmp, int *j, int *bool)
{
	char	*k;
	int		p;

	p = 0;
	while ((*tmp)[*j].name[p] == (*tmp)[*j + 1].name[p])
		p++;
	if ((*tmp)[*j].name[p] > (*tmp)[*j + 1].name[p])
	{
		k = (*tmp)[*j].name;
		(*tmp)[*j].name = (*tmp)[*j + 1].name;
		(*tmp)[*j + 1].name = k;
		k = (*tmp)[*j].val;
		(*tmp)[*j].val = (*tmp)[*j + 1].val;
		(*tmp)[*j + 1].val = k;
		*bool = 0;
	}
	(*j)++;
}

void	bubbleSort(t_env **export, size_t len)
{
	int		bool;
	t_env	*tmp;
	int		i;
	int		j;

	bool = 1;
	i = len - 1;
	tmp = *export;
	while (i >= 0)
	{
		j = 0;
		while (j < i)
			bubbleSort_1(&tmp, &j, &bool);
		if (bool == 1)
			break ;
		i--;
	}
}
