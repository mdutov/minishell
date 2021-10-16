#ifndef HEADERS_M_H
# define HEADERS_M_H

# include "../types.h"
# include "../src_t/headers_t.h"

typedef struct s_pars
{
	int	q;
	int	q2;
	int	numarg;
	int	st;
	int	fl;
	int	fr;
	int	end;
}		t_pars;

void		ft_cd(t_minish *minish, char **lin, t_env **env);
void		ft_pwd(t_env **env, t_minish *minish);
void		ft_exit(t_minish *minish, char **lin);
void		echoshell(t_minish *minish, char **lin);
void		parser_pipe(char *pip_line, int *b, char ***commlines);
t_comm		*parser_commline(char *piplin);
int			doughter(t_minish *minish, t_env **env, t_comm *comm_data);
int			find_build_index(char **lin, t_minish *minish, t_env **env);
int			ourpipe(t_minish *minish, t_env **env, t_comm **comm_data);
int			ourmultipipe(t_minish *minish, t_env **env,
				t_comm **comm_data, int comm_nbr);
int			doublebackreddir(t_minish *minish, char *argv, t_env **env);
t_minish	*ret_minish(void);
void		readfdchange(int i, t_minish *minish);
int			doublleft(t_minish *minish, t_comm **comm_data, t_env **env, int i);
int			leftreddir(t_comm **comm_data, int i, t_minish *minish);
void		initdata(t_comm *commdata, t_pars *p);
int			right_redd(t_pars *p, t_comm *commdata, int i, char *piplin);
int			left_redd(t_pars *p, t_comm *commdata, int i, char *piplin);
int			newarg_add(t_pars *p, t_comm *commdata, int i, char *piplin);
int			past_arg(t_pars *p, t_comm *commdata, int i, char *piplin);
char		**newargarr(char **argum, int num);
char		*bezkav(char *sub, int q, int i);
void		cutquot(t_comm *commda);
void		argbefor_red(t_pars *p, t_comm *commdata, char *piplin);
void		clean_data(t_comm	***comm_data);
int			comm_data_cicle(t_comm **comm_data, int comm_nbr,
				t_minish *minish, char **commlines);

#endif
