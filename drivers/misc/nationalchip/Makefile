obj-$(CONFIG_NATIONALCHIP_COUNTER) += nc_counter.o
obj-$(CONFIG_NATIONALCHIP_UART_MCTRL) += uart_control.o
obj-$(CONFIG_NATIONALCHIP_OTP) += otp.o
$(obj)/otp.o:
	cp $(srctree)/$(src)/otp.fw $(src)/otp.o

ifeq ($(CONFIG_NATIONALCHIP_NPU), y)
	obj-$(CONFIG_NATIONALCHIP_NPU) += npu.o
endif

ifeq ($(CONFIG_NATIONALCHIP_GXAVDEV), y)
	obj-$(CONFIG_NATIONALCHIP_GXAVDEV) += gxavdev.o
endif
