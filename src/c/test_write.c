/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 04:35:15 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 15:47:52 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	test_write_ft(ssize_t (*ft)(), int *err, char *buffer, int fd_in)
{
	int	ret_value;

	ret_value = ft(fd_in, buffer, strlen(buffer));
	if (ret_value == -1)
		*err = errno;
	return (ret_value);
}

static void	test_write_wrong_file(int *err_ft, int *err_og)
{
	int			ret_value_og;
	int			ret_value_ft;
	static char	buffer[] = "do not write this string to file";

	printf(BGRN"Testing ft_write for wrong fd:\e[0m\n");
	ret_value_og = test_write_ft(write, err_og, buffer, -1);
	ret_value_ft = test_write_ft(ft_write, err_ft, buffer, -1);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m ft_write return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m ft_write Errno: \e[0m[%d]\n", *err_ft);
	if (ret_value_og == ret_value_ft && *err_og == *err_ft)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

static void	test_write_open_file(int *err_ft, int *err_og)
{
	int			fd;
	int			ret_value_og;
	int			ret_value_ft;
	static char	buffer[] = "repeating myself\n";
	char		c[2];

	printf(BGRN"Testing ft_write for open file descriptor:\e[0m\n");
	fd = open("src/text/write.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	ret_value_og = test_write_ft(write, err_og, buffer, fd);
	printf(BCYN"Check file at 'src/text/write.txt'.\e[0m\n");
	printf("Press enter to continue\n");
	fgets(c, 2, stdin);
	ret_value_ft = test_write_ft(ft_write, err_ft, buffer, fd);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m ft_write return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m ft_write Errno: \e[0m[%d]\n\n", *err_ft);
	close(fd);
	printf(BCYN"If there are two repeated lines, it is working!\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

static void	test_write_stdout(int *err_ft, int *err_og)
{
	int			ret_value_og;
	int			ret_value_ft;
	static char	s[] = {"Hello, world!\n"};

	printf(BGRN"Testing ft_write for standard output:\e[0m\n");
	ret_value_og = test_write_ft(write, err_og, s, 1);
	ret_value_ft = test_write_ft(ft_write, err_ft, s, 1);
	printf("\e[0;32m Expected return:\e[0m[%d]\n", ret_value_og);
	printf("\e[0;32m Expected Errno: \e[0m[%d]\n", *err_og);
	printf("\e[0;33m ft_write return:\e[0m[%d]\n", ret_value_ft);
	printf("\e[0;33m ft_write Errno: \e[0m[%d]\n", *err_ft);
	if (ret_value_og == ret_value_ft && *err_og == *err_ft)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
	printf(BBLK"%s\e[0m\n", LINESEP);
}

void	test_write(int *err_ft, int *err_og)
{
	test_write_stdout(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
	test_write_open_file(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
	test_write_wrong_file(err_ft, err_og);
	*err_ft = 0;
	*err_og = 0;
}
