- TODO prerequisites

- TODO build steps for including godot-cpp
- ``cd godot-cpp``
- ``scons platform=<your platform> generate_bindings=yes target=release``


- TODO build steps for including aiso
- TODO build steps for including json
- TODO build steps for including valijson
- TODO build steps for including websocketpp
- TODO build steps for including wswrap
- TODO build steps for including apclientpp



- ``cd subprojects``

- Make sure you're using "x64 Native Tools Command Prompt for VS 2022" for the next 2 libraries

- ``cd zlib``
- Build with ``nmake -f win32/Makefile.msc``


- Follow build guides for OpenSSL (https://github.com/openssl/openssl/blob/master/NOTES-WINDOWS.md)
- ``git clone -b OpenSSL_1_1_1-stable --depth 1 https://github.com/openssl/openssl.git openssl``
- ``cd openssl``
- ``perl Configure VC-WIN64A``
- ``nmake``


- ``cd ../..``
- ``scons platform=windows target=release``