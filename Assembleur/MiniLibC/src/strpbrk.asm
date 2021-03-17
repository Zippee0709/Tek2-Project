BITS 64
global my_strpbrk:function

my_strpbrk:
    xor rcx, rcx    
    cmp rdi, 0      
    je false       
    cmp rsi, 0      
    je false

loop:
    xor rcx, rcx
    mov r8b, [rdi]
    mov r9b, [rsi]
    cmp r8b, r9b
    je sloop
    cmp r8b, 0
    je false
    inc rdi
    jmp loop         

sloop:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    cmp r9b, 0
    je loop
    cmp r8b, 0
    je false
    cmp r8b, r9b
    je true
    inc rcx
    jmp sloop

true:
    mov rax, rdi
    ret

false:
    mov rax, 0
    ret
