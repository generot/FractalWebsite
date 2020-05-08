.data
String db "Hello, world"

.code
Print proc
    lea rax, qword ptr[String]
    ret
Print endp
end