#define UART_BASE 0x10000000 // QEMU virt's UART0 address
#define UART_THR (*(volatile unsigned char *)(UART_BASE + 0x00))
#define UART_LSR (*(volatile unsigned char *)(UART_BASE + 0x05))

void uart_putc(char c) {
    while ((UART_LSR & 0x20) == 0) {
        // wait
    }

    UART_THR = c;
}

void uart_puts(const char *str) {
    while (*str != '\0') {
        uart_putc(*str);
        str++;
    }
}
