.cpu cortex-m0
.text
.global application
.align 2

sentence:
    .asciz "Hello world, the ANSWER is 42 @[]`{}~"

application:
    push {r0}
    ldr r0, =sentence
    bl print_asciz
    pop {r0}

