.cpu cortex-m0
.text
.global application
.align 2

toggle_case:
    push {r5, r6, r7, lr}
    sub r5, r0, #65
    bge condition2
    b done

condition2:
    sub r6, r0, #90
    ble make_lower
    b done

make_lower:
    add r0, r0, #32

done:
    pop {r5, r6, r7, pc}
