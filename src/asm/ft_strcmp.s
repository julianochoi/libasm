# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 23:33:04 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:20:19 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;int		ft_strcmp(const char *s1, const char *s2)
;			[	rdi	|	rsi	|	rdx	|	r10	|	r8	|	r9	]
;ft_strcmp	[	*s1	|	*s2	|		|		|		|		]

global ft_strcmp

ft_strcmp:
	xor rax, rax	;	zerando os registradores
	xor rcx, rcx
	xor rdx, rdx
loop:
	mov al, BYTE [rdi + rcx]	;	armazena no a o "rcx-ésimo" BYTE do s1
	mov dl, BYTE [rsi + rcx]	;	armazena no d o "rcx-ésimo" BYTE do s2
	cmp al, 0					;	if (!s1[rcx]) -> return
	je end
	cmp dl, 0					;	if (!s2[rcx]) -> return
	je end
	cmp al, dl					;	if (s1[rcx] == s2[rcx])
	jne end						;	se diferente -> return
	inc rcx						;	senão rcx++ e loop
	jmp loop
end:
	sub rax, rdx				;	retorna (s1[rcx] - s2[rcx]) na primeira diff
	ret