#include <stdio.h>
#include "../../libft/libft.h"
#include "../headers_m.h"

int	pipnumb(char *line)
{
	int	i;
	int	q;
	int	q_two;
	int	howmanypip;

	howmanypip = 0;
	i = 0;
	q = 1;
	q_two = 1;
	while (line[i] != '\0')
	{
		if (line[i] == '\"' && q_two > 0)
			q *= -1;
		if (line[i] == '\'' && q > 0)
			q_two *= -1;
		if (line[i] == '|' && q > 0 && q_two > 0)
			howmanypip++;
		if ((line[i] == '|' && line[i + 1] == '|' )
			|| (line[i] == '|' && line[i + 1] == '\0'))
			return (-1);
		i++;
	}
	return (howmanypip);
}

static int	linegen_util(char *lin, int aa, int a)
{
	int	q;
	int	q_two;
	int	i;

	q = 1;
	q_two = 1;
	i = 0;
	while (lin[i] != '\0' && aa < a)
	{
		if (lin[i] == '\"' && q_two > 0)
			q *= -1;
		if (lin[i] == '\'' && q > 0)
			q_two *= -1;
		if (lin[i] == '|' && q > 0 && q_two > 0)
			aa++;
		i++;
	}
	return (i);
}

char	*linegen(int a, char *lin)
{
	int		i;
	int		q;
	int		q_two;
	int		ind;
	char	*newlin;

	i = linegen_util(lin, 0, a);
	if (lin[i] == '\0')
		return (NULL);
	ind = 1;
	q = 1;
	q_two = 1;
	while (lin[i + ind] != '\0')
	{
		if (lin[i + ind] == '\"' && q_two > 0)
			q *= -1;
		if (lin[i + ind] == '\'' && q > 0)
			q_two *= -1;
		if (lin[i + ind] == '|' && q > 0 && q_two > 0)
			break ;
		ind++;
	}
	newlin = ft_substr(lin, i, ind);
	return (newlin);
}

void	parser_pipe_1(int	*pipn, char	*pip_line, char	***commline, int	*a)
{
	while (*pipn >= 0 && *a < *pipn + 1)
	{
		(*commline)[*a] = linegen(*a, pip_line);
		(*a)++;
	}
	if (*pipn == 0)
	{
		clean_ptr(&(*commline)[0]);
		(*commline)[0] = ft_strdup(pip_line);
	}
}

void	parser_pipe(char *pip_line, int *b, char	***commline)
{
	int		pipn;
	int		a;
	int		aa;

	pipn = pipnumb(pip_line);
	if (pipn == -1)
	{
		(*commline) = NULL;
		return ;
	}
	(*commline) = (char **)malloc(sizeof(char *) * (pipn + 2));
	(*commline)[pipn + 1] = NULL;
	a = 0;
	parser_pipe_1(&pipn, pip_line, commline, &a);
	aa = 0;
	while (aa < a)
		aa++;
	*b = a;
}
