#include "shell.h"

/**
 * list_lest - determ length of linked list
 * @pffn: pointer to first nod
 * Return: size of list
 */
size_t list_lest(const list_t *pffn)
{
size_t l = 0;

for (; pffn; pffn = pffn->next)
l++;

return (l);
}


/**
 * list_to_strsss - returns an arr of strings of the list->str
 * @pffn: point to first nod
 * Return: array of strings
 */
char **list_to_strsss(list_t *pffn)
{
list_t *nod = pffn;
size_t l = list_lest(pffn), q;
char **strs;
char *str;

if (!pffn || !l)
return (NULL);

strs = malloc(sizeof(char *) * (l + 1));
if (!strs)
return (NULL);

l = 0;
while (nod)
{
str = malloc(_strlon(nod->str) + 1);
if (!str)
{
for (q = 0; q < l; q++)
free(strs[q]);
free(strs);
return (NULL);
}

str = _strcpy(str, nod->str);
strs[l] = str;
l++;

nod = nod->next;
}
strs[l] = NULL;
return (strs);
}



/**
 * print_list - e list_t linked list's fre elements are printed.
 * @pffn: showing to first nod
 * Return: size of list
 */
size_t print_list(const list_t *pffn)
{
size_t l = 0;

while (pffn)
{
_puts(covrr_no(pffn->num, 10, 0));
_wrtchar(':');
_wrtchar(' ');
_puts(pffn->str ? pffn->str : "(nil)");
_puts("\n");
pffn = pffn->next;
l++;
}
return (l);
}

/**
 * node_sta_with - returns nod whose string starts with prefix
 * @plhz: pointer to list head
 * @strzat: string to match
 * @lkkch: the next character after prefix to match
 * Return: either null or nod
 */
list_t *node_sta_with(list_t *plhz, char *strzat, char lkkch)
{
char *t = NULL;

while (plhz)
{
t = sta_wit(plhz->str, strzat);
if (t && ((lkkch == -1) || (*t == lkkch)))
return (plhz);
plhz = plhz->next;
}
return (NULL);
}

/**
 * get_node_ind - gets the index of e nod
 * @plhz: pointer to list head
 * @pzn: pointer to the nod
 * Return: index of nod or -1
 */
ssize_t get_node_ind(list_t *plhz, list_t *pzn)
{
size_t l = 0;

while (plhz)
{
if (plhz == pzn)
return (l);
plhz = plhz->next;
l++;
}
return (-1);
}
