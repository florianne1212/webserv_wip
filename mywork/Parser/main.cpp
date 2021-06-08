#include "gnl.hpp"
#include "parseRequest.hpp"
#include <fcntl.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include "Message.hpp"

int			main(int ac, char **av)
{
	int		fd;
	// FILE	*fdf;
	char	*line;
    int i = 0;
    ParseRequest _parserequest;
	ParseHeaderFields _parseheader;
	Message _message;

	// char str1[] = "GET /index.html HTTP/1.1\n";
	// char str2[] = "Host: localhost:8080\n";
	// char str3[] = "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:89.0) Gecko/20100101 Firefox/89.0\n";

	// fdf = fopen("req", "w");
    // fwrite(str1 , 1 , sizeof(str1) , fdf );
	// fwrite(str2 , 1 , sizeof(str1) , fdf );
	// fwrite(str3 , 1 , sizeof(str3) , fdf );
    // fclose(fdf);

	line = NULL;
	fd = open(av[ac - 1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		// printf("%s\n",line);
        i = 0;
        while (line[i])
        {
            _parserequest.parse(line[i]);

            i++;
        }
        std::cout << "method = -" << _parserequest.get_method() << "-\npath = ";
		std::cout << _parserequest.get_path() << "-\nmajor = ";
		std::cout << _parserequest.get_major() << "-\nminor = ";
		std::cout << _parserequest.get_minor();
		std::cout << _parseheader.get_field();
        free(line);
	}
	close(fd);
}