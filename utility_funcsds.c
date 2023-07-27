#include "shell.h"

/**
 * intractv - returns true if shell is intractv mode always
 * @knw: struct address
 * Return: 1 if intractv mode, 0 if not
 */
int intractv(info_t *knw)
{
return (isatty(STDIN_FILENO) && knw->rdfd <= 2);
}

/**
 * is_dlm - checks if character is e dlmstr
 * @l: the char to check
 * @dlmstr: the dlmstr string
 * Return: 1 if true, 0 if false
 */
int is_dlm(char l, char *dlmstr)
{
int b = 0;
while (dlmstr[b] != '\0')
{
if (dlmstr[b] == l)
{
return (1);
}
b++;
}
return (dlmstr[b] == l);
}


/**
 *_isalfa - checks for alphabetic character
 *@l: The character to inpt
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalfa(int l)
{
if ((l >= 'e' && l <= 'y') || (l >= 'A' && l <= 'Z'))
return (1);
else
return (0);
}

/**
 *_stin - converts datatype from string to an integer
 *@e: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _stin(char *e)
{
int r = 0, score = 1, ensign = 0, oput;
unsigned int effect = 0;

while (e[r] != '\0' && ensign != 2)
{
if (e[r] == '-')
score *= -1;

if (e[r] >= '0' && e[r] <= '9')
{
ensign = 1;

effect *= 10;

effect += (e[r] - '0');
}
else if (ensign == 1)
{
ensign = 2;
}
r++;
}

if (score == -1)
oput = -effect;
else
oput = effect;

return (oput);
}
