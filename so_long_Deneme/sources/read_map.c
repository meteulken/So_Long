#include "so_long.h"

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd); // map satır satır okuyor
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line); //yeni satırı öncekinin sonuna ekliyor
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n'); // satırları ayırıp alt alta yazıyor ve harita ortaya çıkıyor.
	free(holder_map);
	close(fd);
	return (map);
}
