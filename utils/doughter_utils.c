#include "../src_t/headers_t.h"

int	find_build_index(char **lin, t_minish *minish, t_env **env)
{
	if (ft_strncmp_1(lin[0], "cd", 3) == 0)
		ft_cd(minish, lin, env);
	else if (ft_strncmp_1(lin[0], "env", 4) == 0)
		env_main(env, minish, lin);
	else if (ft_strncmp_1(lin[0], "pwd", 4) == 0 )
		ft_pwd(env, minish);
	else if (ft_strncmp_1(lin[0], "echo", 5) == 0)
		echoshell(minish, lin);
	else if (ft_strncmp(lin[0], "export", 7) == 0)
		export_main(env, minish, lin);
	else if (ft_strncmp(lin[0], "unset", 6) == 0)
		unset_main(env, minish, lin);
	else if (ft_strncmp(lin[0], "exit", 5) == 0)
		ft_exit(minish, lin);
	else
		return (0);
	return (1);
}
