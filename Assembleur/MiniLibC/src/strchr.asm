BITS 64
global strchr:function

strchr:
    xor rcx, rcx    ; init counter register to 0
    cmp rdi, 0      ; compare 1st arg to null
    je false        ; jump equal to false
    cmp rsi, 0      ; compare 2nd arg to null
    je false        ; jump equal to false

loop:
    cmp [rdi + rcx], sil       ; compare arg[rcx] to, sil = 1st caracter of rsi
    je true                    ; if previous condition is true, jump on true
    cmp byte[rdi + rcx], 0     ; compare arg[rcx] to \0
    je false                   ; if previous condition is true, jump on false
    inc rcx                    ; increase rcx
    jmp loop                   ; repete loop

true:
    add rdi, rcx    ; add rcx to rdi, it modifie rdi pointer position to search character
    mov rax, rdi    ; mov rdi to rax        
    ret             ; return rax

false:
    mov rax, 0      ; add null pointer to rax
    ret             ; return rax