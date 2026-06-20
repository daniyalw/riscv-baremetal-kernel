#include <uart.h>
#include <logging.h>
#include <trap.h>

void trigger_illegal_instruction() {
    asm volatile(".word 0x00000000");
}

int main() {
    log_info_nl("Booted up!");
    log_warn_nl("Testing warning");

    void set_mtvec(void);
    set_mtvec();

    log_info_nl("Set mtvec!");
    asm volatile("ecall");
    log_info_nl("SURVIVED");

    // test
    //trigger_illegal_instruction();

    read_mstatus();
    read_mie();
    read_mip();

    while (1) {
    }

    return 0;
}
