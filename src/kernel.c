#include <uart.h>
#include <logging.h>
#include <trap.h>

int main() {
    log_info_nl("Booted up!");
    log_warn_nl("Testing warning");

    void set_mtvec(void);
    set_mtvec();

    asm volatile("csrc mie, %0" :: "r"(0x80));

    log_info_nl("Set mtvec!");
    asm volatile("ecall");
    log_info_nl("SURVIVED");

    read_mstatus();
    read_mie();
    read_mip();

    //log_info_nl("Before mtime pointer");
    volatile unsigned int *mtime_lo = (volatile unsigned int *)0x0200BFF8;
    //log_info_nl("After mtime pointer");

    //log_info_nl("Before mtime read");
    unsigned int now = *mtime_lo;
    log_info("mtime = ");
    log_int(now, 16);

    while (1) {
    }

    return 0;
}
