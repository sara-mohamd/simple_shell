#include "shell.h"

/**
 * get_hist_file - A hist file being obtained
 * @prmstr: parameter struct
 * Return: file hist in the designated string
 */
char *get_hist_file(info_t *prmstr)
{
char *bff, *dir;
dir = _vrenv(prmstr, "HOME=");
if (!dir)
return (NULL);
bff = malloc(sizeof(char) * (_strlon(dir) + _strlon(HIST_FILE) + 2));
if (!bff)
return (NULL);
bff[0] = 0;
_strcpy(bff, dir);
_strcat(bff, "/");
_strcat(bff, HIST_FILE);
return (bff);
}
/**
 * wrt_hist - creates a file or adds to an existing one.
 * @prmstr: for parameter, struct
 * Return: 1 on success, else -1
 */
int wrt_hist(info_t *prmstr)
{
ssize_t dd;
char *filename = get_hist_file(prmstr);
list_t *nod = NULL;
if (!filename)
{
return (-1);
}
dd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);

if (dd == -1)
{
return (-1);
}
nod = prmstr->hist;
while (nod)
{
_putsfd(nod->str, dd);
_wrtcf('\n', dd);
nod = nod->next;
}
_wrtcf(BUF_FLUSH, dd);
close(dd);
return (1);
}

/**
 * read_history - s reading the file hist
 * @prmstr: for parameter, struct
 * Return: counting on success, 0 otherwise
 */
int read_history(info_t *prmstr)
{
int l, last = 0, linecount = 0;
ssize_t dd, rdlen, fsize = 0;
struct stat pssr;
char *bff = NULL, *filename = get_hist_file(prmstr);
if (!filename)
return (0);
dd = open(filename, O_RDONLY);
free(filename);
if (dd == -1)
return (0);
if (!fstat(dd, &pssr))
fsize = pssr.st_size;
if (fsize < 2)
return (0);
bff = malloc(sizeof(char) * (fsize + 1));
if (!bff)
return (0);
rdlen = read(dd, bff, fsize);
bff[fsize] = 0;
if (rdlen <= 0)
return (free(bff), 0);
close(dd);
for (l = 0; l < fsize; l++)
{
if (bff[l] == '\n')
{
bff[l] = 0;
bild_hist_lst(prmstr, bff + last, linecount++);
last = l + 1;
}
}
if (last != l)
bild_hist_lst(prmstr, bff + last, linecount++);
free(bff);
prmstr->hiscou = linecount;
for (; prmstr->hiscou >= HIST_MAX; prmstr->hiscou--)
delete_node_at_ind(&(prmstr->hist), 0);
reno_hist(prmstr);
return (prmstr->hiscou);
}
/**
 * bild_hist_lst - adds a new entry to the hist list that is linked.
 * @stoor: Arrangement with possibi of disputes. used to maintain
 * @bff: buffer
 * @hisln: the hist linecount, hiscou
 * Return: Always 0
 */
int bild_hist_lst(info_t *stoor, char *bff, int hisln)
{
list_t *nod = NULL;
if (stoor->hist)
nod = stoor->hist;
add_node_edd(&nod, bff, hisln);
if (!stoor->hist)
stoor->hist = nod;
return (0);
}
/**
 * reno_hist - The hist linked list is renumbered upon modifications.
 * @stoor: Arrangement with possibility of disputes. used to maintain
 * Return: the new hiscou
 */
int reno_hist(info_t *stoor)
{
list_t *nod = stoor->hist;
int l = 0;
while (nod != NULL)
{
nod->num = l++;
nod = nod->next;
}
stoor->hiscou = l;
return (stoor->hiscou);
}
