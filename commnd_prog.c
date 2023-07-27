#include "shell.h"

/**
 * bfee - NULLs the address and frees the e poin.
 * @asstr: address of the free pointer
 * Return: 1 if freed, otherwise 0.
 */
int bfee(void **asstr)
{
if (asstr && *asstr)
{
free(*asstr);
*asstr = NULL;
return (1);
}
return (0);
}
