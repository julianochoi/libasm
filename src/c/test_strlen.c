/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 04:11:59 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/23 15:50:34 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_strlen(void)
{
	unsigned int	ret_value_ft;
	unsigned int	ret_value_og;
	static char		*s_arr[] = {"", "Lorem ipsum dolor sit amet, consectetur \
adipiscing elit. Fusce aliquam dapibus metus quis maximus. Praesent \
laoreet leo sit amet magna auctor, ut sodales mi gravida. Donec id ligula \
sit amet justo consectetur accumsan. Duis feugiat elementum odio ac \
rhoncus. Sed ullamcorper orci sed nibh vehicula interdum. Duis consequat \
sem nec risus porttitor consectetur. Nam iaculis sit amet diam vel luctus. \
Vivamus scelerisque arcu vel scelerisque faucibus."};
	int				i;

	i = 0;
	printf(BGRN"Testing ft_strlen:\e[0m\n");
	while (i <= 1)
	{
		ret_value_ft = ft_strlen(s_arr[i]);
		ret_value_og = strlen(s_arr[i]);
		printf("string:\"%s\"\n", s_arr[i]);
		printf("\e[0;36m    strlen return:\e[0m[%d]\n", ret_value_og);
		printf("\e[0;36m ft_strlen return:\e[0m[%d]\n", ret_value_ft);
		if (ret_value_ft == ret_value_og)
			printf(BGRN"OK\e[0m\n");
		else
			printf(BRED"KO\e[0m\n");
		i++;
	}
	printf(BBLK"%s\e[0m\n", LINESEP);
}
