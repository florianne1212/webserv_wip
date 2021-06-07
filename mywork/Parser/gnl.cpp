#include "gnl.hpp"

int					ft_strlen(char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	int				size_s1;
	char			*copy;
	int				i;

	i = 0;
	size_s1 = ft_strlen((char *)s1);
	if (!(copy = (char*)malloc(sizeof(char) * (size_s1 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	size_t			ss1;
	size_t			ss2;
	char			*s3;

	i = 0;
	j = 0;
	if (s1 == NULL)
		ss1 = 0;
	else
		ss1 = ft_strlen((char *)s1);
	ss2 = ft_strlen((char *)s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (ss1 + ss2 + 1))))
		return (0);
	while (i < (ss1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < (ss2))
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((char *)s1);
	return (s3);
}

int					ft_check_retour(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char				*debut(char *rest, char **line, int i)
{
	char			*tmp;

	if (i >= 0)
	{
		rest[i] = '\0';
		*line = ft_strdup(rest);
		tmp = ft_strdup(rest + (i + 1));
		free(rest);
		rest = NULL;
		rest = tmp;
		return (rest);
	}
	return (rest);
}

char				*last_line(char *rest, char **line, int i, int ret)
{
	char			*tmp;

	if (ret == 0 && i != -1)
	{
		rest[i] = '\0';
		*line = ft_strdup(rest);
		tmp = ft_strdup(rest + (i + 1));
		free(rest);
		rest = NULL;
		rest = tmp;
		free(tmp);
		tmp = NULL;
		return (rest);
	}
	else if (ret == 0)
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (rest);
	}
	return (rest);
}

int					get_next_line(int fd, char **line)
{
	static char		*rest = NULL;
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	int				i;

	i = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || i != -1)
	{
		buf[ret] = '\0';
		rest = ft_strjoin(rest, buf);
		i = ft_check_retour(rest);
		if (i >= 0)
			rest = debut(rest, line, i);
		if (i >= 0)
			return (1);
	}
	rest = last_line(rest, line, i, ret);
	if (ret == 0 && i != -1)
		return (1);
	else if (ret == 0)
		return (0);
	return (-1);
}