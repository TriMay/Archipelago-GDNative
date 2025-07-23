- TODO prerequisites

- TODO build steps for including godot-cpp
- TODO build steps for including aiso
- TODO build steps for including json
- TODO build steps for including valijson
- TODO build steps for including websocketpp
- TODO build steps for including wswrap
- TODO build steps for including apclientpp

- ``cd zlib``
- Make sure you're using "x64 Native Tools Command Prompt for VS 2022"
- Build with ``nmake -f win32/Makefile.msc``

- TODO check the following steps
- ``git clone -b OpenSSL_1_1_1-stable --depth 1 https://github.com/openssl/openssl.git openssl``
- ``cd openssl``
- md ${{env.BUILD_PLATFORM}}
- cd ${{env.BUILD_PLATFORM}}
- perl ..\Configure ${{env.OPENSSL_BUILD_PLATFORM}} no-shared
- nmake /S