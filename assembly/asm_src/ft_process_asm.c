#include "asm.h"

int		ft_is_whitespace(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (!ft_strncmp(line, "//", 2) || !(*line) || *line == 13 || *line == '(');
}

int		ft_is_a_instruction(char *line)
{
	return (*line == '@');
}

void	ft_process_asm(t_asm *e)
{
	char	*str;
	t_cins	*t;
	int		n;
	int		k;

	k = 16;
	while (e->lst)
	{
		str = ft_pop_lst(&e->lst);
		if (!ft_is_whitespace(str) && ft_is_a_instruction(str))
		{
			n = ft_give_symbol(str + 1, e->sym_tab);
			if (ft_isdigit(*(str + 1)))
				ft_write_to_fd(e, ft_translate_a_instruction(ft_atoi(str + 1)), 17);
			else if (n < 0)	
			{
				ft_add_symbol(&e->sym_tab, k, str + 1);
				ft_write_to_fd(e, ft_translate_a_instruction(k), 17);
				k++;
			}
			else
				ft_write_to_fd(e, ft_translate_a_instruction(n), 17);
		}
		else if (!ft_is_whitespace(str))
		{
			t = ft_parse_c_instruction(e, str);
			free(t);
		}
	}
}
