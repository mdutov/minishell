#include "../src_t/headers_t.h"

size_t	ft_strlen_env(t_env	**env)
{
	int	i;

	i = 0;
	if (*env)
		while ((*env)[i].name)
			i++;
	return (i);
}

size_t	ft_strlen_engv(char	**s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	copy_env_1(t_env **env, size_t	len_name)
{
	len_name = ft_strlen_env(env);
	extra_struct(env);
	(*env)[len_name].name = ft_strdup("OLDPWD=");
	(*env)[len_name].val = ft_strdup("");
}

void	copy_env(t_env **env, char **engv, size_t	len_name)
{
	int		i;
	char	*n;

	i = 0;
	while (engv[i])
	{
		if (ft_strchr(engv[i], '='))
			len_name = (size_t)(ft_strchr(engv[i], '=') - &engv[i][0] + 1);
		else
			len_name = ft_strlen(engv[i]);
		(*env)[i].name = ft_substr(engv[i], 0, len_name);
		n = ft_strchr(engv[i], '=');
		if (n && *(++n) != '\0')
			(*env)[i].val = ft_strdup(ft_strchr(engv[i], '=') + 1);
		else
			(*env)[i].val = NULL;
		i++;
	}
	if (find_index_equal("OLDPWD", env) >= 0)
		return ;
	else
		copy_env_1(env, len_name);
}
