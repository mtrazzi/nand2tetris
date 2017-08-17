/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:59:16 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/17 11:11:58 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *h, const char *nee);
char				*ft_strnstr(const char *h, const char *nee, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_free_tab(int **tab, int size);
void				ft_free_char_tab(char **tab, int size);
int					ft_open(char *file_name);
int					ft_nb_lines(char *file_name);
int					ft_tab_length(char **tab);
long				ft_atol(const char *nptr);
int					ft_open(char *file_name);
void				ft_free(char *str);
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content);
void				ft_lstdelone(t_list **alst, void (*del)(void *));
void				ft_lstdel(t_list **alst, void (*del)(void *));
void				ft_lstadd(t_list **lst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
