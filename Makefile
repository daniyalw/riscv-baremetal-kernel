CC = riscv-none-elf-gcc
CFLAGS = -march=rv32imac_zicsr -mabi=ilp32 -ffreestanding -O0 -Iinclude

LDFLAGS = -T linker.ld -nostdlib

TARGET = firmware
EMU = qemu-system-riscv32
EMU_FLAGS = -machine virt -nographic -bios none -kernel

SRCS = src/start.S src/kernel.c src/uart.c src/logging.c src/string.c src/test.S src/trap_asm.S src/trap.c

OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

src/%.o: src/%.S
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET).elf
	$(EMU) $(EMU_FLAGS) $(TARGET).elf
