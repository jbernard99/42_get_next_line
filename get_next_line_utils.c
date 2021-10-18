#include "get_next_line.h"

int ft_strlen_char(char *str, char c)
{
    //Fully Tested
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (!c)
        return (i);
    if (str[i] != c)
        return (0);
    else
        return (i + 1);
}

char    *ft_joinfree(char *to_free, char *to_add)
{
    char    *ret;
    int     i;

    ret = malloc(sizeof(char) * (ft_strlen_char(to_free, 0) + ft_strlen_char(to_add, 0) + 1));
    if (!ret)
        return (0);

    i = 0;
    while (to_free && to_free[i])
    {
        ret[i] = to_free[i];
        i++;
    }
    free(to_free);
    while (*to_add)
        ret[i++] = *to_add++;
    ret[i] = '\0';
    return (ret);
}

char    *ft_strdup(char *str)
{
    char    *ret;
    int     i;
    i = ft_strlen_char(str, 0);
    ret = malloc(sizeof(char) * i + 1);
    if (!ret)
        return (0);
    i = -1;
    while (str[++i])
        ret[i] = str[i];
    ret[i] = '\0';
    return (ret);
}