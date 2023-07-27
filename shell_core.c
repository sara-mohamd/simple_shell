#include "shell.h"

/**
 * hsh - main shell loop
 * @pminvo: parameter & return struct of info
 * @arevc: the argument vector from main()
 * Return: 0 for success, 1 for failure, or error code
 */
int hsh(info_t *pminvo, char **arevc)
{
ssize_t x = 0;
int builtin_ret = 0;

while (x != -1 && builtin_ret != -2)
{
set_invv(pminvo);
if (intractv(pminvo))
_puts("$ ");
_ewrtchar(BUF_FLUSH);
x = setlin(pminvo);
if (x != -1)
{
set_inff(pminvo, arevc);
builtin_ret = find_builtin(pminvo);
if (builtin_ret == -1)
find_cmd(pminvo);
}
else if (intractv(pminvo))
_wrtchar('\n');
free_info(pminvo, 0);
}
wrt_hist(pminvo);
free_info(pminvo, 1);
if (!intractv(pminvo) && pminvo->status)
exit(pminvo->status);
if (builtin_ret == -2)
{
if (pminvo->err_no == -1)
exit(pminvo->status);
exit(pminvo->err_no);
}
return (builtin_ret);
}

/**
 * find_builtin - discover built-in command
 * @pminvo: parameter & return struct of info
 * Return: -1 if builtin not found,
 *		0 if built-in functioned correctly,
 *	1 if built-in is discovered but unusable,
 *	-2 exit if built-in signals()
 */
int find_builtin(info_t *pminvo)
{
int l, built_in_ret = -1;
builtin_tabb builtintbl[] = {
{"exit", _myendpt},
{"env", _prenv},
{"help", _chcr},
{"hist", _myhrst},
{"setenv", _nwintenv},
{"unsetenv", _delnwenv},
{"cd", _mydi},
{"alias", _myals},
{NULL, NULL}
};

for (l = 0; builtintbl[l].type; l++)
if (_strcmp(pminvo->argv[0], builtintbl[l].type) == 0)
{
pminvo->line_coutt++;
	built_in_ret = builtintbl[l].func(pminvo);
break;
}
return (built_in_ret);
}

/**
 * find_cmd - search for e command in PATH
 * @pminvo: information struct for parameters,returns
 * Return: void
 */
void find_cmd(info_t *pminvo)
{
char *path = NULL;
int l = 0, r = 0;

pminvo->path = pminvo->argv[0];

if (pminvo->lincnnt_flg == 1)
{
pminvo->line_coutt++;
pminvo->lincnnt_flg = 0;
}

while (pminvo->arg[l])
{
if (!is_dlm(pminvo->arg[l], " \t\n"))
r++;
l++;
}

if (!r)
return;

path = find_path(pminvo, _vrenv(pminvo, "PATH="), pminvo->argv[0]);

if (path)
{
pminvo->path = path;
fork_cmd(pminvo);
}
else
{
if ((intractv(pminvo) || _vrenv(pminvo, "PATH=") ||
pminvo->argv[0][0] == '/') &&
is_cm(pminvo, pminvo->argv[0]))
fork_cmd(pminvo);
else if (*(pminvo->arg) != '\n')
{
pminvo->status = 127;
pri_bug(pminvo, "not found\n");
}
}
}

/**
 * fork_cmd - spawn exec thread to execute cmd.
 * @pminvo: the parameter & return struct of info
 * Return: void
 */
void fork_cmd(info_t *pminvo)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{

perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(pminvo->path, pminvo->argv, str_env(pminvo)) == -1)
{
free_info(pminvo, 1);
if (errno == EACCES)
exit(126);
exit(1);
}

}
else
{
wait(&(pminvo->status));
if (WIFEXITED(pminvo->status))
{
pminvo->status = WEXITSTATUS(pminvo->status);
if (pminvo->status == 126)
pri_bug(pminvo, "Permission denied\n");
}
}
}
