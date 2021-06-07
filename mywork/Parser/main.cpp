#include "gnl.hpp"
#include "parseRequest.hpp"
#include <fcntl.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdio.h>
#include <iostream>

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
    int i = 0;
    ParseRequest _parserequest;

	line = NULL;
	fd = open(av[ac-1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		// printf("%s\n",line);
        i = 0;
        while (line[i])
        {
            _parserequest.parse(line[i]);
            i++;
        }
        std::cout << _parserequest.get_method();
        free(line);
	}
	close(fd);
}