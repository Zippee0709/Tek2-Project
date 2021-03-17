BITS 64
global strlen:function

strlen:
    xor rcx, rcx    ; Reset register, assigne 0 to rcx
    cmp rdi, 0      ; compare 1st argument to NULL
    je  return      ; if true je on return

loop:
    cmp byte[rdi + rcx], 0      ; compare 1st argument by byte
    je return                   ; if is true je on return
    inc rcx                     ; increase counter rcx
    jmp loop                     ; je on loop

return:
    mov rax, rcx        ; move the value in rcx to rax
    ret                 ; return the last value in rax
