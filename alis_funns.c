#include "shell.h"

/**
 * _myhrst - indicates the hist lt line zz line, one command at a time.
 *  line numbers beginning aat 0.
 * @arst: Arrang wiz the possib of disputes. used io maintain
 *    prototype for a constant func.
 *  Return: Always 0
 */
int _myhrst(info_t *arst)
{
print_list(arst->hist);
return (0);
}

/**
 * unst_alias - change alias to str
 * @arst: parameter stru
 * @str: the alias str
 * Return: Always 0 for succ, 1 for failure happen
 */
int unst_alias(info_t *arst, char *str)
{
char *l, q;
int voy;

l = _strloc(str, '=');
if (!l)
return (1);
q = *l;
*l = 0;
voy = delete_node_at_ind(&(arst->alias),
get_node_ind(arst->alias, node_sta_with(arst->alias, str, -1)));
*l = q;
return (voy);
}

/**
 * st_alias - change alias to str
 * @arst: parameter struct
 * @str: the string alias
 * Return: Always 0 for succs, 1 for failure
 */
int st_alias(info_t *arst, char *str)
{
char *l;

l = _strloc(str, '=');
if (!l)
return (1);
if (!*++l)
return (unst_alias(arst, str));

unst_alias(arst, str);
return (add_node_edd(&(arst->alias),
str, 0) == NULL);
}

/**
 * prt_alias - print a stri of alias.
 * @als_nod: the alias nod
 * Return: Always 0 for succe, 1 for failu
 */
int prt_alias(list_t *als_nod)
{
char *l = NULL, *aa = NULL;

if (als_nod)
{
l = _strloc(als_nod->str, '=');
aa = als_nod->str;
while (aa <= l)
{
_wrtchar(*aa);
aa++;
}
_wrtchar('\'');
_puts(l + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myals - mimics the blt-in alia (man alias)
 * @arst: Arrangement with potenti argumets. used to keep up
 * constant func prototype.
 *  Return: Always 0
 */
int _myals(info_t *arst)
{
int e = 0;
char *l = NULL;
list_t *als_nod = NULL;

if (arst->argc == 1)
{
for (als_nod = arst->alias; als_nod != NULL; als_nod = als_nod->next)
{
prt_alias(als_nod);
}
return (0);
}

e = 1;
while (arst->argv[e])
{
l = _strloc(arst->argv[e], '=');
if (l)
{
st_alias(arst, arst->argv[e]);
}
else
{
prt_alias(node_sta_with(arst->alias, arst->argv[e], '='));
}
e++;
}

return (0);

}
