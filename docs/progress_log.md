# Progress Log

### May 30, 2026
- began project

### June 1, 2026
- added a linker script, start.S, Makefile, and basic QEMU UART
- added `itoa`
- added coloured & numerical logging

### June 4, 2026
- began learning Assembly
- learned Assembly function argument passing/return

### June 5, 2026
- learned how to use `lw`/`sw` & that they operate on memory addresses
- practiced `lw`/`sw` through C pointers

### June 7, 2026
- learned how to call a C function from Assembly
    - verified these calls through the C logging functions

### June 9, 2026
- learned about the stack:
    - `sp`
    - saving to stack and freeing stack
    - about stack alignment
- learned how to read CSRs
    - read `mhartid` from Assembly

### June 15, 2026
- implemented basic traps using CSRs `mcause` & `mepc`
- implemented function to set `mtvec` to `trap_entry` Assembly function
- implemeneted trap handler function in C
    - outputs `mcause` and `mepc`
    - determines whether trap is `ecall` & if so adds 4 to `mepc` before returning
