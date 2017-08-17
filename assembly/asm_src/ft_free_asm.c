#include "asm.h"

void	ft_free_content(void *content)
{
	ft_memdel(&content);	
}

void	ft_free_lst(t_list *lst)
{
	ft_lstdel(&lst, &ft_free_content);
}

void	ft_free_asm_env(t_asm *e)
{
	ft_free_lst(e->lst);
	ft_memdel((void **)&e);
}
