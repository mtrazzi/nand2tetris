#ifndef ASM_H

# define ASM_H
# include "libft.h"

/*
** Structure for the environment 
** for the assembler
*/

typedef struct		s_asm
{
	t_list			*lst;
	int				fd;
}					t_asm;

/*
** Structure for c-instructions
*/

typedef	struct		s_cins
{
	char			a;
	char			c[6];	
	char			d[3];
	char			j[3];
}					t_cins;


/*
** Functions for lists 
*/

void				ft_add_to_end_lst(t_list **lst, void const *content);
char				*ft_pop_lst(t_list **lst);
void				ft_print_lst_str(t_list *lst);

/*
** Functions that deal with the 
** asm environment
*/

t_asm				*ft_init_asm(void);
void				ft_free_asm_env(t_asm *e);

/*
** Functions for error handling
*/

void				ft_error_asm(t_asm *e, char *error_message);
void				ft_perror_asm(t_asm *e);

/*
** Functions for input/output in file
*/

void				ft_file_to_lst_asm(t_asm *e, char *file_name);
int					ft_open_new_file_asm(t_asm *e, char *file_name, char *ext);
void				ft_write_to_fd(t_asm *e, char *str, size_t n);

/*
** Functions for parsing
*/

int					ft_is_whitespace(char *line);

/*
** Functions for translating from assembly to binary
*/

void				ft_process_asm(t_asm *e);
char				*ft_translate_a_instruction(char *line);
t_cins				*ft_parse_c_instruction(char *line);

#endif
