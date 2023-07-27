#include "shell.h"

/**
 * set_invv - establishes the info_t struct.
 * @adstr: address in struct
 */
void set_invv(info_t *adstr)
{
adstr->arg = NULL;
adstr->argv = NULL;
adstr->path = NULL;
adstr->argc = 0;
}

/**
 * set_inff - initializes info_t struct
 * @adstr: address in struct
 * @arevc: argument vector
 */
void set_inff(info_t *adstr, char **arevc)
{
int l = 0;

adstr->fnamm = arevc[0];

if (adstr->arg)
{
adstr->argv = streew(adstr->arg, " \t");

if (!adstr->argv)
{
adstr->argv = malloc(sizeof(char *) * 2);

if (adstr->argv)
{
adstr->argv[0] = _strdup(adstr->arg);
adstr->argv[1] = NULL;
}
}

while (adstr->argv &&
adstr->argv[l])
{
l++;
}

adstr->argc = l;

rep_alias(adstr);
rep_vars(adstr);
}
}

/**
 * free_info - frees info_t struct fields
 * @adstr: address in struct
 * @fre: if freeing fre fields is true
 */
void free_info(info_t *adstr, int fre)
{
ffree(adstr->argv);
adstr->argv = NULL;
adstr->path = NULL;
if (fre)
{
if (!adstr->cmd_buff)
free(adstr->arg);
if (adstr->env)
free_liss(&(adstr->env));
if (adstr->hist)
free_liss(&(adstr->hist));
if (adstr->alias)
free_liss(&(adstr->alias));
ffree(adstr->environ);
adstr->environ = NULL;
bfee((void **)adstr->cmd_buff);
if (adstr->rdfd > 2)
close(adstr->rdfd);
_wrtchar(BUF_FLUSH);
}
}
