#include "headers_t.h"

int	export_main_4(t_minish	*minish, char **lin, int *i)
{
	char	*n;

	n = check_valid(lin[*i]);
	if (n != NULL)
	{
		printf("minishell: export: `%s': not a valid identifier\n", n);
		minish->ex_status = 1;
		return (1);
	}
	return (0);
}

void	export_main_3(t_env	**env, t_minish	*minish, t_env	**export)
{
	env_clean(env);
	dublicate_env(export, env);
	env_clean(export);
	minish->ex_status = 0;
}

void	export_main_1(t_env	**export, char	***lin, int *i)
{
	char	**s;
	char	*tmp;
	char	*n;

	extra_struct(export);
	n = ft_strchr((*lin)[*i], '=');
	if ((n && *(++n) == '\0') || n == NULL)
		copy_name_val((*lin)[*i], NULL, export, ft_strlen_env(export));
	n = ft_strchr((*lin)[*i], '=');
	if (n && *(++n) != '\0')
	{
		s = ft_split((*lin)[*i], '=');
		tmp = ft_strjoin(s[0], "=");
		copy_name_val(tmp, s[1], export, ft_strlen_env(export));
		lin_clean(&s);
		clean_ptr(&tmp);
	}
}

void	export_main_2(char ***lin, t_env	**export, int flag, int *i)
{
	flag = name_check_export((*lin)[*i], export);
	if (flag > 0)
		rename_export((*lin)[*i], export, flag);
	else
		export_main_1(export, lin, i);
}

int	export_main(t_env	**env, t_minish	*minish, char	**lin)
{
	t_env	*export;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	export = NULL;
	if (lin_null(&export, lin, &i, env) != -500)
		return (minish->ex_status);
	dublicate_env(env, &export);
	while (lin[i])
	{
		if (export_main_4(minish, lin, &i) == 1)
		{
			env_clean(&export);
			return (1);
		}
		export_main_2(&lin, &export, flag, &i);
		i++;
	}
	export_main_3(env, minish, &export);
	return (minish->ex_status);
}
