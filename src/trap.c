#include <logging.h>
#include <trap.h>
#include <timer.h>

unsigned int trap_handler(unsigned int mcause, unsigned int mepc, unsigned int mtval) {
    unsigned int hi = 31;
    unsigned int interrupt_mask = 1u << hi;

    unsigned int cause_bits = mcause & 0x7fffffff;
    unsigned int interrupt_bit = (mcause & interrupt_mask) >> hi;

    new_line();

    if (interrupt_bit == 1) {
        log_info("Interrupt, cause = ");
    } else {
        log_info("Exception, cause = ");
    }

    log_int(cause_bits, 10);
    new_line();

    if (mcause == 11) {
        // ecall
        log_info("ECALL DETECTED");

        mepc += 4;
    } else if (mcause == 0x80000007) {
        // timer interrupt
        timer_schedule_next();
    } else {
        // if not ecall, it's an illegal call, and error & halt
        unknown_trap();

        log_error_nl("UNHANDLED TRAP");
        log_info_nl("mcause:");
        log_int(mcause, 16);
        log_info_nl("mepc:");
        log_int(mepc, 16);

        while (1) {}
    }

    return mepc;
}

void unknown_trap() {
    const char unknown_trap_msg[] = "Unknown trap! Halting.";
    log_error(unknown_trap_msg);
}

void read_mstatus() {
    unsigned int read_mstatus_reg();
    unsigned int mstatus = read_mstatus_reg();
    log_info("MSTATUS: ");
    log_int(mstatus, 16);
    new_line();
}

void read_mie() {
    unsigned int read_mie_reg();
    unsigned int mie = read_mie_reg();
    log_info("MIE: ");
    log_int(mie, 16);
    new_line();
}

void read_mip() {
    unsigned int read_mip_reg();
    unsigned int mip = read_mip_reg();
    log_info("MIP: ");
    log_int(mip, 16);
    new_line();
}
