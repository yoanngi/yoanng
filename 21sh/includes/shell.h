/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:43:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 11:21:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <term.h>

/*
** PRINT COLORS
*/

# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define YELLOW "\033[33m"
# define RESET "\033[00m"

/*
**	A Faire :
**	Si variable path suprimer, ne pas lancer de commande (sauf si chemin indiquer)
**	gestion des cotes et doubles code pour setenv et unsetenv
**
**	Source :
**	http://putaindecode.io/fr/articles/shell/redirections/
**	https://www.gnu.org/software/bash/manual/bashref.html#Redirections
**	https://abs.traduc.org/abs-5.3-fr/ch19.html
**	https://openclassrooms.com/forum/sujet/executer-fonctions-sur-pipes-successifs
**	https://stackoverflow.com/questions/17630247/coding-multiple-pipe-in-c/17631589
**	https://openclassrooms.com/forum/sujet/dup-dup2-et-close-12008
**
**
*/

/*
**	***	Structures ***
**
**	t_cmd -> liste chainer des commandes a executer
**
**	rep = Repertoire de commande
**	tab_cmd : commande et options sous forme de tableau
**	pathname : Si redirection dans un fichier, pathanme != NULL

**	Code operateur:
**	0 : NULL
**	1 : |
**	2 : >
**	3 : >>
**	4 : <
**	5 : <<
**	6 : &
**	7 : &&
**	8 : ||
**	9 : >&
**
**	env : Environnement a envoyer pour la commande
**
** t_cmd -> commande a traiter
*/

typedef struct		s_cmd
{
	char			*rep;
	char			**tab_cmd;
	char			*pathname;

	int				op_redir;
	int				op_next;

	int				stdcmd;
	int				stdin_cmd;
	int				stdout_cmd;
	int				stderr_cmd;
	int				pid;

	char			**env;
	struct s_cmd	*next;
}					t_cmd;

/*
**	t_ins -> line spliter par les ;
*/

typedef struct		s_ins
{
	char			*str;
	struct s_cmd	*cmd;
	struct s_ins	*next;
}					t_ins;

/*
**  Infos tab de hashage
*/

typedef struct		s_infos
{
	char			*rep;
	char			*name;
	char			*repname;
	struct s_infos	*next;
}					t_infos;

/*
**	t_struct -> On la ballade partout
*/

typedef struct		s_struct
{
	long			**tab_hash;
	char			**tab_path;
	char			**env;
	char			**builtins;
	char			**env_tmp;
	char			*path;
	char			*pwd;
	char			*oldpwd;
	char			*home;
	char			*charfound;
	char			*current_path;
	char			*prompt;
	char			*prompt_current;
	char			*char_echo;
	int				option_echo;
	int				option_i_env;
	int				code_erreur;
	int				sizemax;
	int				pid;
	t_ins			*commandes;
}					t_struct;

/*
**	***	Fonctions ***
**
**	CORE
*/
void				core_shell(t_struct *data);
int					execute_commandes(t_struct *mystruct, t_cmd *data);
int					execute_builtins(t_struct *mystruct, t_cmd *data, int pipe_fd[2], int *fd_in);
int					execute_builtins_light(t_struct *mystruct, t_cmd *data);
int					exec_pipe(t_struct *data);
int					exec_pipe_suite(t_struct *data);
int					ft_process(t_cmd *data);
/*
**	PARSING
*/
t_ins				*ft_split_commandes(char **line, t_struct *data);
t_ins				*ft_split_pvirgule(char *line, t_ins *lst);
t_cmd				*ft_split_cmd(char *str, t_struct *data);
int					clear_line(char **line);
char				*clean_before(char *str);
char				*clean_next(char *str);
int					replace_in_line(t_struct *data, char **line);
char				*ft_search_path(char *str, t_struct *data);
int					ft_nefaitrien(char **line);
int					ft_check_pvir_error(char *str);
int					ft_search_opnext(char *str, int i);
int					chose_rep(t_struct *data, t_cmd **new);
int					ft_redirection_avancees(t_cmd **new, char **str);
/*
**	BUILTINS
*/
int					ft_search_func(t_struct *mystruct, t_cmd *lst, int i);
int					func_exit(t_struct *data, t_cmd *lst);
int					func_env(t_struct *data, t_cmd *lst);
int					func_echo(t_struct *data, t_cmd *lst);
int					func_cd(t_struct *data, t_cmd *lst);
int					func_setenv(t_struct **data, t_cmd *lst);
int					func_unsetenv(t_struct **data, t_cmd *lst);



/*
**	INIT
*/
t_struct			*init_struct(char **env);
char				*ft_check_infos(char **env, char *find);
char				**ft_initialise_builtins(void);
int					ft_delete_struct(t_struct **data);
t_cmd				*ft_init_cmd(void);
t_cmd				*clear_cmd(t_cmd *start);
t_ins				*ft_init_ins(void);
t_ins				*clear_ins(t_ins *start);
int					ft_load_path(t_struct **data);
t_infos             *init_infos(char *rep, char *name);
t_infos             *clear_infos(t_infos *start);

