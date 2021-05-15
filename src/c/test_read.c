/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:26:35 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 15:49:51 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	test_read_ft(ssize_t (*ft)(), int *err, char *buffer, int fd_in)
{
	int		ret_value;
	int		fd;

	if (fd_in == 1)
		fd = open("src/text/read.txt", O_RDONLY);
	else
		fd = fd_in;
	ret_value = ft(fd, buffer, BUFFER_SIZE);
	if (ret_value == -1)
		*err = errno;
	if (fd_in == 1)
		close(fd);
	return (ret_value);
}

static void	test_read_wrong_file(int *err_ft, int *err_og)
{
	int		ret_value_og;
	int		ret_value_ft;
	char	buffer_og[BUFFER_SIZE];
	char	buffer_ft[BUFFER_SIZE];

	printf(BGRN"Testing ft_read for wrong fd:\e[0m\n");
	ret_value_og = test_read_ft(read, err_og, buffer_og, -1);
	ret_value_ft = test_read_ft(ft_read, err_ft, buffer_ft, -1);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m  ft_read return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m  ft_read Errno: \e[0m[%d]\n", *err_ft);
	if (ret_value_og == ret_value_ft && *err_og == *err_ft)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

static void	test_read_open_file(int *err_ft, int *err_og)
{
	int		ret_value_og;
	int		ret_value_ft;
	char	buffer_og[BUFFER_SIZE];
	char	buffer_ft[BUFFER_SIZE];

	printf(BGRN"Testing ft_read for open file descriptor:\e[0m\n");
	ret_value_og = test_read_ft(read, err_og, buffer_og, 1);
	ret_value_ft = test_read_ft(ft_read, err_ft, buffer_ft, 1);
	printf("\e[1;96m Expected text:\n\e[0m%s\n", buffer_og);
	printf("\e[1;96m  ft_read text:\n\e[0m%s\n", buffer_ft);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m  ft_read return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m  ft_read Errno: \e[0m[%d]\n\n", *err_ft);
	if (!strcmp(buffer_ft, buffer_og) && ret_value_og == ret_value_ft
		&& *err_og == *err_ft)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

static void	test_read_stdin(int *err_ft, int *err_og)
{
	int		ret_value_og;
	int		ret_value_ft;
	char	buffer_og[BUFFER_SIZE];
	char	buffer_ft[BUFFER_SIZE];

	printf(BGRN"Testing ft_read for standard input:\e[0m\n");
	printf("Please insert an input for the original read function:\n");
	ret_value_og = test_read_ft(read, err_og, buffer_og, 0);
	printf("Please insert the same input for the ft_read function:\n");
	ret_value_ft = test_read_ft(ft_read, err_ft, buffer_ft, 0);
	printf("\e[1;96m Expected text:\n\e[0m%s\n", buffer_og);
	printf("\e[1;96m  ft_read text:\n\e[0m%s\n", buffer_ft);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m  ft_read return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m  ft_read Errno: \e[0m[%d]\n\n", *err_ft);
	if (strcmp(buffer_ft, buffer_og))
		printf("\e[1;33mDifferent inputs\e[0m\n");
	else if (ret_value_og == ret_value_ft && *err_og == *err_ft)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

void	test_read(int *err_ft, int *err_og)
{
	test_read_stdin(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
	test_read_open_file(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
	test_read_wrong_file(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
}
