.section .text.init
.globl _start

_start:
    la sp, _stack_top      # set stack pointer
    call main              # jump to C code

hang:
    j hang                 # infinite loop
