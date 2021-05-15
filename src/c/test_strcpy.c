/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:51:19 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 15:41:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_strcpy(void)
{
	int			i;
	char		dest1[500];
	char		dest2[500];
	int			ret_value;
	static char	*s_arr[] = {"", "Lorem ipsum dolor sit amet, consectetur \
adipiscing elit. Fusce aliquam dapibus metus quis maximus. Praesent \
laoreet leo sit amet magna auctor, ut sodales mi gravida. Donec id ligula \
sit amet justo consectetur accumsan. Duis feugiat elementum odio ac \
rhoncus. Sed ullamcorper orci sed nibh vehicula interdum. Duis consequat \
sem nec risus porttitor consectetur. Nam iaculis sit amet diam vel luctus. \
Vivamus scelerisque arcu vel scelerisque faucibus."};

	i = 0;
	printf(BGRN"Testing ft_strcpy:\e[0m\n");
	while (i <= 1)
	{
		ret_value = strcmp(ft_strcpy(dest1, s_arr[i]), strcpy(dest2, s_arr[i]));
		printf(BCYN"   strcpy:\e[0m\"%s\" at [%p]\n", dest2, dest2);
		printf(BCYN"ft_strcpy:\e[0m\"%s\" at [%p]\n", dest1, dest1);
		if (!ret_value)
			printf(BGRN"OK\e[0m\n");
		else
			printf(BRED"KO\e[0m\n");
		i++;
	}
	printf(BBLK"%s\e[0m\n", LINESEP);
}
