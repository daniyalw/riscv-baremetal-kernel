#include <uart.h>
#include <logging.h>
#include <trap.h>
#include <timer.h>

int main() {
    log_info_nl("Booted up!");
    log_warn_nl("Testing warning");

    void set_mtvec(void);
    set_mtvec();

    timer_schedule_next();
    asm volatile("csrs mie, %0" :: "r"(0x80));  // set MTIE
    asm volatile("csrs mstatus, %0" :: "r"(0x8)); // set MIE

    while (1) {
    }

    return 0;
}
