#include "../../libft/libft.h"
#include "../headers_m.h"
#include "../../src_t/headers_t.h"

void	change_quote(int qcase, char *piplin, t_pars *p, int i)
{
	if (qcase == 1)
	{
		p->q *= -1;
		piplin[i] = -1;
	}
	else if (qcase == 2)
	{
		p->q2 *= -1;
		piplin[i] = -1;
	}
}

void	change_flag_red(t_pars *p)
{
	p->fl *= -1;
	p->fr *= -1;
}

int	reddir_cases(t_pars *p, t_comm *commdata, int i, char *piplin)
{
	if (piplin[i] == '>')
		return (right_redd(p, commdata, i, piplin));
	else if (piplin[i] == '<')
		return (left_redd(p, commdata, i, piplin));
	return (i);
}

void	parser_comm_cicle(char *piplin, t_comm *commdata, t_pars *p, int i)
{
	while (piplin[i] != '\0')
	{
		if ((p->q > 0 && p->q2 > 0) && (p->end != p->st) && (piplin[i] == '>' \
		|| piplin[i] == '<') && (!p->fl && !p->fr) && (piplin[i - 1] != ' '))
			argbefor_red(p, commdata, piplin);
		p->end = i;
		if (p->q2 > 0 && piplin[i] == '\"')
			change_quote(1, piplin, p, i);
		if (p->q > 0 && piplin[i] == '\'')
			change_quote(2, piplin, p, i);
		if (p->q > 0 && p->q2 > 0 && (piplin[i] == '>' || piplin[i] == '<'))
		{
			i = reddir_cases(p, commdata, i, piplin);
			continue ;
		}
		if ((p->fl > 0 || p->fr > 0) && piplin[i] != ' ')
			change_flag_red(p);
		if ((p->q > 0 && p->q2 > 0) && (p->end != p->st) && (piplin[i] == ' '
				|| piplin[i] == '>' || piplin[i] == '<'))
			i = newarg_add(p, commdata, i, piplin);
		else if ((p->q > 0 && p->q2 > 0) && piplin[i] == ' ' && (++i > 0))
			p->st = i;
		else
			i = past_arg(p, commdata, i, piplin);
	}
}

t_comm	*parser_commline(char *piplin)
{
	t_comm	*commdata;
	t_pars	*p;

	p = (t_pars *)malloc(sizeof(t_pars) * 1);
	commdata = (t_comm *)malloc(sizeof(t_comm) * 1);
	initdata(commdata, p);
	parser_comm_cicle(piplin, commdata, p, 0);
	if (p->numarg != 0)
		(*commdata).argum[p->numarg] = NULL;
	else
		return (NULL);
	cutquot(commdata);
	free(p);
	p = NULL;
	return (commdata);
}
