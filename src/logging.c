#include <uart.h>
#include <string.h>

void log_info(const char *str) {
    uart_puts("\033[40;36m"); // cyan
    uart_puts("[INFO] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
    uart_puts("\n");
}

void log_error(const char *str) {
    uart_puts("\033[40;31m"); // red
    uart_puts("[ERROR] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
    uart_puts("\n");
}

void log_warn(const char *str) {
    uart_puts("\033[40;33m"); // yellow
    uart_puts("[WARNING] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
    uart_puts("\n");
}

// base: 2 for binary, 10 for decmal, 16 for hex
void log_int(int num, int base) {
    char buffer[12];
    itoa(buffer, base, num);

    if (base == 16) {
        uart_puts("0x");
    } else if (base == 2) {
        uart_puts("0b");
    }

    uart_puts(buffer);
}
