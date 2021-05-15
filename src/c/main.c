/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:46:50 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 16:52:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_caller(char *choice)
{
	int	err_ft;
	int	err_og;
	int	c;

	err_ft = 0;
	err_og = 0;
	while (c != EOF && c != '\n')
		c = getchar();
	printf(BBLK"%s\e[0m\n", LINESEP);
	if (*choice == '1' || *choice == '7')
		test_read(&err_ft, &err_og);
	if (*choice == '2' || *choice == '7')
		test_strcmp();
	if (*choice == '3' || *choice == '7')
		test_strcpy();
	if (*choice == '4' || *choice == '7')
		test_strdup();
	if (*choice == '5' || *choice == '7')
		test_strlen();
	if (*choice == '6' || *choice == '7')
		test_write(&err_ft, &err_og);
	if (*choice == '8')
		system("clear");
	*choice = 0;
}

static void	print_options(void)
{
	printf("Choose the function to test:\n");
	printf("1:ft_read\t5:ft_strlen\n");
	printf("2:ft_strcmp\t6:ft_write\n");
	printf("3:ft_strcpy\t7:All mandatory\n");
	printf("4:ft_strdup\t8:Clear terminal\n");
	printf("9:Exit\n");
}

int	main(void)
{
	char	*choice;

	choice = calloc(2, sizeof(char));
	while (1)
	{
		if (!choice[0])
			print_options();
		choice = fgets(choice, 2, stdin);
		if (choice[0] >= '1' && choice[0] <= '8')
			test_caller(choice);
		if (choice[0] == '9')
			break ;
	}
	free (choice);
	return (0);
}
