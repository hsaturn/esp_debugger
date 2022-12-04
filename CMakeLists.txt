cmake_minimum_required(VERSION 3.5)

project(esp_debug LANGUAGES CXX)

add_subdirectory(ext/Qt-Advanced-Docking-System)
add_compile_options(-Wall -g)

include_directories(ext/Qt-Advanced-Docking-System/src)
include_directories(src)
include_directories(ext/klive/core)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)
# set(TS_FILES resources/esp_debug_fr_FR.ts)

add_executable(esp_debug
    ${ads_SRCS}
    src/core/main.cpp
    src/core/mainwindow.h src/core/mainwindow.cpp
    src/handlers/debugginghandler.h src/handlers/debugginghandler.cpp
    ext/klive/core/handler.h ext/klive/core/handler.cpp
    #[[common/observer.h
    common/mapreader.h
    common/expr.h
    common/expr.cpp
    common/crc.h


    *[[core/hardware/computer.cpp
    core/hardware/computer.h
    core/hardware/memory.cpp
    core/hardware/memory.h
    core/hardware/cpu.cpp
    core/hardware/cpu.h
    core/hardware/z80.cpp
    core/hardware/z80.h
    core/hardware/z80registers.cpp
    core/hardware/z80registers.h
    core/hardware/ioports.h
    core/hardware/checkpoints.cpp
    core/hardware/keyboard.cpp

    handlers/project/projecthandler.cpp
    handlers/project/projecthandler.h

    handlers/gadgets/z80/gens.cpp
    handlers/gadgets/z80/monsview.cpp
    handlers/gadgets/z80/monsview.h
    handlers/gadgets/z80/mons.cpp
    handlers/gadgets/z80/mons.h


    handlers/gadgets/gdb/minigdb.cpp
    handlers/gadgets/gdb/minigdb.h

    handlers/screen/screenhandler.cpp
    handlers/screen/screenhandler.h

    handlers/memory/memoryviewer.cpp
    handlers/memory/memoryviewer.h

    handlers/gadgets/zx/spectrum/SpectrumScreen.cpp
    handlers/gadgets/zx/spectrum/SpectrumScreen.h

    handlers/gadgets/clock/clock.cpp
    handlers/gadgets/clock/clock.h

    handlers/gadgets/lines/linebouncer.cpp
    handlers/gadgets/lines/linebouncer.h
    handlers/gadgets/lines/lines.cpp
    handlers/gadgets/lines/lines.h
    ]]

    resources/esp_debug.qrc
    ${TS_FILES}
)
# target_compile_options(esp_debug PUBLIC -std=c++17 -g -Weverything -Wno-c++98-compat -Wno-c++98-c++11-c++14-compat -Wno-c++98-compat-pedantic -fsanitize=address)

#set(CMAKE_C_FLAGS_ASAN "-fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g -O1" CACHE STRING "Flags used by the C compiler during AddressSanitizer builds." FORCE)
#set(CMAKE_CXX_FLAGS_ASAN "-fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g -O1" CACHE STRING "Flags used by the C++ compiler during AddressSanitizer builds." FORCE)

target_link_libraries(esp_debug PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(esp_debug PRIVATE qtadvanceddocking)
