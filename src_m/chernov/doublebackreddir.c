#include "../headers_m.h"
#include "../../src_t/headers_t.h"

void	double_util_1(char	***line, char	**ret, char	**tmp)
{
	clean_ptr(ret);
	*ret = *tmp;
	*tmp = ft_strjoin(*ret, **line);
	clean_ptr(ret);
	*ret = *tmp;
}

static char	*double_util(char **line, char *ret, char *argv, t_env **env)
{
	t_minish	*minish_1;
	char		*tmp;

	tmp = NULL;
	minish_1 = ret_minish();
	while (ft_strncmp(argv, *line, ft_strlen(argv) + 1) != 0)
	{
		clean_ptr(line);
		*line = readline(">");
		if (ft_strncmp(argv, *line, ft_strlen(argv) + 1) == 0)
		{
			clean_ptr(line);
			break ;
		}
		if (ret != NULL)
			tmp = ft_strjoin(ret, "\n");
		double_util_1(&line, &ret, &tmp);
		tmp = doll(ret, env, minish_1);
		clean_ptr(&ret);
		ret = tmp;
	}
	clean_ptr(line);
	return (tmp);
}

int	doublebackreddir(t_minish *minish, char *argv, t_env **env)
{
	char	*line;
	char	*ret;
	int		fd;

	line = NULL;
	ret = NULL;
	if (argv == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		minish->ex_status = (258);
		return (258);
	}
	ret = double_util(&line, ret, argv, env);
	fd = open(minish->tempredl, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, &(ret[0]), ft_strlen(ret));
	write(fd, "\n", 1);
	close(fd);
	clean_ptr(&ret);
	clean_ptr(&line);
	return (0);
}
