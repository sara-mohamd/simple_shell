#include "shell.h"

/**
 * _strcpy - copyis e str
 * @gill: the destination
 * @sou: the sou
 * Return: pointer to desti
 */
char *_strcpy(char *gill, char *sou)
{
int e = 0;

if (gill == sou || sou == 0)
return (gill);
while (sou[e])
{
gill[e] = sou[e];
e++;
}
gill[e] = 0;
return (gill);
}

/**
 * _strdup -  double e str
 * @str_duu: the str to double that
 * Return: pointer to the dupli string using malloc
 */
char *_strdup(const char *str_duu)
{
int lon = 0;
char *pts;

if (str_duu == NULL)
return (NULL);
while (*str_duu++)
lon++;
pts = malloc(sizeof(char) * (lon + 1));
if (!pts)
return (NULL);
for (lon++; lon--;)
pts[lon] = *--str_duu;
return (pts);
}

/**
 *_puts - displ an inpt stri
 *@prnott: the stris printed
 * Return: Nothing to return
 */
void _puts(char *prnott)
{
int e = 0;

if (!prnott)
return;
while (prnott[e] != '\0')
{
_wrtchar(prnott[e]);
e++;
}
}

/**
 * _wrtchar - writes the chara c to stdout
 * @l: The character to print
 * Return: On success 1 will be.
 * On error, -1 is returned, and errno is set approp.
 */
int _wrtchar(char l)
{
static int e;
static char bff[WRITE_BUF_SIZE];

if (l == BUF_FLUSH || e >= WRITE_BUF_SIZE)
{
write(1, bff, e);
e = 0;
}
if (l != BUF_FLUSH)
bff[e++] = l;
return (1);
}
