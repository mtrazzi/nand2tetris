#include "asm.h"

static	char	*ft_change_extension(char *file_name, char *new_ext)
{
	char	*res;
	size_t	i;
	size_t	n;

	i = 0;
	while (file_name[i] != '.')
		i++;
	res = ft_strnew(i + ft_strlen(new_ext));
	n = -1;
	while (++n < i)
		res[n] = file_name[n];
	i = -1;
	while (new_ext[++i])
		res[n + i] = new_ext[i];
	return (res);
}

int		ft_open_new_file_asm(t_asm *e, char *file_name, char *ext)
{
	int		fd;
	char	*new_name;

	new_name = ft_change_extension(file_name, ext);
	if ((fd = open(new_name, O_CREAT | O_WRONLY,0771)) < 0)
		ft_perror_asm(e);
	return (fd);	
}

void	ft_write_to_fd(t_asm *e, char *str, size_t n)
{
	write(e->fd, str, n);
}
