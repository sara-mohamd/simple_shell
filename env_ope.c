#include "shell.h"

/**
 * str_env - returns the string arr copy of our environ
 * @stoor: Structure contai potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
char **str_env(info_t *stoor)
{
if (!stoor->environ || stoor->env_changed)
{
stoor->environ = list_to_strsss(stoor->env);
stoor->env_changed = 0;
}
return (stoor->environ);
}

/**
 * _dezenv - Remove an environment variable
 * @stoor: Structure contain potential arguments. Used to maintain
 * constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @stepr: the string env voy property
 */
int _dezenv(info_t *stoor, char *stepr)
{
list_t *nod = stoor->env;
size_t l = 0;
char *t;

if (!nod || !stepr)
return (0);

for (nod = stoor->env; nod != NULL; nod = nod->next)
{
t = sta_wit(nod->str, stepr);
if (t && *t == '=')
{
stoor->env_changed = delete_node_at_ind(&(stoor->env), l);
l = 0;
nod = stoor->env;
}
else
{
l++;
}
}

return (stoor->env_changed);
}

/**
 * _initvvv - Initialize e new environment variable,
 * or modify an existing one
 * @stoor: Structure contai potential arguments. Used to maintain
 * constant function prototype.
 * @stepr: the string env voy property
 * @strvz: the string env voy value
 *  Return: Always 0
 */
int _initvvv(info_t *stoor, char *stepr, char *strvz)
{
char *bff = NULL;
list_t *nod;
char *t;

if (!stepr || !strvz)
return (0);

bff = malloc(_strlon(stepr) + _strlon(strvz) + 2);
if (!bff)
return (1);

_strcpy(bff, stepr);
_strcat(bff, "=");

_strcat(bff, strvz);

for (nod = stoor->env; nod != NULL; nod = nod->next)

{

t = sta_wit(nod->str, stepr);
if (t && *t == '=')
{
free(nod->str);
nod->str = bff;
stoor->env_changed = 1;
free(bff);

return (0);
}
}

add_node_edd(&(stoor->env), bff, 0);

stoor->env_changed = 1;
free(bff);
return (0);
}
