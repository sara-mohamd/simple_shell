#include "shell.h"

/**
 * _myendpt - exits the shell
 * @arst: Structure contains possible objections.Used to maintain
 * the constant function.
 * Return: exit with e value that given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myendpt(info_t *arst)
{
int end_check;
if (arst->argv[1])
{
end_check =
_strtoin(arst->argv[1]);

if (end_check == -1)
{
arst->status = 2;
pri_bug(arst, "Illegal number: ");
_prinp(arst->argv[1]);
_ewrtchar('\n');
return (1);
}
arst->err_no = _strtoin(arst->argv[1]);
return (-2);
}
arst->err_no = -1;
return (-2);
}
/**
 * _mydi - changes the current dir of the process
 * @arst: Structure containing potential arguments. Used to maintain
 *    constant function prototype.
 *  Return: Always 0
 */
int _mydi(info_t *arst)
{
char *c, *dir,
buffer[1024];
int ch_dir;
c = getcwd(buffer, 1024);
if (!c)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!arst->argv[1])
{
dir = _vrenv(arst, "HOME=");
if (!dir)
ch_dir =
chdir((dir = _vrenv(arst, "PWD=")) ? dir : "/");
else
ch_dir = chdir(dir);
}
else if (_strcmp(arst->argv[1], "-") == 0)
{
if (!_vrenv(arst, "OLDPWD="))
{
_puts(c);
_wrtchar('\n');
return (1);
}
_puts(_vrenv(arst, "OLDPWD=")), _wrtchar('\n');
ch_dir =
chdir((dir = _vrenv(arst, "OLDPWD=")) ? dir : "/");
}
else
ch_dir = chdir(arst->argv[1]);
if (ch_dir == -1)
{
pri_bug(arst, "can't cd to ");
_prinp(arst->argv[1]), _ewrtchar('\n');
}
else
{
_initvvv(arst, "OLDPWD", _vrenv(arst, "PWD="));
_initvvv(arst, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
 * _chcr - changes the current dir of the process
 * @arst: Structure containing potential arguments. Used to maintain
 *      constant function prototype.
 *  Return: Always 0
 */
int _chcr(info_t *arst)
{
char **arg_ary;

arg_ary = arst->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_ary);
return (0);
}
