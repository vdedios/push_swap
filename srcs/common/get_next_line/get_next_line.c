#include "get_next_line.h"

char	*add_char(char *line, char buffer)
{
	char	*output;
	int		l;

	l = 0;
	while (line && line[l])
		l++;
	output = malloc((l + 2) * sizeof(char));
	if (!output)
		return (NULL);
	l = 0;
	while (line && line[l])
	{
		output[l] = line[l];
		l++;
	}
	output[l] = buffer;
	output[l + 1] = '\0';
	free(line);
	return (output);
}

int	get_next_line(char **line)
{
	int		output;
	char	buffer;

	*line = malloc(sizeof(char));
	if (!line)
		return (-1);
	buffer = 0;
	**line = '\0';
	output = read(0, &buffer, 1);
	while (output)
	{
		if (output == -1)
			return (-1);
		if (buffer == '\n')
			break ;
		*line = add_char(*line, buffer);
		if (!(*line))
			return (-1);
		output = read(0, &buffer, 1);
	}
	return (output);
}
