cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    test.cpp
)

add_executable(Sandbox32 ${SOURCE_FILES})


target_compile_options(Sandbox32 PUBLIC
        -masm=intel
        -m32  -fno-exceptions
        -Wall
        -Wextra
        -pedantic
        -D_GNU_SOURCE
        -Wno-format
)
target_link_options(Sandbox32 PUBLIC
        -Wl,-z,stack-size=33554432
        -Xlinker -Map=output.map
        -Xlinker -m32
)

target_link_libraries(Sandbox32 m rt pthread)



add_executable(Sandbox64 ${SOURCE_FILES})


target_compile_options(Sandbox64 PUBLIC
        -masm=intel
        -m64  -fno-exceptions
        -Wall
        -Wextra
        -pedantic
        -D_GNU_SOURCE
        -Wno-format
        )
target_link_options(Sandbox64 PUBLIC
        -Wl,-z,stack-size=33554432
        -Xlinker -Map=output.map
        -Xlinker -m64
        )

target_link_libraries(Sandbox64 m rt pthread)

