# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 23:33:45 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:21:56 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ssize_t	ft_read(int fd, void *buf, size_t count)
;			[	rax	|	rdi	|	rsi		|	rdx		|	r10	|	r8	|	r9	]
;syscall	[	(0)	|	fd	|	*buf	|	count	|		|		|		]

global ft_read

extern __errno_location

ft_read:
	mov rax, 0				; syscall 0(read)
	syscall
	cmp rax, 0				; compara rax com 0
	jl error				; se menor que zero, deu erro
	ret
error:
	neg rax					; erro do read volta negativo, entao inverte
	push rax				; salva o retorno no stack
	call __errno_location	; errno_location poe o ptr para o erro no rax
	pop qword[rax]			; desreferencia ptr do erro, coloca o erro do read
	mov rax, -1				; retorna -1
	ret	
	