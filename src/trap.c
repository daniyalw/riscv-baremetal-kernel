#include <logging.h>
#include <trap.h>

unsigned int trap_handler(unsigned int mcause, unsigned int mepc) {
    const char mcause_text[] = "mcause = ";
    const char mepc_text[] = "mepc = ";

    log_info(mcause_text);
    log_int(mcause, 10);
    new_line();

    log_info(mepc_text);
    log_int(mepc, 16);
    new_line();

    if (mcause == 11) {
        // ecall
        log_info("ECALL DETECTED");

        mepc += 4;
    } else {
        // if not ecall, it's an illegal call, and error & halt
        unknown_trap();

        while (1) {}
    }

    return mepc;
}

void unknown_trap() {
    const char unknown_trap_msg[] = "Unknown trap! Halting.";
    log_error(unknown_trap_msg);
}
