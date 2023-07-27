#include "shell.h"

/**
 * main - start point
 * @acco: arg count
 * @arevc: arg vector
 * Return: 0 for success, 1 for failure
 */
int main(int acco,
char **arevc)
{
info_t info[] =

{
INFO_INIT };
int dd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (dd)
: "r" (dd));

if (acco == 2)
{
dd = open(arevc[1],
O_RDONLY);
if (dd ==
-1)
{
if (errno ==
EACCES)
exit(126);
if (errno ==
ENOENT)
{
_prinp(arevc[0]);
_prinp(": 0: Can't open ");
_prinp(arevc[1]);
_ewrtchar('\n');
_ewrtchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->rdfd = dd;
}
pop_env_lst(info);
read_history(info);
hsh(info, arevc);
return (EXIT_SUCCESS);
}
