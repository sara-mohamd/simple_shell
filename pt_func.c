#include "shell.h"

/**
 *_prinp - displays an inpt string
 * @prtstr: a string will be printed
 * Return: Nothing
 */
void _prinp(char *prtstr)
{
int e = 0;

if (!prtstr)
return;
while (prtstr[e] != '\0')
{
_ewrtchar(prtstr[e]);
e++;
}
}

/**
 * _ewrtchar - adds the letter C to stderr.
 * @q: The text to be printed
 * Return: On success 1.
 * On error, -1 is returned, with the proper setting of errno.
 */
int _ewrtchar(char q)
{
static int e;
static char bff[WRITE_BUF_SIZE];

if (q == BUF_FLUSH || e >= WRITE_BUF_SIZE)
{
write(2, bff, e);
e = 0;
}
if (q != BUF_FLUSH)
bff[e++] = q;
return (1);
}

/**
 * _wrtcf - writes the letter C to the specified filenames.
 * @q: The text to be printed
 * @fildes: The address to write to is
 * Return: On success 1.
 * On error, -1 is returned, with the proper setting of errno.
 */
int _wrtcf(char q, int fildes)
{
static int e;
static char bff[WRITE_BUF_SIZE];

if (q == BUF_FLUSH ||
e >= WRITE_BUF_SIZE)
{
write(fildes, bff, e);
e = 0;
}
if (q != BUF_FLUSH)
bff[e++] = q;
return (1);
}

/**
 *_putsfd - displays an inpt string
 * @prtstr: a string that will be printed
 * @fildes: A address for communication is
 * Return: amount of characters entered
 */
int _putsfd(char *prtstr, int fildes)
{
int e = 0;

if (!prtstr)
return (0);

for (; *prtstr; prtstr++)
{
e += _wrtcf(*prtstr, fildes);
}

return (e);
}
