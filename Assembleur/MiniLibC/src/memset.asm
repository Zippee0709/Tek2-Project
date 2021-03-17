BITS 64
global memset:function

memset:
    xor rcx, rcx    ;init rcx to 0
    cmp rdi, 0      ;cmp 1st arg to NULL
    je false
    cmp rsi, 0      ;cmp 2nd arg to NULL
    je false
    cmp rdx, 0      ;cmp 3rd arg to 0
    je false

loop:
    cmp rdx, 0      ;if 3rd arg == 0
    je true         ;jump true
    mov byte[rdi + rcx], sil    ;mov 2nd arg to 1st arg[rcx]
    dec rdx         ;decrease 3nd arg
    inc rcx         ;increase rcx
    jmp loop        ;jmp loop

true:
    mov rax, rdi
    ret

false:
    ret