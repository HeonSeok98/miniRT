/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:42:57 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 15:27:46 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}				t_list;

int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int _value, size_t size);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int n);
int		ft_tolower(int n);
char	*ft_strchr(const char *str, int n);
char	*ft_strrchr(const char *str, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
char	*ft_strnstr(const char *str, const char *sub, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**free_split(char **split);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//add after libft subject

void	quick_sort(int	*set, int min, int sup);
char	*ft_strjoin_all(char *str, ...);
int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);
char	*get_next_line(int fd);
long	ft_atol(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		free_double(char ***str);
int		char_dangling(char **str);
int		int_dangling(int **ptr);

#endif