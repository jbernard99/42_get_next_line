#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* utils */
int	    ft_strlen_char(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_joinfree(char *s1, char *s2);

/* get_next_line */
int     read_next_buffer(char **save, int fd);
void    stream_content(char **save, char **line, int eol_position);
char	*get_next_line(int fd);


# include <fcntl.h>
# include <stdio.h>
int main();
#endif