// HASH
int					ft_count(char *path);
int					ft_work_in_tab(char **tabl, int(*ft)(char *));
int					ft_rforhash(int s, char **tabp, long **tabh,
	long(*f)(char *, int));
int                 ft_insert_hash(char *str, int hash, long **tabh,
	char *tabp);
int					ft_insert_collision(t_infos **start, char *tabp, char *str);
long				ft_calcul_hash(char *str, int sizemax);
int					ft_create_table_hash(t_struct **data);
long				**create_tab_hash(int size);
long				**delete_tab_hash(long **tabh, int size);

/*
**	LIB_SHELL
*/
int					ft_replace_word(char **str, char *word, char *replace);
char				**ft_del_tab(char **tabl);
int					ft_len_tab(char **tabl);
char				**ft_duplicate_tab(char **tabl);
char				**ft_insert_in_tab(char **tabl, char *str);
void				ft_print_tab(char **tabl);
char				**ft_del_tab_index(char **tabl, int max);
char				*ft_add_line(char *str, char **add, t_struct *data);
int					ft_dir_exist(char *path);
void				ft_display(t_struct *data);
int					ft_access(char *path);
int					ft_access_rep(char *path);
void				basic_error(char *name, char *cmd);
int					ft_error(int cmd, char **line);
void				ft_error_dir(char *name, char *pre);
void				ft_error_unset(char *str, int what);
void				ft_error_fork(int father);
void				ft_check_path(t_struct *data, char **path);
int					good_path(char *target, char *cmd, int opt);
char				*ft_return_path(char *str);
char				*ft_insert_home(t_struct *data, char **str, int i, int len);
char				*ft_insert_dollar(t_struct *data, char **str, int i, int len);
char				*ft_insert_moins(t_struct *data, char **str, int i, int len);
int					ft_existe_in_path(t_struct *data, char **path);
char				*ft_return_pwd(void);
int					len_list(t_cmd *lst);
/*
**	LIB_TERMCAPS
*/
# define KEY_CODE_NONE 0
# define KEY_CODE_UP buff[0] == 27 && buff[1] == 91 && buff[2] == 65
# define KEY_CODE_DOWN buff[0] == 27 && buff[1] == 91 && buff[2] == 66
# define KEY_CODE_RIGHT buff[0] == 27 && buff[1] == 91 && buff[2] == 67
# define KEY_CODE_LEFT buff[0] == 27 && buff[1] == 91 && buff[2] == 68
# define KEY_CODE_ALT_UP buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 65
# define KEY_CODE_ALT_DOWN buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 66
# define KEY_CODE_ALT_RIGHT buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 67
# define KEY_CODE_ALT_LEFT buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 68
# define KEY_CODE_BSP *(int*)buff == 127
# define KEY_CODE_RC *(int*)buff == 10
# define KEY_CODE_END buff[0] == 27 && buff[1] == 91 && buff[2] == 70
# define KEY_CODE_HOME buff[0] == 27 && buff[1] == 91 && buff[2] == 72
# define KEY_CODE_CTRL_A
# define KEY_CODE_CTRL_D *(int*)buff == 4
# define KEY_CODE_TAB *(int*)buff == 9

# define CURS_X get_curs_pos(0, info)
# define CURS_Y get_curs_pos(1, info)


typedef struct winsize t_wndw;
typedef struct termios t_termios;

typedef struct		s_hist
{
	char			*name;
	char			*backup;
	int				current;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_info
{
	int				s_len;
	int				orig_y;
	int				curs_x;
	int				curs_y;
	int				row_nb;
	int				col_nb;
	int				curs_in_str;
	char			*line;
	char			*prmpt;
	t_hist			*history;
	t_wndw			wndw;
	t_termios		term;
}					t_info;

void				default_term_mode(t_info *info);
void				raw_term_mode(t_info *info);
void				get_key(int *loop, t_info *info, t_hist *tmp);
t_info				*memo_info(t_info *info, int mode);
int					get_curs_pos(int mode, t_info *info);
void				get_signals(void);
void				left_key(t_info *info);
void				right_key(t_info *info);
void				add_c_in_str(t_info *info, char c, t_hist *tmp);
void				del_c_in_str(t_info *info, t_hist *tmp);
void				del_char(t_info *info, t_hist *tmp);
void				add_char(char c, t_info *info, t_hist *tmp);
void				insert_char(char c, t_info *info, t_hist *tmp);
void				curs_extremity(t_info *info, char *buff);
void				add_queue(t_hist *root);
void				add_head(t_hist *root);
void				remove_elem(t_hist *elem);
t_hist				*root_hist(void);
t_hist				*first_elem(t_hist *root);
t_hist				*last_elem(t_hist *root);
void				alt_up_down(t_info *info, char *buff);
void				init_current(t_hist *history);
void				alt_right(t_info *info, t_hist *tmp);
void				alt_left(t_info *info, t_hist *tmp);
void				up_key(t_info *info, t_hist *tmp);
void				down_key(t_info *info, t_hist *tmp);
/*
**	END
*/
#endif
