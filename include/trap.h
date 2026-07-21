unsigned int trap_handler(unsigned int mcause, unsigned int mepc, unsigned int mtval);
void unknown_trap();

void read_mstatus();
void read_mie();
void read_mip();
