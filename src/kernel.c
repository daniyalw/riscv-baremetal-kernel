#include <uart.h>
#include <logging.h>

int main() {
    log_info("Booted up!");
    log_warn("Testing warning");
    log_info("Testing putting number: ");
    log_int(0b11, 2);

    while (1) {
    }

    return 0;
}
