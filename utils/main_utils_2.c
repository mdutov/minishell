#include "../src_t/headers_t.h"
#include "../src_m/headers_m.h"

int	parser_1(t_comm	***comm_data, int	*comm_nbr,
		t_minish *minish, char	***commlines)
{
	*comm_data = (t_comm **)malloc(sizeof(t_comm *) * (*comm_nbr + 1));
	(*comm_data)[*comm_nbr] = NULL;
	if (comm_data_cicle(*comm_data, *comm_nbr, minish, *commlines) != 0)
	{
		clean_data(comm_data);
		lin_clean(commlines);
		return (1);
	}
	return (0);
}

int	parser_2(t_comm ***comm_data, t_minish *minish, char ***commlines)
{
	if (*commlines == NULL && (tokenerror(minish) > 0))
	{
		clean_data(comm_data);
		lin_clean(commlines);
		return (0);
	}
	return (-500);
}
