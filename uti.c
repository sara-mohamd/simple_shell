#include "shell.h"

/**
 * _strtoin - e string is changed to an integer.
 * @cstr: the string being transformed
 * Return: 0 if the string contains no numbers; or, converted number
 * -1 on error
 */
int _strtoin(char *cstr)
{
int l = 0;
unsigned long int result = 0;

if (*cstr == '+')
cstr++;

while (cstr[l] != '\0')
{
if (cstr[l] >= '0' && cstr[l] <= '9')
{
result *= 10;
result += (cstr[l] - '0');
if (result > INT_MAX)
return (-1);
}
else
{
return (-1);
}

l++;
}

return (result);
}

/**
 * pri_bug - prints a message in error
 * @pminvo: information struct for parameters and returns
 * @bstr: string with the indicated error type
 * Return: 0 if the string contains no numbers;or,converted number
 * -1 on error
 */
void pri_bug(info_t *pminvo, char *bstr)
{
_prinp(pminvo->fnamm);
_prinp(": ");
prdc(pminvo->line_coutt, STDERR_FILENO);
_prinp(": ");
_prinp(pminvo->argv[0]);
_prinp(": ");
_prinp(bstr);
}

/**
 * prdc - function outputs integer decimal number in base 10 for e.
 * @inpt: an input
 * @fdw: The address to contact is
 * Return: how many characters printed
 */
int prdc(int inpt, int fdw)
{
int (*__wrtchar)(char) = _wrtchar;
int l = 1000000000, total = 0;
unsigned int abs, current;

if (fdw == STDERR_FILENO)
__wrtchar = _ewrtchar;
if (inpt < 0)
{
abs = -inpt;
__wrtchar('-');
total++;
}
else
abs = inpt;

current = abs;
while (l > 1)
{
if (abs / l)
{
__wrtchar('0' + current / l);
total++;
}

current %= l;
l /= 10;
}

__wrtchar('0' + current);
total++;

return (total);
}

/**
 * covrr_no - converter function; e of itoa clone
 * @no: number
 * @b: base
 * @arflg: argument flags
 * Return: string
 */
char *covrr_no(long int no, int b, int arflg)
{
static char *arr;
static char buffer[50];
char sign = 0;
char *pts;
unsigned long n = no;

if (!(arflg & CONVERT_UNSIGNED) && no < 0)
{
n = -no;
sign = '-';
}

arr = arflg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pts = &buffer[49];
*pts = '\0';

for (; n != 0; n /= b)
*--pts = arr[n % b];

if (sign)
*--pts = sign;

return (pts);
}

/**
 * del_com - function substitute "0" for first occurence of "#"
 * @addmo: address of the modified string
 * Return: Always 0;
 */
void del_com(char *addmo)
{
int l = 0;
char found_comment = 0;

while (addmo[l] != '\0' && !found_comment)

{
if (addmo[l] == '#' && (!l || addmo[l - 1] == ' '))
{
addmo[l] = '\0';
found_comment = 1;
}
l++;
}
}
