#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* order to chain commands */
#define CMD_AND		2
#define CMD_CHAIN	3
#define CMD_NORM	0
#define CMD_OR		1

/* reading/writing buffers */
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024

/* one if system getline() is used */
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
extern char **environ;

/* converting number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct listr - singly linked list
 * @num: the number field
 * @str: e string
 * @next: points to the next nod
 */
typedef struct listr
{
int num;
char *str;
struct listr *next;
} list_t;

/**
 *struct pasinf - compr fict argu to e function,,
 *enabling e standard func point struct prototype
 *@arg: e string generas from getline contain arguements
 *@argv: an arr of strings generated from arg
 *@path: e string path for the curre command
 *@argc: the argument count
 *@line_coutt: the error count
 *@err_no:  the error code for exit()s
 *@lincnnt_flg: if on count this line of inpt
 *@fnamm: the program is filename
 *@env: linked list local copy of enrrron
 *@environ: custom modified copy of enrrron from LL env
 *@hist: the hist nod
 *@alias: the alias nod
 *@env_changed: on if envrron was changed
 *@status: the return status of the lost exec'd command
 *@cmd_buff: addreiss of point to cmd_buff, on if chaining
 *@cmd_buff_typ: CMD_type ||, &&, ;
 *@rdfd: is fdw fro which to read line inpt
 *@hiscou: the hist line number count
 */
typedef struct pasinf
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_coutt;
int err_no;
int lincnnt_flg;
char *fnamm;
list_t *env;
list_t *hist;
list_t *alias;
char **environ;
int env_changed;
int status;

char **cmd_buff; /* pointer to cmd ; chain buffer, for memory mangement */
int cmd_buff_typ; /* CMD_type ||, &&, ; */
int rdfd;
int hiscou;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains e builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_tabb;


/* shell_core.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* File_helps.c */
int is_cm(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* pt_func.c */
void _prinp(char *);
int _ewrtchar(char);
int _wrtcf(char q, int fildes);
int _putsfd(char *prtstr, int fildes);

/* strg_func.c */
int _strlon(char *);
int _strcmp(char *, char *);
char *sta_wit(const char *, const char *);
char *_strcat(char *, char *);

/* str2_fun.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _wrtchar(char);

/* str_funct.c */
char *_strcp(char *, char *, int);
char *_concst(char *, char *, int);
char *_strloc(char *, char);

/* strggg_funas.c */
char **streew(char *, char *);
char **streew2(char *, char);

/* memoy_opens.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* commnd_prog.c */
int bfee(void **);

/* utility_funcsds.c*/
int intractv(info_t *);
int is_dlm(char, char *);
int _isalfa(int);
int _stin(char *);

/* uti.c*/
int _strtoin(char *);
void pri_bug(info_t *, char *);
int prdc(int, int);
char *covrr_no(long int, int, int);
void del_com(char *);

/* shell_fun2r.c */
int _myendpt(info_t *);
int _mydi(info_t *);
int _chcr(info_t *);

/* alis_funns.c */
int _myhrst(info_t *);
int _myals(info_t *);

/* gete_fns.c */
ssize_t setlin(info_t *);
int _getline(info_t *, char **, size_t *);
void blockc(int);

/* info_funns.c */
void set_invv(info_t *);
void set_inff(info_t *, char **);
void free_info(info_t *, int);

/* env_fun4.c */
char *_vrenv(info_t *, const char *);
int _prenv(info_t *);
int _nwintenv(info_t *);
int _delnwenv(info_t *);
int pop_env_lst(info_t *);

/* env_ope.c */
char **str_env(info_t *);
int _dezenv(info_t *, char *);
int _initvvv(info_t *, char *, char *);

/* hisy.c */
char *get_hist_file(info_t *prmstr);
int wrt_hist(info_t *prmstr);
int read_history(info_t *prmstr);
int bild_hist_lst(info_t *stoor, char *bff, int histc);
int reno_hist(info_t *stoor);

/* linkrr_list.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_edd(list_t **, const char *, int);
size_t pr_lst_str(const list_t *);
int delete_node_at_ind(list_t **, unsigned int);
void free_liss(list_t **);

/* node_sta_with.c */
size_t list_lest(const list_t *);
char **list_to_strsss(list_t *);
size_t print_list(const list_t *);
list_t *node_sta_with(list_t *, char *, char);
ssize_t get_node_ind(list_t *, list_t *);

/* replace_string.c */
int is_chaion(info_t *, char *, size_t *);
void check_chaion(info_t *, char *, size_t *, size_t, size_t);
int rep_alias(info_t *);
int rep_vars(info_t *);
int rep_string(char **, char *);

#endif
