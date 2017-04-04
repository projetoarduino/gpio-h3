cmd_Release/obj.target/gpio/gpio.o := g++ '-DNODE_GYP_MODULE_NAME=gpio' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/usr/include/nodejs/include/node -I/usr/include/nodejs/src -I/usr/include/nodejs/deps/uv/include -I/usr/include/nodejs/deps/v8/include -I../lib  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -O3 -ffunction-sections -fdata-sections -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=gnu++0x -MMD -MF ./Release/.deps/Release/obj.target/gpio/gpio.o.d.raw   -c -o Release/obj.target/gpio/gpio.o ../gpio.cpp
Release/obj.target/gpio/gpio.o: ../gpio.cpp \
 /usr/include/nodejs/src/node.h /usr/include/nodejs/deps/v8/include/v8.h \
 /usr/include/nodejs/deps/v8/include/v8-version.h \
 /usr/include/nodejs/deps/v8/include/v8config.h \
 /usr/include/nodejs/src/node_version.h ../lib/gpio_lib.h
../gpio.cpp:
/usr/include/nodejs/src/node.h:
/usr/include/nodejs/deps/v8/include/v8.h:
/usr/include/nodejs/deps/v8/include/v8-version.h:
/usr/include/nodejs/deps/v8/include/v8config.h:
/usr/include/nodejs/src/node_version.h:
../lib/gpio_lib.h:
