#include "shell.h"

/**
 **_strcp - e string is copied
 *@stdt:  string to be copied to at the destination
 *@srsstr: the sou string
 *@nocp: how many characters will be duplicated
 *Return: the string that has been joined
 */
char *_strcp(char *stdt, char *srsstr, int nocp)
{
int l;
char *g = stdt;

for (l = 0; srsstr[l] != '\0' && l < nocp - 1; l++)
{
stdt[l] = srsstr[l];
}

if (l < nocp)
{
for (; l < nocp; l++)
{
stdt[l] = '\0';
}
}

return (g);
}

/**
 **_concst - joins two strings together.
 *@unostr: the opening string
 *@duestr: the second string
 *@nob: the maximum number of bytes to be used
 *Return: the string that has been joined
 */
char *_concst(char *unostr, char *duestr, int nob)
{
int l, q;
char *g = unostr;

for (l = 0; unostr[l] != '\0'; l++)
;

for (q = 0; duestr[q] != '\0' && q < nob; q++)
{
unostr[l + q] = duestr[q];
}

if (q < nob)
{
unostr[l + q] = '\0';
}

return (g);
}

/**
 **_strloc - finds the character e in string e.
 *@pst: the string to be parsed
 *@lkkch: the character to look for
 *Return: (pst) e pointer to the memory area pst
 */
char *_strloc(char *pst, char lkkch)
{
while (*pst != lkkch && *pst != '\0')
{
pst++;
}

if (*pst == lkkch)
{
return (pst);
}
else
{
return (NULL);
}
}
