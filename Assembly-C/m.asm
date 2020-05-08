.data
smth db 4

.code
Hello proc
    mov rax, 0

    lp1:
    add rax, rcx
    dec smth
    jnz lp1

    ret
Hello endp
end