#include <uart.h>
#include <logging.h>
#include <trap.h>

void trigger_illegal_instruction(void)
{
    asm volatile(".word 0x00000000");
}

int main() {
    log_info("Booted up!");
    log_warn("Testing warning");

    void set_mtvec(void);
    set_mtvec();

    log_info("Set mtvec!");
    asm volatile("ecall");
    log_info("SURVIVED");

    // test
    trigger_illegal_instruction();

    while (1) {
    }

    return 0;
}
