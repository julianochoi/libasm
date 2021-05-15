# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 23:33:26 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/04/23 16:46:54 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;char		size_t	ft_strlen(const char *s)
;void		*malloc(size_t size)
;char		*ft_strcpy(char *dest, const char *src)
;char		*ft_strdup(const char *s)
;			[	rdi		|	rsi		|	rdx	|	r10	|	r8	|	r9	]
;ft_strlen	[	*s		|			|		|		|		|		]
;malloc		[	size	|			|		|		|		|		]
;ft_strcpy	[	*dest	|	*src	|		|		|		|		]
;ft_strdup	[	*s		|			|		|		|		|		]

global ft_strdup

extern ft_strlen
extern malloc
extern ft_strcpy
extern __errno_location

ft_strdup:
	cmp rdi, 0			;	if(!rdi)-> erro
	jz error
	push rdi			;	guarda copia da string no stack
	call ft_strlen		;	passa rdi para strlen e obtem o tamanho no rax
	inc rax				;	queremos malloc de (strlen + 1)
	mov rdi, rax		;	passa o argumento para rdi para ser chamado no malloc
	call malloc
	test rax, rax		;	teste se o malloc deu certo
	jz malloc_error
	pop rdi
	mov rsi, rdi		;	recupera a string no stack para o rsi(source)
	mov rdi, rax		;	passa o ponteiro do malloc para o rdi(dest)
	call ft_strcpy
	ret
malloc_error:
	neg rax					; erro do malloc volta negativo, entao inverte
	push rax				; salva o retorno no stack
	call __errno_location	; errno_location poe o ptr para o erro no rax
	pop qword[rax]			; desreferencia ptr do erro, coloca o erro do malloc
error:
	xor rax, rax
	ret
	