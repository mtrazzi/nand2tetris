#include "asm.h"

static int	ft_is_valid_ext(char *file_name, char *extension)
{
	while (*file_name != '.')
		file_name++;
	return (!ft_strcmp(file_name, extension));
}

void		ft_file_to_lst_asm(t_asm *e, char *file_name)
{
	int		fd;
	char	*line;
	int		ret;

	line = NULL;
	if (!ft_is_valid_ext(file_name, ".asm"))
		ft_error_asm(e, "not a valid extension. \".asm\" extension expected");
	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_perror_asm(e);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_add_to_end_lst(&e->lst, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	if (ret < 0)
		ft_perror_asm(e);
}
