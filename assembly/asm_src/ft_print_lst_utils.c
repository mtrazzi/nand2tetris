#include "asm.h"

void	ft_print_elt_str(t_list *elt)
{
	ft_putendl(elt->content);
}

void	ft_print_lst_str(t_list *lst)
{
	ft_lstiter(lst, &ft_print_elt_str);
}
