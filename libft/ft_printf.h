/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:55 by klha              #+#    #+#             */
/*   Updated: 2024/02/06 18:15:13 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);

int		printf_putchar_fd(char c, int fd);
int		printf_putnbr_fd(int n, int fd);
int		printf_putstr_fd(char *s, int fd);
int		ft_put_unnbr_fd(unsigned int n, int fd);
char	*ft_put_hex(unsigned int n, char det);
size_t	ft_strlen(const char *str);
char	*ft_put_ptr(void *ptr);
char	*ft_put_hex(unsigned int n, char det);

#endif
