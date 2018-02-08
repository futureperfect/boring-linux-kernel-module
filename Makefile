obj-m += boring.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
info:
	sudo modinfo boring.ko
test:
	-sudo rmmod boring
	sudo dmesg -C
	sudo insmod boring.ko
	sudo dmesg
