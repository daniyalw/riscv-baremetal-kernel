CC = riscv-none-elf-gcc
CFLAGS = -march=rv32imac -mabi=ilp32 -ffreestanding -O0 -Iinclude

LDFLAGS = -T linker.ld -nostdlib

TARGET = firmware
EMU = qemu-system-riscv32
EMU_FLAGS = -machine virt -nographic -bios none -kernel

SRCS = src/start.S src/kernel.c src/uart.c

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

clean:
	rm -f src/*.o *.elf
