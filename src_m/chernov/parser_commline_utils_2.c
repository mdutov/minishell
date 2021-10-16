#include "../../libft/libft.h"
#include "../headers_m.h"
#include "../../src_t/headers_t.h"

char	**newargarr(char **argum, int num)
{
	char	**newarg;
	int		i;

	i = 0;
	newarg = (char **)malloc(sizeof (char *) * (num + 2));
	if (argum == NULL)
	{
		newarg[1] = NULL;
		return (newarg);
	}
	while (i < num)
	{
		newarg[i] = ft_strdup(argum[i]);
		free(argum[i]);
		argum[i] = NULL;
		i++;
	}
	free(argum);
	argum = NULL;
	return (newarg);
}

char	*bezkav(char *sub, int q, int i)
{
	char	*bez;

	if (sub == NULL)
		return (NULL);
	while (sub[++i] != '\0')
	{
		if (sub[i] == -1)
			q++;
	}
	if (q == 0)
		return (sub);
	bez = malloc(sizeof (char) * (ft_strlen(sub) - q + 1));
	i = -1;
	q = 0;
	while (sub[++i] != '\0')
	{
		if (sub[i] == -1)
			continue ;
		else
			bez[q] = sub[i];
		q++;
	}
	bez[q] = '\0';
	clean_ptr(&sub);
	return (bez);
}

void	cutquot(t_comm *commda)
{
	int	i;

	i = 0;
	while ((*commda).argum[i] != NULL)
	{
		(*commda).argum[i] = bezkav((*commda).argum[i], 0, -1);
		i++;
	}
	(*commda).redr = bezkav((*commda).redr, 0, -1);
	(*commda).redl = bezkav((*commda).redl, 0, -1);
}

void	argbefor_red(t_pars *p, t_comm *commdata, char *piplin)
{
	(*commdata).argum = newargarr((*commdata).argum, p->numarg);
	(*commdata).argum[p->numarg] = ft_substr(piplin, \
	p->st, p->end - p->st);
	p->numarg++;
}
