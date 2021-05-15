/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:43:52 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 16:40:24 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# define BUFFER_SIZE 2048

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

# define LARGE_STRING "Lorem ipsum dolor sit amet, consectetur \
adipiscing elit. Fusce aliquam dapibus metus quis maximus. Praesent \
laoreet leo sit amet magna auctor, ut sodales mi gravida. Donec id ligula \
sit amet justo consectetur accumsan. Duis feugiat elementum odio ac \
rhoncus. Sed ullamcorper orci sed nibh vehicula interdum. Duis consequat \
sem nec risus porttitor consectetur. Nam iaculis sit amet diam vel luctus. \
Vivamus scelerisque arcu vel scelerisque faucibus."

# define LINESEP "************************************************************"

ssize_t	ft_read(int fd, void *buf, size_t count);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);

void	test_read(int *err_ft, int *err_og);
void	test_strcmp(void);
void	test_strcpy(void);
void	test_strdup(void);
void	test_strlen(void);
void	test_write(int *err_ft, int *err_og);

#endif
