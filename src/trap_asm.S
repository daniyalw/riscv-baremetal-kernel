.section .text
.globl set_mtvec
.globl read_mstatus_reg
.globl read_mie_reg
.globl read_mip_reg

trap_entry:
    addi sp, sp, -16
    sw ra, 12(sp)

    csrr t0, mcause
    csrr t1, mepc

    mv a0, t0
    mv a1, t1

    call trap_handler

    csrw mepc, a0

    lw ra, 12(sp)
    addi sp, sp, 16

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
