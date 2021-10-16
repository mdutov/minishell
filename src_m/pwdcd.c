#include "headers_m.h"

static void	ft_pwdchange(t_env **env, int pwdindx, int oldindx, int len)
{
	while ((*env)[pwdindx].name != NULL)
	{
		if (ft_strncmp("PWD=", (*env)[pwdindx].name, 4) == 0)
			break ;
		pwdindx++;
	}
	if ((*env)[pwdindx].name == NULL)
	{
		printf("PWD= not founded\n");
		return ;
	}
	while ((*env)[oldindx].name != NULL)
	{
		if (ft_strncmp("OLDPWD=", (*env)[oldindx].name, 7) == 0)
			break ;
		oldindx++;
	}
	len = ft_strlen((*env)[pwdindx].val);
	free((*env)[oldindx].val);
	(*env)[oldindx].val = ft_newstr(len);
	(*env)[oldindx].val = ft_strncpy((*env)[oldindx].val,
			(*env)[pwdindx].val, len);
	free((*env)[pwdindx].val);
	(*env)[pwdindx].val = getcwd(NULL, 66);
}

void	ft_pwd(t_env **env, t_minish *minish)
{	
	char	*pwdprint;

	(void)env;
	pwdprint = NULL;
	pwdprint = getcwd(pwdprint, 66);
	ft_putendl_fd(pwdprint, 1);
	free(pwdprint);
	minish->ex_status = 1;
}

static void	cd_util(t_minish *minish, t_env **env, int i)
{
	while ((*env)[++i].name != NULL)
	{
		if (ft_strncmp("HOME=", (*env)[i].name, 5) == 0)
		{
			if (chdir((*env)[i].val) != 0)
			{
				minish->ex_status = 1;
				return ;
			}
			ft_pwdchange(env, 0, 0, 0);
			break ;
		}
	}
}

void	ft_cd(t_minish *minish, char **lin, t_env **env)
{
	minish->ex_status = 0;
	if (lin[1] == NULL)
		cd_util(minish, env, -1);
	else
	{
		if (chdir(lin[1]) != 0)
		{
			printf("cd: no such file or directory: %s\n", lin[1]);
			minish->ex_status = 1;
			return ;
		}
		ft_pwdchange(env, 0, 0, 0);
	}
}
