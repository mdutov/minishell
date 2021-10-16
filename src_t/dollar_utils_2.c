#include "headers_t.h"

int	true_doll(t_doll	*doll)
{
	if ((*doll).dest[(*doll).i + 1] != ' '
		&& (*doll).dest[(*doll).i + 1] != '\t'
		&& (*doll).dest[(*doll).i + 1] != '\0'
		&& (*doll).dest[(*doll).i + 1] != '\"'
		&& (*doll).dest[(*doll).i + 1] != '\'')
		return (1);
	return (0);
}
