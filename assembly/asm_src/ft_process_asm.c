#include "asm.h"

int		ft_is_whitespace(char *line)
{
	return (!ft_strncmp(line, "//", 2) || !(*line) || *line == 13);
}

int		ft_is_a_instruction(char *line)
{
	return (*line == '@');
}


void	ft_process_asm(t_asm *e)
{
	char	*str;
	t_cins	*t;

	while (e->lst)
	{
		str = ft_pop_lst(&e->lst);
		if (!ft_is_whitespace(str) && ft_is_a_instruction(str))
			ft_write_to_fd(e, ft_translate_a_instruction(str), 17);
		else if (!ft_is_whitespace(str))
		{
			t = ft_parse_c_instruction(str);
			ft_write_to_fd(e, "111", 3);
			ft_write_to_fd(e, &t->a, 1);
			ft_write_to_fd(e, t->c, 6);
			ft_write_to_fd(e, t->d, 3);
			ft_write_to_fd(e, t->j, 3);
			ft_write_to_fd(e, "\n", 1);
			free(t);
		}
	}
}
