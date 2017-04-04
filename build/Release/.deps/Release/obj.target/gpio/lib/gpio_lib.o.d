cmd_Release/obj.target/gpio/lib/gpio_lib.o := cc '-DNODE_GYP_MODULE_NAME=gpio' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/usr/include/nodejs/include/node -I/usr/include/nodejs/src -I/usr/include/nodejs/deps/uv/include -I/usr/include/nodejs/deps/v8/include -I../lib  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -O3 -ffunction-sections -fdata-sections -fno-omit-frame-pointer  -MMD -MF ./Release/.deps/Release/obj.target/gpio/lib/gpio_lib.o.d.raw  -c -o Release/obj.target/gpio/lib/gpio_lib.o ../lib/gpio_lib.c
Release/obj.target/gpio/lib/gpio_lib.o: ../lib/gpio_lib.c \
 ../lib/gpio_lib.h
../lib/gpio_lib.c:
../lib/gpio_lib.h:
