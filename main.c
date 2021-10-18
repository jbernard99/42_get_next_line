#include "get_next_line.h"

int	main()
{
    char	*line;
	int		fd;
	int		counter;

	counter = 1;
	fd = open("file", O_RDONLY);
	while (counter <= 10)
    {
		line = get_next_line(fd);
		printf("Line #%d : %s", counter, line);
		free(line);
		counter++;
	}

	return (0);
}