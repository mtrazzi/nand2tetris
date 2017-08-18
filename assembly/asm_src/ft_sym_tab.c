#include "asm.h"

t_line_lst	*ft_add_symbol(t_line_lst **line_lst, int fd, char *line)
{
	t_line_lst	*to_add;
	t_line_lst	*begin_lst;

	if (!line)
		return (*line_lst);
	begin_lst = *line_lst;
	to_add = (t_line_lst *)ft_memalloc(sizeof(t_line_lst));
	to_add->line = line;
	to_add->fd = fd;
	to_add->next = NULL;
	if (!(*line_lst))
	{
		*line_lst = to_add;
		return (to_add);
	}
	while ((*line_lst)->next)
		*line_lst = (*line_lst)->next;
	(*line_lst)->next = to_add;
	*line_lst = begin_lst;
	return (begin_lst);
}

int					ft_give_symbol(char *sym, t_line_lst *line_lst)
{
	if (!line_lst)
		return (-1);
	while (line_lst && ft_strcmp(sym, line_lst->line))
		line_lst = line_lst->next;
	if (line_lst && !ft_strcmp(sym, line_lst->line))
		return (line_lst->fd);
	return (-1);
}

void				ft_start_table(t_asm *e)
{
	t_line_lst	*lst;

	lst = NULL;
	ft_add_symbol(&lst, 0, "R0");	
	ft_add_symbol(&lst, 1, "R1");	
	ft_add_symbol(&lst, 2, "R2");	
	ft_add_symbol(&lst, 3, "R3");	
	ft_add_symbol(&lst, 4, "R4");	
	ft_add_symbol(&lst, 5, "R5");	
	ft_add_symbol(&lst, 6, "R6");	
	ft_add_symbol(&lst, 7, "R7");	
	ft_add_symbol(&lst, 8, "R8");	
	ft_add_symbol(&lst, 9, "R9");	
	ft_add_symbol(&lst, 10, "R10");	
	ft_add_symbol(&lst, 11, "R11");	
	ft_add_symbol(&lst, 12, "R12");	
	ft_add_symbol(&lst, 13, "R13");	
	ft_add_symbol(&lst, 14, "R14");	
	ft_add_symbol(&lst, 15, "R15");
	ft_add_symbol(&lst, 16384, "SCREEN"); 
	ft_add_symbol(&lst, 24576, "KBD");		
	ft_add_symbol(&lst, 0, "SP");	
	ft_add_symbol(&lst, 1, "LCL");	
	ft_add_symbol(&lst, 2, "ARG");	
	ft_add_symbol(&lst, 3, "THIS");	
	ft_add_symbol(&lst, 4, "THAT");
	e->sym_tab = lst;
}

void				ft_print_sym_table(t_line_lst *lst)
{
	while (lst)
	{
		ft_printf("(%d, %s)\n", lst->fd, lst->line);
		lst = lst->next;
	}
}
