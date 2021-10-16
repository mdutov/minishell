#ifndef TYPES_H
# define TYPES_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "./libft/libft.h"
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_env
{
	char	*name;
	char	*val;
}				t_env;

typedef struct s_minish
{
	int		ex_status;
	int		signal;
	char	*temp1;
	char	*temp2;
	char	*tempredl;
	int		oldstdout;
}				t_minish;

typedef struct s_comm
{
	char	**argum;
	char	*redr;
	int		redrflag;
	char	*redl;
	int		redlflag;
	int		fdin;
	int		fdout;
}				t_comm;

typedef struct s_doll
{
	int		i;
	int		old_i;
	int		j;
	char	*dest;
	char	*old_dest;
	char	*tmp_1;
	char	*tmp_2;
	int		index;
	int		n_dol;
	int		k;
	int		q;
	int		q2;
	int		flag;
}				t_doll;

t_minish	*ret_minish(void);
int			tabandspace(char *line);
void		shell_lvl(t_env **env);
void		ft_ignor(int sig);
void		minish_init(t_minish *minish, t_env **env);

#endif
