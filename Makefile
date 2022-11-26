export PATH := $(PATH):$(PWD)/build/arm-linux-gnueabihf/bin

CC := gcc
CC-arm := arm-linux-gnueabihf-gcc
CFLAGS := -Wall
C_SOURCES=$(shell find ./src -name '*.c')
CPP_SOURCES :=$(shell find ./src -name '*.cpp')
RM = rm -rf
MKDIR = mkdir -p

.PHONY: install-toolchain host target clean

install-toolchain:
	$(MKDIR) ./downloads
	$(MKDIR) ./build
	wget -c -O ./downloads/arm-linux-gnueabihf.tar.xz https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabihf/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf.tar.xz
	if [ ! -d ./build/arm-linux-gnueabihf ]; then \
		tar -xf ./downloads/arm-linux-gnueabihf.tar.xz -C ./build; \
		mv ./build/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf ./build/arm-linux-gnueabihf; \
	fi
	@echo $(PATH)

target: $(C_SOURCES)
	$(MKDIR) install
	$(CC-arm) -o ./install/$@ $^ $(CFLAGS)

host: $(C_SOURCES)
	$(MKDIR) install
	$(CC) -o ./install/$@ $^ $(CFLAGS)

clean:
	$(RM) $(@D)/build
	$(RM) $(@D)/downloads