#ifndef HEADERS_T_H
# define HEADERS_T_H

# include "../types.h"
# include "../src_m/headers_m.h"

int		env_main(t_env **env, t_minish *minish, char **lin);
int		export_main(t_env **env, t_minish *minish, char **lin);
void	addition_equal(t_env	**export, int	i);
char	*check_valid(char *lin);
size_t	ft_strlen_env(t_env **env);
void	print_export(t_env **export);
void	bubbleSort(t_env **export, size_t len);
void	dublicate_env(t_env **src, t_env **dest);
int		find_index_equal(char *lin, t_env **export);
void	copy_name_val(char *name, char *val, t_env **dest, int i);
void	copy_one_struct(t_env **src, t_env **dest, int i);
void	copy_structs(t_env **src, t_env **dest, size_t len_env);
void	extra_struct(t_env **export);
int		without_equal(char *s);
int		check_valid_1(char	**lin, int *i, char *n);
int		name_check_export(char	*lin, t_env	**export);
int		rename_export(char	*lin, t_env	**export, int	flag);
void	print_export_0(t_env	**env, t_minish	*minish, t_env	**export);
char	*check_valid(char	*lin);
void	bubbleSort_1(t_env **tmp, int *j, int *bool);
void	bubbleSort(t_env **export, size_t len);
int		unset_main(t_env **env, t_minish *minish, char **lin);
void	lin_clean(char ***lin);
void	env_clean(t_env **env);
void	clean_ptr(char **s);
size_t	ft_strlen_engv(char **s);
void	copy_env(t_env **env, char **engv, size_t len_name);
char	*doll(char *line, t_env **env, t_minish *minish);
void	dollar_2(t_doll	*doll);
void	dollar_4(t_doll	*doll, t_env	**env);
void	dollar_5(t_doll	*doll, t_minish	*minish);
void	dollar_6(t_doll	*doll, t_env **env);
void	dollar_7(t_doll	*doll);
int		true_doll(t_doll	*doll);
char	*find_bin(t_env **env, char **comm);
char	**struct_to_string(t_env **env);
char	**create_path(t_env **env);
int		find_index_path(t_env	**env);
void	rl_replace_line(char *q, int w);
int		lin_null(t_env	**export, char	**lin, int *i, t_env	**env);
int		parser_1(t_comm	***comm_data, int	*comm_nbr,
			t_minish *minish, char	***commlines);
int		parser_2(t_comm ***comm_data, t_minish *minish, char ***commlines);
int		tokenerror(t_minish *minish);

#endif
