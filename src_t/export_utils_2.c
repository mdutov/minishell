#include "headers_t.h"

void	copy_name_val(char	*name, char	*val, t_env	**dest, int	i)
{
	(*dest)[i].name = ft_strdup(name);
	(*dest)[i].val = ft_strdup(val);
}

void	copy_one_struct(t_env	**src, t_env	**dest, int	i)
{
	copy_name_val((*src)[i].name, (*src)[i].val, dest, i);
}

void	copy_structs(t_env	**src, t_env	**dest, size_t	len_env)
{
	size_t	i;

	i = 0;
	while (i < len_env)
	{
		copy_one_struct(src, dest, i);
		i++;
	}
}

void	extra_struct(t_env	**export)
{
	t_env	*temp;
	int		len;

	len = ft_strlen_env(export);
	temp = (t_env *)malloc(sizeof(t_env) * (len + 2));
	temp[len].name = NULL;
	temp[len].val = NULL;
	temp[len + 1].name = NULL;
	temp[len + 1].val = NULL;
	copy_structs(export, &temp, len);
	env_clean(export);
	*export = (t_env *)malloc(sizeof(t_env) * (len + 2));
	(*export)[len].name = NULL;
	(*export)[len].val = NULL;
	(*export)[len + 1].name = NULL;
	(*export)[len + 1].val = NULL;
	copy_structs(&temp, export, len);
	env_clean (&temp);
}

int	without_equal(char *s)
{
	int	ret;

	if (ft_strchr(s, '='))
		ret = ft_strchr(s, '=') - s;
	else
		ret = ft_strlen(s);
	return (ret);
}
