.section .text
.balign 4 # forces 4-bit alignment
.globl set_mtvec
.globl read_mstatus_reg
.globl read_mie_reg
.globl read_mip_reg

trap_entry:
    addi sp, sp, -80

    sw ra,  0(sp)

    sw t0,  4(sp)
    sw t1,  8(sp)
    sw t2, 12(sp)
    sw t3, 16(sp)
    sw t4, 20(sp)
    sw t5, 24(sp)
    sw t6, 28(sp)

    sw a0, 32(sp)
    sw a1, 36(sp)
    sw a2, 40(sp)
    sw a3, 44(sp)
    sw a4, 48(sp)
    sw a5, 52(sp)
    sw a6, 56(sp)
    sw a7, 60(sp)

    csrr a0, mcause
    csrr a1, mepc
    csrr a2, mtval

    call trap_handler

    csrw mepc, a0

    lw ra,  0(sp)

    lw t0,  4(sp)
    lw t1,  8(sp)
    lw t2, 12(sp)
    lw t3, 16(sp)
    lw t4, 20(sp)
    lw t5, 24(sp)
    lw t6, 28(sp)

    lw a0, 32(sp)
    lw a1, 36(sp)
    lw a2, 40(sp)
    lw a3, 44(sp)
    lw a4, 48(sp)
    lw a5, 52(sp)
    lw a6, 56(sp)
    lw a7, 60(sp)

    addi sp, sp, 80

    mret

read_mstatus_reg:
    csrr a0, mstatus

read_mie_reg:
    csrr a0, mie

read_mip_reg:
    csrr a0, mip

set_mtvec:
    la t0, trap_entry
    csrw mtvec, t0
    ret
