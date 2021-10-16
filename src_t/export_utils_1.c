#include "headers_t.h"

void	print_export(t_env	**export)
{
	int	i;

	i = 0;
	while ((*export)[i].name)
	{
		printf("declare -x ");
		printf("%s", (*export)[i].name);
		if ((*export)[i].val)
			printf("\"%s\"\n", (*export)[i].val);
		else if (ft_strchr((*export)[i].name, '='))
			printf("\"\"\n");
		else
			printf("\n");
		i++;
	}
}

void	dublicate_env(t_env	**src, t_env	**dest)
{
	size_t	len;

	len = ft_strlen_env(src);
	*dest = (t_env *)malloc(sizeof(t_env) * (len + 1));
	(*dest)[len].name = NULL;
	(*dest)[len].val = NULL;
	copy_structs(src, dest, len);
}

int	find_index_equal(char	*lin, t_env	**export)
{
	int	i;
	int	len;
	int	flag;
	int	k1;
	int	k2;

	i = 0;
	len = ft_strlen_env(export);
	flag = 0;
	while (i < len)
	{
		k1 = ft_strncmp((*export)[i].name, lin,
				without_equal((*export)[i].name));
		k2 = ft_strncmp(lin, (*export)[i].name, without_equal(lin));
		if (k1 == 0 && k2 == 0)
		{
			flag = 1;
			break ;
		}
		else
			i++;
	}
	if (flag)
		return (i);
	return (-1);
}

void	addition_equal(t_env	**export, int	i)
{
	char	*tmp;

	if (ft_strchr((*export)[i].name, '=') == NULL)
	{
		tmp = ft_strjoin((*export)[i].name, "=");
		clean_ptr(&(*export)[i].name);
		(*export)[i].name = ft_strdup(tmp);
		clean_ptr(&tmp);
	}
}
