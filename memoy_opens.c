#include "shell.h"

/**
 **_memset - fills memory with e constant byte
 *@d: the pointer to the memory area
 *@b: the byte to fill *d with
 *@nob: the amount of bytes to be filled
 *Return: (d) e pointer to the memory area d
 */
char *_memset(char *d, char b, unsigned int nob)
{
unsigned int l = 0;

while (l < nob)
{
d[l] = b;
l++;
}

return (d);
}


/**
 * ffree - frees e string of strings
 * @sdd: string of strings
 */
void ffree(char **sdd)
{
char **e = sdd;

if (!sdd)
return;

for (; *sdd; sdd++)
free(*sdd);

free(e);
}


/**
 * _realloc - reallocates e block of memory
 * @old_ptr: pointer to previous malloc'ated block
 * @old_bsize: byte size of previous block
 * @new_bsize: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *old_ptr, unsigned int old_bsize, unsigned int new_bsize)
{
char *t;

if (!old_ptr)
return (malloc(new_bsize));
if (!new_bsize)
return (free(old_ptr), NULL);
if (new_bsize == old_bsize)
return (old_ptr);

t = malloc(new_bsize);
if (!t)
return (NULL);

old_bsize = old_bsize < new_bsize ? old_bsize : new_bsize;
while (old_bsize--)
t[old_bsize] = ((char *)old_ptr)[old_bsize];
free(old_ptr);
return (t);
}
