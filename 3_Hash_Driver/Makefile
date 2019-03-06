IOT_HOME = /opt/iot-devkit/1.7.2/sysroots
KERNEL = $(IOT_HOME)/i586-poky-linux/usr/src/kernel
PATH := $(PATH):$(IOT_HOME)/x86_64-pokysdk-linux/usr/bin/i586-poky-linux

APP = hashtester

obj-m += Hash_Driver.o


all:
	@echo ---Galileo---
	# make ARCH=x86 CROSS_COMPILE=i586-poky-linux- -C $(KERNEL) M=$(PWD) modules
	make ARCH=x86 CROSS_COMPILE=i586-poky-linux- -Wall -C $(KERNEL) M=$(PWD) modules
	i586-poky-linux-gcc -pthread -o $(APP) -Wall Main.c 
	rm -f *.o
	rm -f Module.symvers
	rm -f modules.order
	rm -f *.mod.c
	rm -f *.mod.o

os:
	@echo ---LAPTOP---
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc -pthread -o $(APP) -Wall Main.c 
	gcc -pthread -o TRW -Wall Test_Read_Write.c 
	gcc -pthread -o TIO -Wall Test_IOCTL.c 
	gcc -pthread -o TRC -Wall TRC.c
	rm -f *.o
	rm -f Module.symvers
	rm -f modules.order
	rm -f *.mod.c
	rm -f *.mod.o

clean:
	make ARCH=x86 CROSS_COMPILE=i586-poky-linux- -C $(KERNEL) M=$(PWD) clean
	rm -f $(APP)



