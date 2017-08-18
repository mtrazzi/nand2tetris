#include "asm.h"

void	ft_process_label(t_asm *e, char *label, int n)
{
	char *str;

	str = label + 1;
	*(ft_strchr(str, ')')) = '\0';
	if (ft_give_symbol(str, e->sym_tab) < 0)
		ft_add_symbol(&e->sym_tab, n, ft_strdup(str));	
	*(ft_strchr(str, '\0')) = ')';
	ft_printf("label is now : %s\n", label);
}

void	ft_first_pass(t_asm *e)
{
	t_list		*lst;
	int			n;

	lst = e->lst;
	n = 0;
	while (lst)
	{
		if (*((char *)lst->content) == '(')
			ft_process_label(e, (char *)lst->content, n);
		if (!ft_is_whitespace((char *)lst->content))
			n++;
		while (*((char *)lst->content) == ' ' || *((char *)lst->content) == '\t')
			(lst->content)++;
		lst = lst->next;
	}
}
