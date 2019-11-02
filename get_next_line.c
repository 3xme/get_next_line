/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:12:52 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/02 12:53:08 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE  15

char	*ft_getlines(int fd, char *str)
{
	char	*temp;
	int 	ret;
	char 	*buffer;


	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 0; 
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str,'\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		{	
			free(buffer);
			return 0;
		}
		buffer[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ret == 0 || str[0] =='\0' )
			break;
	}
	free(buffer);
	return (str);
}
int	get_next_line(int fd, char **line)
{

	static char *str;
	size_t  len;
	char  *temp;
	char c;

	if (fd < 0)
		return (-1);
	if (!line || read(fd, &c,0))
		return (-1);
	if((str = ft_getlines(fd ,str)) == NULL)
		return  (0);
	if (!(ft_strchr(str, '\n')))
	{
			if(!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		return 0;
	}
	else 
	{
		len = ft_strchr(str, '\n') - str;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);		
		free(temp);
		return (1);
	}
}

int main(int argc, char **argv)
{

	int fd = open(argv[1], O_RDONLY);
	char *line;
 	while (get_next_line(fd, &line))
	{
		printf("%s\n",line);
		free(line);
}
	free(line);
	return (argc);
}

