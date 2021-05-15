# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 21:48:43 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:22:23 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;char		*ft_strcpy(char *dest, const char *src)
;			[	rdi		|	rsi		|	rdx	|	r10	|	r8	|	r9	]
;ft_strcpy	[	*dest	|	*src	|		|		|		|		]

global ft_strcpy

ft_strcpy:
	xor rcx, rcx			;	zera o registrador contador (i = 0)
	xor rdx, rdx			;	zera o registrador temporario
	cmp rsi, 0				;	(if (!rsi) -> return)
	je return
loop:
	mov dl, BYTE [rsi + rcx];	copia 1 byte do source(rsi) para o temporario dl
	mov BYTE [rdi + rcx], dl;	move dl para a posicao rcx no destino(rdi)
	inc rcx
	cmp dl, 0				;	if (!rsi[rcx]) -> break
	jne loop
return:
	mov rax, rdi			;	rax recebe o ponteiro(dest) em rdi
	ret