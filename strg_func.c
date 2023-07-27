#include "shell.h"

/**
 * _strlon - returns e's string's length
 * @strg: the string to check for length
 * Return: integer string length
 */
int _strlon(char *strg)
{
int l = 0;

if (!strg)
return (0);

while (*strg++)
l++;
return (l);
}

/**
 * _strcmp - compares lexical patterns of two different languages.
 * @st1: the first strang
 * @st2: the second strang
 * Return: negative if st1 < st2, positive if st1 > st2, zero if st1 == st2
 */
int _strcmp(char *st1, char *st2)
{
while (*st1 && *st2)
{
if (*st1 != *st2)
return (*st1 - *st2);
st1++;
st2++;
}
if (*st1 == *st2)
return (0);
else
return (*st1 < *st2 ? -1 : 1);
}

/**
 * sta_wit - sees whether haystack comes before needle.
 * @strsr: searching a string
 * @sbstr: The needed substring
 * Return: haystack's next char's address, or NULL
 */
char *sta_wit(const char *strsr, const char *sbstr)
{
while (*sbstr)
if (*sbstr++ != *strsr++)
return (NULL);
return ((char *)strsr);
}

/**
 * _strcat - joins two strings together.
 * @stdt: is the last buffer
 * @bfsrc: the origin buffer
 * Return: pointer to the desired buffer
 */
char *_strcat(char *stdt, char *bfsrc)
{
char *ret = stdt;

while (*stdt)
stdt++;
while (*bfsrc)
*stdt++ = *bfsrc++;
*stdt = *bfsrc;
return (ret);
}
