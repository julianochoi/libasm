# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 16:29:25 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:26:46 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;char		size_t	ft_strlen(const char *s)
;			[	rdi	|	rsi	|	rdx	|	r10	|	r8	|	r9	]
;ft_strlen	[	*s	|		|		|		|		|		]

global ft_strlen

ft_strlen:
	xor rcx, rcx			;	zera o registrador contador (rcx = 0)
loop:
	cmp BYTE [rdi + rcx], 0	;	if(!rdi[rcx]) -> break 
	je return				;	se verdadeiro, passa para a rotina de retorno.
	inc rcx					;	se nao, incrementa o contador e volta ao loop
	jmp loop
return:
	mov rax, rcx			;	passa o contador para o rax para retornar
	ret