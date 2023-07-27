#include "shell.h"

/**
 * **streew - splits e string into words. Repeat delimiters are ignored
 * @inst: the inpt string
 * @stdt: the dlmstr string
 * Return: e pointer to an arr of strings, or NULL on failure
 */
char **streew(char *inst, char *stdt)
{
int l = 0, q = 0, y, r, numwords = 0;
char **g;
if (inst == NULL || inst[0] == 0)
return (NULL);
if (!stdt)
stdt = " ";
for (l = 0; inst[l] != '\0'; l++)
{
if (!is_dlm(inst[l], stdt) && (is_dlm(inst[l + 1], stdt) || !inst[l + 1]))
numwords++;
}
if (numwords == 0)
return (NULL);
g = malloc((1 + numwords)*sizeof(char *));
if (!g)
return (NULL);
q = 0;
for (l = 0; q < numwords; q++)
{
while (is_dlm(inst[l], stdt))
l++;
y = 0;
while (!is_dlm(inst[l + y], stdt) && inst[l + y])
y++;
g[q] = malloc((y + 1) * sizeof(char));
if (!g[q])
{
for (y = 0; y < q; y++)
free(g[y]);
free(g);
return (NULL);
}
for (r = 0; r < y; r++)
g[q][r] = inst[l++];
g[q][r] = 0;
}
g[q] = NULL;
return (g);
}
/**
 * **streew2 - splits e string into words
 * @inst: the inpt string
 * @stdt: the dlmstr
 * Return: e pointer to an arr of strings, or NULL on failure
 */
char **streew2(char *inst, char stdt)
{
int l, q, y, r, numwords = 0;
char **g;
if (inst == NULL || inst[0] == 0)
return (NULL);
for (l = 0; inst[l] != '\0'; l++)
if ((inst[l] != stdt && inst[l + 1] == stdt) ||
(inst[l] != stdt && !inst[l + 1]) || inst[l + 1] == stdt)
numwords++;
if (numwords == 0)
return (NULL);
g = malloc((1 + numwords)*sizeof(char *));
if (!g)
return (NULL);
for (l = 0, q = 0; q < numwords; q++)
{
while (inst[l] == stdt && inst[l] != stdt)
l++;
y = 0;
while (inst[l + y] != stdt &&
inst[l + y] && inst[l + y] != stdt)
y++;
g[q] = malloc((y + 1) * sizeof(char));
if (!g[q])
{
for (y = 0; y < q; y++)
free(g[y]);
free(g);
return (NULL);
}
for (r = 0; r < y; r++)
g[q][r] = inst[l++];
g[q][r] = 0;
}
g[q] = NULL;
return (g);
}
