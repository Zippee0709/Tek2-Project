BITS 64
global strncmp:function

strncmp:
    xor rcx, rcx
    cmp rdi, 0
    je false
    cmp rsi, 0
    je false
    cmp rdx, 0
    je false

loop:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    cmp r8b, 0
    je true
    cmp r9b, 0
    je true, 
    cmp r8b, r9b
    jne true
    cmp rcx, rdx
    je true
    inc rcx
    jmp loop

true:
    sub r8b, r9b
    cmp r8b, 0
    jl inf
    cmp r8b, 0
    jg sup
    cmp r8b, 0
    je equal

inf:
    mov rax, -1
    ret

sup:
    mov rax, 1
    ret

equal:
    mov rax, 0
    ret

false:
    ret