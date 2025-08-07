#!python
import os

opts = Variables([], ARGUMENTS)

# Gets the standard flags CC, CCX, etc.
env = DefaultEnvironment()


# TODO debug release doesn't work, investigate why

# Define our options
opts.Add(EnumVariable('target', "Compilation target", 'release', ['r', 'release'])) # 'd', 'debug'
opts.Add(EnumVariable('platform', "Compilation platform", '', ['', 'windows', 'linuxbsd', 'linux', 'osx']))
opts.Add(EnumVariable('p', "Compilation target, alias for 'platform'", '', ['', 'windows', 'linuxbsd', 'linux', 'osx']))
opts.Add(BoolVariable('use_llvm', "Use the LLVM / Clang compiler", 'no'))
opts.Add(PathVariable('target_path', 'The path where the lib is installed.', 'bin/'))
opts.Add(PathVariable('target_name', 'The library name.', 'godot-apclient', PathVariable.PathAccept))
opts.Add(EnumVariable('macos_arch', "Compilation architecture", 'arm64', ['x86_64', 'arm64']))

env.Append(CPPDEFINES=['ASIO_STANDALONE'])
env.Append(CPPDEFINES=['_WIN32_WINNT=0x0600'])
env.Append(CPPDEFINES=['_WEBSOCKETPP_CPP11_STL_']) # @TODO this might not be the correct way to solve this

#env.Append(CPPDEFINES=['WSWRAP_NO_SSL']) # @TODO remove after testing

# Local dependency paths, adapt them to your setup
godot_headers_path = "godot-cpp/godot-headers/"
cpp_bindings_path = "godot-cpp/"
cpp_library = "libgodot-cpp"

# Only support 64 at this time
bits = 64

# Updates the environment with the option variables.
opts.Update(env)

# Process some arguments
if env['use_llvm']:
    env['CC'] = 'clang'
    env['CXX'] = 'clang++'

if env['p'] != '':
    env['platform'] = env['p']

if env['platform'] == '':
    print("No valid target platform selected.")
    quit();

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Check our platform specifics
if env['platform'] == "osx":
    env['target_path'] += 'osx/'
    cpp_library += '.osx'
    if env["macos_arch"] == "x86_64":
        env.Append(CCFLAGS = ['-g','-O2', '-arch', 'x86_64', '-std=c++17'])
        env.Append(LINKFLAGS = ['-arch', 'x86_64'])
    else: # Default to ARM since M1/M2 is the future for mac
        env.Append(CCFLAGS = ['-g','-O2', '-arch', 'arm64', '-std=c++17'])
        env.Append(LINKFLAGS = ['-arch', 'arm64'])

    env.Append(CCFLAGS=['-g', '-O3', '-std=c++17'])
    
elif env['platform'] in ('linuxbsd', 'linux'):
    env['target_path'] += 'linuxbsd/'
    cpp_library += '.linux'
    
    env.Append(CCFLAGS=['-fPIC'])
    env.Append(CXXFLAGS=['-std=c++17'])
    env.Append(RPATH=env.Literal('\\$$ORIGIN'))
    env.Append(CCFLAGS=['-g', '-O3'])

elif env['platform'] == "windows":
    env['target_path'] += 'win64/'
    cpp_library += '.windows'

    env.Append(CPPDEFINES=['WIN32', '_WIN32', '_WINDOWS', '_CRT_SECURE_NO_WARNINGS'])
    env.Append(CCFLAGS=['-W3', '-GR', '-FS'])
    env.Append(CXXFLAGS='/std:c++17')
    
    if env['target'] in ('debug', 'd'):
        env.Append(CPPDEFINES=['_DEBUG'])
        env.Append(CCFLAGS=['-EHsc', '-MDd', '-ZI'])
        env.Append(LINKFLAGS=['-DEBUG'])
    else:
        env.Append(CPPDEFINES=['NDEBUG'])
        env.Append(CCFLAGS=['-O2', '-EHsc', '-MD'])

if env['target'] in ('debug', 'd'):
    cpp_library += '.debug'
else:
    cpp_library += '.release'

if env['platform'] == 'osx':
    if env['macos_arch'] == 'x86_64':
        cpp_library += '.' + 'x86_64'
    else:
        cpp_library += '.' + 'arm64'
else:
    cpp_library += '.' + str(bits)



# Make sure our binding library is properly includes
env.Append(CPPPATH=['.', godot_headers_path, cpp_bindings_path + 'include/', cpp_bindings_path + 'include/core/', cpp_bindings_path + 'include/gen/'])
env.Append(LIBPATH=[cpp_bindings_path + 'bin/'])
env.Append(LIBS=[cpp_library, 'Shell32'])

# Dependencies
env.Append(CPPPATH=['subprojects/asio/include/'])
env.Append(CPPPATH=['subprojects/websocketpp/'])
env.Append(CPPPATH=['subprojects/wswrap/include/'])
env.Append(CPPPATH=['subprojects/json/include/'])
env.Append(CPPPATH=['subprojects/valijson/include'])
env.Append(CPPPATH=['subprojects/apclientpp'])

# ZLib Linking
env.Append(CPPPATH=['subprojects/zlib/'])
env.Append(LIBPATH=['subprojects/zlib/'])
env.Append(LIBS=['zlib'])

# OpenSSL Linking
env.Append(CPPPATH=['subprojects/openssl/include/'])
env.Append(LIBPATH=['subprojects/openssl/'])
env.Append(LIBS=['libssl_static', 'libcrypto_static', 'WS2_32', 'Gdi32', 'AdvAPI32', 'Crypt32', 'User32'])

# Tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=['src/'])
sources = Glob('src/*.cpp')

library = env.SharedLibrary(target=env['target_path'] + env['target_name'] , source=sources)

Default(library)

# Generates help for the -h scons option.
Help(opts.GenerateHelpText(env))