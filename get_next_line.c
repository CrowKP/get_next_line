#include "get_next_line.h"
#include <unistd.h>

int	ft_checkrddata(int data, char *left_str)
{
	if (data < 0)
		return (0);
	if (!left_str && data == 0)
		return (0);
	else
		return (1);
}

char	*ft_read_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_data;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_data = 1;
	while (!ft_strchr(left_str, '\n') && rd_data != 0)
	{
		rd_data = read(fd, buff, BUFFER_SIZE);
		if (!ft_checkrddata(rd_data, left_str))
		{
			free(buff);
			return (0);
		}
		buff[rd_data] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_left_str(fd, left_str);
	if (!left_str)
		return (0);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
