#include "shell.h"

/**
 * is_cm - determines if e file is an executable command
 * @strin: the info struct
 * @fpath: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cm(info_t *strin, char *fpath)
{
struct stat pst;

(void)strin;
if (!fpath || stat(fpath, &pst))
return (0);

if (pst.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dup_chars - duplicates characters
 * @pahhstr: the PATH str
 * @strtind: starting ind
 * @stoind: stopping ind
 * Return: pointer to new buffer
 */
char *dup_chars(char *pahhstr, int strtind, int stoind)
{
static char bff[1024];
int l = strtind, y = 0;

while (l < stoind)
{
if (pahhstr[l] != ':')
bff[y++] = pahhstr[l];
l++;
}

bff[y] = 0;
return (bff);
}


/**
 * find_path - the PATH str identifies command
 * @strin: struct of info
 * @pahhstr: PATH of str
 * @fcd: the cmd to find
 * Return: complete path of commnd, if found, or NULL
 */
char *find_path(info_t *strin, char *pahhstr, char *fcd)
{
int l = 0, ceur_ppis = 0;
char *path;

if (!pahhstr)
return (NULL);
if ((_strlon(fcd) > 2) && sta_wit(fcd, "./"))
{
if (is_cm(strin, fcd))
return (fcd);
}
while (1)
{
if (!pahhstr[l] || pahhstr[l] == ':')
{
path = dup_chars(pahhstr, ceur_ppis, l);
if (!*path)
_strcat(path, fcd);
else
{
_strcat(path, "/");
_strcat(path, fcd);
}
if (is_cm(strin, path))
return (path);
if (!pahhstr[l])
break;
ceur_ppis = l;
}
l++;
}
return (NULL);
}
