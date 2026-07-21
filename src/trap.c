#include <logging.h>
#include <trap.h>

unsigned int trap_handler(unsigned int mcause, unsigned int mepc, unsigned int mtval) {
    const char mcause_text[] = "mcause = ";
    const char mepc_text[] = "mepc = ";
    const char mtval_text[] = "mtval = ";

    log_info(mcause_text);
    log_int(mcause, 10);
    new_line();

    log_info(mepc_text);
    log_int(mepc, 16);
    new_line();

    log_info(mtval_text);
    log_int(mtval, 16);
    new_line();

    if (mcause == 11) {
        // ecall
        log_info("ECALL DETECTED");

        mepc += 4;
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
