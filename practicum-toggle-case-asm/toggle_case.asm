.cpu cortex-m0
.text
.global toggle_case
.align 2

toggle_case:
    push {r4-r7, lr}
    mov r4, r0
    mov r5, r0
    mov r6, r0
    mov r7, r0

check_upper1:
    sub r4, #'A'
    bge check_upper2
    b check_lower1

check_upper2:
    sub r5, #'Z'
    ble make_lower
    b check_lower1

check_lower1:
    sub r6, r6, #'a'
    bge check_lower2
    b done

check_lower2:
    sub r7, #'z'
    ble make_upper
    b done

make_lower:
    add r0, #32
    b done

make_upper:
    sub r0, #32
    b done

done:
    pop {r4-r7, pc}
