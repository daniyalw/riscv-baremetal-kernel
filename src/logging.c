#include <uart.h>
#include <string.h>
#include <logging.h>

void log_info(const char *str) {
    uart_puts("\033[40;36m"); // cyan
    uart_puts("[INFO] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
}

void log_info_nl(const char *str) {
    log_info(str);
    new_line();
}

void log_char(const char c) {
    uart_putc(c);
}

void log_error(const char *str) {
    uart_puts("\033[40;31m"); // red
    uart_puts("[ERROR] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
}

void log_error_nl(const char *str) {
    log_error(str);
    new_line();
}

void log_warn(const char *str) {
    uart_puts("\033[40;33m"); // yellow
    uart_puts("[WARNING] ");
    uart_puts("\033[0m"); // reset colour
    uart_puts(str);
}

void log_warn_nl(const char *str) {
    log_warn(str);
    new_line();
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

void new_line() {
    uart_puts("\n");
}
