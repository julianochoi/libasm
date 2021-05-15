/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:54:50 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 16:48:23 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_strcmp_functions(int (*ft)(), int (*og)(), char *s1, char *s2)
{
	int	ret_value_ft;
	int	ret_value_og;

	ret_value_ft = ft(s1, s2);
	ret_value_og = og(s1, s2);
	printf("\ns1:\"%s\"\ts2:\"%s\"\n", s1, s2);
	printf(GRN" Expected return:\e[0m[%d]\n", ret_value_og);
	printf(YEL"ft_strcmp return:\e[0m[%d]\n", ret_value_ft);
	if (ret_value_ft == ret_value_og)
		printf(BGRN"OK\e[0m\n");
	else
		printf(BRED"KO\e[0m\n");
}

void	test_strcmp(void)
{
	static char	*s_array[] = {"", "42", "normal string"};

	printf(BGRN"Testing ft_strcmp:\e[0m\n");
	test_strcmp_functions(ft_strcmp, strcmp, s_array[0], s_array[0]);
	test_strcmp_functions(ft_strcmp, strcmp, s_array[0], s_array[1]);
	test_strcmp_functions(ft_strcmp, strcmp, s_array[1], s_array[0]);
	test_strcmp_functions(ft_strcmp, strcmp, s_array[1], s_array[1]);
	test_strcmp_functions(ft_strcmp, strcmp, s_array[1], s_array[2]);
	test_strcmp_functions(ft_strcmp, strcmp, s_array[2], s_array[1]);
	printf(BBLK"%s\e[0m\n", LINESEP);
}
