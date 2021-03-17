BITS 64
global memcpy:function

memcpy:
    xor rcx, rcx
    cmp rdi, 0
    je false
    cmp rsi, 0
    je false
    cmp rdx, 0
    je false

loop:
    cmp byte[rsi + rcx], 0
    je true
    cmp rdx, rcx
    je true
    mov r8b, [rsi + rcx]
    mov [rdi + rcx], r8b
    inc rcx
    jmp loop

true:
    mov rax, rdi
    ret
false:
    ret