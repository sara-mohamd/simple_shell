#include "shell.h"

/**
 * bufcc - buffers chained commands
 * @strpm: parameter struct
 * @arbuf: address of buffer
 * @arlon: address of lon voy
 * Return: bytes read
 */
ssize_t bufcc(info_t *strpm, char **arbuf, size_t *arlon)
{
ssize_t x = 0;
size_t prlon = 0;

if (!*arlon)
{

free(*arbuf);
*arbuf = NULL;
signal(SIGINT, blockc);
#if USE_GETLINE
r = getline(arbuf, &prlon, stdin);
#else
x = _getline(strpm, arbuf, &prlon);
#endif
if (x > 0)
{
if ((*arbuf)[x - 1] == '\n')
{
(*arbuf)[x - 1] = '\0';
x--;
}
strpm->lincnnt_flg = 1;
del_com(*arbuf);
bild_hist_lst(strpm, *arbuf, strpm->hiscou++);

{
*arlon = x;
strpm->cmd_buff = arbuf;
}
}
}
return (x);
}

/**
 * setlin - gets e line minus the newline
 * @strpm: parameter struct
 * Return: bytes read
 */
ssize_t setlin(info_t *strpm)
{
static char *bff;
static size_t l, q, lon;
ssize_t x = 0;
char **buf_p = &(strpm->arg), *t;

_wrtchar(BUF_FLUSH);
x = bufcc(strpm, &bff, &lon);

if (x == -1)
{
return (-1);
}

if (lon)
{
q = l;
t = bff + l;

check_chaion(strpm, bff, &q, l, lon);

for (q = l; q < lon; q++)
{
if (is_chaion(strpm, bff, &q))
{
break;
}
}

l = q + 1;
if (l >= lon)
{
l = lon = 0;
strpm->cmd_buff_typ = CMD_NORM;
}
*buf_p = t;
return (_strlon(t));
}
*buf_p = bff;
return (x);
}

/**
 * rid_buf - reads e buffer
 * @strpm: parameter struct
 * @bff: buffer
 * @syz: size
 * Return: x
 */
ssize_t rid_buf(info_t *strpm,
char *bff, size_t *syz)
{
ssize_t x = 0;

if (*syz)
return (0);
x = read(strpm->rdfd, bff, READ_BUF_SIZE);
if (x >= 0)
*syz = x;
return (x);
}

/**
 * _getline - gets the next line of inpt from STDIN
 * @strpm: parameter struct
 * @asstr: address of poin to buffer, preallocated or NULL
 * @syptr: size of preallocated pts buffer if not NULL
 * Return: g
 */
int _getline(info_t *strpm, char **asstr, size_t *syptr)
{
static char bff[READ_BUF_SIZE];
static size_t l, lon;
size_t x;
ssize_t y = 0,
g = 0;
char *t = NULL,
*new_p = NULL, *c;

t = *asstr;
if (t && syptr)
g = *syptr;
if (l == lon)
l = lon = 0;

y = rid_buf(strpm, bff, &lon);
if (y == -1 ||
(y == 0 && lon == 0))
return (-1);

c = _strloc(bff + l, '\n');
x = c ? 1 + (unsigned int)(c - bff) : lon;
new_p = _realloc(t, g, g ? g + x : x + 1);
if (!new_p) /* MALLOC FAILURE! */
return (t ? free(t), -1 : -1);

if (g)
_concst(new_p, bff + l, x - l);
else
_strcp(new_p, bff + l, x - l + 1);

g += x - l;
l = x;
t = new_p;

if (syptr)
*syptr = g;
*asstr = t;
return (g);
}

/**
 * blockc - blocks ctrl-C
 * @sgnl_no: the signal number
 * Return: void
 */
void blockc(__attribute__((unused))int sgnl_no)
{
_puts("\n");
_puts("$ ");
_wrtchar(BUF_FLUSH);
}
