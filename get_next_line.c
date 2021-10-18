#include "get_next_line.h"

int read_next_buffer(char **save, int fd)
{
    char    *buffer;
    int     is_reading;

    while (!*save || !ft_strlen_char(*save, '\n'))
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (0);
        is_reading = read(fd, buffer, BUFFER_SIZE);
        if (is_reading <= 0)
        {
            free(buffer);
            return (0);
        }
        buffer[is_reading] = '\0';
        //printf("\n\nBuffer : * %s *\n", buffer);
        *save = ft_joinfree(*save, buffer);
        free(buffer);
    }
    return (ft_strlen_char(*save, '\n'));
}

void stream_content(char **save, char **line, int eol_position)
{
    char    *new_save;
    int     i;

    i = -1;
    // printf("\n*\nSave: %s\neol_position: %d\n", *save, eol_position);
    // printf("*save[%d] = %c, *line[%d] = %c\n\n", i+1, *save[i + 1], i+1, *line[i + 1]);

    while (++i < eol_position)
    {
        // printf("*save[%d] = %c, *line[%d] = %c\n", i, *save[i], i, *line[i]);
        (*line)[i] = (*save)[i];
        // printf("\nLoop #%d : \n    *line[i] = %c\n    line -> %s\n*\n", i, *save[i], *line);
    }
    (*line)[i] = '\0';
    if (!ft_strlen_char(*save, '\n'))
    {
        free(*save);
        *save = NULL;
    }
    else
    {
        new_save = ft_strdup(&(*save)[eol_position]);
        free(*save);
        *save = new_save;
    }
}

char    *get_next_line(int fd)
{
    static char *save[12288];
    char        *line;
    int         i;

    //printf("\n*save[%d] = %s\n", fd, save[fd]);

    i = read_next_buffer(&save[fd], fd);
    if (!i)
        i = ft_strlen_char(save[fd], '\0');
    if (!i)
    {
        free(save[fd]);
        return NULL;
    }
    //printf("\n*save[%d] = %s\n", fd, save[fd]);
    line = malloc(sizeof(char) * i + 1);
    if (!line)
        return (NULL);
    stream_content(&save[fd], &line, i);
    return (line);
}
