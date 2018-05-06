/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:12:05 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 15:15:27 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# define READ_SIZE 4096
# include "../libft/libft.h"
# include <limits.h>

int				g_p;
char			*g_user;
int				g_test;
int				g_ess;
int				g_leak;

typedef struct	s_minishell
{
	char **tab;
	char **cmd;
	char **env;
}				t_minishell;

int		my_getenv(char *name, char **env);
char			**path(t_minishell *shell, char **env);
void			aff_prompt(t_minishell *shell);
int				ft_builtin(char *cmd, t_minishell *shell);
char			**ft_str_cmd(char *cmd, t_minishell *shell);
void			sigint(int sig);
void			ft_fork(t_minishell *shell, char *cmd, char *buff);
void			ft_putstr_color(const char *str, int nb);
char			*split_path(t_minishell *shell);
void			ft_direct(char **cmd, char **env, t_minishell *shell, \
		char *buff);
void			ft_print_error(const char *s1, const char *s2);
void			ft_print_prompt(void);
int				ft_check_path(char **env, int value);
void			ft_set_env(char **env_cmd, t_minishell *shell);
void			ft_unset_env(t_minishell *shell);
void			ft_cd(char *str, char **env, t_minishell *shell);
void			init_shell(void);
void			env_now(t_minishell *shell, char **envv);
char			*split_path(t_minishell *shell);
char			**ft_str_cmd_quote(char *cmd, t_minishell *shell);
char			*ft_ajout_quote(char *str);
int				ft_check_quote(char *buff);
char			*ft_epure_quote(char *str);
char			*ft_epure(char *str);
int				ft_check_space(char *buff);
void			ft_free(char **tab, char **env, char **cmd);
void			cmd_exec(t_minishell *shell, int value);
void			set_pwd(char **env, char *str, int i);
void			set_old_pwd(char **env, char *old, int i);
void			ft_transfer(char *env, char *str);
char			*ft_insert_old(char **env);
void			ft_chang_pwd(char **env, char *str);
char			**ft_set_env_tool(char **env_cmd, t_minishell *shell, int p, \
		char *tmp);
void			ft_free_tool(char *buff, char *cmd, t_minishell *shell);
char 		**ft_split(char *str);
char	**ft_strsplit2(char *str);
char **ft_split_quote(char *str);
int 		ft_verif3(char *str, int value);
#endif
