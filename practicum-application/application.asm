.cpu cortex-m0
.text
.global application

sentence:
    .asciz "Hello world, the ANSWER is 42 @[]`{}~"

application:
    push {r0}
    ldr r0, =sentence
    bl print_asciz
    pop {r0}

