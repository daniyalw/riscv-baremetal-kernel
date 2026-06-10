#include <uart.h>
#include <logging.h>

void c_log_from_asm() {
    log_info("Hello from assembly through the stack!");
}

int main() {
    log_info("Booted up!");
    log_warn("Testing warning");

    unsigned int asm_read_mhartid(void);
    unsigned int val = asm_read_mhartid();

    log_int(val);

    while (1) {
    }

    return 0;
}
