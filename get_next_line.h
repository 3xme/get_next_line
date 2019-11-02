#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int 	get_next_line(int fd,char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s1, int  c);
