#include "../../libft/libft.h"
#include "../headers_m.h"
#include "../../src_t/headers_t.h"

void	initdata(t_comm *commdata, t_pars *p)
{	
	(*commdata).redr = NULL;
	(*commdata).redl = NULL;
	(*commdata).argum = NULL;
	(*commdata).fdin = 0;
	(*commdata).fdout = 1;
	(*commdata).redrflag = 0;
	(*commdata).redlflag = 0;
	(*p).q = 1;
	(*p).q2 = 1;
	(*p).numarg = 0;
	(*p).st = 0;
	(*p).end = 0;
	(*p).fl = 0;
	(*p).fr = 0;
}

int	right_redd(t_pars *p, t_comm *commdata, int i, char *piplin)
{
	if (piplin[i + 1] == '>')
	{
		p->fr = 2;
		(*commdata).redrflag = 2;
		i++;
	}
	else
	{
		p->fr = 1;
		(*commdata).redrflag = 1;
	}
	i++;
	p->st = i;
	return (i);
}

int	left_redd(t_pars *p, t_comm *commdata, int i, char *piplin)
{
	if (piplin[i + 1] == '<')
	{
		p->fl = 2;
		(*commdata).redlflag = 2;
		i++;
	}
	else
	{
		p->fl = 1;
		(*commdata).redlflag = 1;
	}
	i++;
	p->st = i;
	return (i);
}

int	newarg_add(t_pars *p, t_comm *commdata, int i, char *piplin)
{
	if (!p->fr && !p->fl)
	{
		(*commdata).argum = newargarr((*commdata).argum, p->numarg);
		(*commdata).argum[p->numarg] = ft_substr(piplin, \
			p->st, p->end - p->st);
		p->numarg++;
	}
	else if (p->fr == -1 || p->fr == -2)
	{
		if ((*commdata).redr != NULL)
			free((*commdata).redr);
		(*commdata).redr = ft_substr(piplin, p->st, p->end - p->st);
		p->fr = 0;
	}
	else if (p->fl == -1 || p->fl == -2)
	{
		if ((*commdata).redl != NULL)
			free((*commdata).redl);
		(*commdata).redl = ft_substr(piplin, p->st, p->end - p->st);
		p->fl = 0;
	}
	i++;
	p->st = i;
	return (i);
}

int	past_arg(t_pars *p, t_comm *commdata, int i, char *piplin)
{
	i++;
	p->end = i;
	if (piplin[i] == '\0' && p->st != p->end)
	{
		if (!p->fr && !p->fl)
		{
			(*commdata).argum = newargarr((*commdata).argum, p->numarg);
			(*commdata).argum[p->numarg] = ft_substr(piplin, \
				p->st, i - p->st);
			p->numarg++;
		}
		else if (!p->fr)
		{
			clean_ptr(&(*commdata).redr);
			(*commdata).redl = ft_substr(piplin, p->st, i - p->st);
		}
		else if (!p->fl)
		{
			clean_ptr(&(*commdata).redr);
			(*commdata).redr = ft_substr(piplin, p->st, i - p->st);
		}
	}
	return (i);
}
