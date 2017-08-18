#include "asm.h"

t_asm	*ft_init_asm(void)
{
	t_asm	*e;

	e = (t_asm *)ft_memalloc(sizeof(t_asm));
	e->fd = 0;
	e->lst = NULL;
	ft_start_table(e);
	return (e);
}
