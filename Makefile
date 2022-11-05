gcc-arm-linux-gnueabihf:
	mkdir -p $(@D)/downloads
	wget -c -O $(@D)/downloads/gcc-arm-linux-gnueabihf.tar.xz https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabihf/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf.tar.xz
	mkdir -p $(@D)/build
	tar -xf $(@D)/downloads/gcc-arm-linux-gnueabihf.tar.xz -C $(@D)/build

clean:
	rm -rf $(@D)/build
	rm -rf $(@D)/downloads