#include "shell.h"

/**
 * _prenv - current environment is printed
 * @arst: Structure containing potential arguments. Used to maintain
 *   prototype constant function.
 * Return: Always 0
 */
int _prenv(info_t *arst)
{
pr_lst_str(arst->env);
return (0);
}

/**
 * _vrenv - gets the value of an environ variable
 * @arst: Arrangement with poten arguments. used to keep up
 * @env_nam: Environment Vocabulary
 * Return: the value
 */
char *_vrenv(info_t *arst, const char *env_nam)
{
list_t *als_nod;
char *l;

for (als_nod = arst->env; als_nod != NULL; als_nod = als_nod->next)

{
l = sta_wit(als_nod->str, env_nam);
if (l && *l)
{
return (l);
}
}

return (NULL);
}

/**
 * _nwintenv - Set up a fresh environment variable,
 * or change a current one
 * @arst: arrangment with poten arguments. used to keep up
 * prototype constant function.
 * Return: Always 0
 */
int _nwintenv(info_t *arst)
{
if (arst->argc != 3)
{
_prinp("Incorrect number of arguements\n");
return (1);
}
if (_initvvv(arst, arst->argv[1],
arst->argv[2]))
return (0);
return (1);
}

/**
 * _delnwenv - Remove a configuration parameter
 * @arst: Arrangement that may cause disputes. used to follow
 * prototype constant function.
 * Return: Always 0
 */
int _delnwenv(info_t *arst)

{

int e = 1;
if (arst->argc == 1)
{
_prinp("Too few arguments.\n");
return (1);
}
while (e <= arst->argc)
{
_dezenv(arst, arst->argv[e]);
e++;
}

return (0);
}

/**
 * pop_env_lst - fills in the env linked list
 * @arst: Design consid potential defenses. used to keep up
 * prototype constant function.
 * Return: Always 0
 */
int pop_env_lst(info_t *arst)
{
list_t *als_nod = NULL;
size_t e = 0;

while (environ[e] !=
NULL)
{
add_node_edd(&als_nod, environ[e], 0);
e++;
}

arst->env = als_nod;
return (0);
}
