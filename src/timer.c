#include <logging.h>

#define CLINT_MTIMECMP_LO  (*(volatile unsigned int *)0x02004000)
#define CLINT_MTIMECMP_HI  (*(volatile unsigned int *)0x02004004)

#define CLINT_MTIME_LO     (*(volatile unsigned int *)0x0200BFF8)
#define CLINT_MTIME_HI     (*(volatile unsigned int *)0x0200BFFC)

#define TIMER_INTERVAL     10000000

int timer_tick = -1; // start at -1 since we call timer_schedule_next exactly once before enabling interrupts in main()

void timer_schedule_next() {
    unsigned int now = CLINT_MTIME_LO;
    unsigned int next = now + TIMER_INTERVAL;

    CLINT_MTIMECMP_LO = next;
    CLINT_MTIMECMP_HI = 0;

    timer_tick += 1;

    log_info("Timer interrupt tick: ");
    log_int(timer_tick, 10);
}
