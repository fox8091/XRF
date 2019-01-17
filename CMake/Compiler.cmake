cmake_minimum_required(VERSION 3.8)

#######################
# MSVC Compiler Setup
#######################

# Ignore the default Win32 libraries
set(CMAKE_CXX_STANDARD_LIBRARIES "")

# Common linker flags
set(MSVC_LINKER_FLAGS "/NOLOGO /DYNAMICBASE /INCREMENTAL:NO /RELEASE /NODEFAULTLIB")

# Setup target specific flags
set(CMAKE_MODULE_LINKER_FLAGS "${MSVC_LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${MSVC_LINKER_FLAGS} 
    /SUBSYSTEM:WINDOWS,6.00 
    /LARGEADDRESSAWARE 
    /NXCOMPAT
    /DEBUGTYPE:cv,fixup 
    /PDBCOMPRESS")

set(CMAKE_EXE_LINKER_FLAGS "${MSVC_LINKER_FLAGS} /SUBSYSTEM:CONSOLE /PDBCOMPRESS")

set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "/NOVCFEATURE")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${MSVC_LINKER_FLAGS}")

set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "/LTCG")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/LTCG /OPT:REF /OPT:ICF")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/LTCG /OPT:REF /OPT:ICF")

# Default definitions
set(DEFAULT_DEFINITIONS
    -DAMD64
    -D_WIN64
    -D_AMD64
    -D_M_AMD64
    -DWIN32
    -D_WIN32
    -DWIN32_LEAN_AND_MEAN=1
    -D_CRT_SECURE_NO_WARNINGS
)
string(REPLACE ";" " " DEFAULT_DEFINITIONS "${DEFAULT_DEFINITIONS}")

add_definitions(${DEFAULT_DEFINITIONS})

# Default flags to use (C++)
set(CXX_COMMON_FLAGS 
    /TP             # Compile as C++
    /d2Zi+          # Make optimized builds debugging easier
    /w              # Suppress compiler warnings
    /Oi             # Enable intrinsics
    /Oy-            # 
    /GF             # Enable read-only string pooling
    /Gm-            # Disable minimal rebuild
    /EHa            # Enable C++ EH (w/ SEH exceptions)
    /Zp8            # Pack structs on 8-byte boundary
    /Gy             # Enable function level linking
    /Zc:wchar_t-    # Set wchar_t as an interal type
    /Zc:forScope    # Standard scoping rules
    /GR-            # Disable RTTI
    /GS             # Enable buffer security check
    /Zi             # Enable debug info
    /guard:cf       # Enable control flow guard
)
string(REPLACE ";" " " CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS}")

set(CMAKE_CXX_FLAGS "${CXX_COMMON_FLAGS}")