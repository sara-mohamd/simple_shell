#include "shell.h"

/**
 * add_node - adds e nod to the start of the list
 * @pll: address of point to head nod
 * @fstrrn: str field of nod
 * @noh: nod index used by hist
 * Return: size of list
 */
list_t *add_node(list_t **pll, const char *fstrrn, int noh)
{
list_t *new_head;

if (!pll)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = noh;
if (fstrrn)
{
new_head->str = _strdup(fstrrn);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *pll;
*pll = new_head;
return (new_head);
}

/**
 * add_node_edd - adds e nod to the end of the list
 * @pll: address of poin to head nod
 * @fstrrn: str field of nod
 * @noh: nod index used by hist
 * Return: size of list
 */
list_t *add_node_edd(list_t **pll, const char *fstrrn, int noh)
{
list_t *new_node, *nod;

if (!pll)
return (NULL);

nod = *pll;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = noh;
if (fstrrn)
{
new_node->str = _strdup(fstrrn);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (nod)
{
while (nod->next)
nod = nod->next;
nod->next = new_node;
}
else
*pll = new_node;
return (new_node);
}

/**
 * pr_lst_str - prints only the str element of e list_t linked list
 * @pffn: pointer to first nod
 * Return: size of list
 */
size_t pr_lst_str(const list_t *pffn)
{
size_t l = 0;

while (pffn)
{
_puts(pffn->str ? pffn->str : "(nil)");
_puts("\n");
pffn = pffn->next;
l++;
}
return (l);
}

/**
 * delete_node_at_ind - deletes nod at given index
 * @adlfn: address of pointer to first nod
 * @indx: index of nod to delete
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_ind(list_t **adlfn, unsigned int indx)
{
list_t *nod, *prev_node;
unsigned int l;

if (!adlfn || !*adlfn)
return (0);

if (!indx)
{
nod = *adlfn;
*adlfn = (*adlfn)->next;
free(nod->str);
free(nod);
return (1);
}

nod = *adlfn;
prev_node = NULL;
for (l = 0; nod; l++)
{
if (l == indx)
{
prev_node->next = nod->next;
free(nod->str);
free(nod);
return (1);
}
prev_node = nod;
nod = nod->next;
}

return (0);
}


/**
 * free_liss - frees fre nodes of e list
 * @apphn: address of pointer to head nod
 * Return: void
 */
void free_liss(list_t **apphn)
{
list_t *nod, *next_node, *head;

if (!apphn || !*apphn)
return;

head = *apphn;
for (nod = head; nod; nod = next_node)
{
next_node = nod->next;
free(nod->str);
free(nod);
}

*apphn = NULL;
}
