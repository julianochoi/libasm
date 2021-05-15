# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 23:33:36 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:45:21 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ssize_t	ft_write(int fd, const void *buf, size_t count)
;			[	rax	|	rdi	|	rsi		|	rdx		|	r10	|	r8	|	r9	]
;syscall	[	(1)	|	fd	|	*buf	|	count	|		|		|		]

global ft_write

extern __errno_location

ft_write:
	mov rax, 1				; syscall 1(write)
	syscall
	cmp rax, 0				; compara rax com 0
	jl error				; se menor que zero, deu erro
	ret
error:
	neg rax					; erro do write volta negativo, entao inverte
	push rax				; salva o retorno no stack
	call __errno_location	; errno_location poe o ptr para o erro no rax
	pop qword[rax]			; desreferencia ptr do erro, coloca o erro do write
	mov rax, -1				; retorna -1
	ret	
	