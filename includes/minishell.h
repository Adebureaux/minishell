/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:23:06 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 14:17:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
# include <sys/param.h>
# include <stddef.h>
# include <signal.h>
# include <fcntl.h>
# include <bits/posix2_lim.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "../libs/libft/includes/libft.h"

# define ECHO 0
# define CD 1
# define PWD 2
# define EXPORT 3
# define F_EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7
# define CMD_NBR 9
/*# define PRINTPOS ft_printf("%s line %d\n", __func__, __LINE__)*/

typedef enum e_type
{
	NEIN,
	WORD,
	FD,
	LIMITER,
	CMD,
	REDIR_IN,
	REDIR_OUT,
	APPEND_OUT,
	HERE_DOC,
	PIPE,
}			t_type;

typedef enum e_status
{
	NONE,
	OPEN,
	CLOSE,
	OPEN_D,
	CLOSE_D,
	OPEN_S,
	CLOSE_S
}			t_status;

/*
** Element of chain list for handle cmd with args
*/
typedef struct s_token
{
	t_type			id;
	char			*str;
	char			*expand;
	struct s_token	*previous;
	struct s_token	*next;
}				t_token;

typedef struct s_cmd
{
	pid_t			pid;
	t_token			*args;
	t_token			*redir;
	int				run;
	int				tmp_status;
	int				blt;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_shell
{
	int			status;
	char		**env;
	char		**export;
	int			tmp_stdin;
	int			tmp_stdout;
	int			cmd_nbr;
	int			i;
	int			*fd;
	char		*line;
	t_cmd		*first_cmd;
	t_token		*first_token;
}				t_shell;

typedef struct s_quotes
{
	size_t		i_first_quote;
	size_t		i_last_quote;
	int			first;
	t_status	state;
}			t_quotes;

typedef struct s_norm
{
	bool	quotes;
	char	**tab;
	t_type	previous;
	t_cmd	*cmd;
}				t_norm;

extern int	g_exit_status;

/*
** DEBUG
*/
int			print_error(t_cmd *cmd, char *str, int exit_status, int error_type);
void		print_error_exit(t_shell *shell, t_cmd *cmd,
				int exit_status, int error_type);
void		print_t_shell(t_shell *data);
void		print_list_token(char *name, t_token *list);
void		print_token(t_token *element);
void		print_cmd(t_cmd *element);
void		print_list_cmd(t_cmd *list);
void		understanding(t_cmd *cmd);
void		display_token(t_cmd *cmd, t_token *actual, int args);
void		free_cmd(t_shell *shell, t_cmd *cmd);
void		exit_custom(t_shell *shell, int exit_status);
void		free_token(t_token **actual);
/*
** Initialize
*/

t_shell		*init_shell(void);
t_cmd		*init_t_cmd(void);
t_quotes	init_data_quotes(void);

/*
** Handler Signal
*/
void		handle_cmd_signals(void);
void		handle_global_signals(void);
char		*prepare_cmd(char *cmd_line, char **envp);
char		*set_path_exec(char **envp, char *cmd);
char		**set_args(t_token *token);

/*
** PROCESS LINE
*/
int			token_parser(t_shell *data, char *line);
int			recognize_token(t_shell *data, char **tab);
int			expansion_token(t_token *lst, char **env);
char		*process_aliases(char **env, char *line);
void		process_quotes(t_token *actual, char ***tab, char **env);
void		no_quote_process(t_token *actual, char **env,
				char ***tab, int index);
void		extract_quote(char *line, char ***tab, int i, t_quotes *data);
int			add_token(char ***tab, char *line, int start, int end);
t_status	set_status(char *line, int i, t_status state);
bool		is_delim(char *delim, char c);
void		simple_quote_process(char ***tab, int index);
void		double_quote_process(t_token *actual, char ***tab,
				int index, char **env);
int			check_quote(t_token *actual, char **env);
void		no_quote_process(t_token *actual, char **env,
				char ***tab, int index);
void		token_push_back(t_token **lst, t_token *new);
int			manage_token(t_norm *norm, size_t i);
int			check_redir(char **tab, size_t i, t_type id, t_type previous);
int			check_pipe(char **tab, int i, t_type previous);
void		ignore_all_signals(void);

/*
** UTILS
*/
char		*replace_by_var_env(char *str, char *var_env,
				size_t start, size_t end);
bool		is_redir(t_type id);
bool		find_some_chars(char *str, char *to_find);
void		ft_lstadd_back(t_token *lst, t_token *new);
t_token		*ft_lstlast(t_token *lst);
t_token		*set_t_token(t_type id, char *str);
bool		find_some_chars(char *str, char *to_find);
/*
** Basics Function
*/
char		*find_var_env(char **envp, char *to_find);
void		init_env(char ***tab);
void		replace_env(t_shell *shell, char *key, char *value);
char		*recovery_var(char *line);

void		export_var_env(char ***envp, char *to_find, char *to_add);

bool		check_if_var_exist(char *args, char **env);
bool		find_char_str(char *str, char find);
bool		find_in_tab(char **tab, char *str);

void		ft_print_tab(char **p_tab);
void		replace_in_tab(char *args, char ***env);
void		init_tab_export(char ***export, char **env);
void		init_tab_free(char ***tab_dest, char **tab_src);
void		init_tab(char ***tab_dest, char **tab_src);
char		*ft_strappend(char *s1, char *s2);
size_t		ft_strlen_delim(char *str, char *delim);

t_token		*init_t_token(void);
t_cmd		*init_t_cmd(void);
void		check_mutli_cmd(void);
char		*ft_str_replace(char *str, char *to_replace,
				size_t start, size_t end);
char		*get_cmd_path(char *cmd, char **path);

/*
** Execution
*/
int			execute_loop(t_shell *shell, t_cmd *cmd);
void		execute_forked_builtin(t_shell *shell, t_cmd *cmd);
void		execute_builtin(t_shell *shell, t_cmd *cmd);
void		execute_pipe(t_shell *shell);
void		wait_process(t_shell *shell, t_cmd *cmd);
void		manage_fd(t_shell *shell, t_cmd *cmd);
int			execute_redir(t_shell *shell, t_cmd	*cmd, t_token *redir);
int			here_doc(t_shell *shell, t_cmd	*cmd, t_token *redir);
int			is_builtin(t_cmd *cmd);

/*
** EXPORT
*/
void		print_export(char **export);
void		check_var(t_shell *shell, t_cmd *cmd);
int			check_error(t_cmd *cmd, t_token *actual);
void		check_var_env(char ***envp, char *to_find, char *to_add);
/*
** Own Builtins
*/
char		*blt_str(int i);
void		echo_cmd(t_shell *shell, t_cmd *cmd);
void		cd_cmd(t_shell *shell, t_cmd *cmd);
void		pwd_cmd(t_shell *shell, t_cmd *cmd);
void		export_cmd(t_shell *shell, t_cmd *cmd);
void		forked_export_cmd(t_shell *shell, t_cmd *cmd);
void		unset_cmd(t_shell *shell, t_cmd *cmd);
void		env_cmd(t_shell *shell, t_cmd *cmd);
void		exit_cmd(t_shell *shell, t_cmd *cmd);

#endif
