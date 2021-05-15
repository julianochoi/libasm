/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 04:09:56 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 16:47:53 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_strdup(void)
{
	int			i;
	char		*dest1;
	char		*dest2;
	int			ret_value;
	static char	*s_array[] = {"", LARGE_STRING};

	i = 0;
	printf(BGRN"Testing ft_strdup:\e[0m\n");
	while (i <= 1)
	{
		dest1 = ft_strdup(s_array[i]);
		dest2 = strdup(s_array[i]);
		ret_value = strcmp(dest1, dest2);
		printf(BCYN"string:\e[0m\"%s\" at [%p]\n", s_array[i], s_array[i]);
		printf(BCYN"strdup:\e[0m\"%s\" at [%p]\n", dest2, dest2);
		printf(BCYN"ft_strdup:\e[0m\"%s\" at [%p]\n", dest1, dest1);
		if (!ret_value)
			printf(BGRN"OK\e[0m\n");
		else
			printf(BRED"KO\e[0m\n");
		i++;
		free(dest1);
		free(dest2);
	}
	printf(BBLK"%s\e[0m\n", LINESEP);
}
