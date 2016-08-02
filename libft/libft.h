/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_temp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:37:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/07/09 16:08:45 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <inttypes.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer
{
	char			*data;
	char			*init;
	int				fd;
	struct s_buffer	*next;
	struct s_buffer	*prev;
}					t_buffer;

extern size_t		ft_strlen(const char *s);
extern char			*ft_strdup(char *s);
extern char			*ft_strcpy(char *dest, char *src);
extern char			*ft_strncpy(char *dst, const char *src, size_t n);
extern char			*ft_strcat(char *dst, const char *src);
extern char			*ft_strncat(char *dest, const char *src, size_t n);
extern size_t		ft_strlcat(char *dst, const char *src, size_t n);
extern char			*ft_strchr(const char *s, int c);
extern char			*ft_strrchr(const char *s, int c);
extern char			*ft_strstr(const char *meule_de_foin, const char *aiguille);
extern char			*ft_strnstr(const char *meule_de_foin, const char *aiguille,
size_t n);
extern int			ft_strcmp(const char *s1, const char *s2);
extern int			ft_strncmp(const char *s1, const char *s2, size_t n);
extern int			ft_isalpha(int c);
extern int			ft_isdigit(int c);
extern int			ft_isalnum(int c);
extern int			ft_isascii(int c);
extern int			ft_isprint(int c);
extern int			ft_toupper(int c);
extern int			ft_tolower(int c);
extern void			*ft_memset(void *b, int c, size_t len);
extern void			ft_bzero(void *s, size_t n);
extern void			*ft_memcpy(void *dst, const void *src, size_t n);
extern void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
extern void			*ft_memmove(void *dst, const void *src, size_t n);
extern void			*ft_memchr(const void *s, int c, size_t n);
extern int			ft_memcmp(const void *s1, const void *s2, size_t n);
extern void			*ft_memalloc(size_t n);
extern void			ft_memdel(void **ap);
extern char			*ft_strnew(size_t n);
extern void			ft_strdel(char **as);
extern void			ft_strclr(char *s);
extern void			ft_striter(char *s, void (*f)(char *));
extern void			ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char			*ft_strmap(char const *s, char (*f)(char));
extern char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern int			ft_strequ(char const *s1, char const *s2);
extern int			ft_strnequ(char const *s1, char const *s2, size_t n);
extern char			*ft_strsub(char const *s, unsigned int start, size_t len);
extern char			*ft_strjoin(char const *s1, char const *s2);
extern char			*ft_strtrim(char const *s);
extern void			ft_putchar(int c);
extern void			ft_putstr(char const *s);
extern char			**ft_strsplit(char const *s, char c);
extern void			ft_putendl(char const *s);
extern void			ft_putchar_fd(char c, int fd);
extern void			ft_putstr_fd(char const *s, int fd);
extern void			ft_putendl_fd(char const *s, int fd);
extern char			*ft_itoa(int n);
extern void			ft_putnbr(int n);
extern void			ft_putnbr_fd(int n, int fd);
extern int			ft_atoi(const char *str);
extern t_list		*ft_lstnew(void const *content, size_t content_size);
extern void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
extern void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
extern void			ft_lstadd(t_list **alst, t_list *new);
extern void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
extern t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
extern void			ft_lstaddend(t_list **list, t_list *elem);
extern void			ft_swap(char *str);
extern size_t		ft_lstcount(t_list *lst);
extern int			ft_tabcount(char **tab);
extern void			ft_tabtri(int *tab, int size);
extern int			ft_strrep(char *str, char c);
extern char			*ft_itoa_base(intmax_t n, int base);
extern char			*unsigned_itoa_base(uintmax_t n, int base);
extern void			ft_uni_putchar(wchar_t c);
extern int			ft_atoi_base(const char *str, int base);
extern char			**ft_split_copy(char **str);
extern int			ft_str_char_cmp(char *str, char *str2, char c);
extern int			get_next_line(int const fd, char **line);
extern void			ft_strpushback(char *str, int n);
extern void			ft_free_double_str(char **str);
extern int			ft_get_size_double_str(char **str);
extern void			ft_insert_double_str(char ***str, char *new);
extern void			ft_replace_char(char *str, char c, char new);
extern void			ft_delete_double_str(char **str, int pos);
extern int			ft_search_char(char *str, char c);

#endif
