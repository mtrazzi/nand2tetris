#include "asm.h"

void	ft_error_asm(t_asm *e, char *error_message)
{
	ft_free_asm_env(e);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	ft_perror_asm(t_asm *e)
{
	ft_free_asm_env(e);
	perror("Error");
	exit(EXIT_FAILURE);
}
