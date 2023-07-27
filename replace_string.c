#include "shell.h"

/**
 * is_chaion - e chain dlmstr test for the current chare buffer
 * @prmstr: the parameter struct
 * @bff:  the character buffer
 * @adp: current position's address in bff
 * Return: 1 if chain dlmstr, 0 otherwise
 */
int is_chaion(info_t *prmstr, char *bff, size_t *adp)
{
size_t q = *adp;

if (bff[q] == '|' && bff[q + 1] == '|')
{
bff[q] = 0;
q++;
prmstr->cmd_buff_typ = CMD_OR;
}
else if (bff[q] == '&' && bff[q + 1] == '&')
{
bff[q] = 0;
q++;
prmstr->cmd_buff_typ = CMD_AND;
}
else if (bff[q] == ';')
{
bff[q] = 0;
prmstr->cmd_buff_typ = CMD_CHAIN;
}
else
return (0);
*adp = q;
return (1);
}

/**
 * check_chaion - checks we should continue chaining based on last status
 * @prmstr: the parameter struct
 * @bff: the char buffer
 * @adp: address of current position in bff
 * @sp: starting position in bff
 * @lon: length of bff
 * Return: Void
 */
void check_chaion(info_t *prmstr, char *bff,
size_t *adp, size_t sp, size_t lon)
{
size_t q = *adp;

if (prmstr->cmd_buff_typ == CMD_AND)
{
if (prmstr->status)
{
bff[sp] = 0;
q = lon;
}
}
if (prmstr->cmd_buff_typ == CMD_OR)
{
if (!prmstr->status)
{
bff[sp] = 0;
q = lon;
}
}

*adp = q;
}

/**
 * rep_alias - replaces an aliases in the tokenized string
 * @prmstr: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int rep_alias(info_t *prmstr)
{
int l = 0;
list_t *nod;
char *t;

while (l < 10)
{
nod = node_sta_with(prmstr->alias, prmstr->argv[0], '=');
if (!nod)
return (0);
free(prmstr->argv[0]);
t = _strloc(nod->str, '=');
if (!t)
return (0);
t = _strdup(t + 1);
if (!t)
return (0);
prmstr->argv[0] = t;
l++;
}
return (1);
}


/**
 * rep_vars - alternate var in the tokened str
 * @prmstr: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int rep_vars(info_t *prmstr)
{
int l = 0;
list_t *nod;

while (prmstr->argv[l])
{
if (prmstr->argv[l][0] != '$' || !prmstr->argv[l][1])
{
l++;
continue;
}

if (!_strcmp(prmstr->argv[l], "$?"))
{
rep_string(&(prmstr->argv[l]), _strdup(covrr_no(prmstr->status, 10, 0)));
l++;
continue;
}

if (!_strcmp(prmstr->argv[l], "$$"))
{
rep_string(&(prmstr->argv[l]), _strdup(covrr_no(getpid(), 10, 0)));
l++;
continue;
}

nod = node_sta_with(prmstr->env, &prmstr->argv[l][1], '=');
if (nod)
{
rep_string(&(prmstr->argv[l]), _strdup(_strloc(nod->str, '=') + 1));
}
else
{
rep_string(&prmstr->argv[l], _strdup(""));
}

l++;
}
return (0);
}


/**
 * rep_string - swaps out a string
 * @oldstr: address of old string
 * @newstr: fresh string
 * Return: 1 if replaced, 0 otherwise
 */
int rep_string(char **oldstr, char *newstr)
{
free(*oldstr);
*oldstr = newstr;
return (1);
}
