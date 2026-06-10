.section .text
.globl asm_read_mhartid

asm_read_mhartid:
    csrr a0, mhartid
    addi a0, a0, 5
    ret
